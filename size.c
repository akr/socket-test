#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(int argc, char *argv[])
{
  struct sockaddr_un sun;

  printf("sizeof(struct sockaddr_un) = %d\n", sizeof(struct sockaddr_un));
  printf("sizeof(struct sockaddr_un.sun_family) = %d\n", sizeof(sun.sun_family));
  printf("sizeof(struct sockaddr_un.sun_path) = %d\n", sizeof(sun.sun_path));
  printf("offsetof(struct sockaddr_un, sun_family) = %d\n", offsetof(struct sockaddr_un, sun_family));
  printf("offsetof(struct sockaddr_un, sun_path) = %d\n", offsetof(struct sockaddr_un, sun_path));

  return EXIT_SUCCESS;
}
