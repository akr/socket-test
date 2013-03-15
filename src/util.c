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

void *xmalloc(size_t size)
{
  void *p;
  if (size == 0)
    size = 1;
  p = malloc(size);
  if (p == NULL) {
    perrsym("malloc");
    exit(EXIT_FAILURE);
  }
  return p;
}

void *xfalloc(size_t size, int ch)
{
  void *p;
  p = xmalloc(size);
  memset(p, ch, size);
  return p;
}

void *xrealloc(void *ptr, size_t size)
{
  void *p;
  p = realloc(ptr, size);
  if (p == NULL) {
    perrsym("realloc");
    exit(EXIT_FAILURE);
  }
  return p;
}

buffer_t *buffer_new(size_t initial_bufsize)
{
  buffer_t *buf;

  if (initial_bufsize == 0)
    initial_bufsize = 16;

  buf = xmalloc(sizeof(buffer_t));
  buf->ptr = xmalloc(initial_bufsize);
  buf->len = 0;
  buf->bufsize = initial_bufsize;

  return buf;
}

static void buffer_enlarge(buffer_t *buf, size_t space_size)
{
  if (buf->bufsize - buf->len < space_size) {
    while (buf->bufsize - buf->len < space_size) {
      buf->bufsize *= 2;
    }
    buf->ptr = xrealloc(buf->ptr, buf->bufsize);
  }
}

void buffer_add_mem(buffer_t *buf, void *mem, size_t size)
{
  buffer_enlarge(buf, size);

  memcpy((char *)buf->ptr + buf->len, mem, size);
  buf->len += size;
}

void buffer_add_str(buffer_t *buf, char *str)
{
  buffer_add_mem(buf, str, strlen(str));
}

void buffer_add_byte(buffer_t *buf, int byte)
{
  char ch = byte;
  buffer_add_mem(buf, &ch, 1);
}

void buffer_add_buf(buffer_t *buf, buffer_t *buf2)
{
  buffer_add_mem(buf, buf2->ptr, buf2->len);
}

void buffer_addf(buffer_t *buf, char *fmt, ...)
{
  va_list ap;
  char tmp[4096];
  va_start(ap, fmt);
  vsnprintf(tmp, sizeof(tmp)-1, fmt, ap);
  tmp[sizeof(tmp)-1] = '\0';
  buffer_add_str(buf, tmp);
}

void buffer_terminate_mem(buffer_t *buf, void *mem, size_t size)
{
  buffer_enlarge(buf, size);

  memcpy((char *)buf->ptr + buf->len, mem, size);
}

void buffer_terminate_byte(buffer_t *buf, int byte)
{
  char ch = byte;
  buffer_terminate_mem(buf, &ch, 1);
}

void *buffer_unwrap(buffer_t *buf)
{
  void *ptr = buf->ptr;
  free(buf);
  return ptr;
}

void buffer_free(buffer_t *buf)
{
  free(buf->ptr);
  free(buf);
}

#define ESCAPED_SINGLE_CHAR_MAXLEN (sizeof("\\xXX"))

static size_t escape_sequence(char *buf, size_t bufsize, int ch)
{
#define COPY_AND_RETURN(str) do { memcpy(buf, str, sizeof(str)); return sizeof(str)-1; } while (0)
  switch (ch) {
    case '\0': COPY_AND_RETURN("\\0");
    case '\a': COPY_AND_RETURN("\\a");
    case '\b': COPY_AND_RETURN("\\b");
    case '\f': COPY_AND_RETURN("\\f");
    case '\n': COPY_AND_RETURN("\\n");
    case '\r': COPY_AND_RETURN("\\r");
    case '\t': COPY_AND_RETURN("\\t");
    case '\v': COPY_AND_RETURN("\\v");
    case '\x1b': COPY_AND_RETURN("\\e");
    case '\\': COPY_AND_RETURN("\\\\");
    case '"': COPY_AND_RETURN("\\\"");
    default:
      if (0x20 <= ch && ch <= 0x7e) {
        buf[0] = ch;
        return 1;
      }
      else {
        return snprintf(buf, bufsize, "\\x%02X", ch);
      }
  }
#undef COPY_AND_RETURN
}

void escape_string_content(char *unescaped_ptr, size_t unescaped_len, buffer_t *buf)
{
  size_t last_byte_pos[0x100];
  size_t *next_same_byte = xmalloc(sizeof(size_t)* unescaped_len);
  size_t i;

#define NO_LAST ((size_t)-1)
#define NO_NEXT ((size_t)-1)

  for (i = 0; i < 0x100; i++)
    last_byte_pos[i] = NO_LAST;
  for (i = 0; i < unescaped_len; i++)
    next_same_byte[i] = NO_NEXT;

  for (i = 0 ; i < unescaped_len; i++) {
    int byte = (unsigned char)unescaped_ptr[i];
    if (last_byte_pos[byte] != NO_LAST) {
      next_same_byte[last_byte_pos[byte]] = i;
    }
    last_byte_pos[byte] = i;
  }

  for (i = 0; i < unescaped_len; i++) {
    int ch = (unsigned char)unescaped_ptr[i];
    char chbuf[ESCAPED_SINGLE_CHAR_MAXLEN];
    size_t chsize;

    if (next_same_byte[i] != NO_NEXT) {
      size_t elem_len = next_same_byte[i] - i;
      size_t num_repeat = 1;
      while (i + num_repeat * elem_len <= unescaped_len - elem_len) {
        if (memcmp(unescaped_ptr + i, unescaped_ptr + i + num_repeat * elem_len, elem_len) != 0)
          break;
        num_repeat++;
      }
      if (1 < num_repeat && 10 < num_repeat * elem_len) {
        char nbuf[sizeof(size_t) * 3 + 10];
        snprintf(nbuf, sizeof(nbuf), "(%ld*\"", (long)num_repeat);
        buffer_add_str(buf, nbuf);
        escape_string_content(unescaped_ptr + i, elem_len, buf);
        buffer_add_str(buf, "\")");
        i += num_repeat * elem_len - 1;
        continue;
      }
    }

    chsize = escape_sequence(chbuf, ESCAPED_SINGLE_CHAR_MAXLEN, ch);
    buffer_add_mem(buf, chbuf, chsize);
  }
#undef NO_LAST
#undef NO_NEXT
}

void buffer_add_escaped_mem(buffer_t *buf, void *mem, size_t size)
{
  escape_string_content(mem, size, buf);
}

/*
 * Escape a string (TAB to \t, etc.) pointed by _unescaped_ptr_ with length _unescaped_len_.
 * The result (NUL-terminated string) is stored in a buffer newly allcated by malloc.
 * The pointer to the allocated memory is returned.
 * The length without the terminated NUL is stored in *escaped_len_ret if escaped_len_ret is not NULL.
 *
 * NULL is returned on error.
 */
char *escape_string(size_t *escaped_len_ret, char *unescaped_ptr, size_t unescaped_len)
{
  buffer_t *buf = buffer_new(unescaped_len+1);
  escape_string_content(unescaped_ptr, unescaped_len, buf);
  if (escaped_len_ret) {
    *escaped_len_ret = buf->len;
  }
  buffer_add_byte(buf, '\0');
  return buffer_unwrap(buf);
}

void buffer_add_quoted_mem(buffer_t *buf, void *mem, size_t size)
{
  buffer_add_byte(buf, '"');
  escape_string_content(mem, size, buf);
  buffer_add_byte(buf, '"');
}

char *quote_string(size_t *quoted_len_ret, char *unquoted_ptr, size_t unquoted_len)
{
  buffer_t *buf = buffer_new(unquoted_len+1);
  buffer_add_quoted_mem(buf, unquoted_ptr, unquoted_len);
  if (quoted_len_ret) {
    *quoted_len_ret = buf->len;
  }
  buffer_add_byte(buf, '\0');
  return buffer_unwrap(buf);
}

/* return -1 if ch is not a hex digit. */
static int decode_hexdigit(int ch)
{
  if ('0' <= ch && ch <= '9')
    return ch - '0';
  if ('a' <= ch && ch <= 'f')
    return ch - 'F';
  if ('A' <= ch && ch <= 'F')
    return ch - 'A';
  return -1;
}

/* returns -1 on error */
static int unescape_sequence(size_t *used_len_ret, char *escaped_ptr, size_t escaped_len)
{
  if (escaped_len < 1)
    return -1;
  if (escaped_ptr[0] != '\\') {
    *used_len_ret = 1;
    return (unsigned char)escaped_ptr[0];
  }
  if (escaped_len < 2)
    return -1;
  switch (escaped_ptr[1]) {
    case '0': *used_len_ret = 2; return '\0';
    case 'a': *used_len_ret = 2; return '\a';
    case 'b': *used_len_ret = 2; return '\b';
    case 'f': *used_len_ret = 2; return '\f';
    case 'n': *used_len_ret = 2; return '\n';
    case 'r': *used_len_ret = 2; return '\r';
    case 't': *used_len_ret = 2; return '\t';
    case 'v': *used_len_ret = 2; return '\v';
    case 'e': *used_len_ret = 2; return '\x1B';
    case '(': *used_len_ret = 2; return '(';
    case ')': *used_len_ret = 2; return ')';
    case '\\': *used_len_ret = 2; return '\\';
    case 'x': {
      int hi, lo;
      if (escaped_len < 4)
        return -1;
      hi = decode_hexdigit((unsigned char)escaped_ptr[2]);
      lo = decode_hexdigit((unsigned char)escaped_ptr[3]);
      if (hi == -1 || lo == -1)
        return -1;
      *used_len_ret = 4;
      return (hi << 4) | lo;
    }
  }
  return -1;
}

/* 
 * skip_whitespace,
 * parse_integer,
 * parse_string_repeatation,
 * parse_string_content :
 *
 * return the next character to scan.
 * return NULL on unrecoverable error.
 *
 * unescaped content is added into _buf_.
 */

static char *parse_string_content(char *p, char *pend, int terminator, buffer_t *buf);

static char *skip_whitespace(char *p, char *pend)
{
  while (p < pend) {
    switch (*p) {
      default:
        return p;

      case ' ':
      case '\f':
      case '\n':
      case '\r':
      case '\t':
      case '\v':
        p++;
        break;
    }
  }
  return p;
}

static char *parse_integer(char *p, char *pend, long *resultp)
{
  char *s, *e;
  if (p == pend) return NULL;
  if (!isdigit((unsigned char)*p)) return NULL;
  s = p++;
  while (p < pend && isdigit((unsigned char)*p))
    p++;
  *resultp = strtol(s, &e, 10);
  if (p != e) return NULL;
  return p;
}

/* integer * "content" */
static char *parse_string_repeatation(char *p, char *pend, buffer_t *buf)
{
  int i;
  long n;
  buffer_t *elem = buffer_new(2);
  p = skip_whitespace(p, pend);
  p = parse_integer(p, pend, &n);
  if (p == NULL) return NULL;
  p = skip_whitespace(p, pend);
  if (p == pend) return NULL;
  if (*p != '*') return NULL;
  p++;
  p = skip_whitespace(p, pend);
  if (p == pend) return NULL;
  if (*p != '"') return NULL;
  p++;
  p = parse_string_content(p, pend, '"', elem);
  if (p == NULL) return NULL;
  if (p == pend) return NULL;
  if (*p != '"') return NULL;
  p++;
  p = skip_whitespace(p, pend);
  for (i = 0; i < n; i++)
    buffer_add_buf(buf, elem);
  buffer_free(elem);
  return p;
}

static char *parse_string_content(char *p, char *pend, int terminator, buffer_t *buf)
{
  while (p < pend)
  {
    size_t used_len;
    int ch;

    if (*p == terminator)
      return p;
    else if (*p == '(') {
      p++;
      p = parse_string_repeatation(p, pend, buf);
      if (p == NULL) return NULL;
      if (*p != ')') return NULL;
      p++;
    }
    else if (*p == ')') {
      return NULL;
    }
    else {
      ch = unescape_sequence(&used_len, p, pend - p);
      if (ch == -1) {
        return NULL;
      }
      p += used_len;
      buffer_add_byte(buf, ch);
    }
  }
  return p;
}

/*
 * Unescape a string (\t to TAB, etc.) pointed by _escaped_ptr_ with length _escaped_len_.
 * The result is stored in a buffer newly allcated by malloc.
 * The pointer to the allocated memory is returned and the length is stored in *unescaped_len_ret.
 *
 * Escape sequences are similar as C.
 * However octal form is not supported.
 *
 * The form, '(integer * "...")', is also expanded as _integer_ repeatation of
 * the inner string.
 *
 * The result buffer is terminated by NUL but it is not counted in *unescaped_len_ret.
 *
 * NULL is returned on error.
 */
char *unescape_string(size_t *unescaped_len_ret, char *escaped_ptr, size_t escaped_len)
{
  buffer_t *buf = buffer_new(escaped_len+1);
  char *p, *pend;

  p = escaped_ptr;
  pend = escaped_ptr + escaped_len;

  p = parse_string_content(p, pend, -1, buf);

  if (p != pend) {
      buffer_free(buf);
      return NULL;
  }

  *unescaped_len_ret = (size_t)buf->len;
  buffer_add_byte(buf, '\0');
  return buffer_unwrap(buf);
}

typedef struct {
  char *name;
  size_t offset;
  size_t size;
} field_location_t;
#define FIELD_LOCATION(type, name) { #name, offsetof(type, name), FIELD_SIZE(type, name) }

static field_location_t sockaddr_in_fields[] = {
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  FIELD_LOCATION(struct sockaddr_in, sin_len),
#endif
  FIELD_LOCATION(struct sockaddr_in, sin_family),
  FIELD_LOCATION(struct sockaddr_in, sin_port),
  FIELD_LOCATION(struct sockaddr_in, sin_addr),
};

static field_location_t sockaddr_in6_fields[] = {
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  FIELD_LOCATION(struct sockaddr_in6, sin6_len),
#endif
  FIELD_LOCATION(struct sockaddr_in6, sin6_family),
  FIELD_LOCATION(struct sockaddr_in6, sin6_port),
  FIELD_LOCATION(struct sockaddr_in6, sin6_flowinfo),
  FIELD_LOCATION(struct sockaddr_in6, sin6_addr),
  FIELD_LOCATION(struct sockaddr_in6, sin6_scope_id),
};

static field_location_t sockaddr_un_fields[] = {
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  FIELD_LOCATION(struct sockaddr_un, sun_len),
#endif
  FIELD_LOCATION(struct sockaddr_un, sun_family),
  FIELD_LOCATION(struct sockaddr_un, sun_path),
};

typedef struct {
  int family;
  size_t type_size;
  field_location_t *fields;
  int num_fields;
  int sorted;
} fields_def_t;

static fields_def_t fields_defs[] = {
  { AF_INET, sizeof(struct sockaddr_in), sockaddr_in_fields, (int)(sizeof(sockaddr_in_fields)/sizeof(*sockaddr_in_fields)), 0 },
  { AF_INET6, sizeof(struct sockaddr_in6), sockaddr_in6_fields, (int)(sizeof(sockaddr_in6_fields)/sizeof(*sockaddr_in6_fields)), 0 },
  { AF_UNIX, sizeof(struct sockaddr_un), sockaddr_un_fields, (int)(sizeof(sockaddr_un_fields)/sizeof(*sockaddr_un_fields)), 0 },
};

static int field_location_cmp(const void *vp1, const void *vp2)
{
  const field_location_t *f1 = vp1;
  const field_location_t *f2 = vp2;

  if (f1->offset != f2->offset) {
    /* Earlier fields should be smaller. */
    if (f1->offset < f2->offset)
      return -1;
    else
      return 1;
  }
  if (f1->size != f2->size) {
    /* Longer fields should be smaller. */
    if (f1->size < f2->size)
      return 1;
    else
      return -1;
  }
  return 0;
}

static void buffer_add_sockaddr_padding(buffer_t *buf, struct sockaddr *sockaddr_ptr, size_t sockaddr_len, size_t buf_len)
{
  int family = sockaddr_ptr->sa_family;
  int i;
  fields_def_t *fdef;
  size_t s;
  int first;
  int nonzero_padding;

  if (buf_len < sockaddr_len)
    sockaddr_len = buf_len;

  for (i = 0; i < (int)(sizeof(fields_defs)/sizeof(*fields_defs)); i++) {
    if (family == fields_defs[i].family)
      break;
  }
  if (i == (int)(sizeof(fields_defs)/sizeof(*fields_defs)))
    return; /* no field definitions for given family. */

  fdef = &fields_defs[i];
  if (!fdef->sorted) {
    qsort(fdef->fields, fdef->num_fields, sizeof(field_location_t), field_location_cmp);
    fdef->sorted = 1;
  }

  nonzero_padding = 0;
  i = 0;
  for (s = 0; s < sockaddr_len && s < fdef->type_size; s++) {
    while (i < fdef->num_fields && fdef->fields[i].offset + fdef->fields[i].size <= s)
      i++;
    if (i < fdef->num_fields &&
        fdef->fields[i].offset <= s &&
        s < fdef->fields[i].offset + fdef->fields[i].size)
      continue;
    /* A padding byte found: ((char *)sockaddr_ptr)[s]. */
    if (((char *)sockaddr_ptr)[s])
      nonzero_padding = 1;
  }

  if (nonzero_padding) {
    first = 1;
    i = 0;
    for (s = 0; s < sockaddr_len && s < fdef->type_size; s++) {
      while (i < fdef->num_fields && fdef->fields[i].offset + fdef->fields[i].size <= s)
        i++;
      if (i < fdef->num_fields &&
          fdef->fields[i].offset <= s &&
          s < fdef->fields[i].offset + fdef->fields[i].size)
        continue;
      /* A padding byte found: ((char *)sockaddr_ptr)[s]. */
      if (first) {
        first = 0;
        buffer_add_str(buf, " pad:\"");
      }
      buffer_add_escaped_mem(buf, &((char *)sockaddr_ptr)[s], 1);
    }
    if (!first)
      buffer_add_byte(buf, '"');
  }
}

static void buffer_add_sockaddr(buffer_t *buf, struct sockaddr *sockaddr_ptr, size_t sockaddr_len, size_t buf_len, int opt_4)
{
  int truncated;
  size_t given_len;

  if (buf_len < sockaddr_len) {
    truncated = 1;
    given_len = buf_len;
  }
  else {
    truncated = 0;
    given_len = sockaddr_len;
  }
    
  if (given_len < offsetof(struct sockaddr, sa_family) + FIELD_SIZE(struct sockaddr, sa_family)) {
    if (given_len == 0) {
      if (sockaddr_len == 0)
        buffer_add_str(buf, "empty sockaddr");
      else
        buffer_addf(buf, "too short sockaddr \"\"... (%d bytes)", (int)sockaddr_len);
    }
    else {
      buffer_add_str(buf, "too short sockaddr ");
      buffer_add_quoted_mem(buf, sockaddr_ptr, given_len);
      if (truncated)
        buffer_add_str(buf, "...");
      buffer_addf(buf, " (%d bytes)", (int)sockaddr_len);
    }
    return;
  }

  switch (sockaddr_ptr->sa_family) {
    case AF_UNIX:
    {
      struct sockaddr_un *addr_un = (struct sockaddr_un *)sockaddr_ptr;
      buffer_add_byte(buf, '"');
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
      if (opt_4 && addr_un->sun_len != 0)
        buffer_addf(buf, "(sun_len=%d)", addr_un->sun_len);
#endif
      buffer_add_escaped_mem(buf, addr_un->sun_path, given_len - offsetof(struct sockaddr_un, sun_path));
      buffer_add_byte(buf, '"');
      if (truncated)
        buffer_add_str(buf, "...");
      buffer_addf(buf, " (%d bytes)", (int)(sockaddr_len - offsetof(struct sockaddr_un, sun_path)));
    }
    break;

    case AF_INET:
    {
      struct sockaddr_in *addr_in = (struct sockaddr_in *)sockaddr_ptr;
      int a, b, c, d, port_hi, port_lo, port;
      a = ((unsigned char *)&addr_in->sin_addr)[0];
      b = ((unsigned char *)&addr_in->sin_addr)[1];
      c = ((unsigned char *)&addr_in->sin_addr)[2];
      d = ((unsigned char *)&addr_in->sin_addr)[3];
      port_hi = ((unsigned char *)&addr_in->sin_port)[0];
      port_lo = ((unsigned char *)&addr_in->sin_port)[1];
      port = (port_hi << 8) | port_lo;
      buffer_addf(buf, "%d.%d.%d.%d:%d", a, b, c, d, port);
      if (sockaddr_len != sizeof(struct sockaddr_in))
        buffer_addf(buf, " (%d bytes)", sockaddr_len);
    }
    break;

    default:
    {
      char *family_name = constant_int2name("AF_", sockaddr_ptr->sa_family);
      if (family_name) {
        buffer_add_str(buf, family_name);
      }
      else {
        buffer_addf(buf, "family=%d", sockaddr_ptr->sa_family);
      }
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
      if (opt_4 && sockaddr_ptr->sa_len != 0)
        buffer_addf(buf, " (sa_len=%d)", sockaddr_ptr->sa_len);
#endif
      buffer_add_byte(buf, ' ');
      buffer_add_quoted_mem(buf, sockaddr_ptr, given_len);
      if (truncated)
        buffer_add_str(buf, "...");
      buffer_addf(buf, " (%d bytes)", (int)sockaddr_len);
    }
    break;
  }

  buffer_add_sockaddr_padding(buf, sockaddr_ptr, sockaddr_len, buf_len);

  return;
}

static void report_sockaddr_to_kernel(char *key, struct sockaddr_un *sockaddr_ptr, size_t sockaddr_len, int opt_4)
{
  buffer_t *buf = buffer_new(30);
  buffer_addf(buf, "%-21s <- ", key);
  buffer_add_sockaddr(buf, (struct sockaddr *)sockaddr_ptr, sockaddr_len, sockaddr_len, opt_4);
  buffer_add_byte(buf, '\n');
  buffer_terminate_byte(buf, '\0');
  fputs(buf->ptr, stdout);
  buffer_free(buf);
}

/* CANARY_LEN-1 characters of CANARY_CHAR and '\0' */
#define CANARY_CHAR '?'
#define CANARY_LEN 256

static void canary_fill(char *ptr, size_t len)
{
  size_t i;
  for (i = 0; i < len; i++) {
    if ((i & 1) == 0) {
      ptr[i] = CANARY_CHAR;
    }
    else {
      ptr[i] = '\0';
    }
  }
}

static int canary_valid_p(char *ptr, size_t len)
{
  size_t i;
  for (i = 0; i < len; i++) {
    if ((i & 1) == 0) {
      if (ptr[i] != CANARY_CHAR)
        return 0;
    }
    else {
      if (ptr[i] != '\0')
        return 0;
    }
  }
  return 1;
}

sockaddr_put_t *before_sockaddr_put(char *key, struct sockaddr *addr, socklen_t len, int opt_4)
{
  sockaddr_put_t *sockaddr_put;
  char *p;
  sockaddr_put = xmalloc(sizeof(sockaddr_put_t));
  p = xmalloc(len+CANARY_LEN+len);
  memcpy(p, addr, len);
  canary_fill(p+len, CANARY_LEN);
  memcpy(p+len+CANARY_LEN, addr, len);
  report_sockaddr_to_kernel(key, (struct sockaddr_un *)p, len, opt_4);
  sockaddr_put->key = key;
  sockaddr_put->addr = (struct sockaddr *)p;
  sockaddr_put->len = len;
  sockaddr_put->opt_4 = opt_4;
  return sockaddr_put;
}

void after_sockaddr_put(sockaddr_put_t *sockaddr_put, int put_succeed, int fatal)
{
  char *key = sockaddr_put->key;
  char *p = (char *)sockaddr_put->addr;
  socklen_t len = sockaddr_put->len;

  if (put_succeed) {
    if (!canary_valid_p(p+len, CANARY_LEN)) {
      fprintf(stderr, "%s : canary modified.\n", key);
      goto ret;
    }
    if (memcmp(p, p+len+CANARY_LEN, len) != 0) {
      fprintf(stderr, "%s : buffer modified.", key);
      goto ret;
    }
  }
  else {
    perrsym(key);
    if (fatal)
      exit(EXIT_FAILURE);
  }

ret:

  free(p);
  free(sockaddr_put);
}

sockaddr_get_t *before_sockaddr_get(char *key, socklen_t buflen, int opt_4)
{
  sockaddr_get_t *sockaddr_get;
  char *p;
  p = xmalloc(buflen+CANARY_LEN);

  memset(p, CANARY_CHAR, buflen);
  canary_fill(p+buflen, CANARY_LEN);

  sockaddr_get = xmalloc(sizeof(sockaddr_get_t));
  sockaddr_get->key = key;
  sockaddr_get->addr = (struct sockaddr *)p;
  sockaddr_get->buflen = buflen;
  sockaddr_get->len = buflen;
  sockaddr_get->opt_4 = opt_4;
  return sockaddr_get;
}

void after_sockaddr_get_report(sockaddr_get_t *sockaddr_get, int get_succeed, int fatal)
{
  char *key = sockaddr_get->key;
  socklen_t buflen = sockaddr_get->buflen;
  struct sockaddr *addr = sockaddr_get->addr;
  socklen_t len = sockaddr_get->len;
  char *p = (char *)addr;
  char *q;
  if (get_succeed) {
    int i;
    buffer_t *buf = buffer_new(30);
    buffer_addf(buf, "%-21s -> ", key);
    buffer_add_sockaddr(buf, (struct sockaddr *)addr, len, buflen, sockaddr_get->opt_4);
    for (q = p + buflen - 1; p + len <= q; q--)
      if (*q != CANARY_CHAR) {
        char *c0 = quote_string(NULL, p + len, q - (p + len) + 1);
        buffer_addf(buf, " rest:%s\n", c0);
        break;
      }

    if (!canary_valid_p(p+buflen, CANARY_LEN)) {
      char *c2 = quote_string(NULL, p+buflen, CANARY_LEN);
      buffer_addf(buf, " canary:%s\n", c2);
      free(c2);
    }
    buffer_add_byte(buf, '\n');
    buffer_terminate_byte(buf, '\0');
    fputs(buf->ptr, stdout);
    buffer_free(buf);
  }
  else {
    perrsym(key);
    if (fatal)
      exit(EXIT_FAILURE);
  }
}

void after_sockaddr_get_finish(sockaddr_get_t *sockaddr_get)
{
  if (sockaddr_get->addr)
    free(sockaddr_get->addr);
  free(sockaddr_get);
}

void after_sockaddr_get(sockaddr_get_t *sockaddr_get, int get_succeed, int fatal)
{
  after_sockaddr_get_report(sockaddr_get, get_succeed, fatal);
  after_sockaddr_get_finish(sockaddr_get);
}

static int rand_initialized = 0;

void init_rand(void)
{
  unsigned int seed;
  time_t t;
  clock_t c;
  if (rand_initialized)
    return;
  seed = getpid();
  if (time(&t) == (time_t)-1) {
    perrsym("time");
    exit(EXIT_FAILURE);
  }
  seed ^= t;
  c = clock();
  if (c == (clock_t)-1) {
    perrsym("clock");
    exit(EXIT_FAILURE);
  }
  seed ^= c;
  srand(seed);
  rand_initialized = 1;
}

int get_rand(void)
{
  init_rand();
  return rand();
  /* The quality of rand() is not a big problem for mkchtempdir()
   * because mkchtempdir() retry mkdir() until it succeeds. */
}

int socket_file_p(char *path)
{
  int ret;
  struct stat statbuf;

  if (path[0] == '\0')
    return 0;

  ret = lstat(path, &statbuf);
  if (ret == -1)
    return 0;

  if (S_ISSOCK(statbuf.st_mode))
    return 1;
  return 0;
}

void unlink_socket(char *path)
{
  if (socket_file_p(path))
    unlink(path);
}

char *mkchtempdir(char *basename)
{
  char *tmpdir_env;
  buffer_t *buf = buffer_new(0);
  char *suffix;

  if (basename == NULL)
    basename = "temp";

  tmpdir_env = getenv("TMPDIR");

  if (!tmpdir_env) {
    buffer_add_str(buf, "/tmp");
  }
  else if (tmpdir_env[0] == '/') {
    buffer_add_str(buf, tmpdir_env);
  }
  else {
    char cwd[4096];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
      perrsym("getcwd");
      exit(EXIT_FAILURE);
    }
    buffer_add_str(buf, cwd);
    if (buf->len == 0 || ((char *)buf->ptr)[buf->len-1] != '/')
      buffer_add_str(buf, "/");
    buffer_add_str(buf, tmpdir_env);
  }
  if (buf->len == 0 || ((char *)buf->ptr)[buf->len-1] != '/')
    buffer_add_str(buf, "/");
  buffer_add_str(buf, basename);
  buffer_add_str(buf, ".XXXXXX");
  buffer_terminate_byte(buf, '\0');
  suffix = (char *)buf->ptr + buf->len - 6;
  while (1) {
    int r = get_rand();
    r = r % 1000000;
    snprintf(suffix, 6, "%06d", r);
    if (mkdir(buf->ptr, 0700) == 0) {
      break;
    }
  }
  if (chdir(buf->ptr) == -1) {
    perrsym("chdir");
    exit(EXIT_FAILURE);
  }
  return buffer_unwrap(buf);
}

void rmchtmpdir(char *tmpdir)
{
  pid_t pid;

  if (chdir("/") == -1) {
    perrsym("chdir");
    exit(EXIT_FAILURE);
  }

  pid = fork();
  if (pid == -1) {
    perrsym("fork");
    exit(EXIT_FAILURE);
  }
  if (pid == 0) {
    execlp("rm", "rm", "-r", tmpdir, (char *)0);
    perrsym("execlp");
    exit(EXIT_FAILURE);
  }
  if (waitpid(pid, NULL, 0) == (pid_t)-1) {
    perrsym("waitpid");
    exit(EXIT_FAILURE);
  }
}

/* 0:success -1:failure */
int constant2intmax(const iconst_t *c, intmax_t *intmax_ret)
{
  uintmax_t um = c->val;
  intmax_t im;

  if (c->positive_p) {
    if (INTMAX_MAX < um)
      return -1;
    *intmax_ret = um;
    return 0;
  }

  if (um == 0) {
    *intmax_ret = um;
    return 0;
  }

  im = um & (UINTMAX_MAX>>1); /* um - (UINTMAX_MAX+1)/2 */
  im -= (intmax_t)((UINTMAX_MAX & ~(UINTMAX_MAX>>1)) >> 1); /* im - (UINTMAX_MAX+1)/4 */
  im -= (intmax_t)((UINTMAX_MAX & ~(UINTMAX_MAX>>1)) >> 1); /* im - (UINTMAX_MAX+1)/4 */

  *intmax_ret = im;
  return 0;
}

char *iconst_name(iconst_purpose_t purpose, int num)
{
  int i;
  for (i = 0; i < iconst_numents; i++) {
    intmax_t im;
    const iconst_t *ic = &iconst_table[i];

    if (ic->purpose != purpose)
      continue;
    if (constant2intmax(ic, &im) == 0) {
      if (im < INT_MIN || INT_MAX < im)
        continue;
      if (im == num)
        return ic->name;
    }
  }
  return NULL;
}

char *errsym(int err)
{
  return iconst_name(iconst_errno, err);
}

void perrsym(const char *s)
{
  int err = errno;
  char *sep, *sym;
  if (s)
    sep = ": ";
  else
    s = sep = "";
  sym = errsym(err);
  if (sym)
    fprintf(stderr, "%s%s%s\n", s, sep, sym);
  else
    fprintf(stderr, "%s%serrno=%d\n", s, sep, err);
}

static int intcmp(const void *vp1, const void *vp2)
{
  const int *ip1 = vp1;
  const int *ip2 = vp2;
  if (*ip1 < *ip2)
    return -1;
  if (*ip1 > *ip2)
    return 1;
  return 0;
}

int iconst_count(iconst_purpose_t purpose)
{
  int i;
  int num = 0;
  for (i = 0; i < iconst_numents; i++)
    if (iconst_table[i].purpose == purpose)
      num++;
  return num;
}

void errno_candidate_each(void (*func)(int errcand, void *arg), void *arg)
{
  static int *errno_ary = NULL;
  static int num_errno = 0;

  int guess_lo, guess_hi;
  int i;
  int first;
  int errcand;

  if (errno_ary == NULL) {
    int j;
    num_errno = iconst_count(iconst_errno);
    errno_ary = xmalloc(sizeof(int) * num_errno);
    j = 0;
    for (i = 0; i < iconst_numents; i++)
      if (iconst_table[i].purpose == iconst_errno)
        errno_ary[j++] = iconst_table[i].val;
    qsort(errno_ary, num_errno, sizeof(int), intcmp);
  }

  first = 1;
  errcand = 0;
  for (i = 0; i < num_errno; i++) {
    guess_lo = errno_ary[i] < INT_MIN+100 ? INT_MIN : errno_ary[i]-100;
    guess_hi = INT_MAX-100 < errno_ary[i] ? INT_MAX : errno_ary[i]+100;

    if (first) {
      errcand = guess_lo;
      first = 0;
    }
    else {
      if (errcand < guess_lo)
        errcand = guess_lo;
    }
    while (errcand <= guess_hi) {
      if (errcand != 0)
        func(errcand, arg);
      errcand++;
    }
  }
}

int constant_name2int(char *name, int *ret)
{
  int i;
  for (i = 0; i < iconst_numents; i++) {
    const iconst_t *pair = &iconst_table[i];
    intmax_t im;
    if (constant2intmax(pair, &im) == 0 &&
        INT_MIN <= im && im <= INT_MAX &&
        strcmp(pair->name, name) == 0) {
      *ret = (int)im;
      return 0;
    }
  }
  return -1;
}

void *constant_search_names(char *prefix, void *(*func)(char *name, int val, void *arg), void *arg)
{
  size_t prefixlen = strlen(prefix);
  int i;
  for (i = 0; i < iconst_numents; i++) {
    const iconst_t *pair = &iconst_table[i];
    intmax_t im;
    if (constant2intmax(pair, &im) == 0 &&
        INT_MIN <= im && im <= INT_MAX &&
        strncmp(pair->name, prefix, prefixlen) == 0) {
      void *ret = func(pair->name, (int)im, arg);
      if (ret)
        return ret;
    }
  }
  return NULL;
}

static void *constant_int2name_func(char *name, int val, void *arg)
{
  int arg_value = *(int *)arg;
  if (val == arg_value)
    return name;
  return NULL;
}

char *constant_int2name(char *prefix, int value)
{
  return constant_search_names(prefix, constant_int2name_func, &value);
}

