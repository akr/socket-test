#include "sockettest.h"

#define FIELD_SIZE(struct_name, field_name) sizeof(((struct_name *)0)->field_name)
static char *unix_path_str;
static size_t unix_path_len = 0;

static int opt_g = 0;

void usage(int status)
{
  fputs(
      "usage: bind-getsockname unix-socket-path\n"
      "option: -h : show this help message\n"
      "        -g N : increase buffer size of getsockname (negative to decrease)\n"
      , stdout);
  exit(status);
}

static void parse_args(int argc, char *argv[])
{
  int opt;
  char *escaped_unix_socket_path, *unescaped_unix_socket_path;
  size_t unescaped_unix_socket_path_len;

  while ((opt = getopt(argc, argv, "hg:")) != -1) {
    switch (opt) {
      case 'h':
        usage(EXIT_SUCCESS);
        break; /* not reached */

      case 'g':
        opt_g = atoi(optarg);
        break;

      default:
        exit(EXIT_FAILURE);
    }
  }
  if (argc <= optind) {
    fprintf(stderr, "needs a unix-socket-path argument\n");
    exit(EXIT_FAILURE);
  }
  escaped_unix_socket_path = argv[optind];
  unescaped_unix_socket_path = unescape_string(&unescaped_unix_socket_path_len, escaped_unix_socket_path, strlen(escaped_unix_socket_path));

  unix_path_str = unescaped_unix_socket_path;
  unix_path_len = unescaped_unix_socket_path_len;
}

static void unlink_socket(char *path)
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

static void test_bind_getsockname(void)
{
  int s, ret;
  struct sockaddr_un *a1;
  struct sockaddr_un *a2;
  socklen_t alen1, alen2;
  socklen_t alen;
  size_t len;
  char *escaped_unix_socket_path;
  int truncated;

  printf("sizeof(sun_path) = %d\n", (int)FIELD_SIZE(struct sockaddr_un, sun_path));

  alen1 = offsetof(struct sockaddr_un, sun_path) + unix_path_len;
  a1 = malloc(alen1);
  if (a1 == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  alen2 = sizeof(struct sockaddr_un) + opt_g;
  a2 = malloc(alen2);
  if (a1 == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  unlink_socket(unix_path_str);

  s = socket(AF_UNIX, SOCK_STREAM, 0);
  if (s == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset((void *)a1, '\0', alen1);
  a1->sun_family = AF_UNIX;
  memcpy(a1->sun_path, unix_path_str, unix_path_len);

  escaped_unix_socket_path = escape_string(NULL, unix_path_str, unix_path_len);
  printf("bind        : \"%s\" (%d bytes)\n", escaped_unix_socket_path, (int)unix_path_len);
  free(escaped_unix_socket_path);

  ret = bind(s, (const struct sockaddr *)a1, alen1);
  if (ret == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  alen = alen2;
  ret = getsockname(s, (struct sockaddr *)a2, &alen);
  if (ret == -1) {
    perror("getsockname");
    exit(EXIT_FAILURE);
  }

  truncated = 0;
  if (alen <= alen2) {
    truncated = 0;
    len = alen - offsetof(struct sockaddr_un, sun_path);
  }
  else {
    truncated = 1;
    len = alen2 - offsetof(struct sockaddr_un, sun_path);
  }

  escaped_unix_socket_path = escape_string(NULL, a2->sun_path, len);
  printf("getsockname : \"%s\"%s (%d bytes)\n", escaped_unix_socket_path, truncated ? "..." : "", (int)(alen - offsetof(struct sockaddr_un, sun_path)));
  free(escaped_unix_socket_path);

  unlink_socket(unix_path_str);
}

int main(int argc, char *argv[])
{
  parse_args(argc, argv);
  test_bind_getsockname();
  return EXIT_SUCCESS;
}
