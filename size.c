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

#define SHOW_STRUCT(struct_name) \
  printf("%s :%*s size=%d align=%d\n", \
      #struct_name, \
      (int)(28-sizeof(#struct_name)), "", \
      (int)sizeof(struct struct_name), \
      ALIGNOF(struct struct_name))
#define SHOW_FIELD(struct_name, field_name) \
  printf("%s.%s :%*s offset=%-4d size=%d\n", \
      #struct_name, #field_name, \
      (int)(30-sizeof(#struct_name)-sizeof(#field_name)), "", \
      (int)offsetof(struct struct_name, field_name), \
      (int)FIELD_SIZE(struct struct_name, field_name))

int main(int argc, char *argv[])
{
  SHOW_STRUCT(sockaddr);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD(sockaddr, sa_len);
#endif
  SHOW_FIELD(sockaddr, sa_family);
  SHOW_FIELD(sockaddr, sa_data);

  SHOW_STRUCT(sockaddr_un);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD(sockaddr_un, sun_len);
#endif
  SHOW_FIELD(sockaddr_un, sun_family);
  SHOW_FIELD(sockaddr_un, sun_path);

  SHOW_STRUCT(sockaddr_in);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD(sockaddr_in, sin_len);
#endif
  SHOW_FIELD(sockaddr_in, sin_family);
  SHOW_FIELD(sockaddr_in, sin_port);
  SHOW_FIELD(sockaddr_in, sin_addr);

  SHOW_STRUCT(sockaddr_in6);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD(sockaddr_in6, sin6_len);
#endif
  SHOW_FIELD(sockaddr_in6, sin6_family);
  SHOW_FIELD(sockaddr_in6, sin6_port);
  SHOW_FIELD(sockaddr_in6, sin6_flowinfo);
  SHOW_FIELD(sockaddr_in6, sin6_addr);
  SHOW_FIELD(sockaddr_in6, sin6_scope_id);

  SHOW_STRUCT(sockaddr_storage);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD(sockaddr_storage, ss_len);
#endif
  SHOW_FIELD(sockaddr_storage, ss_family);

  return EXIT_SUCCESS;
}
