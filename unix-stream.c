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
static int opt_s = 0;
static int opt_p = 0;
static int opt_g = 0;
static int opt_f = '\0';
static int opt_e = 0;

static char *server_path_str;
static size_t server_path_len = 0;
static char *connect_path_str;
static size_t connect_path_len = 0;
static char *client_path_str;
static size_t client_path_len = 0;

void usage(int status)
{
  fputs(
      "usage: unix-stream [options] server-path [connect-path [client-path]]\n"
      "option: -h : show this help message\n"
      "        -U : don't unlink sockets.\n"
      "        -s : server only test mode.\n"
      "        -p : prepend sizeof(sun_path)-10 characters for socket-path.\n"
      "        -g N : increase buffer size for getsockname/getpeername/accept (negative to decrease)\n"
      "        -f N : ASCII code to fill for getsockname buffer\n"
      "        -e N : number of extra bytes for getsockname buffer\n"
      , stdout);
  exit(status);
}

#define PREPEND_LENGTH (FIELD_SIZE(struct sockaddr_un, sun_path)-10)
static char *unescape_and_prepend_string(size_t *unescaped_len_ret, char *escaped_ptr, size_t escaped_len)
{
  char *unescaped_str;
  size_t unescaped_len;
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
  return unescaped_str;
}

static void parse_args(int argc, char *argv[])
{
  int opt;
  char *arg;

  while ((opt = getopt(argc, argv, "hUspg:f:e:")) != -1) {
    switch (opt) {
      case 'h':
        usage(EXIT_SUCCESS);
        break; /* not reached */

      case 'U':
        opt_U = 1;
        break;

      case 's':
        opt_s = 1;
        break;

      case 'p':
        opt_p = 1;
        break;

      case 'g':
        opt_g = atoi(optarg);
        break;

      case 'f':
        opt_f = atoi(optarg);
        break;

      case 'e':
        opt_e = atoi(optarg);
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
  server_path_str = unescape_and_prepend_string(&server_path_len, arg, strlen(arg));
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
  connect_path_str = unescape_and_prepend_string(&connect_path_len, arg, strlen(arg));
  if (connect_path_str == NULL) {
    fprintf(stderr, "connect path unescape failed\n");
    exit(EXIT_FAILURE);
  }

  if (optind == argc) {
    return;
  }

  arg = argv[optind++];
  client_path_str = unescape_and_prepend_string(&client_path_len, arg, strlen(arg));
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

static void report_path(char *key, char *path_ptr, size_t path_len)
{
  char *escaped_path;
  escaped_path = escape_string(NULL, path_ptr, path_len);
  printf("%-21s <- \"%s\" (%d bytes)\n", key, escaped_path, (int)path_len);
  free(escaped_path);
}

static void report_path_gotten(char *key, size_t buf_len, struct sockaddr_un *sockaddr_ptr, size_t sockaddr_len)
{
  int truncated;
  size_t len;
  char *escaped_path;

  if (sockaddr_len < offsetof(struct sockaddr_un, sun_path)) {
    printf("%-21s -> too short sockaddr_un (%d bytes)\n", key, (int)sockaddr_len);
    return;
  }

  if (sockaddr_len <= buf_len) {
    truncated = 0;
    len = sockaddr_len - offsetof(struct sockaddr_un, sun_path);
  }
  else {
    truncated = 1;
    len = buf_len - offsetof(struct sockaddr_un, sun_path);
  }

  escaped_path = escape_string(NULL, sockaddr_ptr->sun_path, len);
  printf("%-21s -> \"%s\"%s (%d bytes)\n",
      key, escaped_path,
      truncated ? "..." : "",
      (int)(sockaddr_len - offsetof(struct sockaddr_un, sun_path)));
  free(escaped_path);
}

static void test_unix_stream(void)
{
  struct sockaddr_un *server_sockaddr_ptr, *connect_sockaddr_ptr, *client_sockaddr_ptr, *get_sockaddr_ptr;
  socklen_t server_sockaddr_len, connect_sockaddr_len, client_sockaddr_len, get_sockaddr_len;
  socklen_t len;
  int s, c, sc;
  int ret;

  server_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + server_path_len;
  server_sockaddr_ptr = xfalloc(server_sockaddr_len, '\0');
  server_sockaddr_ptr->sun_family = AF_UNIX;
  memcpy(server_sockaddr_ptr->sun_path, server_path_str, server_path_len);

  connect_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + connect_path_len;
  connect_sockaddr_ptr = xfalloc(connect_sockaddr_len, '\0');
  connect_sockaddr_ptr->sun_family = AF_UNIX;
  memcpy(connect_sockaddr_ptr->sun_path, connect_path_str, connect_path_len);

  if (client_path_str) {
    client_sockaddr_len = offsetof(struct sockaddr_un, sun_path) + client_path_len;
    client_sockaddr_ptr = xfalloc(client_sockaddr_len, '\0');
    client_sockaddr_ptr->sun_family = AF_UNIX;
    memcpy(client_sockaddr_ptr->sun_path, client_path_str, client_path_len);
  }

  get_sockaddr_len = sizeof(struct sockaddr_un) + opt_g;
  get_sockaddr_ptr = xmalloc(get_sockaddr_len);

  if (!opt_U) {
    unlink_socket(server_path_str);
    if (client_path_str)
      unlink_socket(client_path_str);
  }

  s = socket(AF_UNIX, SOCK_STREAM, 0);
  if (s == -1) { perror2("socket(server)"); exit(EXIT_FAILURE); }

  report_path("bind(server)", server_path_str, server_path_len);
  ret = bind(s, (const struct sockaddr *)server_sockaddr_ptr, server_sockaddr_len);
  if (ret == -1) { perror2("bind(server)"); exit(EXIT_FAILURE); }

  ret = socket_file_p(server_path_str);
  printf("socket file exist?    : %s\n", ret ? "yes" : "no");

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
  ret = getsockname(s, (struct sockaddr *)get_sockaddr_ptr, &len);
  if (ret == -1) { perror2("getsockname(server)"); exit(EXIT_FAILURE); }
  report_path_gotten("getsockname(server)", get_sockaddr_len, get_sockaddr_ptr, len);

  if (opt_s) {
    if (!opt_U) {
      unlink_socket(server_path_str);
    }
    return;
  }

  ret = listen(s, SOMAXCONN);
  if (ret == -1) { perror2("listen"); exit(EXIT_FAILURE); }

  c = socket(AF_UNIX, SOCK_STREAM, 0);
  if (c == -1) { perror2("socket(client)"); exit(EXIT_FAILURE); }

  if (client_path_str) {
    report_path("bind(client)", client_path_str, client_path_len);
    ret = bind(c, (const struct sockaddr *)client_sockaddr_ptr, client_sockaddr_len);
    if (ret == -1) { perror2("bind(client)"); exit(EXIT_FAILURE); }
  }

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
  ret = getsockname(c, (struct sockaddr *)get_sockaddr_ptr, &len);
  if (ret == -1) { perror2("getsockname(client)"); exit(EXIT_FAILURE); }
  report_path_gotten("getsockname(client)", get_sockaddr_len, get_sockaddr_ptr, len);

  report_path("connect", connect_path_str, connect_path_len);
  ret = connect(c, (struct sockaddr *)connect_sockaddr_ptr, connect_sockaddr_len);
  if (ret == -1) { perror2("connect"); exit(EXIT_FAILURE); }

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
  ret = getpeername(c, (struct sockaddr *)get_sockaddr_ptr, &len);
  if (ret == -1) { perror2("getpeername(client)"); exit(EXIT_FAILURE); }
  report_path_gotten("getpeername(client)", get_sockaddr_len, get_sockaddr_ptr, len);

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
  sc = accept(s, (struct sockaddr *)get_sockaddr_ptr, &len);
  if (sc == -1) { perror2("accept"); exit(EXIT_FAILURE); }
  report_path_gotten("accept", get_sockaddr_len, get_sockaddr_ptr, len);

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
  ret = getsockname(sc, (struct sockaddr *)get_sockaddr_ptr, &len);
  if (ret == -1) { perror2("getsockname(accepted)"); exit(EXIT_FAILURE); }
  report_path_gotten("getsockname(accepted)", get_sockaddr_len, get_sockaddr_ptr, len);

  memset(get_sockaddr_ptr, opt_f, get_sockaddr_len);
  len = get_sockaddr_len;
  ret = getpeername(sc, (struct sockaddr *)get_sockaddr_ptr, &len);
  if (ret == -1) { perror2("getpeername(accepted)"); exit(EXIT_FAILURE); }
  report_path_gotten("getpeername(accepted)", get_sockaddr_len, get_sockaddr_ptr, len);

  if (!opt_U) {
    unlink_socket(server_path_str);
    if (client_path_str)
      unlink_socket(client_path_str);
  }
}

int main(int argc, char *argv[])
{
  setvbuf(stdout, NULL, _IONBF, 0);
  parse_args(argc, argv);
  test_unix_stream();
  return EXIT_SUCCESS;
}
