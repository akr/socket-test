/* errsym.c is generated from errsym.erb. */

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

#ifdef PRIuMAX
#  define SHOW_POSITIVE_INTEGER(name, num) \
     printf("%s = %"PRIuMAX" (%d bytes)\n", name, (uintmax_t)num, (int)sizeof(num))
#else
#  define SHOW_POSITIVE_INTEGER(name, num) \
     printf("%s = %lu (%d bytes)\n", name, (unsigned long)num, (int)sizeof(num))
#endif

#ifdef PRIdMAX
#  define SHOW_NEGATIVE_INTEGER(name, num) \
     printf("%s = %"PRIdMAX" (%d bytes)\n", name, (intmax_t)num, (int)sizeof(num))
#else
#  define SHOW_POSITIVE_INTEGER(name, num) \
     printf("%s = %ld (%d bytes)\n", name, (long)num, (int)sizeof(num))
#endif

int main(int argc, char *argv[])
{
#ifdef AF_UNSPEC
  if (0 <= AF_UNSPEC)
    SHOW_POSITIVE_INTEGER("AF_UNSPEC", AF_UNSPEC);
  else
    SHOW_NEGATIVE_INTEGER("AF_UNSPEC", AF_UNSPEC);
#endif
#ifdef PF_UNSPEC
  if (0 <= PF_UNSPEC)
    SHOW_POSITIVE_INTEGER("PF_UNSPEC", PF_UNSPEC);
  else
    SHOW_NEGATIVE_INTEGER("PF_UNSPEC", PF_UNSPEC);
#endif
#ifdef AF_UNIX
  if (0 <= AF_UNIX)
    SHOW_POSITIVE_INTEGER("AF_UNIX", AF_UNIX);
  else
    SHOW_NEGATIVE_INTEGER("AF_UNIX", AF_UNIX);
#endif
#ifdef PF_UNIX
  if (0 <= PF_UNIX)
    SHOW_POSITIVE_INTEGER("PF_UNIX", PF_UNIX);
  else
    SHOW_NEGATIVE_INTEGER("PF_UNIX", PF_UNIX);
#endif
#ifdef AF_INET
  if (0 <= AF_INET)
    SHOW_POSITIVE_INTEGER("AF_INET", AF_INET);
  else
    SHOW_NEGATIVE_INTEGER("AF_INET", AF_INET);
#endif
#ifdef PF_INET
  if (0 <= PF_INET)
    SHOW_POSITIVE_INTEGER("PF_INET", PF_INET);
  else
    SHOW_NEGATIVE_INTEGER("PF_INET", PF_INET);
#endif
#ifdef AF_INET6
  if (0 <= AF_INET6)
    SHOW_POSITIVE_INTEGER("AF_INET6", AF_INET6);
  else
    SHOW_NEGATIVE_INTEGER("AF_INET6", AF_INET6);
#endif
#ifdef PF_INET6
  if (0 <= PF_INET6)
    SHOW_POSITIVE_INTEGER("PF_INET6", PF_INET6);
  else
    SHOW_NEGATIVE_INTEGER("PF_INET6", PF_INET6);
#endif
#ifdef SOCK_STREAM
  if (0 <= SOCK_STREAM)
    SHOW_POSITIVE_INTEGER("SOCK_STREAM", SOCK_STREAM);
  else
    SHOW_NEGATIVE_INTEGER("SOCK_STREAM", SOCK_STREAM);
#endif
#ifdef SOCK_DGRAM
  if (0 <= SOCK_DGRAM)
    SHOW_POSITIVE_INTEGER("SOCK_DGRAM", SOCK_DGRAM);
  else
    SHOW_NEGATIVE_INTEGER("SOCK_DGRAM", SOCK_DGRAM);
#endif
#ifdef SOCK_SEQPACKET
  if (0 <= SOCK_SEQPACKET)
    SHOW_POSITIVE_INTEGER("SOCK_SEQPACKET", SOCK_SEQPACKET);
  else
    SHOW_NEGATIVE_INTEGER("SOCK_SEQPACKET", SOCK_SEQPACKET);
#endif
#ifdef SOMAXCONN
  if (0 <= SOMAXCONN)
    SHOW_POSITIVE_INTEGER("SOMAXCONN", SOMAXCONN);
  else
    SHOW_NEGATIVE_INTEGER("SOMAXCONN", SOMAXCONN);
#endif
#ifdef NAME_MAX
  if (0 <= NAME_MAX)
    SHOW_POSITIVE_INTEGER("NAME_MAX", NAME_MAX);
  else
    SHOW_NEGATIVE_INTEGER("NAME_MAX", NAME_MAX);
#endif
#ifdef PATH_MAX
  if (0 <= PATH_MAX)
    SHOW_POSITIVE_INTEGER("PATH_MAX", PATH_MAX);
  else
    SHOW_NEGATIVE_INTEGER("PATH_MAX", PATH_MAX);
#endif
#ifdef SYMLOOP_MAX
  if (0 <= SYMLOOP_MAX)
    SHOW_POSITIVE_INTEGER("SYMLOOP_MAX", SYMLOOP_MAX);
  else
    SHOW_NEGATIVE_INTEGER("SYMLOOP_MAX", SYMLOOP_MAX);
#endif
#ifdef EXIT_SUCCESS
  if (0 <= EXIT_SUCCESS)
    SHOW_POSITIVE_INTEGER("EXIT_SUCCESS", EXIT_SUCCESS);
  else
    SHOW_NEGATIVE_INTEGER("EXIT_SUCCESS", EXIT_SUCCESS);
#endif
#ifdef EXIT_FAILURE
  if (0 <= EXIT_FAILURE)
    SHOW_POSITIVE_INTEGER("EXIT_FAILURE", EXIT_FAILURE);
  else
    SHOW_NEGATIVE_INTEGER("EXIT_FAILURE", EXIT_FAILURE);
#endif
#ifdef CHAR_BIT
  if (0 <= CHAR_BIT)
    SHOW_POSITIVE_INTEGER("CHAR_BIT", CHAR_BIT);
  else
    SHOW_NEGATIVE_INTEGER("CHAR_BIT", CHAR_BIT);
#endif
#ifdef SCHAR_MIN
  if (0 <= SCHAR_MIN)
    SHOW_POSITIVE_INTEGER("SCHAR_MIN", SCHAR_MIN);
  else
    SHOW_NEGATIVE_INTEGER("SCHAR_MIN", SCHAR_MIN);
#endif
#ifdef SCHAR_MAX
  if (0 <= SCHAR_MAX)
    SHOW_POSITIVE_INTEGER("SCHAR_MAX", SCHAR_MAX);
  else
    SHOW_NEGATIVE_INTEGER("SCHAR_MAX", SCHAR_MAX);
#endif
#ifdef UCHAR_MAX
  if (0 <= UCHAR_MAX)
    SHOW_POSITIVE_INTEGER("UCHAR_MAX", UCHAR_MAX);
  else
    SHOW_NEGATIVE_INTEGER("UCHAR_MAX", UCHAR_MAX);
#endif
#ifdef CHAR_MIN
  if (0 <= CHAR_MIN)
    SHOW_POSITIVE_INTEGER("CHAR_MIN", CHAR_MIN);
  else
    SHOW_NEGATIVE_INTEGER("CHAR_MIN", CHAR_MIN);
#endif
#ifdef CHAR_MAX
  if (0 <= CHAR_MAX)
    SHOW_POSITIVE_INTEGER("CHAR_MAX", CHAR_MAX);
  else
    SHOW_NEGATIVE_INTEGER("CHAR_MAX", CHAR_MAX);
#endif
#ifdef MB_LEN_MAX
  if (0 <= MB_LEN_MAX)
    SHOW_POSITIVE_INTEGER("MB_LEN_MAX", MB_LEN_MAX);
  else
    SHOW_NEGATIVE_INTEGER("MB_LEN_MAX", MB_LEN_MAX);
#endif
#ifdef SHRT_MIN
  if (0 <= SHRT_MIN)
    SHOW_POSITIVE_INTEGER("SHRT_MIN", SHRT_MIN);
  else
    SHOW_NEGATIVE_INTEGER("SHRT_MIN", SHRT_MIN);
#endif
#ifdef SHRT_MAX
  if (0 <= SHRT_MAX)
    SHOW_POSITIVE_INTEGER("SHRT_MAX", SHRT_MAX);
  else
    SHOW_NEGATIVE_INTEGER("SHRT_MAX", SHRT_MAX);
#endif
#ifdef USHRT_MAX
  if (0 <= USHRT_MAX)
    SHOW_POSITIVE_INTEGER("USHRT_MAX", USHRT_MAX);
  else
    SHOW_NEGATIVE_INTEGER("USHRT_MAX", USHRT_MAX);
#endif
#ifdef INT_MIN
  if (0 <= INT_MIN)
    SHOW_POSITIVE_INTEGER("INT_MIN", INT_MIN);
  else
    SHOW_NEGATIVE_INTEGER("INT_MIN", INT_MIN);
#endif
#ifdef INT_MAX
  if (0 <= INT_MAX)
    SHOW_POSITIVE_INTEGER("INT_MAX", INT_MAX);
  else
    SHOW_NEGATIVE_INTEGER("INT_MAX", INT_MAX);
#endif
#ifdef UINT_MAX
  if (0 <= UINT_MAX)
    SHOW_POSITIVE_INTEGER("UINT_MAX", UINT_MAX);
  else
    SHOW_NEGATIVE_INTEGER("UINT_MAX", UINT_MAX);
#endif
#ifdef LONG_MIN
  if (0 <= LONG_MIN)
    SHOW_POSITIVE_INTEGER("LONG_MIN", LONG_MIN);
  else
    SHOW_NEGATIVE_INTEGER("LONG_MIN", LONG_MIN);
#endif
#ifdef LONG_MAX
  if (0 <= LONG_MAX)
    SHOW_POSITIVE_INTEGER("LONG_MAX", LONG_MAX);
  else
    SHOW_NEGATIVE_INTEGER("LONG_MAX", LONG_MAX);
#endif
#ifdef ULONG_MAX
  if (0 <= ULONG_MAX)
    SHOW_POSITIVE_INTEGER("ULONG_MAX", ULONG_MAX);
  else
    SHOW_NEGATIVE_INTEGER("ULONG_MAX", ULONG_MAX);
#endif
#ifdef LLONG_MIN
  if (0 <= LLONG_MIN)
    SHOW_POSITIVE_INTEGER("LLONG_MIN", LLONG_MIN);
  else
    SHOW_NEGATIVE_INTEGER("LLONG_MIN", LLONG_MIN);
#endif
#ifdef LLONG_MAX
  if (0 <= LLONG_MAX)
    SHOW_POSITIVE_INTEGER("LLONG_MAX", LLONG_MAX);
  else
    SHOW_NEGATIVE_INTEGER("LLONG_MAX", LLONG_MAX);
#endif
#ifdef ULLONG_MAX
  if (0 <= ULLONG_MAX)
    SHOW_POSITIVE_INTEGER("ULLONG_MAX", ULLONG_MAX);
  else
    SHOW_NEGATIVE_INTEGER("ULLONG_MAX", ULLONG_MAX);
#endif
#ifdef FLT_RADIX
  if (0 <= FLT_RADIX)
    SHOW_POSITIVE_INTEGER("FLT_RADIX", FLT_RADIX);
  else
    SHOW_NEGATIVE_INTEGER("FLT_RADIX", FLT_RADIX);
#endif
#ifdef FLT_MANT_DIG
  if (0 <= FLT_MANT_DIG)
    SHOW_POSITIVE_INTEGER("FLT_MANT_DIG", FLT_MANT_DIG);
  else
    SHOW_NEGATIVE_INTEGER("FLT_MANT_DIG", FLT_MANT_DIG);
#endif
#ifdef DBL_MANT_DIG
  if (0 <= DBL_MANT_DIG)
    SHOW_POSITIVE_INTEGER("DBL_MANT_DIG", DBL_MANT_DIG);
  else
    SHOW_NEGATIVE_INTEGER("DBL_MANT_DIG", DBL_MANT_DIG);
#endif
#ifdef LDBL_MANT_DIG
  if (0 <= LDBL_MANT_DIG)
    SHOW_POSITIVE_INTEGER("LDBL_MANT_DIG", LDBL_MANT_DIG);
  else
    SHOW_NEGATIVE_INTEGER("LDBL_MANT_DIG", LDBL_MANT_DIG);
#endif
#ifdef DECIMAL_DIG
  if (0 <= DECIMAL_DIG)
    SHOW_POSITIVE_INTEGER("DECIMAL_DIG", DECIMAL_DIG);
  else
    SHOW_NEGATIVE_INTEGER("DECIMAL_DIG", DECIMAL_DIG);
#endif
#ifdef FLT_DIG
  if (0 <= FLT_DIG)
    SHOW_POSITIVE_INTEGER("FLT_DIG", FLT_DIG);
  else
    SHOW_NEGATIVE_INTEGER("FLT_DIG", FLT_DIG);
#endif
#ifdef DBL_DIG
  if (0 <= DBL_DIG)
    SHOW_POSITIVE_INTEGER("DBL_DIG", DBL_DIG);
  else
    SHOW_NEGATIVE_INTEGER("DBL_DIG", DBL_DIG);
#endif
#ifdef LDBL_DIG
  if (0 <= LDBL_DIG)
    SHOW_POSITIVE_INTEGER("LDBL_DIG", LDBL_DIG);
  else
    SHOW_NEGATIVE_INTEGER("LDBL_DIG", LDBL_DIG);
#endif
#ifdef FLT_MIN_EXP
  if (0 <= FLT_MIN_EXP)
    SHOW_POSITIVE_INTEGER("FLT_MIN_EXP", FLT_MIN_EXP);
  else
    SHOW_NEGATIVE_INTEGER("FLT_MIN_EXP", FLT_MIN_EXP);
#endif
#ifdef DBL_MIN_EXP
  if (0 <= DBL_MIN_EXP)
    SHOW_POSITIVE_INTEGER("DBL_MIN_EXP", DBL_MIN_EXP);
  else
    SHOW_NEGATIVE_INTEGER("DBL_MIN_EXP", DBL_MIN_EXP);
#endif
#ifdef LDBL_MIN_EXP
  if (0 <= LDBL_MIN_EXP)
    SHOW_POSITIVE_INTEGER("LDBL_MIN_EXP", LDBL_MIN_EXP);
  else
    SHOW_NEGATIVE_INTEGER("LDBL_MIN_EXP", LDBL_MIN_EXP);
#endif
#ifdef FLT_MIN_10_EXP
  if (0 <= FLT_MIN_10_EXP)
    SHOW_POSITIVE_INTEGER("FLT_MIN_10_EXP", FLT_MIN_10_EXP);
  else
    SHOW_NEGATIVE_INTEGER("FLT_MIN_10_EXP", FLT_MIN_10_EXP);
#endif
#ifdef DBL_MIN_10_EXP
  if (0 <= DBL_MIN_10_EXP)
    SHOW_POSITIVE_INTEGER("DBL_MIN_10_EXP", DBL_MIN_10_EXP);
  else
    SHOW_NEGATIVE_INTEGER("DBL_MIN_10_EXP", DBL_MIN_10_EXP);
#endif
#ifdef LDBL_MIN_10_EXP
  if (0 <= LDBL_MIN_10_EXP)
    SHOW_POSITIVE_INTEGER("LDBL_MIN_10_EXP", LDBL_MIN_10_EXP);
  else
    SHOW_NEGATIVE_INTEGER("LDBL_MIN_10_EXP", LDBL_MIN_10_EXP);
#endif
#ifdef FLT_MAX_EXP
  if (0 <= FLT_MAX_EXP)
    SHOW_POSITIVE_INTEGER("FLT_MAX_EXP", FLT_MAX_EXP);
  else
    SHOW_NEGATIVE_INTEGER("FLT_MAX_EXP", FLT_MAX_EXP);
#endif
#ifdef DBL_MAX_EXP
  if (0 <= DBL_MAX_EXP)
    SHOW_POSITIVE_INTEGER("DBL_MAX_EXP", DBL_MAX_EXP);
  else
    SHOW_NEGATIVE_INTEGER("DBL_MAX_EXP", DBL_MAX_EXP);
#endif
#ifdef LDBL_MAX_EXP
  if (0 <= LDBL_MAX_EXP)
    SHOW_POSITIVE_INTEGER("LDBL_MAX_EXP", LDBL_MAX_EXP);
  else
    SHOW_NEGATIVE_INTEGER("LDBL_MAX_EXP", LDBL_MAX_EXP);
#endif
#ifdef FLT_MAX_10_EXP
  if (0 <= FLT_MAX_10_EXP)
    SHOW_POSITIVE_INTEGER("FLT_MAX_10_EXP", FLT_MAX_10_EXP);
  else
    SHOW_NEGATIVE_INTEGER("FLT_MAX_10_EXP", FLT_MAX_10_EXP);
#endif
#ifdef DBL_MAX_10_EXP
  if (0 <= DBL_MAX_10_EXP)
    SHOW_POSITIVE_INTEGER("DBL_MAX_10_EXP", DBL_MAX_10_EXP);
  else
    SHOW_NEGATIVE_INTEGER("DBL_MAX_10_EXP", DBL_MAX_10_EXP);
#endif
#ifdef LDBL_MAX_10_EXP
  if (0 <= LDBL_MAX_10_EXP)
    SHOW_POSITIVE_INTEGER("LDBL_MAX_10_EXP", LDBL_MAX_10_EXP);
  else
    SHOW_NEGATIVE_INTEGER("LDBL_MAX_10_EXP", LDBL_MAX_10_EXP);
#endif

#ifdef FLT_MAX
  if (sizeof(FLT_MAX) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "FLT_MAX", LDBL_DIG, (long double)FLT_MAX, (int)sizeof(FLT_MAX));
  else if (sizeof(FLT_MAX) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "FLT_MAX", DBL_DIG, (double)FLT_MAX, (int)sizeof(FLT_MAX));
  else if (sizeof(FLT_MAX) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "FLT_MAX", FLT_DIG, (double)FLT_MAX, (int)sizeof(FLT_MAX));
  else
    printf("%s = %.*g (%d bytes)\n", "FLT_MAX", DBL_DIG, (double)FLT_MAX, (int)sizeof(FLT_MAX));
#endif
#ifdef DBL_MAX
  if (sizeof(DBL_MAX) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "DBL_MAX", LDBL_DIG, (long double)DBL_MAX, (int)sizeof(DBL_MAX));
  else if (sizeof(DBL_MAX) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "DBL_MAX", DBL_DIG, (double)DBL_MAX, (int)sizeof(DBL_MAX));
  else if (sizeof(DBL_MAX) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "DBL_MAX", FLT_DIG, (double)DBL_MAX, (int)sizeof(DBL_MAX));
  else
    printf("%s = %.*g (%d bytes)\n", "DBL_MAX", DBL_DIG, (double)DBL_MAX, (int)sizeof(DBL_MAX));
#endif
#ifdef LDBL_MAX
  if (sizeof(LDBL_MAX) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "LDBL_MAX", LDBL_DIG, (long double)LDBL_MAX, (int)sizeof(LDBL_MAX));
  else if (sizeof(LDBL_MAX) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "LDBL_MAX", DBL_DIG, (double)LDBL_MAX, (int)sizeof(LDBL_MAX));
  else if (sizeof(LDBL_MAX) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "LDBL_MAX", FLT_DIG, (double)LDBL_MAX, (int)sizeof(LDBL_MAX));
  else
    printf("%s = %.*g (%d bytes)\n", "LDBL_MAX", DBL_DIG, (double)LDBL_MAX, (int)sizeof(LDBL_MAX));
#endif
#ifdef FLT_EPSILON
  if (sizeof(FLT_EPSILON) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "FLT_EPSILON", LDBL_DIG, (long double)FLT_EPSILON, (int)sizeof(FLT_EPSILON));
  else if (sizeof(FLT_EPSILON) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "FLT_EPSILON", DBL_DIG, (double)FLT_EPSILON, (int)sizeof(FLT_EPSILON));
  else if (sizeof(FLT_EPSILON) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "FLT_EPSILON", FLT_DIG, (double)FLT_EPSILON, (int)sizeof(FLT_EPSILON));
  else
    printf("%s = %.*g (%d bytes)\n", "FLT_EPSILON", DBL_DIG, (double)FLT_EPSILON, (int)sizeof(FLT_EPSILON));
#endif
#ifdef DBL_EPSILON
  if (sizeof(DBL_EPSILON) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "DBL_EPSILON", LDBL_DIG, (long double)DBL_EPSILON, (int)sizeof(DBL_EPSILON));
  else if (sizeof(DBL_EPSILON) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "DBL_EPSILON", DBL_DIG, (double)DBL_EPSILON, (int)sizeof(DBL_EPSILON));
  else if (sizeof(DBL_EPSILON) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "DBL_EPSILON", FLT_DIG, (double)DBL_EPSILON, (int)sizeof(DBL_EPSILON));
  else
    printf("%s = %.*g (%d bytes)\n", "DBL_EPSILON", DBL_DIG, (double)DBL_EPSILON, (int)sizeof(DBL_EPSILON));
#endif
#ifdef LDBL_EPSILON
  if (sizeof(LDBL_EPSILON) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "LDBL_EPSILON", LDBL_DIG, (long double)LDBL_EPSILON, (int)sizeof(LDBL_EPSILON));
  else if (sizeof(LDBL_EPSILON) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "LDBL_EPSILON", DBL_DIG, (double)LDBL_EPSILON, (int)sizeof(LDBL_EPSILON));
  else if (sizeof(LDBL_EPSILON) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "LDBL_EPSILON", FLT_DIG, (double)LDBL_EPSILON, (int)sizeof(LDBL_EPSILON));
  else
    printf("%s = %.*g (%d bytes)\n", "LDBL_EPSILON", DBL_DIG, (double)LDBL_EPSILON, (int)sizeof(LDBL_EPSILON));
#endif
#ifdef FLT_MIN
  if (sizeof(FLT_MIN) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "FLT_MIN", LDBL_DIG, (long double)FLT_MIN, (int)sizeof(FLT_MIN));
  else if (sizeof(FLT_MIN) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "FLT_MIN", DBL_DIG, (double)FLT_MIN, (int)sizeof(FLT_MIN));
  else if (sizeof(FLT_MIN) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "FLT_MIN", FLT_DIG, (double)FLT_MIN, (int)sizeof(FLT_MIN));
  else
    printf("%s = %.*g (%d bytes)\n", "FLT_MIN", DBL_DIG, (double)FLT_MIN, (int)sizeof(FLT_MIN));
#endif
#ifdef DBL_MIN
  if (sizeof(DBL_MIN) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "DBL_MIN", LDBL_DIG, (long double)DBL_MIN, (int)sizeof(DBL_MIN));
  else if (sizeof(DBL_MIN) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "DBL_MIN", DBL_DIG, (double)DBL_MIN, (int)sizeof(DBL_MIN));
  else if (sizeof(DBL_MIN) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "DBL_MIN", FLT_DIG, (double)DBL_MIN, (int)sizeof(DBL_MIN));
  else
    printf("%s = %.*g (%d bytes)\n", "DBL_MIN", DBL_DIG, (double)DBL_MIN, (int)sizeof(DBL_MIN));
#endif
#ifdef LDBL_MIN
  if (sizeof(LDBL_MIN) == sizeof(long double))
    printf("%s = %.*Lg (%d bytes)\n", "LDBL_MIN", LDBL_DIG, (long double)LDBL_MIN, (int)sizeof(LDBL_MIN));
  else if (sizeof(LDBL_MIN) == sizeof(double))
    printf("%s = %.*g (%d bytes)\n", "LDBL_MIN", DBL_DIG, (double)LDBL_MIN, (int)sizeof(LDBL_MIN));
  else if (sizeof(LDBL_MIN) == sizeof(float))
    printf("%s = %.*g (%d bytes)\n", "LDBL_MIN", FLT_DIG, (double)LDBL_MIN, (int)sizeof(LDBL_MIN));
  else
    printf("%s = %.*g (%d bytes)\n", "LDBL_MIN", DBL_DIG, (double)LDBL_MIN, (int)sizeof(LDBL_MIN));
#endif

  return EXIT_SUCCESS;
}

