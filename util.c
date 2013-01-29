#include "sockettest.h"

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

size_t measure_escaped_string(char *unescaped_ptr, size_t unescaped_len)
{
  size_t i;
  size_t len = 0;
  for (i = 0; i < unescaped_len; i++) {
    int ch = (unsigned char)unescaped_ptr[i];
    char buf[ESCAPED_SINGLE_CHAR_MAXLEN];
    len += escape_sequence(buf, sizeof(buf), ch);
  }
  return len;
}

/* return -1 on error */
ssize_t measure_unescaped_string(char *escaped_ptr, size_t escaped_len)
{
  ssize_t len = 0;
  char *p, *pend;
  p = escaped_ptr;
  pend = escaped_ptr + escaped_len;
  while (p < pend) {
    size_t used_len;
    int ch = unescape_sequence(&used_len, p, pend - p);
    if (ch == -1)
      return -1;
    p += used_len;
    len++;
  }
  return len;
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
  size_t len;
  char *ptr, *p;
  size_t i;

  len = measure_escaped_string(unescaped_ptr, unescaped_len);
  ptr = malloc(len+1);
  if (ptr == NULL) {
    return NULL;
  }

  p = ptr;
  for (i = 0; i < unescaped_len; i++) {
    int ch = (unsigned char)unescaped_ptr[i];
    size_t chsize;
    chsize = escape_sequence(p, ptr + len - p, ch);
    p += chsize;
  }
  ptr[len] = '\0';
  if (escaped_len_ret) {
    *escaped_len_ret = len;
  }
  return ptr;
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
  ssize_t len;
  char *p, *pend;
  char *result, *rp;

  len = measure_unescaped_string(escaped_ptr, escaped_len);
  result = malloc(len+1);
  if (result == NULL) {
    return NULL;
  }

  p = escaped_ptr;
  pend = escaped_ptr + escaped_len;
  rp = result;
  while (p < pend) {
    size_t used_len;
    int ch = unescape_sequence(&used_len, p, pend - p);
    if (ch == -1) {
      free(result);
      return NULL;
    }
    p += used_len;
    *rp++ = ch;
  }
  result[len] = '\0';
  *unescaped_len_ret = (size_t)len;
  return result;
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

