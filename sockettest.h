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

#include "config.h"

#ifdef __sun
/* On SunOS, following definitions declares that
 * this program uses SUS (XPG4v2) with other non-conflicting features. 
 * They are required to use newer struct msghdr for sendmsg/recvmsg. */
/* cf. standards(5). */
#  define _XOPEN_SOURCE
#  define _XOPEN_SOURCE_EXTENDED 1
#  define __EXTENSIONS__
#endif

#ifdef __minix
/* Minix require feature test macro for several definitions.
 * - struct sockaddr_storage needs _XOPEN_SOURCE >= 500
 * - S_ISSOCK needs _XOPEN_SOURCE >= 600
 */
#  define _XOPEN_SOURCE 600
#endif

/* AC_INCLUDES_DEFAULT */
#include <stdio.h>
#ifdef HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif
#ifdef HAVE_SYS_STAT_H
#  include <sys/stat.h>
#endif
#ifdef STDC_HEADERS
#  include <stdlib.h>
#  include <stddef.h>
#else
#  ifdef HAVE_STDLIB_H
#    include <stdlib.h>
#  endif
#endif
#ifdef HAVE_STRING_H
#  if !defined STDC_HEADERS && defined HAVE_MEMORY_H
#    include <memory.h>
#  endif
#  include <string.h>
#endif
#ifdef HAVE_STRINGS_H
#  include <strings.h>
#endif
#ifdef HAVE_INTTYPES_H
#  include <inttypes.h>
#endif
#ifdef HAVE_STDINT_H
#  include <stdint.h>
#endif
#ifdef HAVE_UNISTD_H
#  include <unistd.h>
#endif

#ifdef HAVE_LIMITS_H
#  include <limits.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#  include <sys/socket.h>
#endif

#include <ctype.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <errno.h>
#include <float.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

#define FIELD_SIZE(struct_name, field_name) sizeof(((struct_name *)0)->field_name)
#define ALIGNOF(type) ((int)offsetof(struct { char f1; type f2; }, f2))

void *xmalloc(size_t size);
void *xfalloc(size_t size, int ch);
void *xrealloc(void *ptr, size_t size);

typedef struct {
  void *ptr;
  size_t len;
  size_t bufsize;
} buffer_t;

buffer_t *buffer_new(size_t initial_bufsize);
void buffer_add_mem(buffer_t *buf, void *mem, size_t size);
void buffer_add_str(buffer_t *buf, char *str);
void buffer_add_byte(buffer_t *buf, int byte);
void buffer_terminate_mem(buffer_t *buf, void *mem, size_t size);
void buffer_terminate_byte(buffer_t *buf, int byte);
void *buffer_unwrap(buffer_t *buf);
void buffer_free(buffer_t *buf);

char *escape_string(size_t *escaped_len_ret, char *unescaped_ptr, size_t unescaped_len);
char *unescape_string(size_t *unescaped_len_ret, char *escaped_ptr, size_t escaped_len);

char *quote_string(size_t *quoted_len_ret, char *unquoted_ptr, size_t unquoted_len);
/* char *unquote_string(size_t *unquoted_len_ret, char *quoted_ptr, size_t quoted_len); */

typedef struct {
  char *key;
  struct sockaddr *addr;
  socklen_t len;
  int opt_4;
} sockaddr_put_t;

typedef struct {
  char *key;
  struct sockaddr *addr;
  socklen_t buflen;
  socklen_t len;
  int opt_4;
} sockaddr_get_t;

sockaddr_put_t *before_sockaddr_put(char *key, struct sockaddr *addr, socklen_t len, int opt_4);
void after_sockaddr_put(sockaddr_put_t *sockaddr_put, int put_succeed, int fatal);
sockaddr_get_t *before_sockaddr_get(char *key, socklen_t buflen, int opt_4);
void after_sockaddr_get(sockaddr_get_t *sockaddr_get, int get_succeed, int fatal);
void after_sockaddr_get_report(sockaddr_get_t *sockaddr_get, int get_succeed, int fatal);
void after_sockaddr_get_finish(sockaddr_get_t *sockaddr_get);

void init_rand(void);
int get_rand(void);
char *mkchtempdir(char *basename);
void rmchtmpdir(char *tmpdir);

int socket_file_p(char *path);
void unlink_socket(char *path);
void perrsym(const char *s);
char *errsym(int err);
int errno_minmax(int *minp, int *maxp);

