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
#include "includes.h"

/*
 * PureDarwin 9.8.0 defines PF_UNIX using AF_LOCAL but AF_LOCAL is defined
 * only if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE).
 */
#ifndef AF_LOCAL
#  define AF_LOCAL AF_UNIX
#endif

#define FIELD_SIZE(struct_name, field_name) sizeof(((struct_name *)0)->field_name)
#define ALIGNOF(type) ((int)offsetof(struct { char f1; type f2; }, f2))

#define SIGNED_TYPE_VALUE(value) ((((value) * 0) - 1) < 0)

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
void buffer_add_buf(buffer_t *buf, buffer_t *buf2);
void buffer_addf(buffer_t *buf, char *fmt, ...);
void buffer_add_escaped_mem(buffer_t *buf, void *mem, size_t size);
void buffer_add_quoted_mem(buffer_t *buf, void *mem, size_t size);
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
void errno_candidate_each(void (*func)(int errcand, void *arg), void *arg);

int constant_name2int(char *name, int *ret);
void *constant_search_names(char *prefix, void *(*func)(char *name, int val, void *arg), void *arg);
char *constant_int2name(char *prefix, int value);

typedef enum {
  iconst_unspecified,
  iconst_misc,
  iconst_errno,
  iconst_af,
  iconst_pf,
  iconst_sock,
  iconst_shut,
  iconst_msg,
  iconst_sol,
  iconst_so,
  iconst_scm,
} iconst_purpose_t;

typedef struct {
  iconst_purpose_t purpose;
  char *name;
  uintmax_t val;
  int positive_p;
  int sizeof_type;
  int signed_type;
} iconst_t;

#define INTEGER_CONSTANT_INFO(purpose, name, val)  \
 { purpose, name, (uintmax_t)(val), 0 < (val), sizeof(val), SIGNED_TYPE_VALUE(val) }

int constant2intmax(const iconst_t *c, intmax_t *intmax_ret); /* success:0, failure:-1 */

extern const iconst_t iconst_table[];
extern const int iconst_numentries;
int iconst_count(iconst_purpose_t purpose);

