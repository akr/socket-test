# Copyright (C) 2013 Tanaka Akira  <akr@fsij.org>
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
#  1. Redistributions of source code must retain the above copyright notice, this
#     list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright notice,
#     this list of conditions and the following disclaimer in the documentation
#     and/or other materials provided with the distribution.
#  3. The name of the author may not be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
# EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
# OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
# OF SUCH DAMAGE.

AC_PREREQ(2.61)
AC_INIT(socket-test, 0.1)
AC_CONFIG_SRCDIR([unix-stream.c])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

# Checks for programs.
AC_PROG_CC

# Features this program uses:
#
# - struct msghdr.msg_control
#   SunOS defines it for XPG4v2 programs (_XOPEN_SOURCE and _XOPEN_SOURCE_EXTENDED).
# - struct sockaddr_storage
#   Minix defines it for SUS programs (_XOPEN_SOURCE >= 500).
# - S_ISSOCK
#   Minix defines it for POSIX2001 or SUSv3 programs (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600).
#
# Note:
# - FreeBSD 9.1 overrides _POSIX_C_SOURCE if _XOPEN_SOURCE is defined.
# - OpenBSD 5.2 overrides _POSIX_C_SOURCE if _XOPEN_SOURCE is defined.
# - PureDarwin 9.8.0 defines PF_UNIX using AF_LOCAL but AF_LOCAL is defined only if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE).
#
AS_CASE([$host],
[*-solaris*], [
  AC_DEFINE(_XOPEN_SOURCE, [500], [This program uses SUSv2 (1997) features.])
  AC_DEFINE(_POSIX_C_SOURCE, [200112L], [This program uses POSIX 2001 features.])
],
[*-minix*], [
  AC_DEFINE(_XOPEN_SOURCE, [500], [This program uses SUSv2 (1997) features.])
])

# Determine a compiler mode.
AC_USE_SYSTEM_EXTENSIONS
AC_DEFINE(__USE_BSD, [1], [Declare sys_nerr by stdio.h in glibc.])

# Checks for libraries.
AC_CHECK_LIB([xnet], [socketpair]) # SunOS.  cf. libxnet(3LIB) and standards(5)
AC_CHECK_LIB([network], [socketpair]) # Haiku.

# Checks for header files.

SOCKETTEST_INCLUDES="AC_INCLUDES_DEFAULT"

AH_TEMPLATE([HAVE_STDARG_H], [Define to 1 if you have the <stdarg.h> header file.])
AH_TEMPLATE([HAVE_LIMITS_H], [Define to 1 if you have the <limits.h> header file.])
AH_TEMPLATE([HAVE_ERRNO_H], [Define to 1 if you have the <errno.h> header file.])
AH_TEMPLATE([HAVE_CTYPE_H], [Define to 1 if you have the <ctype.h> header file.])
AH_TEMPLATE([HAVE_FLOAT_H], [Define to 1 if you have the <float.h> header file.])
AH_TEMPLATE([HAVE_TIME_H], [Define to 1 if you have the <time.h> header file.])
AH_TEMPLATE([HAVE_SIGNAL_H], [Define to 1 if you have the <signal.h> header file.])
AH_TEMPLATE([HAVE_SYS_WAIT_H], [Define to 1 if you have the <sys/wait.h> header file.])
AH_TEMPLATE([HAVE_SYS_UIO_H], [Define to 1 if you have the <sys/uio.h> header file.])
AH_TEMPLATE([HAVE_SYS_SOCKET_H], [Define to 1 if you have the <sys/socket.h> header file.])
AH_TEMPLATE([HAVE_SYS_UN_H], [Define to 1 if you have the <sys/un.h> header file.])
AH_TEMPLATE([HAVE_NETINET_IN_H], [Define to 1 if you have the <netinet/in.h> header file.])
# Minix 3.2.0: limits.h is required for sys/socket.h.
for h in \
  stdarg.h limits.h errno.h ctype.h float.h time.h signal.h \
  sys/wait.h sys/uio.h sys/socket.h sys/un.h netinet/in.h
do
  AC_CHECK_HEADERS([$h], [], [], [$SOCKETTEST_INCLUDES])
  SOCKETTEST_INCLUDES="$SOCKETTEST_INCLUDES
[#]ifdef AS_TR_CPP([HAVE_$h])
[#]  include <$h>
[#]endif
"
done

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

AC_CHECK_TYPES([sa_family_t], [], [], [$SOCKETTEST_INCLUDES])
AC_CHECK_TYPES([in_port_t], [], [], [$SOCKETTEST_INCLUDES])
AC_CHECK_TYPES([in_addr_t], [], [], [$SOCKETTEST_INCLUDES])

AC_CHECK_MEMBERS([struct sockaddr.sa_len], [], [], [$SOCKETTEST_INCLUDES])

# Checks for library functions.
AC_FUNC_STAT
AC_CHECK_FUNCS([memset socket])

# Checks for library variables.

AC_DEFUN([SOCKTEST_CHECK_SYS_NERR],
[AC_CACHE_CHECK([for sys_nerr], [socktest_cv_sys_nerr],
  [AC_LINK_IFELSE(
    [AC_LANG_PROGRAM(
      [[$SOCKETTEST_INCLUDES]],
      [[int var = sys_nerr;]])],
    [socktest_cv_sys_nerr=yes],
    [socktest_cv_sys_nerr=no])])
if test "x$socktest_cv_sys_nerr" = xyes; then
  AC_DEFINE([HAVE_SYS_NERR], [1],
            [Define to 1 if you have the "sys_nerr" variable.])
fi])
SOCKTEST_CHECK_SYS_NERR

# Output configure results.

AC_SUBST(SOCKETTEST_INCLUDES)

AC_CONFIG_FILES([compile.sh], [chmod +x compile.sh])
AC_CONFIG_FILES([link.sh], [chmod +x link.sh])
AC_CONFIG_FILES([includes.h])
AC_OUTPUT

