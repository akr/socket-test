/* errsym.c is generated from errsym.erb. */

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

int main(int argc, char *argv[])
{
#ifdef CHAR_BIT
  printf("%s: %ld (%d bytes)\n", "CHAR_BIT", (long)CHAR_BIT, (int)sizeof(CHAR_BIT));
#endif
#ifdef AF_UNSPEC
  printf("%s: %ld (%d bytes)\n", "AF_UNSPEC", (long)AF_UNSPEC, (int)sizeof(AF_UNSPEC));
#endif
#ifdef PF_UNSPEC
  printf("%s: %ld (%d bytes)\n", "PF_UNSPEC", (long)PF_UNSPEC, (int)sizeof(PF_UNSPEC));
#endif
#ifdef AF_UNIX
  printf("%s: %ld (%d bytes)\n", "AF_UNIX", (long)AF_UNIX, (int)sizeof(AF_UNIX));
#endif
#ifdef PF_UNIX
  printf("%s: %ld (%d bytes)\n", "PF_UNIX", (long)PF_UNIX, (int)sizeof(PF_UNIX));
#endif
#ifdef AF_INET
  printf("%s: %ld (%d bytes)\n", "AF_INET", (long)AF_INET, (int)sizeof(AF_INET));
#endif
#ifdef PF_INET
  printf("%s: %ld (%d bytes)\n", "PF_INET", (long)PF_INET, (int)sizeof(PF_INET));
#endif
#ifdef AF_INET6
  printf("%s: %ld (%d bytes)\n", "AF_INET6", (long)AF_INET6, (int)sizeof(AF_INET6));
#endif
#ifdef PF_INET6
  printf("%s: %ld (%d bytes)\n", "PF_INET6", (long)PF_INET6, (int)sizeof(PF_INET6));
#endif
#ifdef SOCK_STREAM
  printf("%s: %ld (%d bytes)\n", "SOCK_STREAM", (long)SOCK_STREAM, (int)sizeof(SOCK_STREAM));
#endif
#ifdef SOCK_DGRAM
  printf("%s: %ld (%d bytes)\n", "SOCK_DGRAM", (long)SOCK_DGRAM, (int)sizeof(SOCK_DGRAM));
#endif
#ifdef SOCK_SEQPACKET
  printf("%s: %ld (%d bytes)\n", "SOCK_SEQPACKET", (long)SOCK_SEQPACKET, (int)sizeof(SOCK_SEQPACKET));
#endif
#ifdef SOMAXCONN
  printf("%s: %ld (%d bytes)\n", "SOMAXCONN", (long)SOMAXCONN, (int)sizeof(SOMAXCONN));
#endif
#ifdef NAME_MAX
  printf("%s: %ld (%d bytes)\n", "NAME_MAX", (long)NAME_MAX, (int)sizeof(NAME_MAX));
#endif
#ifdef PATH_MAX
  printf("%s: %ld (%d bytes)\n", "PATH_MAX", (long)PATH_MAX, (int)sizeof(PATH_MAX));
#endif
#ifdef SYMLOOP_MAX
  printf("%s: %ld (%d bytes)\n", "SYMLOOP_MAX", (long)SYMLOOP_MAX, (int)sizeof(SYMLOOP_MAX));
#endif
#ifdef EXIT_SUCCESS
  printf("%s: %ld (%d bytes)\n", "EXIT_SUCCESS", (long)EXIT_SUCCESS, (int)sizeof(EXIT_SUCCESS));
#endif
#ifdef EXIT_FAILURE
  printf("%s: %ld (%d bytes)\n", "EXIT_FAILURE", (long)EXIT_FAILURE, (int)sizeof(EXIT_FAILURE));
#endif

  return EXIT_SUCCESS;
}

