/* size.c is generated from size.erb. */

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

#define SHOW_BYTEORDER(type_name, type_name_str) \
  do { \
    union { \
      type_name integer; \
      unsigned char bytes[sizeof(type_name)]; \
    } u; \
    int i; \
    u.integer = 0; \
    for (i = 0; i < (int)sizeof(type_name); i++) { \
      u.integer |= ((type_name)('1' + i)) << (i * CHAR_BIT); \
    } \
    printf("%s.byteorder =%*s", type_name_str, (int)(32-sizeof(type_name_str)), ""); \
    for (i = 0; i < (int)sizeof(type_name); i++) { \
      putc(u.bytes[i], stdout); \
    } \
    putc('\n', stdout); \
  } while (0)

#define SHOW_INTEGER_TYPE(type_name) \
  do { \
    printf("%s.size =%*s %d\n", \
        #type_name, \
        (int)(36-sizeof(#type_name)), "", \
        (int)sizeof(type_name)); \
    printf("%s.align =%*s %d\n", \
        #type_name, \
        (int)(35-sizeof(#type_name)), "", \
        ALIGNOF(type_name)); \
    printf("%s.sign =%*s %s\n", \
        #type_name, \
        (int)(36-sizeof(#type_name)), "", \
        0 < ((type_name)-1) ? "unsigned" : "signed"); \
    SHOW_BYTEORDER(type_name, #type_name); \
  } while (0)

#define SHOW_FLOAT_TYPE(type_name) \
  do { \
    printf("%s.size =%*s %d\n", \
        #type_name, \
        (int)(36-sizeof(#type_name)), "", \
        (int)sizeof(type_name)); \
    printf("%s.align =%*s %d\n", \
        #type_name, \
        (int)(35-sizeof(#type_name)), "", \
        ALIGNOF(type_name)); \
  } while (0)

#define SHOW_POINTER_TYPE(type_name) \
  do { \
    printf("%s.size =%*s %d\n", \
        #type_name, \
        (int)(36-sizeof(#type_name)), "", \
        (int)sizeof(type_name)); \
    printf("%s.align =%*s %d\n", \
        #type_name, \
        (int)(35-sizeof(#type_name)), "", \
        ALIGNOF(type_name)); \
  } while (0)


#define SHOW_STRUCT_SIZE(struct_name) \
  do { \
    printf("%s.size =%*s %d\n", \
        #struct_name, \
        (int)(36-sizeof(#struct_name)), "", \
        (int)sizeof(struct struct_name)); \
  } while (0)
#define SHOW_FIELD_SIZE(struct_name, field_name) \
  do { \
    printf("%s.%s.size =%*s %d\n", \
        #struct_name, #field_name, \
        (int)(36-sizeof(#struct_name)-sizeof(#field_name)), "", \
        (int)FIELD_SIZE(struct struct_name, field_name)); \
  } while (0)

#define SHOW_STRUCT_ALIGNMENT(struct_name) \
  do { \
    printf("%s.align =%*s %d\n", \
        #struct_name, \
        (int)(35-sizeof(#struct_name)), "", \
        ALIGNOF(struct struct_name)); \
  } while (0)
#define SHOW_FIELD_OFFSET(struct_name, field_name) \
  do { \
    printf("%s.%s.offset =%*s %d\n", \
        #struct_name, #field_name, \
        (int)(34-sizeof(#struct_name)-sizeof(#field_name)), "", \
        (int)offsetof(struct struct_name, field_name)); \
  } while (0)

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  SHOW_STRUCT_SIZE(sockaddr);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_SIZE(sockaddr, sa_len);
#endif

  SHOW_FIELD_SIZE(sockaddr, sa_family);


  SHOW_FIELD_SIZE(sockaddr, sa_data);

  SHOW_STRUCT_SIZE(sockaddr_un);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_SIZE(sockaddr_un, sun_len);
#endif

  SHOW_FIELD_SIZE(sockaddr_un, sun_family);


  SHOW_FIELD_SIZE(sockaddr_un, sun_path);

  SHOW_STRUCT_SIZE(sockaddr_in);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_SIZE(sockaddr_in, sin_len);
#endif

  SHOW_FIELD_SIZE(sockaddr_in, sin_family);


  SHOW_FIELD_SIZE(sockaddr_in, sin_port);


  SHOW_FIELD_SIZE(sockaddr_in, sin_addr);

  SHOW_STRUCT_SIZE(sockaddr_in6);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_SIZE(sockaddr_in6, sin6_len);
#endif

  SHOW_FIELD_SIZE(sockaddr_in6, sin6_family);


  SHOW_FIELD_SIZE(sockaddr_in6, sin6_port);


  SHOW_FIELD_SIZE(sockaddr_in6, sin6_flowinfo);


  SHOW_FIELD_SIZE(sockaddr_in6, sin6_addr);


  SHOW_FIELD_SIZE(sockaddr_in6, sin6_scope_id);

  SHOW_STRUCT_SIZE(sockaddr_storage);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_SIZE(sockaddr_storage, ss_len);
#endif

  SHOW_FIELD_SIZE(sockaddr_storage, ss_family);

  SHOW_STRUCT_SIZE(in_addr);

  SHOW_FIELD_SIZE(in_addr, s_addr);


  SHOW_STRUCT_ALIGNMENT(sockaddr);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_OFFSET(sockaddr, sa_len);
#endif

  SHOW_FIELD_OFFSET(sockaddr, sa_family);


  SHOW_FIELD_OFFSET(sockaddr, sa_data);

  SHOW_STRUCT_ALIGNMENT(sockaddr_un);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_OFFSET(sockaddr_un, sun_len);
#endif

  SHOW_FIELD_OFFSET(sockaddr_un, sun_family);


  SHOW_FIELD_OFFSET(sockaddr_un, sun_path);

  SHOW_STRUCT_ALIGNMENT(sockaddr_in);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_OFFSET(sockaddr_in, sin_len);
#endif

  SHOW_FIELD_OFFSET(sockaddr_in, sin_family);


  SHOW_FIELD_OFFSET(sockaddr_in, sin_port);


  SHOW_FIELD_OFFSET(sockaddr_in, sin_addr);

  SHOW_STRUCT_ALIGNMENT(sockaddr_in6);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_OFFSET(sockaddr_in6, sin6_len);
#endif

  SHOW_FIELD_OFFSET(sockaddr_in6, sin6_family);


  SHOW_FIELD_OFFSET(sockaddr_in6, sin6_port);


  SHOW_FIELD_OFFSET(sockaddr_in6, sin6_flowinfo);


  SHOW_FIELD_OFFSET(sockaddr_in6, sin6_addr);


  SHOW_FIELD_OFFSET(sockaddr_in6, sin6_scope_id);

  SHOW_STRUCT_ALIGNMENT(sockaddr_storage);
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  SHOW_FIELD_OFFSET(sockaddr_storage, ss_len);
#endif

  SHOW_FIELD_OFFSET(sockaddr_storage, ss_family);

  SHOW_STRUCT_ALIGNMENT(in_addr);

  SHOW_FIELD_OFFSET(in_addr, s_addr);



  SHOW_INTEGER_TYPE(char);
  SHOW_INTEGER_TYPE(short);
  SHOW_INTEGER_TYPE(int);
  SHOW_INTEGER_TYPE(long);
  SHOW_INTEGER_TYPE(long long);
  SHOW_INTEGER_TYPE(intmax_t);
  SHOW_INTEGER_TYPE(socklen_t);
#ifdef HAVE_SA_FAMILY_T
  SHOW_INTEGER_TYPE(sa_family_t);
#endif
#ifdef HAVE_IN_PORT_T
  SHOW_INTEGER_TYPE(in_port_t);
#endif
#ifdef HAVE_IN_ADDR_T
  SHOW_INTEGER_TYPE(in_addr_t);
#endif
  SHOW_INTEGER_TYPE(size_t);
  SHOW_INTEGER_TYPE(ssize_t);

  SHOW_FLOAT_TYPE(float);
  SHOW_FLOAT_TYPE(double);
  SHOW_FLOAT_TYPE(long double);

  SHOW_POINTER_TYPE(void*);
  SHOW_POINTER_TYPE(char*);
  SHOW_POINTER_TYPE(int*);

  return EXIT_SUCCESS;
}
