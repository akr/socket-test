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

#define FIELD_SIZE(struct_name, field_name) sizeof(((struct_name *)0)->field_name)
static char *unix_path_str;
static size_t unix_path_len = 0;

static int opt_g = 0;
static int opt_f = '\0';
static int opt_e = 0;

void usage(int status)
{
  fputs(
      "usage: bind-getsockname unix-socket-path\n"
      "option: -h : show this help message\n"
      "        -g N : increase buffer size of getsockname (negative to decrease)\n"
      "        -f N : ASCII code to fill for getsockname buffer\n"
      "        -e N : number of extra bytes for getsockname buffer\n"
      , stdout);
  exit(status);
}

static void parse_args(int argc, char *argv[])
{
  int opt;
  char *escaped_unix_socket_path, *unescaped_unix_socket_path;
  size_t unescaped_unix_socket_path_len;

  while ((opt = getopt(argc, argv, "hg:f:e:")) != -1) {
    switch (opt) {
      case 'h':
        usage(EXIT_SUCCESS);
        break; /* not reached */

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
  escaped_unix_socket_path = argv[optind];
  unescaped_unix_socket_path = unescape_string(&unescaped_unix_socket_path_len, escaped_unix_socket_path, strlen(escaped_unix_socket_path));

  unix_path_str = unescaped_unix_socket_path;
  unix_path_len = unescaped_unix_socket_path_len;
}

static void unlink_socket(char *path)
{
  int ret;
  struct stat statbuf;

  if (path[0] == '\0')
    return;

  ret = stat(path, &statbuf);
  if (ret == -1)
    return;

  if (S_ISSOCK(statbuf.st_mode))
    unlink(path);
}

static void test_bind_getsockname(void)
{
  int s, ret;
  struct sockaddr_un *a1;
  struct sockaddr_un *a2;
  socklen_t alen1, alen2;
  socklen_t alen;
  size_t len;
  char *escaped_unix_socket_path;
  int truncated;

  printf("sizeof(sun_path) = %d\n", (int)FIELD_SIZE(struct sockaddr_un, sun_path));

  alen1 = offsetof(struct sockaddr_un, sun_path) + unix_path_len;
  a1 = malloc(alen1);
  if (a1 == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  memset((void *)a1, '\0', alen1);

  alen2 = sizeof(struct sockaddr_un) + opt_g;
  a2 = malloc(alen2 + opt_e);
  if (a1 == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  memset((void *)a2, opt_f, alen2 + opt_e);

  unlink_socket(unix_path_str);

  s = socket(AF_UNIX, SOCK_STREAM, 0);
  if (s == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  a1->sun_family = AF_UNIX;
  memcpy(a1->sun_path, unix_path_str, unix_path_len);

  escaped_unix_socket_path = escape_string(NULL, unix_path_str, unix_path_len);
  printf("bind        : \"%s\" (%d bytes)\n", escaped_unix_socket_path, (int)unix_path_len);
  free(escaped_unix_socket_path);

  ret = bind(s, (const struct sockaddr *)a1, alen1);
  if (ret == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  alen = alen2;
  ret = getsockname(s, (struct sockaddr *)a2, &alen);
  if (ret == -1) {
    perror("getsockname");
    exit(EXIT_FAILURE);
  }

  truncated = 0;
  if (alen <= alen2) {
    truncated = 0;
    len = alen - offsetof(struct sockaddr_un, sun_path);
  }
  else {
    truncated = 1;
    len = alen2 - offsetof(struct sockaddr_un, sun_path);
  }

  escaped_unix_socket_path = escape_string(NULL, a2->sun_path, len);
  printf("getsockname : \"%s\"%s (%d bytes)\n", escaped_unix_socket_path, truncated ? "..." : "", (int)(alen - offsetof(struct sockaddr_un, sun_path)));
  free(escaped_unix_socket_path);

  unlink_socket(unix_path_str);
}

int main(int argc, char *argv[])
{
  parse_args(argc, argv);
  test_bind_getsockname();
  return EXIT_SUCCESS;
}
