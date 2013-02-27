/*
 * Copyright (C) 2013 Tanaka Akira  <akr@fsij.org>
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  1. Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

#include "sockettest.h"

#if defined(__minix)
/* MINIX hangs connect() if no one calls accept().
 */
#define USE_FORK 1
#elif defined(__CYGWIN__)
/* cygwin hangs connect() if no one calls accept().
 * Note that cygwin don't need addtional compile/link option for pthread.
 */
#define USE_PTHREAD 1
#endif

#ifdef USE_PTHREAD
#include <pthread.h>
#endif

#ifndef SOMAXCONN
#  define SOMAXCONN 128
#endif

#ifdef USE_FORK
typedef struct { int pipe[2]; } serialized_flow_t;
#endif

static int opt_U = 0;
static int opt_c = 0;
static int opt_s = 0;
static int opt_p = 0;
static socklen_t opt_g = sizeof(struct sockaddr_un);
static int opt_f = '\0';
static int opt_e = 0;
static int opt_4 = 0;

static char *server_path_str;
static size_t server_path_len = 0;
static int server_path_sun_len = 0; /* 4.4BSD sun_len field in sockaddr_un */
static char *connect_path_str;
static size_t connect_path_len = 0;
static int connect_path_sun_len = 0; /* 4.4BSD sun_len field in sockaddr_un */
static char *client_path_str;
static size_t client_path_len = 0;
static int client_path_sun_len = 0; /* 4.4BSD sun_len field in sockaddr_un */

static char *tmpdir = NULL;

struct sockaddr_un *server_sockaddr_ptr;
socklen_t server_sockaddr_len;

static struct sockaddr_un *connect_sockaddr_ptr;
static socklen_t connect_sockaddr_len;

struct sockaddr_un *client_sockaddr_ptr;
socklen_t client_sockaddr_len;

struct sockaddr_un *get_sockaddr_ptr, *get_sockaddr_ptr2;
socklen_t get_sockaddr_len, get_sockaddr_len2;

#ifdef USE_FORK
static pid_t parent_pid;
static pid_t child_pid = 0;
static serialized_flow_t server_serialised_flow;
static serialized_flow_t client_serialised_flow;
#endif

#ifdef USE_PTHREAD
static pthread_t connect_thread;
#endif

static int client_socket;
static int server_socket;
static int accepted_socket;

void usage(int status)
{
  fputs(
      "usage: unix-stream [options] server-path [connect-path [client-path]]\n"
      "option: -h : show this help message\n"
      "        -U : don't unlink sockets.\n"
      "        -c : test in the current directory.\n"
      "        -s : server only test mode.\n"
      "        -p : prepend sizeof(sun_path)-10 characters for socket-path.\n"
      "        -g N : buffer size for getsockname/getpeername/accept (no sign means exact.  +N for increase and -N for decrease from sockaddr_un)\n"
      "        -f N : ASCII code to fill for getsockname buffer\n"
      "        -e N : number of extra bytes for getsockname buffer\n"
      "        -4 : show 4.4BSD sun_len field\n"
      , stdout);
  exit(status);
}

#ifdef USE_FORK
static void serialized_flow_init(serialized_flow_t *ptr)
{
  int ret;
  ret = pipe(ptr->pipe);
  if (ret == -1) { perror("pipe"); exit(EXIT_FAILURE); }
}

static void serialized_flow_send(serialized_flow_t *another, int tag)
{
  int e = errno;
  char buf[1];
  ssize_t ssize;
  buf[0] = tag;
  ssize = write(another->pipe[1], buf, 1);
  if (ssize == -1) { perror("write"); exit(EXIT_FAILURE); }
  errno = e;
}

static void serialized_flow_recv(serialized_flow_t *self, int tag)
{
  int e = errno;
  char buf[1];
  ssize_t ssize;
  ssize = read(self->pipe[0], buf, 1);
  if (ssize == -1) { perror("read"); exit(EXIT_FAILURE); }
  if (ssize == 0) {
    /* serialization error: EOF got */
    /* exit without a error message because another process should print an error. */
    exit(EXIT_FAILURE);
  }
  if ((unsigned char)buf[0] != tag) {
    fprintf(stderr, "serialization error: %d expected but %d got\n", tag, (unsigned char)buf[0]);
    exit(EXIT_FAILURE);
  }
  errno = e;
}

#else
#  define serialized_flow_init(ptr)
#  define serialized_flow_send(another, tag)
#  define serialized_flow_recv(self, tag)
#endif

#define PREPEND_LENGTH (FIELD_SIZE(struct sockaddr_un, sun_path)-10)
static char *unescape_and_prepend_string(
    size_t *unescaped_len_ret, int *sun_len_ret,
    char *escaped_ptr, size_t escaped_len)
{
  char *unescaped_str;
  size_t unescaped_len;
  int sun_len = 0;

#define STATIC_STRLEN(str) (sizeof(str)-1)
  if (STATIC_STRLEN("(sun_len=N)") <= escaped_len &&
      memcmp("(sun_len=", escaped_ptr, STATIC_STRLEN("(sun_len=")) == 0) {
    char *pstart = escaped_ptr + sizeof("(sun_len=")-1;
    char *p = pstart;
    char *pend = escaped_ptr + escaped_len;
    while (p < pend && isdigit((unsigned char)*p))
      p++;
    if (pstart == p) return NULL;
    if (p == pend) return NULL;
    if (*p != ')') return NULL;
    p++;
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
    {
      int n = atoi(pstart);
      if (n < 0 || 0xff < n)
        return NULL;
      sun_len = n;
      escaped_len -= p - escaped_ptr;
      escaped_ptr = p;
    }
#else
    return NULL;
#endif
  }

  unescaped_str = unescape_string(&unescaped_len, escaped_ptr, escaped_len);
  if (unescaped_str == NULL)
    return NULL;

  if (opt_p) {
    unescaped_str = xrealloc(unescaped_str, PREPEND_LENGTH+unescaped_len+1);
    memmove(unescaped_str+PREPEND_LENGTH, unescaped_str, unescaped_len+1);
    memset(unescaped_str, 'Z', PREPEND_LENGTH);
    unescaped_len += PREPEND_LENGTH;
  }

  if (unescaped_len_ret)
    *unescaped_len_ret = unescaped_len;
  if (sun_len_ret)
    *sun_len_ret = sun_len;
  return unescaped_str;
}

static void parse_args(int argc, char *argv[])
{
  int opt;
  char *arg;

  while ((opt = getopt(argc, argv, "hUcspg:f:e:4")) != -1) {
    switch (opt) {
      case 'h':
        usage(EXIT_SUCCESS);
        break; /* not reached */

      case 'U':
        opt_U = 1;
        break;

      case 'c':
        opt_c = 1;
        break;

      case 's':
        opt_s = 1;
        break;

      case 'p':
        opt_p = 1;
        break;

      case 'g':
        if (*optarg == '-' || *optarg == '+') {
          int n = atoi(optarg);
          if (n < 0 && sizeof(struct sockaddr_un) < (size_t)-n) {
            fprintf(stderr, "argument for -g is too small.  (%d minimum)\n",
                -(int)sizeof(struct sockaddr_un));
            exit(EXIT_FAILURE);
          }
          opt_g = sizeof(struct sockaddr_un) + n;
        }
        else
          opt_g = atoi(optarg);
        break;

      case 'f':
        opt_f = atoi(optarg);
        break;

      case 'e':
        opt_e = atoi(optarg);
        break;

      case '4':
        opt_4 = 1;
        break;

      default:
        exit(EXIT_FAILURE);
    }
  }
  if (argc <= optind) {
    fprintf(stderr, "needs a unix-socket-path argument\n");
    exit(EXIT_FAILURE);
  }

  arg = argv[optind++];
  server_path_str = unescape_and_prepend_string(
      &server_path_len, &server_path_sun_len, arg, strlen(arg));
  if (server_path_str == NULL) {
    fprintf(stderr, "server path unescape failed\n");
    exit(EXIT_FAILURE);
  }

  if (optind == argc) {
    connect_path_str = server_path_str;
    connect_path_len = server_path_len;
    return;
  }

  arg = argv[optind++];
  connect_path_str = unescape_and_prepend_string(
      &connect_path_len, &connect_path_sun_len, arg, strlen(arg));
  if (connect_path_str == NULL) {
    fprintf(stderr, "connect path unescape failed\n");
    exit(EXIT_FAILURE);
  }

  if (optind == argc) {
    return;
  }

  arg = argv[optind++];
  client_path_str = unescape_and_prepend_string(
      &client_path_len, &client_path_sun_len, arg, strlen(arg));
  if (client_path_str == NULL) {
    fprintf(stderr, "client path unescape failed\n");
    exit(EXIT_FAILURE);
  }

  if (optind != argc) {
    fprintf(stderr, "too many arguments\n");
    exit(EXIT_FAILURE);
  }

  return;
}

void addr_setup(void)
{
  server_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + server_path_len;
  server_sockaddr_ptr = xfalloc(server_sockaddr_len, '\0');
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  server_sockaddr_ptr->sun_len = server_path_sun_len;
#endif
  server_sockaddr_ptr->sun_family = AF_UNIX;
  memcpy(server_sockaddr_ptr->sun_path, server_path_str, server_path_len);

  connect_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + connect_path_len;
  connect_sockaddr_ptr = xfalloc(connect_sockaddr_len, '\0');
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  server_sockaddr_ptr->sun_len = connect_path_sun_len;
#endif
  connect_sockaddr_ptr->sun_family = AF_UNIX;
  memcpy(connect_sockaddr_ptr->sun_path, connect_path_str, connect_path_len);

  if (client_path_str) {
    client_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + client_path_len;
    client_sockaddr_ptr = xfalloc(client_sockaddr_len, '\0');
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  server_sockaddr_ptr->sun_len = client_path_sun_len;
#endif
    client_sockaddr_ptr->sun_family = AF_UNIX;
    memcpy(client_sockaddr_ptr->sun_path, client_path_str, client_path_len);
  }

  get_sockaddr_len = opt_g;
  get_sockaddr_ptr = xmalloc(get_sockaddr_len);

  get_sockaddr_len2 = opt_g;
  get_sockaddr_ptr2 = xmalloc(get_sockaddr_len2);

  return;
}

void server_setup(void)
{
  socklen_t len;
  int ret;

  server_socket = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server_socket == -1) { perror2("socket(server)"); exit(EXIT_FAILURE); }

  report_path_to_kernel("bind(server)", server_sockaddr_ptr, server_sockaddr_len, opt_4);
  ret = bind(server_socket, (const struct sockaddr *)server_sockaddr_ptr, server_sockaddr_len);
  if (ret == -1) { perror2("bind(server)"); exit(EXIT_FAILURE); }

  ret = socket_file_p(server_path_str);
  printf("socket file (server)  : %s\n", ret ? "exist" : "not exist");

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
  ret = getsockname(server_socket, (struct sockaddr *)get_sockaddr_ptr, &len);
  if (ret == -1) { perror2("getsockname(server)"); }
  else report_path_from_kernel("getsockname(server)", get_sockaddr_len, get_sockaddr_ptr, len, opt_4);

  ret = listen(server_socket, SOMAXCONN);
  if (ret == -1) { perror2("listen"); exit(EXIT_FAILURE); }
}

void client_setup(void)
{
  int ret;

  client_socket = socket(AF_UNIX, SOCK_STREAM, 0);
  if (client_socket == -1) { perror2("socket(client)"); exit(EXIT_FAILURE); }
}

static void *connect_func(void *arg)
{
  socklen_t len;
  int ret;

  if (client_path_str) {
    report_path_to_kernel("bind(client)", client_sockaddr_ptr, client_sockaddr_len, opt_4);
    ret = bind(client_socket, (const struct sockaddr *)client_sockaddr_ptr, client_sockaddr_len);
    if (ret == -1) { perror2("bind(client)"); exit(EXIT_FAILURE); }

    ret = socket_file_p(client_path_str);
    printf("socket file (client)  : %s\n", ret ? "exist" : "not exist");
  }

  memset(get_sockaddr_ptr2, opt_f, get_sockaddr_len2);
  len = get_sockaddr_len2;
  ret = getsockname(client_socket, (struct sockaddr *)get_sockaddr_ptr2, &len);
  if (ret == -1) { perror2("getsockname(client)"); }
  else report_path_from_kernel("getsockname(client)", get_sockaddr_len2, get_sockaddr_ptr2, len, opt_4);

  report_path_to_kernel("connect", connect_sockaddr_ptr, connect_sockaddr_len, opt_4);
  serialized_flow_send(&server_serialised_flow, 2);
//printf("pid=%d line=%d: before connect\n", (int)getpid(), __LINE__);
  ret = connect(
      client_socket,
      (struct sockaddr *)connect_sockaddr_ptr,
      connect_sockaddr_len);

  if (ret != -1) {
    int e = errno;
    write(client_socket, "", 1); /* This avoids hang on MINIX. */
    errno = e;
  }

//printf("pid=%d line=%d: after connect\n", (int)getpid(), __LINE__);

  if (ret == -1) { perror2("connect"); return (void *)"connect"; }

  serialized_flow_recv(&client_serialised_flow, 3);

  memset(get_sockaddr_ptr2, opt_f, get_sockaddr_len2);
  len = get_sockaddr_len2;
  ret = getpeername(client_socket, (struct sockaddr *)get_sockaddr_ptr2, &len);
  if (ret == -1) { perror2("getpeername(client)"); }
  else report_path_from_kernel("getpeername(client)", get_sockaddr_len2, get_sockaddr_ptr2, len, opt_4);

  /*
printf("pid=%d line=%d: before sleep\n", (int)getpid(), __LINE__);
  sleep(2);
printf("pid=%d line=%d: after sleep\n", (int)getpid(), __LINE__);
*/

  serialized_flow_send(&server_serialised_flow, 4);
  return NULL;
}

static void *accept_func(void *arg)
{
  socklen_t len;
  int ret;

  serialized_flow_recv(&server_serialised_flow, 2);

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
//printf("pid=%d line=%d: before accept\n", (int)getpid(), __LINE__);
  accepted_socket = accept(server_socket, (struct sockaddr *)get_sockaddr_ptr, &len);
//printf("pid=%d line=%d: after accept\n", (int)getpid(), __LINE__);

  serialized_flow_send(&client_serialised_flow, 3);
  serialized_flow_recv(&server_serialised_flow, 4);

#if defined(USE_PTHREAD)
  {
    void *connect_func_ret;
    ret = pthread_join(connect_thread, &connect_func_ret);
    if (ret != 0) { errno = ret; perror2("pthread_join"); exit(EXIT_FAILURE); }
    if (connect_func_ret) { exit(EXIT_FAILURE); }
  }
#endif

  if (accepted_socket == -1) { perror2("accept"); return("accept"); }
  report_path_from_kernel("accept", get_sockaddr_len, get_sockaddr_ptr, len, opt_4);

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
//printf("pid=%d line=%d: before getsockname(accepted)\n", (int)getpid(), __LINE__);
  ret = getsockname(accepted_socket, (struct sockaddr *)get_sockaddr_ptr, &len);
//printf("pid=%d line=%d: after getsockname(accepted)\n", (int)getpid(), __LINE__);
  if (ret == -1) { perror2("getsockname(accepted)"); }
  else report_path_from_kernel("getsockname(accepted)", get_sockaddr_len, get_sockaddr_ptr, len, opt_4);

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
//printf("pid=%d line=%d: before getpeername(accepted)\n", (int)getpid(), __LINE__);
  ret = getpeername(accepted_socket, (struct sockaddr *)get_sockaddr_ptr, &len);
//printf("pid=%d line=%d: after getpeername(accepted)\n", (int)getpid(), __LINE__);
  if (ret == -1) { perror2("getpeername(accepted)"); }
  else report_path_from_kernel("getpeername(accepted)", get_sockaddr_len, get_sockaddr_ptr, len, opt_4);

  return NULL;
}

static void test_unix_stream(void)
{
  socklen_t len;
  int s;
  int ret;
  void *connect_func_ret;


  if (!opt_U) {
    unlink_socket(server_path_str);
    if (client_path_str)
      unlink_socket(client_path_str);
  }

  if (!opt_c)
    tmpdir = mkchtempdir(NULL);

  if (opt_s) {
    server_setup();
    return;
  }

#if defined(USE_FORK)
  parent_pid = getpid();
  serialized_flow_init(&server_serialised_flow);
  serialized_flow_init(&client_serialised_flow);
  child_pid = fork();
  if (child_pid == -1) { perror2("fork"); exit(EXIT_FAILURE); }
  if (child_pid == 0) {
    close(server_serialised_flow.pipe[1]);
    server_setup();
    serialized_flow_send(&client_serialised_flow, 1);
    if (accept_func(NULL) != NULL)
      _exit(EXIT_FAILURE);
    _exit(EXIT_SUCCESS);
  }
  close(client_serialised_flow.pipe[1]);
  client_setup();
  serialized_flow_recv(&client_serialised_flow, 1);
  connect_func_ret = connect_func(NULL);
  if (connect_func_ret) { exit(EXIT_FAILURE); }
  if (waitpid(child_pid, &ret, 0) == -1) { perror2("waitpid"); exit(EXIT_FAILURE); }
  child_pid = 0;
  if (!WIFEXITED(ret) || WEXITSTATUS(ret) != EXIT_SUCCESS) { exit(EXIT_FAILURE); }
#elif defined(USE_PTHREAD)
  server_setup();
  client_setup();
  ret = pthread_create(&connect_thread, NULL, connect_func, NULL);
  if (ret != 0) { errno = ret; perror2("pthread_create"); exit(EXIT_FAILURE); }
  accept_func(NULL);
#else
  server_setup();
  client_setup();
  connect_func_ret = connect_func(NULL);
  if (connect_func_ret) { exit(EXIT_FAILURE); }
  accept_func(NULL);
#endif
}

void atexit_func()
{
#if defined(USE_FORK)
  if (parent_pid != getpid())
    return;
#endif
  if (!opt_U) {
    if (server_path_str)
      unlink_socket(server_path_str);
    if (client_path_str)
      unlink_socket(client_path_str);
  }
  if (tmpdir)
    rmchtmpdir(tmpdir);
#if defined(USE_FORK)
  if (child_pid)
    kill(child_pid, 9);
#endif
}

int main(int argc, char *argv[])
{
  setvbuf(stdout, NULL, _IONBF, 0);
  parse_args(argc, argv);
  atexit(atexit_func);
  addr_setup();
  test_unix_stream();
  return EXIT_SUCCESS;
}
