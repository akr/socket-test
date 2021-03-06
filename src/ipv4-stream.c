/*
 * Copyright (C) 2013 Tanaka Akira  <akr@fsij.org>
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *  3. The name of the author may not be used to endorse or promote
 *     products derived from this software without specific prior
 *     written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sockettest.h"

#ifndef SOMAXCONN
#  define SOMAXCONN 128
#endif

static int opt_4 = 0;

static struct sockaddr_in *server_addr_ptr, *connect_addr_ptr, *client_addr_ptr;
static socklen_t server_addr_len, connect_addr_len, client_addr_len;
static socklen_t get_sockaddr_len = (socklen_t)sizeof(struct sockaddr_in);

static int connect_addr_ip_given, connect_addr_port_given;

void usage(int status)
{
  fputs(
      "usage: ipv4-stream [options] [server-ip:port [connect-ip:port [client-ip:port]]]\n"
      "option: -h : show this help message\n"
      "        -4 : show 4.4BSD sa_len field\n"
      , stdout);
  exit(status);
}

void parse_as_sockaddr_in(char *arg, struct sockaddr_in **addrp, socklen_t *lenp, int *ip_given, int *port_given)
{
  char *ip_str, *colonp, *port_str;
  in_addr_t ip = 0;
  in_port_t port = 0;
  struct sockaddr_in *a;

  colonp = strchr(arg, ':');
  if (colonp) {
    *colonp = '\0';
    ip_str = arg;
    port_str = colonp+1;
    if (ip_given) *ip_given = 1;
    if (port_given) *port_given = 1;
  }
  else {
    if (strchr(arg, '.')) {
      ip_str = arg;
      port_str = NULL;
      if (ip_given) *ip_given = 1;
      if (port_given) *port_given = 0;
    }
    else {
      ip_str = NULL;
      port_str = arg;
      if (ip_given) *ip_given = 0;
      if (port_given) *port_given = 1;
    }
  }

  if (ip_str) {
    ip = inet_addr(ip_str);
    if (ip == (in_addr_t)(-1)) {
      fprintf(stderr, "inet_addr failure: %s\n", ip_str);
      exit(EXIT_FAILURE);
    }
  }

  if (port_str)
    port = htons(atoi(port_str));

  a = (struct sockaddr_in *)xmalloc(sizeof(struct sockaddr_in));
  memset(a, '\0', sizeof(struct sockaddr_in));
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  a->sin_len = sizeof(struct sockaddr_in);
#endif
  a->sin_family = AF_INET;
  a->sin_port = port;
  a->sin_addr.s_addr = ip;

  *addrp = a;
  *lenp = sizeof(struct sockaddr_in);
}

static void parse_args(int argc, char *argv[])
{
  int opt;
  char *arg;

  while ((opt = getopt(argc, argv, "h4")) != -1) {
    switch (opt) {
      case 'h':
        usage(EXIT_SUCCESS);
        break; /* not reached */

      case '4':
        opt_4 = 1;
        break;

      default:
        exit(EXIT_FAILURE);
    }
  }
  if (argc <= optind)
    return;

  arg = argv[optind++];
  parse_as_sockaddr_in(arg, &server_addr_ptr, &server_addr_len, NULL, NULL);

  if (argc <= optind)
    return;

  arg = argv[optind++];
  parse_as_sockaddr_in(arg, &connect_addr_ptr, &connect_addr_len, &connect_addr_ip_given, &connect_addr_port_given);

  if (argc <= optind)
    return;

  arg = argv[optind++];
  parse_as_sockaddr_in(arg, &client_addr_ptr, &client_addr_len, NULL, NULL);

  if (optind != argc) {
    fprintf(stderr, "too many arguments\n");
    exit(EXIT_FAILURE);
  }

  return;
}

void setup_server_addr(void)
{
  if (!server_addr_ptr) {
    server_addr_len = sizeof(struct sockaddr_in);
    server_addr_ptr = (struct sockaddr_in *)xmalloc(server_addr_len);
    memset(server_addr_ptr, '\0', server_addr_len);
    server_addr_ptr->sin_family = AF_INET;
    server_addr_ptr->sin_addr.s_addr = htonl(0);
    server_addr_ptr->sin_port = htons(0);
  }
}

void setup_connect_addr(struct sockaddr *actual_server_address, socklen_t len)
{
  if (!connect_addr_ptr) {
    connect_addr_len = len;
    connect_addr_ptr = xmalloc(connect_addr_len);
    memcpy(connect_addr_ptr, actual_server_address, connect_addr_len);
  }

  if (!connect_addr_ip_given) {
    connect_addr_ptr->sin_addr = ((struct sockaddr_in *)actual_server_address)->sin_addr;
    if (connect_addr_ptr->sin_family == AF_INET &&
        connect_addr_ptr->sin_addr.s_addr == htonl(0)) {
      connect_addr_ptr->sin_addr.s_addr = htonl(0x7f000001);
    }
  }
  if (!connect_addr_port_given)
    connect_addr_ptr->sin_port = ((struct sockaddr_in *)actual_server_address)->sin_port;
}


static void test_ipv4_stream(void)
{
  int serv, s, c;
  int ret;
  sockaddr_put_t *sockaddr_put;
  sockaddr_get_t *sockaddr_get;

  serv = socket(AF_INET, SOCK_STREAM, 0);
  if (serv == -1) { perrsym("socket(server)"); exit(EXIT_FAILURE); }

  sockaddr_get = before_sockaddr_get("getsockname(server)(1)", get_sockaddr_len, opt_4);
  ret = getsockname(serv, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 0);

  sockaddr_put = before_sockaddr_put("bind(server)", (struct sockaddr *)server_addr_ptr, server_addr_len, opt_4);
  ret = bind(serv, sockaddr_put->addr, sockaddr_put->len);
  after_sockaddr_put(sockaddr_put, ret != -1, 1);

  sockaddr_get = before_sockaddr_get("getsockname(server)(2)", get_sockaddr_len, opt_4);
  ret = getsockname(serv, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get_report(sockaddr_get, ret != -1, 0);

  setup_connect_addr(sockaddr_get->addr, sockaddr_get->len);
  if (connect_addr_ptr->sin_port == 0)
    connect_addr_ptr->sin_port = ((struct sockaddr_in *)(sockaddr_get->addr))->sin_port;

  after_sockaddr_get_finish(sockaddr_get);

  ret = listen(serv, SOMAXCONN);
  if (ret == -1) { perrsym("listen"); exit(EXIT_FAILURE); }

  c = socket(AF_INET, SOCK_STREAM, 0);
  if (c == -1) { perrsym("socket(client)"); exit(EXIT_FAILURE); }

  if (client_addr_ptr) {
    sockaddr_get = before_sockaddr_get("getsockname(client)(0)", get_sockaddr_len, opt_4);
    ret = getsockname(c, sockaddr_get->addr, &sockaddr_get->len);
    after_sockaddr_get(sockaddr_get, ret != -1, 0);

    sockaddr_put = before_sockaddr_put("bind(client)", (struct sockaddr *)client_addr_ptr, client_addr_len, opt_4);
    ret = bind(c, sockaddr_put->addr, sockaddr_put->len);
    after_sockaddr_put(sockaddr_put, ret != -1, 1);
  }

  sockaddr_get = before_sockaddr_get("getsockname(client)(1)", get_sockaddr_len, opt_4);
  ret = getsockname(c, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 0);

  sockaddr_put = before_sockaddr_put("connect", (struct sockaddr *)connect_addr_ptr, connect_addr_len, opt_4);
  ret = connect(c, sockaddr_put->addr, sockaddr_put->len);
  after_sockaddr_put(sockaddr_put, ret != -1, 1);

  sockaddr_get = before_sockaddr_get("getsockname(client)(2)", get_sockaddr_len, opt_4);
  ret = getsockname(c, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 0);

  sockaddr_get = before_sockaddr_get("accept", get_sockaddr_len, opt_4);
  s = accept(serv, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, s != -1, 1);

  sockaddr_get = before_sockaddr_get("getsockname(accepted)", get_sockaddr_len, opt_4);
  ret = getsockname(s, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 0);

  sockaddr_get = before_sockaddr_get("getpeername(accepted)", get_sockaddr_len, opt_4);
  ret = getpeername(s, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 0);

  close(c);
  close(s);
  close(serv);
}

int main(int argc, char *argv[])
{
  setvbuf(stdout, NULL, _IONBF, 0);
  parse_args(argc, argv);
  setup_server_addr();
  test_ipv4_stream();
  return EXIT_SUCCESS;
}
