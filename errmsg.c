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

typedef struct {
  const char *name;
  int num;
} errno_info_t;

static int errno_cmp(const void *vp1, const void *vp2)
{
  const errno_info_t *ep1 = vp1;
  const errno_info_t *ep2 = vp2;
  int ne1 = ep1->name[0] != 'E';
  int ne2 = ep2->name[0] != 'E';
  if (ne1 != ne2) {
    if (ne1 < ne2)
      return -1;
    else
      return 1;
  }
  return strcmp(ep1->name, ep2->name);
}

void show_errsyms(void)
{
  int num_errno = intconst_count(intconst_errno);
  errno_info_t *errno_ary = xmalloc(sizeof(errno_info_t) * num_errno);
  int i, j;

  j = 0;
  for (i = 0; i < num_integer_constants; i++)
    if (internal_integer_constant[i].purpose == intconst_errno) {
      errno_ary[j].name = internal_integer_constant[i].str;
      errno_ary[j].num = internal_integer_constant[i].num;
      j++;
    }
  qsort(errno_ary, num_errno, sizeof(errno_info_t), errno_cmp);

  for (i = 0; i < num_errno; i++) {
    int err = errno_ary[i].num;
    const char *str = errno_ary[i].name;
    printf("%s = %s\n", str, strerror(err));
  }
}

void show_zero(void)
{
  char *msg;
  msg = strerror(0);
  if (msg)
    printf("0 = %s\n", msg);
}

void func(int errcand, void *arg)
{
  char *sym = errsym(errcand);
  char *msg;
  if (sym)
    return;
  errno = 0;
  msg = strerror(errcand);
  if (msg && !errno) {
    /*
     * strerror() return value for unknown errors:
     * - GNU/Linux: "Unknown error NNN"
     * - NetBSD: "Unknown error: NNN"
     * - Minix: "Undefined error: NNN"
     * - SunOS: "Error NNN"
     * - Haiku:
     *   "Unknown General Error (-NNNNNNNNNN)"
     *   "Unknown OS Error (-NNNNNNNNNN)"
     *   "Unknown MIME type"
     *   "Unknown Application Kit Error (-NNNNNNNNNN)"
     *   "Unknown Interface Kit Error (-NNNNNNNNNN)"
     *   "Unknown Media Kit Error (-NNNNNNNNNN)"
     *   "Unknown Translation Kit Error (-NNNNNNNNNN)"
     *   "Unknown Midi Kit Error (-NNNNNNNNNN)"
     *   "Unknown Storage Kit Error (-NNNNNNNNNN)"
     *   "Unknown POSIX Error (-NNNNNNNNNN)"
     *   "No Error (NNN)"
     */
#define START_WITH(prefix) (strncmp(msg, (prefix), sizeof(prefix)-1) == 0)
    if (START_WITH("Unknown ") ||
        START_WITH("No Error (") ||
        START_WITH("Error ") ||
        START_WITH("Undefined "))
      return;
#undef START_WITH
    printf("%d = %s\n", errcand, msg);
  }
}


int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  show_errsyms();

  show_zero();

  errno_candidate_each(func, NULL);

  return EXIT_SUCCESS;
}
