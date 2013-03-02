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

char *quote_string(size_t *quoted_len_ret, char *unquoted_ptr, size_t unquoted_len)
{
  buffer_t *buf = buffer_new(unquoted_len+1);
  buffer_add_byte(buf, '"');
  escape_string_content(unquoted_ptr, unquoted_len, buf);
  if (quoted_len_ret) {
    *quoted_len_ret = buf->len;
  }
  buffer_add_byte(buf, '"');
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

static void report_path_to_kernel(char *key, struct sockaddr_un *sockaddr_ptr, size_t sockaddr_len, int opt_4)
{
  char *escaped_path;
  char path_sun_len_prefix[sizeof("(sun_len=NNN)")] = "";
  char *path_ptr = sockaddr_ptr->sun_path;
  size_t path_len = sockaddr_len - offsetof(struct sockaddr_un, sun_path);
  int path_sun_len;

  if (sockaddr_len < offsetof(struct sockaddr_un, sun_path)) {
    printf("%-21s -> too short sockaddr_un (%d bytes)\n", key, (int)sockaddr_len);
    return;
  }

  if (sockaddr_ptr->sun_family != AF_UNIX) {
    char *escaped_sockaddr = escape_string(NULL, (char *)sockaddr_ptr, sockaddr_len);
    printf("%-21s -> faimly=%d \"%s\"\n", key, (int)sockaddr_ptr->sun_family, escaped_sockaddr);
    free(escaped_sockaddr);
    return;
  }

#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  path_sun_len = sockaddr_ptr->sun_len;
#else
  path_sun_len = 0;
#endif
  escaped_path = escape_string(NULL, path_ptr, path_len);
  if (opt_4 && path_sun_len != 0) {
    snprintf(path_sun_len_prefix, sizeof(path_sun_len_prefix),
        "(sun_len=%d)", path_sun_len);
  }
  printf("%-21s <- \"%s%s\" (%d bytes)\n", key, path_sun_len_prefix, escaped_path, (int)path_len);
  free(escaped_path);
}

static void report_path_from_kernel(char *key, size_t buf_len, struct sockaddr_un *sockaddr_ptr, size_t sockaddr_len, int opt_4)
{
  int truncated;
  size_t len;
  char *escaped_path;
  char path_sun_len_prefix[sizeof("(sun_len=NNN)")] = "";

  if (sockaddr_len < offsetof(struct sockaddr_un, sun_path)) {
    printf("%-21s -> too short sockaddr_un (%d bytes)\n", key, (int)sockaddr_len);
    return;
  }

  if (sockaddr_ptr->sun_family != AF_UNIX) {
    char *escaped_sockaddr = escape_string(NULL, (char *)sockaddr_ptr, sockaddr_len);
    printf("%-21s -> faimly=%d \"%s\"\n", key, (int)sockaddr_ptr->sun_family, escaped_sockaddr);
    free(escaped_sockaddr);
    return;
  }

#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
  if (opt_4 && sockaddr_ptr->sun_len != 0) {
    snprintf(path_sun_len_prefix, sizeof(path_sun_len_prefix),
        "(sun_len=%d)", (int)sockaddr_ptr->sun_len);
  }
#endif

  if (sockaddr_len <= buf_len) {
    truncated = 0;
    len = sockaddr_len - offsetof(struct sockaddr_un, sun_path);
  }
  else {
    truncated = 1;
    len = buf_len - offsetof(struct sockaddr_un, sun_path);
  }

  escaped_path = escape_string(NULL, sockaddr_ptr->sun_path, len);
  printf("%-21s -> \"%s%s\"%s (%d bytes)\n",
      key, path_sun_len_prefix, escaped_path,
      truncated ? "..." : "",
      (int)(sockaddr_len - offsetof(struct sockaddr_un, sun_path)));
  free(escaped_path);
}

#define CANARY_STR "???????"
#define CANARY_LEN 8

sockaddr_put_t *before_sockaddr_put(char *key, struct sockaddr *addr, socklen_t len, int opt_4)
{
  sockaddr_put_t *sockaddr_put;
  char *p;
  sockaddr_put = xmalloc(sizeof(sockaddr_put_t));
  p = xmalloc(len+CANARY_LEN+len);
  memcpy(p, addr, len);
  memcpy(p+len, CANARY_STR, CANARY_LEN);
  memcpy(p+len+CANARY_LEN, addr, len);
  report_path_to_kernel(key, (struct sockaddr_un *)p, len, opt_4);
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
    if (memcmp(p+len, CANARY_STR, CANARY_LEN) != 0) {
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

  memset(p, '?', buflen);
  memcpy(p+buflen, CANARY_STR, CANARY_LEN);

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
  if (get_succeed) {
    report_path_from_kernel(key, buflen, (struct sockaddr_un *)addr, len, sockaddr_get->opt_4);
    if (memcmp(p+buflen, CANARY_STR, CANARY_LEN) != 0) {
      char *c1 = quote_string(NULL, CANARY_STR, CANARY_LEN);
      char *c2 = quote_string(NULL, p+buflen, CANARY_LEN);
      fprintf(stderr, "%s : canary modified.  %s -> %s\n", key, c1, c2);
      free(c1);
      free(c2);
    }
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
