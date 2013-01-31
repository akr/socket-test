#include "sockettest.h"

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

#define ESCAPED_SINGLE_CHAR_MAXLEN 4

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
  size_t i;

  for (i = 0; i < unescaped_len; i++) {
    int ch = (unsigned char)unescaped_ptr[i];
    char chbuf[ESCAPED_SINGLE_CHAR_MAXLEN];
    size_t chsize;
    chsize = escape_sequence(chbuf, ESCAPED_SINGLE_CHAR_MAXLEN, ch);
    buffer_add_mem(buf, chbuf, chsize);
  }
  if (escaped_len_ret) {
    *escaped_len_ret = buf->len;
  }
  buffer_add_byte(buf, '\0');
  return buffer_unwrap(buf);
}

/*
 * Unescape a string (\t to TAB, etc.) pointed by _escaped_ptr_ with length _escaped_len_.
 * The result is stored in a buffer newly allcated by malloc.
 * The pointer to the allocated memory is returned and the length is stored in *unescaped_len_ret.
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
  while (p < pend) {
    size_t used_len;
    int ch = unescape_sequence(&used_len, p, pend - p);
    if (ch == -1) {
      buffer_free(buf);
      return NULL;
    }
    p += used_len;
    buffer_add_byte(buf, ch);
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

void *xmalloc(size_t size)
{
  void *p;
  p = malloc(size);
  if (p == NULL) {
    perror("malloc");
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
    perror("realloc");
    exit(EXIT_FAILURE);
  }
  return p;
}
