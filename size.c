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
  printf("sizeof(sockaddr)=%d\n", (int)sizeof(struct sockaddr_storage));
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  printf("  offsetof(sa_len)=%d         sizeof(sa_len)=%d\n",
      (int)offsetof(struct sockaddr, sa_len),
      (int)FIELD_SIZE(struct sockaddr, sa_len));
#endif
  printf("  offsetof(sa_family)=%d      sizeof(sa_family)=%d\n",
      (int)offsetof(struct sockaddr, sa_family),
      (int)FIELD_SIZE(struct sockaddr, sa_family));
  printf("  offsetof(sa_data)=%d        sizeof(sa_data)=%d\n",
      (int)offsetof(struct sockaddr, sa_data),
      (int)FIELD_SIZE(struct sockaddr, sa_data));

  printf("sizeof(sockaddr_un)=%d\n", (int)sizeof(struct sockaddr_un));
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  printf("  offsetof(sun_len)=%d        sizeof(sun_len)=%d\n",
      (int)offsetof(struct sockaddr_un, sun_len),
      (int)FIELD_SIZE(struct sockaddr_un, sun_len));
#endif
  printf("  offsetof(sun_family)=%d     sizeof(sun_family)=%d\n",
      (int)offsetof(struct sockaddr_un, sun_family),
      (int)FIELD_SIZE(struct sockaddr_un, sun_family));
  printf("  offsetof(sun_path)=%d       sizeof(sun_path)=%d\n",
      (int)offsetof(struct sockaddr_un, sun_path),
      (int)FIELD_SIZE(struct sockaddr_un, sun_path));

  printf("sizeof(sockaddr_storage)=%d\n", (int)sizeof(struct sockaddr_storage));
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  printf("  offsetof(ss_len)=%d         sizeof(ss_len)=%d\n",
      (int)offsetof(struct sockaddr_storage, ss_len),
      (int)FIELD_SIZE(struct sockaddr_storage, ss_len));
#endif
  printf("  offsetof(ss_family)=%d      sizeof(ss_family)=%d\n",
      (int)offsetof(struct sockaddr_storage, ss_family),
      (int)FIELD_SIZE(struct sockaddr_storage, ss_family));

  return EXIT_SUCCESS;
}
