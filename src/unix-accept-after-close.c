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

#ifndef SOMAXCONN
#  define SOMAXCONN 128
#endif

static int opt_4 = 0;

static char *tmpdir = NULL;

void atexit_func()
{
  if (tmpdir)
    rmchtmpdir(tmpdir);
}

int main(int argc, char *argv[])
{
  int serv, clnt, acpt;
  struct sockaddr_un serv_addr;
  struct sockaddr_un acpt_addr;
  int ret;
  sockaddr_get_t *sockaddr_get;

  (void)argc;
  (void)argv;

  /* alarm() avoids hang on Minix and Cygwin. */
  alarm(2);

  atexit(atexit_func);

  tmpdir = mkchtempdir(NULL);

  serv = socket(AF_UNIX, SOCK_STREAM, 0);
  if (serv == -1) { perror("socket"); exit(EXIT_FAILURE); }

  memset(&serv_addr, '\0', sizeof(serv_addr));
  serv_addr.sun_family = AF_UNIX;
  strcpy(serv_addr.sun_path, "socket-file");

  ret = bind(serv, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (ret == -1) { perror("bind"); exit(EXIT_FAILURE); }

  ret = listen(serv, SOMAXCONN);
  if (ret == -1) { perror("listen"); exit(EXIT_FAILURE); }

  clnt = socket(AF_UNIX, SOCK_STREAM, 0);
  if (clnt == -1) { perror("socket"); exit(EXIT_FAILURE); }

  ret = connect(clnt, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (ret == -1) { perror("connect"); exit(EXIT_FAILURE); }

  ret = close(clnt);
  if (ret == -1) { perror("close"); exit(EXIT_FAILURE); }

  sockaddr_get = before_sockaddr_get("accept", sizeof(acpt_addr), opt_4);
  acpt = accept(serv, sockaddr_get->addr, &sockaddr_get->len);
  after_sockaddr_get(sockaddr_get, ret != -1, 1);

  return EXIT_SUCCESS;
}
