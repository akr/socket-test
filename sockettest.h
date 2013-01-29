#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>

char *escape_string(size_t *escaped_len_ret, char *unescaped_ptr, size_t unescaped_len);
char *unescape_string(size_t *unescaped_len_ret, char *escaped_ptr, size_t escaped_len);

