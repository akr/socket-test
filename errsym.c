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
#ifdef EADV
  if (err == EADV) { return "EADV"; } else
#endif
#ifdef EAFNOSUPPORT
  if (err == EAFNOSUPPORT) { return "EAFNOSUPPORT"; } else
#endif
#ifdef EAGAIN
  if (err == EAGAIN) { return "EAGAIN"; } else
#endif
#ifdef EALREADY
  if (err == EALREADY) { return "EALREADY"; } else
#endif
#ifdef EBADE
  if (err == EBADE) { return "EBADE"; } else
#endif
#ifdef EBADF
  if (err == EBADF) { return "EBADF"; } else
#endif
#ifdef EBADFD
  if (err == EBADFD) { return "EBADFD"; } else
#endif
#ifdef EBADMSG
  if (err == EBADMSG) { return "EBADMSG"; } else
#endif
#ifdef EBADR
  if (err == EBADR) { return "EBADR"; } else
#endif
#ifdef EBADRQC
  if (err == EBADRQC) { return "EBADRQC"; } else
#endif
#ifdef EBADSLT
  if (err == EBADSLT) { return "EBADSLT"; } else
#endif
#ifdef EBFONT
  if (err == EBFONT) { return "EBFONT"; } else
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
#ifdef ECHRNG
  if (err == ECHRNG) { return "ECHRNG"; } else
#endif
#ifdef ECOMM
  if (err == ECOMM) { return "ECOMM"; } else
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
#ifdef EDEADLOCK
  if (err == EDEADLOCK) { return "EDEADLOCK"; } else
#endif
#ifdef EDESTADDRREQ
  if (err == EDESTADDRREQ) { return "EDESTADDRREQ"; } else
#endif
#ifdef EDOM
  if (err == EDOM) { return "EDOM"; } else
#endif
#ifdef EDOTDOT
  if (err == EDOTDOT) { return "EDOTDOT"; } else
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
#ifdef EHOSTDOWN
  if (err == EHOSTDOWN) { return "EHOSTDOWN"; } else
#endif
#ifdef EHOSTUNREACH
  if (err == EHOSTUNREACH) { return "EHOSTUNREACH"; } else
#endif
#ifdef EHWPOISON
  if (err == EHWPOISON) { return "EHWPOISON"; } else
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
#ifdef EISNAM
  if (err == EISNAM) { return "EISNAM"; } else
#endif
#ifdef EKEYEXPIRED
  if (err == EKEYEXPIRED) { return "EKEYEXPIRED"; } else
#endif
#ifdef EKEYREJECTED
  if (err == EKEYREJECTED) { return "EKEYREJECTED"; } else
#endif
#ifdef EKEYREVOKED
  if (err == EKEYREVOKED) { return "EKEYREVOKED"; } else
#endif
#ifdef EL2HLT
  if (err == EL2HLT) { return "EL2HLT"; } else
#endif
#ifdef EL2NSYNC
  if (err == EL2NSYNC) { return "EL2NSYNC"; } else
#endif
#ifdef EL3HLT
  if (err == EL3HLT) { return "EL3HLT"; } else
#endif
#ifdef EL3RST
  if (err == EL3RST) { return "EL3RST"; } else
#endif
#ifdef ELIBACC
  if (err == ELIBACC) { return "ELIBACC"; } else
#endif
#ifdef ELIBBAD
  if (err == ELIBBAD) { return "ELIBBAD"; } else
#endif
#ifdef ELIBEXEC
  if (err == ELIBEXEC) { return "ELIBEXEC"; } else
#endif
#ifdef ELIBMAX
  if (err == ELIBMAX) { return "ELIBMAX"; } else
#endif
#ifdef ELIBSCN
  if (err == ELIBSCN) { return "ELIBSCN"; } else
#endif
#ifdef ELNRNG
  if (err == ELNRNG) { return "ELNRNG"; } else
#endif
#ifdef ELOOP
  if (err == ELOOP) { return "ELOOP"; } else
#endif
#ifdef EMEDIUMTYPE
  if (err == EMEDIUMTYPE) { return "EMEDIUMTYPE"; } else
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
#ifdef ENAVAIL
  if (err == ENAVAIL) { return "ENAVAIL"; } else
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
#ifdef ENOANO
  if (err == ENOANO) { return "ENOANO"; } else
#endif
#ifdef ENOBUFS
  if (err == ENOBUFS) { return "ENOBUFS"; } else
#endif
#ifdef ENOCSI
  if (err == ENOCSI) { return "ENOCSI"; } else
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
#ifdef ENOKEY
  if (err == ENOKEY) { return "ENOKEY"; } else
#endif
#ifdef ENOLCK
  if (err == ENOLCK) { return "ENOLCK"; } else
#endif
#ifdef ENOLINK
  if (err == ENOLINK) { return "ENOLINK"; } else
#endif
#ifdef ENOMEDIUM
  if (err == ENOMEDIUM) { return "ENOMEDIUM"; } else
#endif
#ifdef ENOMEM
  if (err == ENOMEM) { return "ENOMEM"; } else
#endif
#ifdef ENOMSG
  if (err == ENOMSG) { return "ENOMSG"; } else
#endif
#ifdef ENONET
  if (err == ENONET) { return "ENONET"; } else
#endif
#ifdef ENOPKG
  if (err == ENOPKG) { return "ENOPKG"; } else
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
#ifdef ENOTBLK
  if (err == ENOTBLK) { return "ENOTBLK"; } else
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
#ifdef ENOTNAM
  if (err == ENOTNAM) { return "ENOTNAM"; } else
#endif
#ifdef ENOTRECOVERABLE
  if (err == ENOTRECOVERABLE) { return "ENOTRECOVERABLE"; } else
#endif
#ifdef ENOTSOCK
  if (err == ENOTSOCK) { return "ENOTSOCK"; } else
#endif
#ifdef ENOTSUP
  if (err == ENOTSUP) { return "ENOTSUP"; } else
#endif
#ifdef ENOTTY
  if (err == ENOTTY) { return "ENOTTY"; } else
#endif
#ifdef ENOTUNIQ
  if (err == ENOTUNIQ) { return "ENOTUNIQ"; } else
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
#ifdef EPFNOSUPPORT
  if (err == EPFNOSUPPORT) { return "EPFNOSUPPORT"; } else
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
#ifdef EREMCHG
  if (err == EREMCHG) { return "EREMCHG"; } else
#endif
#ifdef EREMOTE
  if (err == EREMOTE) { return "EREMOTE"; } else
#endif
#ifdef EREMOTEIO
  if (err == EREMOTEIO) { return "EREMOTEIO"; } else
#endif
#ifdef ERESTART
  if (err == ERESTART) { return "ERESTART"; } else
#endif
#ifdef ERFKILL
  if (err == ERFKILL) { return "ERFKILL"; } else
#endif
#ifdef EROFS
  if (err == EROFS) { return "EROFS"; } else
#endif
#ifdef ESHUTDOWN
  if (err == ESHUTDOWN) { return "ESHUTDOWN"; } else
#endif
#ifdef ESOCKTNOSUPPORT
  if (err == ESOCKTNOSUPPORT) { return "ESOCKTNOSUPPORT"; } else
#endif
#ifdef ESPIPE
  if (err == ESPIPE) { return "ESPIPE"; } else
#endif
#ifdef ESRCH
  if (err == ESRCH) { return "ESRCH"; } else
#endif
#ifdef ESRMNT
  if (err == ESRMNT) { return "ESRMNT"; } else
#endif
#ifdef ESTALE
  if (err == ESTALE) { return "ESTALE"; } else
#endif
#ifdef ESTRPIPE
  if (err == ESTRPIPE) { return "ESTRPIPE"; } else
#endif
#ifdef ETIME
  if (err == ETIME) { return "ETIME"; } else
#endif
#ifdef ETIMEDOUT
  if (err == ETIMEDOUT) { return "ETIMEDOUT"; } else
#endif
#ifdef ETOOMANYREFS
  if (err == ETOOMANYREFS) { return "ETOOMANYREFS"; } else
#endif
#ifdef ETXTBSY
  if (err == ETXTBSY) { return "ETXTBSY"; } else
#endif
#ifdef EUCLEAN
  if (err == EUCLEAN) { return "EUCLEAN"; } else
#endif
#ifdef EUNATCH
  if (err == EUNATCH) { return "EUNATCH"; } else
#endif
#ifdef EUSERS
  if (err == EUSERS) { return "EUSERS"; } else
#endif
#ifdef EWOULDBLOCK
  if (err == EWOULDBLOCK) { return "EWOULDBLOCK"; } else
#endif
#ifdef EXDEV
  if (err == EXDEV) { return "EXDEV"; } else
#endif
#ifdef EXFULL
  if (err == EXFULL) { return "EXFULL"; } else
#endif
  return NULL;
}

/* returns 0 on success, -1 on failure. */
int errno_minmax(int *minp, int *maxp)
{
  int min = 0, max = 0;
  int defined = 0;
#ifdef HAVE_SYS_NERR
  min = 1;
  max = sys_nerr - 1;
  defined = 1;
#endif

#ifdef E2BIG
  if (!defined) {
    defined = 1;
    min = max = E2BIG;
  }
  else {
    if (E2BIG < min) min = E2BIG;
    if (max < E2BIG) max = E2BIG;
  }
#endif
#ifdef EACCES
  if (!defined) {
    defined = 1;
    min = max = EACCES;
  }
  else {
    if (EACCES < min) min = EACCES;
    if (max < EACCES) max = EACCES;
  }
#endif
#ifdef EADDRINUSE
  if (!defined) {
    defined = 1;
    min = max = EADDRINUSE;
  }
  else {
    if (EADDRINUSE < min) min = EADDRINUSE;
    if (max < EADDRINUSE) max = EADDRINUSE;
  }
#endif
#ifdef EADDRNOTAVAIL
  if (!defined) {
    defined = 1;
    min = max = EADDRNOTAVAIL;
  }
  else {
    if (EADDRNOTAVAIL < min) min = EADDRNOTAVAIL;
    if (max < EADDRNOTAVAIL) max = EADDRNOTAVAIL;
  }
#endif
#ifdef EADV
  if (!defined) {
    defined = 1;
    min = max = EADV;
  }
  else {
    if (EADV < min) min = EADV;
    if (max < EADV) max = EADV;
  }
#endif
#ifdef EAFNOSUPPORT
  if (!defined) {
    defined = 1;
    min = max = EAFNOSUPPORT;
  }
  else {
    if (EAFNOSUPPORT < min) min = EAFNOSUPPORT;
    if (max < EAFNOSUPPORT) max = EAFNOSUPPORT;
  }
#endif
#ifdef EAGAIN
  if (!defined) {
    defined = 1;
    min = max = EAGAIN;
  }
  else {
    if (EAGAIN < min) min = EAGAIN;
    if (max < EAGAIN) max = EAGAIN;
  }
#endif
#ifdef EALREADY
  if (!defined) {
    defined = 1;
    min = max = EALREADY;
  }
  else {
    if (EALREADY < min) min = EALREADY;
    if (max < EALREADY) max = EALREADY;
  }
#endif
#ifdef EBADE
  if (!defined) {
    defined = 1;
    min = max = EBADE;
  }
  else {
    if (EBADE < min) min = EBADE;
    if (max < EBADE) max = EBADE;
  }
#endif
#ifdef EBADF
  if (!defined) {
    defined = 1;
    min = max = EBADF;
  }
  else {
    if (EBADF < min) min = EBADF;
    if (max < EBADF) max = EBADF;
  }
#endif
#ifdef EBADFD
  if (!defined) {
    defined = 1;
    min = max = EBADFD;
  }
  else {
    if (EBADFD < min) min = EBADFD;
    if (max < EBADFD) max = EBADFD;
  }
#endif
#ifdef EBADMSG
  if (!defined) {
    defined = 1;
    min = max = EBADMSG;
  }
  else {
    if (EBADMSG < min) min = EBADMSG;
    if (max < EBADMSG) max = EBADMSG;
  }
#endif
#ifdef EBADR
  if (!defined) {
    defined = 1;
    min = max = EBADR;
  }
  else {
    if (EBADR < min) min = EBADR;
    if (max < EBADR) max = EBADR;
  }
#endif
#ifdef EBADRQC
  if (!defined) {
    defined = 1;
    min = max = EBADRQC;
  }
  else {
    if (EBADRQC < min) min = EBADRQC;
    if (max < EBADRQC) max = EBADRQC;
  }
#endif
#ifdef EBADSLT
  if (!defined) {
    defined = 1;
    min = max = EBADSLT;
  }
  else {
    if (EBADSLT < min) min = EBADSLT;
    if (max < EBADSLT) max = EBADSLT;
  }
#endif
#ifdef EBFONT
  if (!defined) {
    defined = 1;
    min = max = EBFONT;
  }
  else {
    if (EBFONT < min) min = EBFONT;
    if (max < EBFONT) max = EBFONT;
  }
#endif
#ifdef EBUSY
  if (!defined) {
    defined = 1;
    min = max = EBUSY;
  }
  else {
    if (EBUSY < min) min = EBUSY;
    if (max < EBUSY) max = EBUSY;
  }
#endif
#ifdef ECANCELED
  if (!defined) {
    defined = 1;
    min = max = ECANCELED;
  }
  else {
    if (ECANCELED < min) min = ECANCELED;
    if (max < ECANCELED) max = ECANCELED;
  }
#endif
#ifdef ECHILD
  if (!defined) {
    defined = 1;
    min = max = ECHILD;
  }
  else {
    if (ECHILD < min) min = ECHILD;
    if (max < ECHILD) max = ECHILD;
  }
#endif
#ifdef ECHRNG
  if (!defined) {
    defined = 1;
    min = max = ECHRNG;
  }
  else {
    if (ECHRNG < min) min = ECHRNG;
    if (max < ECHRNG) max = ECHRNG;
  }
#endif
#ifdef ECOMM
  if (!defined) {
    defined = 1;
    min = max = ECOMM;
  }
  else {
    if (ECOMM < min) min = ECOMM;
    if (max < ECOMM) max = ECOMM;
  }
#endif
#ifdef ECONNABORTED
  if (!defined) {
    defined = 1;
    min = max = ECONNABORTED;
  }
  else {
    if (ECONNABORTED < min) min = ECONNABORTED;
    if (max < ECONNABORTED) max = ECONNABORTED;
  }
#endif
#ifdef ECONNREFUSED
  if (!defined) {
    defined = 1;
    min = max = ECONNREFUSED;
  }
  else {
    if (ECONNREFUSED < min) min = ECONNREFUSED;
    if (max < ECONNREFUSED) max = ECONNREFUSED;
  }
#endif
#ifdef ECONNRESET
  if (!defined) {
    defined = 1;
    min = max = ECONNRESET;
  }
  else {
    if (ECONNRESET < min) min = ECONNRESET;
    if (max < ECONNRESET) max = ECONNRESET;
  }
#endif
#ifdef EDEADLK
  if (!defined) {
    defined = 1;
    min = max = EDEADLK;
  }
  else {
    if (EDEADLK < min) min = EDEADLK;
    if (max < EDEADLK) max = EDEADLK;
  }
#endif
#ifdef EDEADLOCK
  if (!defined) {
    defined = 1;
    min = max = EDEADLOCK;
  }
  else {
    if (EDEADLOCK < min) min = EDEADLOCK;
    if (max < EDEADLOCK) max = EDEADLOCK;
  }
#endif
#ifdef EDESTADDRREQ
  if (!defined) {
    defined = 1;
    min = max = EDESTADDRREQ;
  }
  else {
    if (EDESTADDRREQ < min) min = EDESTADDRREQ;
    if (max < EDESTADDRREQ) max = EDESTADDRREQ;
  }
#endif
#ifdef EDOM
  if (!defined) {
    defined = 1;
    min = max = EDOM;
  }
  else {
    if (EDOM < min) min = EDOM;
    if (max < EDOM) max = EDOM;
  }
#endif
#ifdef EDOTDOT
  if (!defined) {
    defined = 1;
    min = max = EDOTDOT;
  }
  else {
    if (EDOTDOT < min) min = EDOTDOT;
    if (max < EDOTDOT) max = EDOTDOT;
  }
#endif
#ifdef EDQUOT
  if (!defined) {
    defined = 1;
    min = max = EDQUOT;
  }
  else {
    if (EDQUOT < min) min = EDQUOT;
    if (max < EDQUOT) max = EDQUOT;
  }
#endif
#ifdef EEXIST
  if (!defined) {
    defined = 1;
    min = max = EEXIST;
  }
  else {
    if (EEXIST < min) min = EEXIST;
    if (max < EEXIST) max = EEXIST;
  }
#endif
#ifdef EFAULT
  if (!defined) {
    defined = 1;
    min = max = EFAULT;
  }
  else {
    if (EFAULT < min) min = EFAULT;
    if (max < EFAULT) max = EFAULT;
  }
#endif
#ifdef EFBIG
  if (!defined) {
    defined = 1;
    min = max = EFBIG;
  }
  else {
    if (EFBIG < min) min = EFBIG;
    if (max < EFBIG) max = EFBIG;
  }
#endif
#ifdef EHOSTDOWN
  if (!defined) {
    defined = 1;
    min = max = EHOSTDOWN;
  }
  else {
    if (EHOSTDOWN < min) min = EHOSTDOWN;
    if (max < EHOSTDOWN) max = EHOSTDOWN;
  }
#endif
#ifdef EHOSTUNREACH
  if (!defined) {
    defined = 1;
    min = max = EHOSTUNREACH;
  }
  else {
    if (EHOSTUNREACH < min) min = EHOSTUNREACH;
    if (max < EHOSTUNREACH) max = EHOSTUNREACH;
  }
#endif
#ifdef EHWPOISON
  if (!defined) {
    defined = 1;
    min = max = EHWPOISON;
  }
  else {
    if (EHWPOISON < min) min = EHWPOISON;
    if (max < EHWPOISON) max = EHWPOISON;
  }
#endif
#ifdef EIDRM
  if (!defined) {
    defined = 1;
    min = max = EIDRM;
  }
  else {
    if (EIDRM < min) min = EIDRM;
    if (max < EIDRM) max = EIDRM;
  }
#endif
#ifdef EILSEQ
  if (!defined) {
    defined = 1;
    min = max = EILSEQ;
  }
  else {
    if (EILSEQ < min) min = EILSEQ;
    if (max < EILSEQ) max = EILSEQ;
  }
#endif
#ifdef EINPROGRESS
  if (!defined) {
    defined = 1;
    min = max = EINPROGRESS;
  }
  else {
    if (EINPROGRESS < min) min = EINPROGRESS;
    if (max < EINPROGRESS) max = EINPROGRESS;
  }
#endif
#ifdef EINTR
  if (!defined) {
    defined = 1;
    min = max = EINTR;
  }
  else {
    if (EINTR < min) min = EINTR;
    if (max < EINTR) max = EINTR;
  }
#endif
#ifdef EINVAL
  if (!defined) {
    defined = 1;
    min = max = EINVAL;
  }
  else {
    if (EINVAL < min) min = EINVAL;
    if (max < EINVAL) max = EINVAL;
  }
#endif
#ifdef EIO
  if (!defined) {
    defined = 1;
    min = max = EIO;
  }
  else {
    if (EIO < min) min = EIO;
    if (max < EIO) max = EIO;
  }
#endif
#ifdef EISCONN
  if (!defined) {
    defined = 1;
    min = max = EISCONN;
  }
  else {
    if (EISCONN < min) min = EISCONN;
    if (max < EISCONN) max = EISCONN;
  }
#endif
#ifdef EISDIR
  if (!defined) {
    defined = 1;
    min = max = EISDIR;
  }
  else {
    if (EISDIR < min) min = EISDIR;
    if (max < EISDIR) max = EISDIR;
  }
#endif
#ifdef EISNAM
  if (!defined) {
    defined = 1;
    min = max = EISNAM;
  }
  else {
    if (EISNAM < min) min = EISNAM;
    if (max < EISNAM) max = EISNAM;
  }
#endif
#ifdef EKEYEXPIRED
  if (!defined) {
    defined = 1;
    min = max = EKEYEXPIRED;
  }
  else {
    if (EKEYEXPIRED < min) min = EKEYEXPIRED;
    if (max < EKEYEXPIRED) max = EKEYEXPIRED;
  }
#endif
#ifdef EKEYREJECTED
  if (!defined) {
    defined = 1;
    min = max = EKEYREJECTED;
  }
  else {
    if (EKEYREJECTED < min) min = EKEYREJECTED;
    if (max < EKEYREJECTED) max = EKEYREJECTED;
  }
#endif
#ifdef EKEYREVOKED
  if (!defined) {
    defined = 1;
    min = max = EKEYREVOKED;
  }
  else {
    if (EKEYREVOKED < min) min = EKEYREVOKED;
    if (max < EKEYREVOKED) max = EKEYREVOKED;
  }
#endif
#ifdef EL2HLT
  if (!defined) {
    defined = 1;
    min = max = EL2HLT;
  }
  else {
    if (EL2HLT < min) min = EL2HLT;
    if (max < EL2HLT) max = EL2HLT;
  }
#endif
#ifdef EL2NSYNC
  if (!defined) {
    defined = 1;
    min = max = EL2NSYNC;
  }
  else {
    if (EL2NSYNC < min) min = EL2NSYNC;
    if (max < EL2NSYNC) max = EL2NSYNC;
  }
#endif
#ifdef EL3HLT
  if (!defined) {
    defined = 1;
    min = max = EL3HLT;
  }
  else {
    if (EL3HLT < min) min = EL3HLT;
    if (max < EL3HLT) max = EL3HLT;
  }
#endif
#ifdef EL3RST
  if (!defined) {
    defined = 1;
    min = max = EL3RST;
  }
  else {
    if (EL3RST < min) min = EL3RST;
    if (max < EL3RST) max = EL3RST;
  }
#endif
#ifdef ELIBACC
  if (!defined) {
    defined = 1;
    min = max = ELIBACC;
  }
  else {
    if (ELIBACC < min) min = ELIBACC;
    if (max < ELIBACC) max = ELIBACC;
  }
#endif
#ifdef ELIBBAD
  if (!defined) {
    defined = 1;
    min = max = ELIBBAD;
  }
  else {
    if (ELIBBAD < min) min = ELIBBAD;
    if (max < ELIBBAD) max = ELIBBAD;
  }
#endif
#ifdef ELIBEXEC
  if (!defined) {
    defined = 1;
    min = max = ELIBEXEC;
  }
  else {
    if (ELIBEXEC < min) min = ELIBEXEC;
    if (max < ELIBEXEC) max = ELIBEXEC;
  }
#endif
#ifdef ELIBMAX
  if (!defined) {
    defined = 1;
    min = max = ELIBMAX;
  }
  else {
    if (ELIBMAX < min) min = ELIBMAX;
    if (max < ELIBMAX) max = ELIBMAX;
  }
#endif
#ifdef ELIBSCN
  if (!defined) {
    defined = 1;
    min = max = ELIBSCN;
  }
  else {
    if (ELIBSCN < min) min = ELIBSCN;
    if (max < ELIBSCN) max = ELIBSCN;
  }
#endif
#ifdef ELNRNG
  if (!defined) {
    defined = 1;
    min = max = ELNRNG;
  }
  else {
    if (ELNRNG < min) min = ELNRNG;
    if (max < ELNRNG) max = ELNRNG;
  }
#endif
#ifdef ELOOP
  if (!defined) {
    defined = 1;
    min = max = ELOOP;
  }
  else {
    if (ELOOP < min) min = ELOOP;
    if (max < ELOOP) max = ELOOP;
  }
#endif
#ifdef EMEDIUMTYPE
  if (!defined) {
    defined = 1;
    min = max = EMEDIUMTYPE;
  }
  else {
    if (EMEDIUMTYPE < min) min = EMEDIUMTYPE;
    if (max < EMEDIUMTYPE) max = EMEDIUMTYPE;
  }
#endif
#ifdef EMFILE
  if (!defined) {
    defined = 1;
    min = max = EMFILE;
  }
  else {
    if (EMFILE < min) min = EMFILE;
    if (max < EMFILE) max = EMFILE;
  }
#endif
#ifdef EMLINK
  if (!defined) {
    defined = 1;
    min = max = EMLINK;
  }
  else {
    if (EMLINK < min) min = EMLINK;
    if (max < EMLINK) max = EMLINK;
  }
#endif
#ifdef EMSGSIZE
  if (!defined) {
    defined = 1;
    min = max = EMSGSIZE;
  }
  else {
    if (EMSGSIZE < min) min = EMSGSIZE;
    if (max < EMSGSIZE) max = EMSGSIZE;
  }
#endif
#ifdef EMULTIHOP
  if (!defined) {
    defined = 1;
    min = max = EMULTIHOP;
  }
  else {
    if (EMULTIHOP < min) min = EMULTIHOP;
    if (max < EMULTIHOP) max = EMULTIHOP;
  }
#endif
#ifdef ENAMETOOLONG
  if (!defined) {
    defined = 1;
    min = max = ENAMETOOLONG;
  }
  else {
    if (ENAMETOOLONG < min) min = ENAMETOOLONG;
    if (max < ENAMETOOLONG) max = ENAMETOOLONG;
  }
#endif
#ifdef ENAVAIL
  if (!defined) {
    defined = 1;
    min = max = ENAVAIL;
  }
  else {
    if (ENAVAIL < min) min = ENAVAIL;
    if (max < ENAVAIL) max = ENAVAIL;
  }
#endif
#ifdef ENETDOWN
  if (!defined) {
    defined = 1;
    min = max = ENETDOWN;
  }
  else {
    if (ENETDOWN < min) min = ENETDOWN;
    if (max < ENETDOWN) max = ENETDOWN;
  }
#endif
#ifdef ENETRESET
  if (!defined) {
    defined = 1;
    min = max = ENETRESET;
  }
  else {
    if (ENETRESET < min) min = ENETRESET;
    if (max < ENETRESET) max = ENETRESET;
  }
#endif
#ifdef ENETUNREACH
  if (!defined) {
    defined = 1;
    min = max = ENETUNREACH;
  }
  else {
    if (ENETUNREACH < min) min = ENETUNREACH;
    if (max < ENETUNREACH) max = ENETUNREACH;
  }
#endif
#ifdef ENFILE
  if (!defined) {
    defined = 1;
    min = max = ENFILE;
  }
  else {
    if (ENFILE < min) min = ENFILE;
    if (max < ENFILE) max = ENFILE;
  }
#endif
#ifdef ENOANO
  if (!defined) {
    defined = 1;
    min = max = ENOANO;
  }
  else {
    if (ENOANO < min) min = ENOANO;
    if (max < ENOANO) max = ENOANO;
  }
#endif
#ifdef ENOBUFS
  if (!defined) {
    defined = 1;
    min = max = ENOBUFS;
  }
  else {
    if (ENOBUFS < min) min = ENOBUFS;
    if (max < ENOBUFS) max = ENOBUFS;
  }
#endif
#ifdef ENOCSI
  if (!defined) {
    defined = 1;
    min = max = ENOCSI;
  }
  else {
    if (ENOCSI < min) min = ENOCSI;
    if (max < ENOCSI) max = ENOCSI;
  }
#endif
#ifdef ENODATA
  if (!defined) {
    defined = 1;
    min = max = ENODATA;
  }
  else {
    if (ENODATA < min) min = ENODATA;
    if (max < ENODATA) max = ENODATA;
  }
#endif
#ifdef ENODEV
  if (!defined) {
    defined = 1;
    min = max = ENODEV;
  }
  else {
    if (ENODEV < min) min = ENODEV;
    if (max < ENODEV) max = ENODEV;
  }
#endif
#ifdef ENOENT
  if (!defined) {
    defined = 1;
    min = max = ENOENT;
  }
  else {
    if (ENOENT < min) min = ENOENT;
    if (max < ENOENT) max = ENOENT;
  }
#endif
#ifdef ENOEXEC
  if (!defined) {
    defined = 1;
    min = max = ENOEXEC;
  }
  else {
    if (ENOEXEC < min) min = ENOEXEC;
    if (max < ENOEXEC) max = ENOEXEC;
  }
#endif
#ifdef ENOKEY
  if (!defined) {
    defined = 1;
    min = max = ENOKEY;
  }
  else {
    if (ENOKEY < min) min = ENOKEY;
    if (max < ENOKEY) max = ENOKEY;
  }
#endif
#ifdef ENOLCK
  if (!defined) {
    defined = 1;
    min = max = ENOLCK;
  }
  else {
    if (ENOLCK < min) min = ENOLCK;
    if (max < ENOLCK) max = ENOLCK;
  }
#endif
#ifdef ENOLINK
  if (!defined) {
    defined = 1;
    min = max = ENOLINK;
  }
  else {
    if (ENOLINK < min) min = ENOLINK;
    if (max < ENOLINK) max = ENOLINK;
  }
#endif
#ifdef ENOMEDIUM
  if (!defined) {
    defined = 1;
    min = max = ENOMEDIUM;
  }
  else {
    if (ENOMEDIUM < min) min = ENOMEDIUM;
    if (max < ENOMEDIUM) max = ENOMEDIUM;
  }
#endif
#ifdef ENOMEM
  if (!defined) {
    defined = 1;
    min = max = ENOMEM;
  }
  else {
    if (ENOMEM < min) min = ENOMEM;
    if (max < ENOMEM) max = ENOMEM;
  }
#endif
#ifdef ENOMSG
  if (!defined) {
    defined = 1;
    min = max = ENOMSG;
  }
  else {
    if (ENOMSG < min) min = ENOMSG;
    if (max < ENOMSG) max = ENOMSG;
  }
#endif
#ifdef ENONET
  if (!defined) {
    defined = 1;
    min = max = ENONET;
  }
  else {
    if (ENONET < min) min = ENONET;
    if (max < ENONET) max = ENONET;
  }
#endif
#ifdef ENOPKG
  if (!defined) {
    defined = 1;
    min = max = ENOPKG;
  }
  else {
    if (ENOPKG < min) min = ENOPKG;
    if (max < ENOPKG) max = ENOPKG;
  }
#endif
#ifdef ENOPROTOOPT
  if (!defined) {
    defined = 1;
    min = max = ENOPROTOOPT;
  }
  else {
    if (ENOPROTOOPT < min) min = ENOPROTOOPT;
    if (max < ENOPROTOOPT) max = ENOPROTOOPT;
  }
#endif
#ifdef ENOSPC
  if (!defined) {
    defined = 1;
    min = max = ENOSPC;
  }
  else {
    if (ENOSPC < min) min = ENOSPC;
    if (max < ENOSPC) max = ENOSPC;
  }
#endif
#ifdef ENOSR
  if (!defined) {
    defined = 1;
    min = max = ENOSR;
  }
  else {
    if (ENOSR < min) min = ENOSR;
    if (max < ENOSR) max = ENOSR;
  }
#endif
#ifdef ENOSTR
  if (!defined) {
    defined = 1;
    min = max = ENOSTR;
  }
  else {
    if (ENOSTR < min) min = ENOSTR;
    if (max < ENOSTR) max = ENOSTR;
  }
#endif
#ifdef ENOSYS
  if (!defined) {
    defined = 1;
    min = max = ENOSYS;
  }
  else {
    if (ENOSYS < min) min = ENOSYS;
    if (max < ENOSYS) max = ENOSYS;
  }
#endif
#ifdef ENOTBLK
  if (!defined) {
    defined = 1;
    min = max = ENOTBLK;
  }
  else {
    if (ENOTBLK < min) min = ENOTBLK;
    if (max < ENOTBLK) max = ENOTBLK;
  }
#endif
#ifdef ENOTCONN
  if (!defined) {
    defined = 1;
    min = max = ENOTCONN;
  }
  else {
    if (ENOTCONN < min) min = ENOTCONN;
    if (max < ENOTCONN) max = ENOTCONN;
  }
#endif
#ifdef ENOTDIR
  if (!defined) {
    defined = 1;
    min = max = ENOTDIR;
  }
  else {
    if (ENOTDIR < min) min = ENOTDIR;
    if (max < ENOTDIR) max = ENOTDIR;
  }
#endif
#ifdef ENOTEMPTY
  if (!defined) {
    defined = 1;
    min = max = ENOTEMPTY;
  }
  else {
    if (ENOTEMPTY < min) min = ENOTEMPTY;
    if (max < ENOTEMPTY) max = ENOTEMPTY;
  }
#endif
#ifdef ENOTNAM
  if (!defined) {
    defined = 1;
    min = max = ENOTNAM;
  }
  else {
    if (ENOTNAM < min) min = ENOTNAM;
    if (max < ENOTNAM) max = ENOTNAM;
  }
#endif
#ifdef ENOTRECOVERABLE
  if (!defined) {
    defined = 1;
    min = max = ENOTRECOVERABLE;
  }
  else {
    if (ENOTRECOVERABLE < min) min = ENOTRECOVERABLE;
    if (max < ENOTRECOVERABLE) max = ENOTRECOVERABLE;
  }
#endif
#ifdef ENOTSOCK
  if (!defined) {
    defined = 1;
    min = max = ENOTSOCK;
  }
  else {
    if (ENOTSOCK < min) min = ENOTSOCK;
    if (max < ENOTSOCK) max = ENOTSOCK;
  }
#endif
#ifdef ENOTSUP
  if (!defined) {
    defined = 1;
    min = max = ENOTSUP;
  }
  else {
    if (ENOTSUP < min) min = ENOTSUP;
    if (max < ENOTSUP) max = ENOTSUP;
  }
#endif
#ifdef ENOTTY
  if (!defined) {
    defined = 1;
    min = max = ENOTTY;
  }
  else {
    if (ENOTTY < min) min = ENOTTY;
    if (max < ENOTTY) max = ENOTTY;
  }
#endif
#ifdef ENOTUNIQ
  if (!defined) {
    defined = 1;
    min = max = ENOTUNIQ;
  }
  else {
    if (ENOTUNIQ < min) min = ENOTUNIQ;
    if (max < ENOTUNIQ) max = ENOTUNIQ;
  }
#endif
#ifdef ENXIO
  if (!defined) {
    defined = 1;
    min = max = ENXIO;
  }
  else {
    if (ENXIO < min) min = ENXIO;
    if (max < ENXIO) max = ENXIO;
  }
#endif
#ifdef EOPNOTSUPP
  if (!defined) {
    defined = 1;
    min = max = EOPNOTSUPP;
  }
  else {
    if (EOPNOTSUPP < min) min = EOPNOTSUPP;
    if (max < EOPNOTSUPP) max = EOPNOTSUPP;
  }
#endif
#ifdef EOVERFLOW
  if (!defined) {
    defined = 1;
    min = max = EOVERFLOW;
  }
  else {
    if (EOVERFLOW < min) min = EOVERFLOW;
    if (max < EOVERFLOW) max = EOVERFLOW;
  }
#endif
#ifdef EOWNERDEAD
  if (!defined) {
    defined = 1;
    min = max = EOWNERDEAD;
  }
  else {
    if (EOWNERDEAD < min) min = EOWNERDEAD;
    if (max < EOWNERDEAD) max = EOWNERDEAD;
  }
#endif
#ifdef EPERM
  if (!defined) {
    defined = 1;
    min = max = EPERM;
  }
  else {
    if (EPERM < min) min = EPERM;
    if (max < EPERM) max = EPERM;
  }
#endif
#ifdef EPFNOSUPPORT
  if (!defined) {
    defined = 1;
    min = max = EPFNOSUPPORT;
  }
  else {
    if (EPFNOSUPPORT < min) min = EPFNOSUPPORT;
    if (max < EPFNOSUPPORT) max = EPFNOSUPPORT;
  }
#endif
#ifdef EPIPE
  if (!defined) {
    defined = 1;
    min = max = EPIPE;
  }
  else {
    if (EPIPE < min) min = EPIPE;
    if (max < EPIPE) max = EPIPE;
  }
#endif
#ifdef EPROTO
  if (!defined) {
    defined = 1;
    min = max = EPROTO;
  }
  else {
    if (EPROTO < min) min = EPROTO;
    if (max < EPROTO) max = EPROTO;
  }
#endif
#ifdef EPROTONOSUPPORT
  if (!defined) {
    defined = 1;
    min = max = EPROTONOSUPPORT;
  }
  else {
    if (EPROTONOSUPPORT < min) min = EPROTONOSUPPORT;
    if (max < EPROTONOSUPPORT) max = EPROTONOSUPPORT;
  }
#endif
#ifdef EPROTOTYPE
  if (!defined) {
    defined = 1;
    min = max = EPROTOTYPE;
  }
  else {
    if (EPROTOTYPE < min) min = EPROTOTYPE;
    if (max < EPROTOTYPE) max = EPROTOTYPE;
  }
#endif
#ifdef ERANGE
  if (!defined) {
    defined = 1;
    min = max = ERANGE;
  }
  else {
    if (ERANGE < min) min = ERANGE;
    if (max < ERANGE) max = ERANGE;
  }
#endif
#ifdef EREMCHG
  if (!defined) {
    defined = 1;
    min = max = EREMCHG;
  }
  else {
    if (EREMCHG < min) min = EREMCHG;
    if (max < EREMCHG) max = EREMCHG;
  }
#endif
#ifdef EREMOTE
  if (!defined) {
    defined = 1;
    min = max = EREMOTE;
  }
  else {
    if (EREMOTE < min) min = EREMOTE;
    if (max < EREMOTE) max = EREMOTE;
  }
#endif
#ifdef EREMOTEIO
  if (!defined) {
    defined = 1;
    min = max = EREMOTEIO;
  }
  else {
    if (EREMOTEIO < min) min = EREMOTEIO;
    if (max < EREMOTEIO) max = EREMOTEIO;
  }
#endif
#ifdef ERESTART
  if (!defined) {
    defined = 1;
    min = max = ERESTART;
  }
  else {
    if (ERESTART < min) min = ERESTART;
    if (max < ERESTART) max = ERESTART;
  }
#endif
#ifdef ERFKILL
  if (!defined) {
    defined = 1;
    min = max = ERFKILL;
  }
  else {
    if (ERFKILL < min) min = ERFKILL;
    if (max < ERFKILL) max = ERFKILL;
  }
#endif
#ifdef EROFS
  if (!defined) {
    defined = 1;
    min = max = EROFS;
  }
  else {
    if (EROFS < min) min = EROFS;
    if (max < EROFS) max = EROFS;
  }
#endif
#ifdef ESHUTDOWN
  if (!defined) {
    defined = 1;
    min = max = ESHUTDOWN;
  }
  else {
    if (ESHUTDOWN < min) min = ESHUTDOWN;
    if (max < ESHUTDOWN) max = ESHUTDOWN;
  }
#endif
#ifdef ESOCKTNOSUPPORT
  if (!defined) {
    defined = 1;
    min = max = ESOCKTNOSUPPORT;
  }
  else {
    if (ESOCKTNOSUPPORT < min) min = ESOCKTNOSUPPORT;
    if (max < ESOCKTNOSUPPORT) max = ESOCKTNOSUPPORT;
  }
#endif
#ifdef ESPIPE
  if (!defined) {
    defined = 1;
    min = max = ESPIPE;
  }
  else {
    if (ESPIPE < min) min = ESPIPE;
    if (max < ESPIPE) max = ESPIPE;
  }
#endif
#ifdef ESRCH
  if (!defined) {
    defined = 1;
    min = max = ESRCH;
  }
  else {
    if (ESRCH < min) min = ESRCH;
    if (max < ESRCH) max = ESRCH;
  }
#endif
#ifdef ESRMNT
  if (!defined) {
    defined = 1;
    min = max = ESRMNT;
  }
  else {
    if (ESRMNT < min) min = ESRMNT;
    if (max < ESRMNT) max = ESRMNT;
  }
#endif
#ifdef ESTALE
  if (!defined) {
    defined = 1;
    min = max = ESTALE;
  }
  else {
    if (ESTALE < min) min = ESTALE;
    if (max < ESTALE) max = ESTALE;
  }
#endif
#ifdef ESTRPIPE
  if (!defined) {
    defined = 1;
    min = max = ESTRPIPE;
  }
  else {
    if (ESTRPIPE < min) min = ESTRPIPE;
    if (max < ESTRPIPE) max = ESTRPIPE;
  }
#endif
#ifdef ETIME
  if (!defined) {
    defined = 1;
    min = max = ETIME;
  }
  else {
    if (ETIME < min) min = ETIME;
    if (max < ETIME) max = ETIME;
  }
#endif
#ifdef ETIMEDOUT
  if (!defined) {
    defined = 1;
    min = max = ETIMEDOUT;
  }
  else {
    if (ETIMEDOUT < min) min = ETIMEDOUT;
    if (max < ETIMEDOUT) max = ETIMEDOUT;
  }
#endif
#ifdef ETOOMANYREFS
  if (!defined) {
    defined = 1;
    min = max = ETOOMANYREFS;
  }
  else {
    if (ETOOMANYREFS < min) min = ETOOMANYREFS;
    if (max < ETOOMANYREFS) max = ETOOMANYREFS;
  }
#endif
#ifdef ETXTBSY
  if (!defined) {
    defined = 1;
    min = max = ETXTBSY;
  }
  else {
    if (ETXTBSY < min) min = ETXTBSY;
    if (max < ETXTBSY) max = ETXTBSY;
  }
#endif
#ifdef EUCLEAN
  if (!defined) {
    defined = 1;
    min = max = EUCLEAN;
  }
  else {
    if (EUCLEAN < min) min = EUCLEAN;
    if (max < EUCLEAN) max = EUCLEAN;
  }
#endif
#ifdef EUNATCH
  if (!defined) {
    defined = 1;
    min = max = EUNATCH;
  }
  else {
    if (EUNATCH < min) min = EUNATCH;
    if (max < EUNATCH) max = EUNATCH;
  }
#endif
#ifdef EUSERS
  if (!defined) {
    defined = 1;
    min = max = EUSERS;
  }
  else {
    if (EUSERS < min) min = EUSERS;
    if (max < EUSERS) max = EUSERS;
  }
#endif
#ifdef EWOULDBLOCK
  if (!defined) {
    defined = 1;
    min = max = EWOULDBLOCK;
  }
  else {
    if (EWOULDBLOCK < min) min = EWOULDBLOCK;
    if (max < EWOULDBLOCK) max = EWOULDBLOCK;
  }
#endif
#ifdef EXDEV
  if (!defined) {
    defined = 1;
    min = max = EXDEV;
  }
  else {
    if (EXDEV < min) min = EXDEV;
    if (max < EXDEV) max = EXDEV;
  }
#endif
#ifdef EXFULL
  if (!defined) {
    defined = 1;
    min = max = EXFULL;
  }
  else {
    if (EXFULL < min) min = EXFULL;
    if (max < EXFULL) max = EXFULL;
  }
#endif
  if (defined) {
    *minp = min;
    *maxp = max;
    return 0;
  }
  else {
    return -1;
  }
}

