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

static int opt_U = 0;
static int opt_T = 0;
static int opt_c = 0;
static int opt_m = 0;
static int opt_4 = 0;

static int opt_s = 0;
static int opt_p = 0;
static socklen_t opt_g = sizeof(struct sockaddr_un);

static char *tmpdir = NULL;

static char *server_path_str;
static size_t server_path_len = 0;
static int server_path_sun_len = 0; /* 4.4BSD sun_len field in sockaddr_un */

static char *sendto_path_str;
static size_t sendto_path_len = 0;
static int sendto_path_sun_len = 0; /* 4.4BSD sun_len field in sockaddr_un */

static char *client_path_str;
static size_t client_path_len = 0;
static int client_path_sun_len = 0; /* 4.4BSD sun_len field in sockaddr_un */

void usage(int status)
{
  fputs(
      "usage: unix-dgram [options] server-path [sendto-path [client-path]]\n"
      "option: -h : show this help message\n"
      "        -U : don't unlink sockets.\n"
      "        -T : don't chdir into a temporally directory.\n"
      "        -c : use connect&send instead of sendto.\n"
      "        -m : use recvmsg instead of recvfrom.\n"
      "        -4 : show 4.4BSD sun_len field\n"

      "        -s : server only test mode.\n"
      "        -p : prepend sizeof(sun_path)-10 characters for socket-path.\n"
      "        -g N : buffer size for getsockname/getpeername/accept (no sign means exact.  +N for increase and -N for decrease from sockaddr_un)\n"
      , stdout);
  exit(status);
}

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
    char *p;
    unescaped_str = xrealloc(unescaped_str, PREPEND_LENGTH+unescaped_len+1);
    memmove(unescaped_str+PREPEND_LENGTH, unescaped_str, unescaped_len+1);
    p = unescaped_str;
    while (p+1 < unescaped_str+PREPEND_LENGTH) {
      *p++ = '.';
      *p++ = '/';
    }
    if (p < unescaped_str+PREPEND_LENGTH) 
      *p = 'Z';
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

  while ((opt = getopt(argc, argv, "hUTcmspg:4")) != -1) {
    switch (opt) {
      case 'h':
        usage(EXIT_SUCCESS);
        break; /* not reached */

      case 'U':
        opt_U = 1;
        break;

      case 'T':
        opt_T = 1;
        break;

      case 'c':
        opt_c = 1;
        break;

      case 'm':
        opt_m = 1;
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

      case '4':
        opt_4 = 1;
        break;

      default:
        fprintf(stderr, "unexpected option: %c\n", opt);
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
    sendto_path_str = server_path_str;
    sendto_path_len = server_path_len;
    return;
  }

  arg = argv[optind++];
  sendto_path_str = unescape_and_prepend_string(
      &sendto_path_len, &sendto_path_sun_len, arg, strlen(arg));
  if (sendto_path_str == NULL) {
    fprintf(stderr, "sendto path unescape failed\n");
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

  if (optind == argc) {
    return;
  }

  fprintf(stderr, "too many arguments\n");
  exit(EXIT_FAILURE);
}

static void test_unix_dgram(void)
{
  struct sockaddr_un *server_sockaddr_ptr;
  socklen_t server_sockaddr_len;

  struct sockaddr_un *client_sockaddr_ptr;
  socklen_t client_sockaddr_len;

  struct sockaddr_un *sendto_sockaddr_ptr;
  socklen_t sendto_sockaddr_len;

  socklen_t get_sockaddr_len;

  struct sockaddr *client_sockaddr_ptr_in_server;
  socklen_t client_sockaddr_len_in_server;

  int s, c;
  int ret;
  ssize_t ss;

  sockaddr_put_t *sockaddr_put;
  sockaddr_get_t *sockaddr_get;

  char buf[4096];

  server_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + server_path_len;
  server_sockaddr_ptr = xfalloc(server_sockaddr_len, '\0');
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  server_sockaddr_ptr->sun_len = server_path_sun_len;
#endif
  server_sockaddr_ptr->sun_family = AF_UNIX;
  memcpy(server_sockaddr_ptr->sun_path, server_path_str, server_path_len);

  sendto_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + sendto_path_len;
  sendto_sockaddr_ptr = xfalloc(sendto_sockaddr_len, '\0');
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  server_sockaddr_ptr->sun_len = sendto_path_sun_len;
#endif
  sendto_sockaddr_ptr->sun_family = AF_UNIX;
  memcpy(sendto_sockaddr_ptr->sun_path, sendto_path_str, sendto_path_len);

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

  if (!opt_U) {
    unlink_socket(server_path_str);
    if (client_path_str)
      unlink_socket(client_path_str);
  }

  if (!opt_T)
    tmpdir = mkchtempdir(NULL);

  s = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (s == -1) { perrsym("socket(server)"); exit(EXIT_FAILURE); }

  sockaddr_put = before_sockaddr_put("bind(server)", (struct sockaddr *)server_sockaddr_ptr, server_sockaddr_len, opt_4);
  ret = bind(s, sockaddr_put->addr, sockaddr_put->len);
  after_sockaddr_put(sockaddr_put, ret != -1, 1);

  ret = socket_file_p(server_path_str);
  printf("socket file (server)  : %s\n", ret ? "exist" : "not exist");

  sockaddr_get = before_sockaddr_get("getsockname(server)", get_sockaddr_len, opt_4);
  ret = getsockname(s, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 0);

  if (opt_s) {
    return;
  }

  c = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (c == -1) { perrsym("socket(client)"); exit(EXIT_FAILURE); }

  if (client_path_str) {
    sockaddr_put = before_sockaddr_put("bind(client)", (struct sockaddr *)client_sockaddr_ptr, client_sockaddr_len, opt_4);
    ret = bind(c, sockaddr_put->addr, sockaddr_put->len);
    after_sockaddr_put(sockaddr_put, ret != -1, 1);

    ret = socket_file_p(client_path_str);
    printf("socket file (client)  : %s\n", ret ? "exist" : "not exist");
  }

  sockaddr_get = before_sockaddr_get("getsockname(client)", get_sockaddr_len, opt_4);
  ret = getsockname(c, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 0);

  if (opt_c) {
    sockaddr_put = before_sockaddr_put("connect", (struct sockaddr *)sendto_sockaddr_ptr, sendto_sockaddr_len, opt_4);
    ret = connect(c, sockaddr_put->addr, sockaddr_put->len);
    after_sockaddr_put(sockaddr_put, ret != -1, 1);

    sockaddr_get = before_sockaddr_get("getpeername(client)", get_sockaddr_len, opt_4);
    ret = getpeername(c, sockaddr_get->addr, &sockaddr_get->len);
    after_sockaddr_get(sockaddr_get, ret != -1, 0);

#define REQUEST_STR "request"
#define REQUEST_LEN 7
    ss = send(c, REQUEST_STR, REQUEST_LEN, 0);
    if (ss == -1) { perrsym("send(client)"); exit(EXIT_FAILURE); }
    if (ss != REQUEST_LEN) {
      fprintf(stderr,
          "send(client): try to send %ld bytes but only %ld bytes sent.\n",
          (long) REQUEST_LEN, (long)ss);
    }
  }
  else {
    sockaddr_put = before_sockaddr_put("sendto(client)", (struct sockaddr *)sendto_sockaddr_ptr, sendto_sockaddr_len, opt_4);
    ss = sendto(c, REQUEST_STR, REQUEST_LEN, 0, sockaddr_put->addr, sockaddr_put->len);
    after_sockaddr_put(sockaddr_put, ss != -1, 1);
    if (ss != REQUEST_LEN) {
      fprintf(stderr,
          "sendto(client): try to send %ld bytes but only %ld bytes sent.\n",
          (long)REQUEST_LEN, (long)ss);
    }
  }

  if (opt_m) {
    struct msghdr mhdr;
    struct iovec iov;
    sockaddr_get = before_sockaddr_get("recvmsg(server)", get_sockaddr_len, opt_4);
    iov.iov_base = buf;
    iov.iov_len = sizeof(buf);
    mhdr.msg_name = sockaddr_get->addr;
    mhdr.msg_namelen = sockaddr_get->len;
    mhdr.msg_iov = &iov;
    mhdr.msg_iovlen = 1;
    mhdr.msg_control = NULL;
    mhdr.msg_controllen = 0;
    mhdr.msg_flags = 0;
    ss = recvmsg(s, &mhdr, 0);
    sockaddr_get->len = mhdr.msg_namelen;
    after_sockaddr_get_report(sockaddr_get, ss != -1, 1);
    if (ss != REQUEST_LEN) { fprintf(stderr, "recvmsg(server): %ld bytes expected but %ld bytes received.\n", (long)REQUEST_LEN, (long)ss); }
    if (memcmp(buf, REQUEST_STR, REQUEST_LEN) != 0) { fprintf(stderr, "recvmsg(server): unexpected return message\n"); }
    if (mhdr.msg_flags != 0) { fprintf(stderr, "recvmsg(server): unexpected return flags %lx\n", (unsigned long)mhdr.msg_flags); }
  }
  else {
    sockaddr_get = before_sockaddr_get("recvfrom(server)", get_sockaddr_len, opt_4);
    ss = recvfrom(s, buf, sizeof(buf), 0, sockaddr_get->addr, &sockaddr_get->len);
    after_sockaddr_get_report(sockaddr_get, ss != -1, 1);
    if (ss != REQUEST_LEN) { fprintf(stderr, "recvfrom(server): %ld bytes expected but %ld bytes received.\n", (long)REQUEST_LEN, (long)ss); }
    if (memcmp(buf, REQUEST_STR, REQUEST_LEN) != 0) { fprintf(stderr, "recvfrom(server): unexpected return message\n"); }
  }

  /* keep the address obtained by recvfrom/recvmsg to reply. */
  client_sockaddr_ptr_in_server = sockaddr_get->addr;
  if (sockaddr_get->len <= sockaddr_get->buflen) {
    client_sockaddr_len_in_server = sockaddr_get->len;
  }
  else {
    /* ignore truncated part */
    client_sockaddr_len_in_server = sockaddr_get->buflen;
    printf("address truncation    : %ld bytes\n", (long)sockaddr_get->len-sockaddr_get->buflen);
  }
  sockaddr_get->addr = NULL;
  after_sockaddr_get_finish(sockaddr_get);

#define REPLY_STR "reply"
#define REPLY_LEN 5
  sockaddr_put = before_sockaddr_put("sendto(server)", client_sockaddr_ptr_in_server, client_sockaddr_len_in_server, opt_4);
  ss = sendto(s, REPLY_STR, REPLY_LEN, 0, sockaddr_put->addr, sockaddr_put->len);
  after_sockaddr_put(sockaddr_put, ss != -1, 1);
  if (ss != REPLY_LEN) { fprintf(stderr, "sendto(server): try to send %ld bytes but only %ld bytes sent.\n", (long)REPLY_LEN, (long)ss); }

  if (opt_m) {
    struct msghdr mhdr;
    struct iovec iov;
    sockaddr_get = before_sockaddr_get("recvmsg(client)", get_sockaddr_len, opt_4);
    iov.iov_base = buf;
    iov.iov_len = sizeof(buf);
    mhdr.msg_name = sockaddr_get->addr;
    mhdr.msg_namelen = sockaddr_get->len;
    mhdr.msg_iov = &iov;
    mhdr.msg_iovlen = 1;
    mhdr.msg_control = NULL;
    mhdr.msg_controllen = 0;
    mhdr.msg_flags = 0;
    ss = recvmsg(c, &mhdr, 0);
    sockaddr_get->len = mhdr.msg_namelen;
    after_sockaddr_get(sockaddr_get, ss != -1, 1);
    if (ss != REPLY_LEN) { fprintf(stderr, "recvmsg(client): %ld bytes expected but %ld bytes received.\n", (long)REPLY_LEN, (long)ss); }
    if (memcmp(buf, REPLY_STR, REPLY_LEN) != 0) { fprintf(stderr, "recvmsg(client): unexpected return message\n"); }
    if (mhdr.msg_flags != 0) { fprintf(stderr, "recvmsg(client): unexpected return flags %lx\n", (unsigned long)mhdr.msg_flags); }
  }
  else {
    sockaddr_get = before_sockaddr_get("recvfrom(client)", get_sockaddr_len, opt_4);
    ss = recvfrom(c, buf, sizeof(buf), 0, sockaddr_get->addr, &sockaddr_get->len);
    after_sockaddr_get(sockaddr_get, ss != -1, 1);
    if (ss != REPLY_LEN) { fprintf(stderr, "recvfrom(client): %ld bytes expected but %ld bytes received.\n", (long)REPLY_LEN, (long)ss); }
    if (memcmp(buf, REPLY_STR, REPLY_LEN) != 0) { fprintf(stderr, "recvfrom(client): unexpected return message\n"); }
  }
}

void atexit_func()
{
  if (!opt_U) {
    if (server_path_str)
      unlink_socket(server_path_str);
    if (client_path_str)
      unlink_socket(client_path_str);
  }
  if (tmpdir)
    rmchtmpdir(tmpdir);
}

int main(int argc, char *argv[])
{
  setvbuf(stdout, NULL, _IONBF, 0);
  parse_args(argc, argv);
  atexit(atexit_func);
  test_unix_dgram();
  return EXIT_SUCCESS;
}
