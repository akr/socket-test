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
  printf("sizeof(struct sockaddr_un) = %d\n", sizeof(struct sockaddr_un));
  printf("sizeof(struct sockaddr_un.sun_family) = %d\n", FIELD_SIZE(struct sockaddr_un, sun_family));
  printf("sizeof(struct sockaddr_un.sun_path) = %d\n", FIELD_SIZE(struct sockaddr_un, sun_path));
  printf("offsetof(struct sockaddr_un.sun_family) = %d\n", offsetof(struct sockaddr_un, sun_family));
  printf("offsetof(struct sockaddr_un.sun_path) = %d\n", offsetof(struct sockaddr_un, sun_path));

  printf("sizeof(struct sockaddr_storage) = %d\n", sizeof(struct sockaddr_storage));
  printf("sizeof(struct sockaddr_storage.ss_family) = %d\n", FIELD_SIZE(struct sockaddr_storage, ss_family));
  printf("offsetof(struct sockaddr_storage.sun_family) = %d\n", offsetof(struct sockaddr_storage, ss_family));

  return EXIT_SUCCESS;
}
