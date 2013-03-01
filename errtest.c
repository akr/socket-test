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

void list_errors(void)
{
  int min, max;
  int ret;
  int i;

  ret = errno_minmax(&min, &max);
  if (ret == -1) return;

#ifdef HAVE_SYS_NERR
  printf("sys_nerr = %d\n", sys_nerr);
#endif
  printf("errno_min = %d\n", min);
  printf("errno_max = %d\n", max);

  for (i = min; i <= max; i++) {
    char *sym = errsym(i);
    char *msg;
    errno = 0;
    msg = strerror(i);
    if (msg && !errno) {
      if (sym)
        printf("%s = %s\n", sym, msg);
      else
        printf("%d = %s\n", i, msg);
    }
  }
}

int main(int argc, char *argv[])
{
  int i;

  if (argc <= 1) {
    list_errors();
    return EXIT_SUCCESS;
  }

  for (i = 1; i < argc; i++) {
    int n = atoi(argv[i]);
    char *sym, *msg;
    int strerror_err;
    sym = errsym(n);
    errno = 0;
    msg = strerror(n);
    strerror_err = errno;
    if (sym)
      if (msg)
        if (!strerror_err)
          printf("%s = %s\n", sym, msg);
        else
          printf("%s = %s (strerror sets errno as %d)\n", sym, msg, strerror_err);
      else
        if (!strerror_err)
          printf("%s = strerror returns NULL but doesn't set errno.\n", sym);
        else
          printf("%s = strerror returns NULL and sets errno as %d.\n", sym, strerror_err);
    else
      if (msg)
        if (!strerror_err)
          printf("%d = %s\n", n, msg);
        else
          printf("%d = %s (strerror sets errno as %d)\n", n, msg, strerror_err);
      else
        if (!strerror_err)
          printf("%d = strerror returns NULL but doesn't set errno.\n", n);
        else
          printf("%d = strerror returns NULL and sets errno as %d.\n", n, strerror_err);
  }

  return EXIT_SUCCESS;
}

