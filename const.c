/* errsym.c is generated from errsym.erb. */



#include "sockettest.h"

int main(int argc, char *argv[])
{
#ifdef AF_UNSPEC
  printf("%s: %ld\n", "AF_UNSPEC", (long)AF_UNSPEC);
#endif
#ifdef PF_UNSPEC
  printf("%s: %ld\n", "PF_UNSPEC", (long)PF_UNSPEC);
#endif
#ifdef AF_UNIX
  printf("%s: %ld\n", "AF_UNIX", (long)AF_UNIX);
#endif
#ifdef PF_UNIX
  printf("%s: %ld\n", "PF_UNIX", (long)PF_UNIX);
#endif
#ifdef AF_INET
  printf("%s: %ld\n", "AF_INET", (long)AF_INET);
#endif
#ifdef PF_INET
  printf("%s: %ld\n", "PF_INET", (long)PF_INET);
#endif
#ifdef AF_INET6
  printf("%s: %ld\n", "AF_INET6", (long)AF_INET6);
#endif
#ifdef PF_INET6
  printf("%s: %ld\n", "PF_INET6", (long)PF_INET6);
#endif
#ifdef SOCK_STREAM
  printf("%s: %ld\n", "SOCK_STREAM", (long)SOCK_STREAM);
#endif
#ifdef SOCK_DGRAM
  printf("%s: %ld\n", "SOCK_DGRAM", (long)SOCK_DGRAM);
#endif
#ifdef SOCK_SEQPACKET
  printf("%s: %ld\n", "SOCK_SEQPACKET", (long)SOCK_SEQPACKET);
#endif
#ifdef SOMAXCONN
  printf("%s: %ld\n", "SOMAXCONN", (long)SOMAXCONN);
#endif
#ifdef NAME_MAX
  printf("%s: %ld\n", "NAME_MAX", (long)NAME_MAX);
#endif
#ifdef PATH_MAX
  printf("%s: %ld\n", "PATH_MAX", (long)PATH_MAX);
#endif
#ifdef SYMLOOP_MAX
  printf("%s: %ld\n", "SYMLOOP_MAX", (long)SYMLOOP_MAX);
#endif
#ifdef EXIT_SUCCESS
  printf("%s: %ld\n", "EXIT_SUCCESS", (long)EXIT_SUCCESS);
#endif
#ifdef EXIT_FAILURE
  printf("%s: %ld\n", "EXIT_FAILURE", (long)EXIT_FAILURE);
#endif

  return EXIT_SUCCESS;
}

