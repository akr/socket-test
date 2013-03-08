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
  return strcmp(ep1->name, ep2->name);
}

int main(int argc, char *argv[])
{
  int num_errno = iconst_count(iconst_errno);
  errno_info_t *errno_ary = xmalloc(sizeof(errno_info_t) * num_errno);
  int i, j;

  (void)argc;
  (void)argv;

  j = 0;
  for (i = 0; i < iconst_numents; i++)
    if (iconst_table[i].purpose == iconst_errno) {
      errno_ary[j].name = iconst_table[i].name;
      errno_ary[j].num = iconst_table[i].val;
      j++;
    }
  qsort(errno_ary, num_errno, sizeof(errno_info_t), errno_cmp);

  for (i = 0; i < num_errno; i++) {
    int err = errno_ary[i].num;
    const char *str = errno_ary[i].name;
    printf("%s = %d\n", str, err);
  }

  return EXIT_SUCCESS;
}
