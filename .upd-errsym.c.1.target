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

char *errsym(int err)
{
  if (err == EAGAIN) return "EAGAIN"; /* may be equal to EWOULDBLOCK */
  if (err == ENOTSUP) return "ENOTSUP"; /* may be equal to EOPNOTSUPP */

#ifdef E2BIG
  if (err == E2BIG) { return "E2BIG"; } else
#endif
#ifdef EACCES
  if (err == EACCES) { return "EACCES"; } else
#endif
#ifdef EADDRINUSE
  if (err == EADDRINUSE) { return "EADDRINUSE"; } else
#endif
#ifdef EADDRNOTAVAIL
  if (err == EADDRNOTAVAIL) { return "EADDRNOTAVAIL"; } else
#endif
#ifdef EAFNOSUPPORT
  if (err == EAFNOSUPPORT) { return "EAFNOSUPPORT"; } else
#endif
#ifdef EALREADY
  if (err == EALREADY) { return "EALREADY"; } else
#endif
#ifdef EBADF
  if (err == EBADF) { return "EBADF"; } else
#endif
#ifdef EBADMSG
  if (err == EBADMSG) { return "EBADMSG"; } else
#endif
#ifdef EBUSY
  if (err == EBUSY) { return "EBUSY"; } else
#endif
#ifdef ECANCELED
  if (err == ECANCELED) { return "ECANCELED"; } else
#endif
#ifdef ECHILD
  if (err == ECHILD) { return "ECHILD"; } else
#endif
#ifdef ECONNABORTED
  if (err == ECONNABORTED) { return "ECONNABORTED"; } else
#endif
#ifdef ECONNREFUSED
  if (err == ECONNREFUSED) { return "ECONNREFUSED"; } else
#endif
#ifdef ECONNRESET
  if (err == ECONNRESET) { return "ECONNRESET"; } else
#endif
#ifdef EDEADLK
  if (err == EDEADLK) { return "EDEADLK"; } else
#endif
#ifdef EDESTADDRREQ
  if (err == EDESTADDRREQ) { return "EDESTADDRREQ"; } else
#endif
#ifdef EDOM
  if (err == EDOM) { return "EDOM"; } else
#endif
#ifdef EDQUOT
  if (err == EDQUOT) { return "EDQUOT"; } else
#endif
#ifdef EEXIST
  if (err == EEXIST) { return "EEXIST"; } else
#endif
#ifdef EFAULT
  if (err == EFAULT) { return "EFAULT"; } else
#endif
#ifdef EFBIG
  if (err == EFBIG) { return "EFBIG"; } else
#endif
#ifdef EHOSTUNREACH
  if (err == EHOSTUNREACH) { return "EHOSTUNREACH"; } else
#endif
#ifdef EIDRM
  if (err == EIDRM) { return "EIDRM"; } else
#endif
#ifdef EILSEQ
  if (err == EILSEQ) { return "EILSEQ"; } else
#endif
#ifdef EINPROGRESS
  if (err == EINPROGRESS) { return "EINPROGRESS"; } else
#endif
#ifdef EINTR
  if (err == EINTR) { return "EINTR"; } else
#endif
#ifdef EINVAL
  if (err == EINVAL) { return "EINVAL"; } else
#endif
#ifdef EIO
  if (err == EIO) { return "EIO"; } else
#endif
#ifdef EISCONN
  if (err == EISCONN) { return "EISCONN"; } else
#endif
#ifdef EISDIR
  if (err == EISDIR) { return "EISDIR"; } else
#endif
#ifdef ELOOP
  if (err == ELOOP) { return "ELOOP"; } else
#endif
#ifdef EMFILE
  if (err == EMFILE) { return "EMFILE"; } else
#endif
#ifdef EMLINK
  if (err == EMLINK) { return "EMLINK"; } else
#endif
#ifdef EMSGSIZE
  if (err == EMSGSIZE) { return "EMSGSIZE"; } else
#endif
#ifdef EMULTIHOP
  if (err == EMULTIHOP) { return "EMULTIHOP"; } else
#endif
#ifdef ENAMETOOLONG
  if (err == ENAMETOOLONG) { return "ENAMETOOLONG"; } else
#endif
#ifdef ENETDOWN
  if (err == ENETDOWN) { return "ENETDOWN"; } else
#endif
#ifdef ENETRESET
  if (err == ENETRESET) { return "ENETRESET"; } else
#endif
#ifdef ENETUNREACH
  if (err == ENETUNREACH) { return "ENETUNREACH"; } else
#endif
#ifdef ENFILE
  if (err == ENFILE) { return "ENFILE"; } else
#endif
#ifdef ENOBUFS
  if (err == ENOBUFS) { return "ENOBUFS"; } else
#endif
#ifdef ENODATA
  if (err == ENODATA) { return "ENODATA"; } else
#endif
#ifdef ENODEV
  if (err == ENODEV) { return "ENODEV"; } else
#endif
#ifdef ENOENT
  if (err == ENOENT) { return "ENOENT"; } else
#endif
#ifdef ENOEXEC
  if (err == ENOEXEC) { return "ENOEXEC"; } else
#endif
#ifdef ENOLCK
  if (err == ENOLCK) { return "ENOLCK"; } else
#endif
#ifdef ENOLINK
  if (err == ENOLINK) { return "ENOLINK"; } else
#endif
#ifdef ENOMEM
  if (err == ENOMEM) { return "ENOMEM"; } else
#endif
#ifdef ENOMSG
  if (err == ENOMSG) { return "ENOMSG"; } else
#endif
#ifdef ENOPROTOOPT
  if (err == ENOPROTOOPT) { return "ENOPROTOOPT"; } else
#endif
#ifdef ENOSPC
  if (err == ENOSPC) { return "ENOSPC"; } else
#endif
#ifdef ENOSR
  if (err == ENOSR) { return "ENOSR"; } else
#endif
#ifdef ENOSTR
  if (err == ENOSTR) { return "ENOSTR"; } else
#endif
#ifdef ENOSYS
  if (err == ENOSYS) { return "ENOSYS"; } else
#endif
#ifdef ENOTCONN
  if (err == ENOTCONN) { return "ENOTCONN"; } else
#endif
#ifdef ENOTDIR
  if (err == ENOTDIR) { return "ENOTDIR"; } else
#endif
#ifdef ENOTEMPTY
  if (err == ENOTEMPTY) { return "ENOTEMPTY"; } else
#endif
#ifdef ENOTRECOVERABLE
  if (err == ENOTRECOVERABLE) { return "ENOTRECOVERABLE"; } else
#endif
#ifdef ENOTSOCK
  if (err == ENOTSOCK) { return "ENOTSOCK"; } else
#endif
#ifdef ENOTTY
  if (err == ENOTTY) { return "ENOTTY"; } else
#endif
#ifdef ENXIO
  if (err == ENXIO) { return "ENXIO"; } else
#endif
#ifdef EOPNOTSUPP
  if (err == EOPNOTSUPP) { return "EOPNOTSUPP"; } else
#endif
#ifdef EOVERFLOW
  if (err == EOVERFLOW) { return "EOVERFLOW"; } else
#endif
#ifdef EOWNERDEAD
  if (err == EOWNERDEAD) { return "EOWNERDEAD"; } else
#endif
#ifdef EPERM
  if (err == EPERM) { return "EPERM"; } else
#endif
#ifdef EPIPE
  if (err == EPIPE) { return "EPIPE"; } else
#endif
#ifdef EPROTO
  if (err == EPROTO) { return "EPROTO"; } else
#endif
#ifdef EPROTONOSUPPORT
  if (err == EPROTONOSUPPORT) { return "EPROTONOSUPPORT"; } else
#endif
#ifdef EPROTOTYPE
  if (err == EPROTOTYPE) { return "EPROTOTYPE"; } else
#endif
#ifdef ERANGE
  if (err == ERANGE) { return "ERANGE"; } else
#endif
#ifdef EROFS
  if (err == EROFS) { return "EROFS"; } else
#endif
#ifdef ESPIPE
  if (err == ESPIPE) { return "ESPIPE"; } else
#endif
#ifdef ESRCH
  if (err == ESRCH) { return "ESRCH"; } else
#endif
#ifdef ESTALE
  if (err == ESTALE) { return "ESTALE"; } else
#endif
#ifdef ETIME
  if (err == ETIME) { return "ETIME"; } else
#endif
#ifdef ETIMEDOUT
  if (err == ETIMEDOUT) { return "ETIMEDOUT"; } else
#endif
#ifdef ETXTBSY
  if (err == ETXTBSY) { return "ETXTBSY"; } else
#endif
#ifdef EWOULDBLOCK
  if (err == EWOULDBLOCK) { return "EWOULDBLOCK"; } else
#endif
#ifdef EXDEV
  if (err == EXDEV) { return "EXDEV"; } else
#endif
  return NULL;
}

