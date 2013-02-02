#include "sockettest.h"

void *xmalloc(size_t size)
{
  void *p;
  p = malloc(size);
  if (p == NULL) {
    perror2("malloc");
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
    perror2("realloc");
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

void buffer_add_mem(buffer_t *buf, void *mem, size_t size)
{
  if (buf->bufsize - buf->len < size) {
    while (buf->bufsize - buf->len < size) {
      buf->bufsize *= 2;
    }
    buf->ptr = xrealloc(buf->ptr, buf->bufsize);
  }

  memcpy(buf->ptr + buf->len, mem, size);
  buf->len += size;
  return;
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
#define COPY_AND_RETURN(str) do { strcpy(buf, str); return sizeof(str)-1; } while (0)
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
      if (10 < num_repeat * elem_len) {
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
  if (!isdigit(*p)) return NULL;
  s = p++;
  while (p < pend && isdigit(*p))
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

void unlink_socket(char *path)
{
  int ret;
  struct stat statbuf;

  if (path[0] == '\0')
    return;

  ret = stat(path, &statbuf);
  if (ret == -1)
    return;

  if (S_ISSOCK(statbuf.st_mode))
    unlink(path);
}

void perror2(const char *s)
{
  int err = errno;
  char *sep, *sym;
  if (s)
    sep = ": ";
  else
    s = sep = "";
  sym = errsym(err);
  if (sym)
    fprintf(stderr, "%s%s%s (%s)\n", s, sep, strerror(err), sym);
  else
    fprintf(stderr, "%s%s%s (errno=%d)\n", s, sep, strerror(err), err);
}
