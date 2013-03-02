/* genutil.c is generated from genutil.erb. */

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
#ifdef EAGAIN
  if (err == EAGAIN) { return "EAGAIN"; } else
#endif
#ifdef ENOTSUP
  if (err == ENOTSUP) { return "ENOTSUP"; } else
#endif
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
#ifdef ENOTBLK
  if (err == ENOTBLK) { return "ENOTBLK"; } else
#endif
#ifdef ECHRNG
  if (err == ECHRNG) { return "ECHRNG"; } else
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
#ifdef ELNRNG
  if (err == ELNRNG) { return "ELNRNG"; } else
#endif
#ifdef EUNATCH
  if (err == EUNATCH) { return "EUNATCH"; } else
#endif
#ifdef ENOCSI
  if (err == ENOCSI) { return "ENOCSI"; } else
#endif
#ifdef EL2HLT
  if (err == EL2HLT) { return "EL2HLT"; } else
#endif
#ifdef EBADE
  if (err == EBADE) { return "EBADE"; } else
#endif
#ifdef EBADR
  if (err == EBADR) { return "EBADR"; } else
#endif
#ifdef EXFULL
  if (err == EXFULL) { return "EXFULL"; } else
#endif
#ifdef ENOANO
  if (err == ENOANO) { return "ENOANO"; } else
#endif
#ifdef EBADRQC
  if (err == EBADRQC) { return "EBADRQC"; } else
#endif
#ifdef EBADSLT
  if (err == EBADSLT) { return "EBADSLT"; } else
#endif
#ifdef EDEADLOCK
  if (err == EDEADLOCK) { return "EDEADLOCK"; } else
#endif
#ifdef EBFONT
  if (err == EBFONT) { return "EBFONT"; } else
#endif
#ifdef ENONET
  if (err == ENONET) { return "ENONET"; } else
#endif
#ifdef ENOPKG
  if (err == ENOPKG) { return "ENOPKG"; } else
#endif
#ifdef EREMOTE
  if (err == EREMOTE) { return "EREMOTE"; } else
#endif
#ifdef EADV
  if (err == EADV) { return "EADV"; } else
#endif
#ifdef ESRMNT
  if (err == ESRMNT) { return "ESRMNT"; } else
#endif
#ifdef ECOMM
  if (err == ECOMM) { return "ECOMM"; } else
#endif
#ifdef EDOTDOT
  if (err == EDOTDOT) { return "EDOTDOT"; } else
#endif
#ifdef ENOTUNIQ
  if (err == ENOTUNIQ) { return "ENOTUNIQ"; } else
#endif
#ifdef EBADFD
  if (err == EBADFD) { return "EBADFD"; } else
#endif
#ifdef EREMCHG
  if (err == EREMCHG) { return "EREMCHG"; } else
#endif
#ifdef ELIBACC
  if (err == ELIBACC) { return "ELIBACC"; } else
#endif
#ifdef ELIBBAD
  if (err == ELIBBAD) { return "ELIBBAD"; } else
#endif
#ifdef ELIBSCN
  if (err == ELIBSCN) { return "ELIBSCN"; } else
#endif
#ifdef ELIBMAX
  if (err == ELIBMAX) { return "ELIBMAX"; } else
#endif
#ifdef ELIBEXEC
  if (err == ELIBEXEC) { return "ELIBEXEC"; } else
#endif
#ifdef ERESTART
  if (err == ERESTART) { return "ERESTART"; } else
#endif
#ifdef ESTRPIPE
  if (err == ESTRPIPE) { return "ESTRPIPE"; } else
#endif
#ifdef EUSERS
  if (err == EUSERS) { return "EUSERS"; } else
#endif
#ifdef ESOCKTNOSUPPORT
  if (err == ESOCKTNOSUPPORT) { return "ESOCKTNOSUPPORT"; } else
#endif
#ifdef EPFNOSUPPORT
  if (err == EPFNOSUPPORT) { return "EPFNOSUPPORT"; } else
#endif
#ifdef ESHUTDOWN
  if (err == ESHUTDOWN) { return "ESHUTDOWN"; } else
#endif
#ifdef ETOOMANYREFS
  if (err == ETOOMANYREFS) { return "ETOOMANYREFS"; } else
#endif
#ifdef EHOSTDOWN
  if (err == EHOSTDOWN) { return "EHOSTDOWN"; } else
#endif
#ifdef EUCLEAN
  if (err == EUCLEAN) { return "EUCLEAN"; } else
#endif
#ifdef ENOTNAM
  if (err == ENOTNAM) { return "ENOTNAM"; } else
#endif
#ifdef ENAVAIL
  if (err == ENAVAIL) { return "ENAVAIL"; } else
#endif
#ifdef EISNAM
  if (err == EISNAM) { return "EISNAM"; } else
#endif
#ifdef EREMOTEIO
  if (err == EREMOTEIO) { return "EREMOTEIO"; } else
#endif
#ifdef ENOMEDIUM
  if (err == ENOMEDIUM) { return "ENOMEDIUM"; } else
#endif
#ifdef EMEDIUMTYPE
  if (err == EMEDIUMTYPE) { return "EMEDIUMTYPE"; } else
#endif
#ifdef ENOKEY
  if (err == ENOKEY) { return "ENOKEY"; } else
#endif
#ifdef EKEYEXPIRED
  if (err == EKEYEXPIRED) { return "EKEYEXPIRED"; } else
#endif
#ifdef EKEYREVOKED
  if (err == EKEYREVOKED) { return "EKEYREVOKED"; } else
#endif
#ifdef EKEYREJECTED
  if (err == EKEYREJECTED) { return "EKEYREJECTED"; } else
#endif
#ifdef ERFKILL
  if (err == ERFKILL) { return "ERFKILL"; } else
#endif
#ifdef EHWPOISON
  if (err == EHWPOISON) { return "EHWPOISON"; } else
#endif
#ifdef EAUTH
  if (err == EAUTH) { return "EAUTH"; } else
#endif
#ifdef EBACKGROUND
  if (err == EBACKGROUND) { return "EBACKGROUND"; } else
#endif
#ifdef EBADRPC
  if (err == EBADRPC) { return "EBADRPC"; } else
#endif
#ifdef ED
  if (err == ED) { return "ED"; } else
#endif
#ifdef EDIED
  if (err == EDIED) { return "EDIED"; } else
#endif
#ifdef EFTYPE
  if (err == EFTYPE) { return "EFTYPE"; } else
#endif
#ifdef EGRATUITOUS
  if (err == EGRATUITOUS) { return "EGRATUITOUS"; } else
#endif
#ifdef EGREGIOUS
  if (err == EGREGIOUS) { return "EGREGIOUS"; } else
#endif
#ifdef EIEIO
  if (err == EIEIO) { return "EIEIO"; } else
#endif
#ifdef ELAST
  if (err == ELAST) { return "ELAST"; } else
#endif
#ifdef ENEEDAUTH
  if (err == ENEEDAUTH) { return "ENEEDAUTH"; } else
#endif
#ifdef EPROCLIM
  if (err == EPROCLIM) { return "EPROCLIM"; } else
#endif
#ifdef EPROCUNAVAIL
  if (err == EPROCUNAVAIL) { return "EPROCUNAVAIL"; } else
#endif
#ifdef EPROGMISMATCH
  if (err == EPROGMISMATCH) { return "EPROGMISMATCH"; } else
#endif
#ifdef EPROGUNAVAIL
  if (err == EPROGUNAVAIL) { return "EPROGUNAVAIL"; } else
#endif
#ifdef ERPCMISMATCH
  if (err == ERPCMISMATCH) { return "ERPCMISMATCH"; } else
#endif
#ifdef ENOATTR
  if (err == ENOATTR) { return "ENOATTR"; } else
#endif
#ifdef EIPSEC
  if (err == EIPSEC) { return "EIPSEC"; } else
#endif
#ifdef EDOOFUS
  if (err == EDOOFUS) { return "EDOOFUS"; } else
#endif
#ifdef ENOTCAPABLE
  if (err == ENOTCAPABLE) { return "ENOTCAPABLE"; } else
#endif
#ifdef ECAPMODE
  if (err == ECAPMODE) { return "ECAPMODE"; } else
#endif
#ifdef EPWROFF
  if (err == EPWROFF) { return "EPWROFF"; } else
#endif
#ifdef EDEVERR
  if (err == EDEVERR) { return "EDEVERR"; } else
#endif
#ifdef EBADEXEC
  if (err == EBADEXEC) { return "EBADEXEC"; } else
#endif
#ifdef EBADARCH
  if (err == EBADARCH) { return "EBADARCH"; } else
#endif
#ifdef ESHLIBVERS
  if (err == ESHLIBVERS) { return "ESHLIBVERS"; } else
#endif
#ifdef EBADMACHO
  if (err == EBADMACHO) { return "EBADMACHO"; } else
#endif
#ifdef ENOPOLICY
  if (err == ENOPOLICY) { return "ENOPOLICY"; } else
#endif
#ifdef EPACKSIZE
  if (err == EPACKSIZE) { return "EPACKSIZE"; } else
#endif
#ifdef EBADIOCTL
  if (err == EBADIOCTL) { return "EBADIOCTL"; } else
#endif
#ifdef EBADMODE
  if (err == EBADMODE) { return "EBADMODE"; } else
#endif
#ifdef EURG
  if (err == EURG) { return "EURG"; } else
#endif
#ifdef ENOURG
  if (err == ENOURG) { return "ENOURG"; } else
#endif
#ifdef ENOCONN
  if (err == ENOCONN) { return "ENOCONN"; } else
#endif
#ifdef EGENERIC
  if (err == EGENERIC) { return "EGENERIC"; } else
#endif
#ifdef ELOCKED
  if (err == ELOCKED) { return "ELOCKED"; } else
#endif
#ifdef EBADCALL
  if (err == EBADCALL) { return "EBADCALL"; } else
#endif
#ifdef EBADSRCDST
  if (err == EBADSRCDST) { return "EBADSRCDST"; } else
#endif
#ifdef ECALLDENIED
  if (err == ECALLDENIED) { return "ECALLDENIED"; } else
#endif
#ifdef EDEADSRCDST
  if (err == EDEADSRCDST) { return "EDEADSRCDST"; } else
#endif
#ifdef ENOTREADY
  if (err == ENOTREADY) { return "ENOTREADY"; } else
#endif
#ifdef EBADREQUEST
  if (err == EBADREQUEST) { return "EBADREQUEST"; } else
#endif
#ifdef ETRAPDENIED
  if (err == ETRAPDENIED) { return "ETRAPDENIED"; } else
#endif
#ifdef EDONTREPLY
  if (err == EDONTREPLY) { return "EDONTREPLY"; } else
#endif
#ifdef EBADEPT
  if (err == EBADEPT) { return "EBADEPT"; } else
#endif
#ifdef EDEADEPT
  if (err == EDEADEPT) { return "EDEADEPT"; } else
#endif
#ifdef EBADCPU
  if (err == EBADCPU) { return "EBADCPU"; } else
#endif
#ifdef ELBIN
  if (err == ELBIN) { return "ELBIN"; } else
#endif
#ifdef ENMFILE
  if (err == ENMFILE) { return "ENMFILE"; } else
#endif
#ifdef ENOSHARE
  if (err == ENOSHARE) { return "ENOSHARE"; } else
#endif
#ifdef ECASECLASH
  if (err == ECASECLASH) { return "ECASECLASH"; } else
#endif
#ifdef ELOCKUNMAPPED
  if (err == ELOCKUNMAPPED) { return "ELOCKUNMAPPED"; } else
#endif
#ifdef ENOTACTIVE
  if (err == ENOTACTIVE) { return "ENOTACTIVE"; } else
#endif
#ifdef B_NO_ERROR
  if (err == B_NO_ERROR) { return "B_NO_ERROR"; } else
#endif
#ifdef B_ERROR
  if (err == B_ERROR) { return "B_ERROR"; } else
#endif
#ifdef B_NO_MEMORY
  if (err == B_NO_MEMORY) { return "B_NO_MEMORY"; } else
#endif
#ifdef B_POSIX_ENOMEM
  if (err == B_POSIX_ENOMEM) { return "B_POSIX_ENOMEM"; } else
#endif
#ifdef B_IO_ERROR
  if (err == B_IO_ERROR) { return "B_IO_ERROR"; } else
#endif
#ifdef B_PERMISSION_DENIED
  if (err == B_PERMISSION_DENIED) { return "B_PERMISSION_DENIED"; } else
#endif
#ifdef B_BAD_INDEX
  if (err == B_BAD_INDEX) { return "B_BAD_INDEX"; } else
#endif
#ifdef B_BAD_TYPE
  if (err == B_BAD_TYPE) { return "B_BAD_TYPE"; } else
#endif
#ifdef B_BAD_VALUE
  if (err == B_BAD_VALUE) { return "B_BAD_VALUE"; } else
#endif
#ifdef B_MISMATCHED_VALUES
  if (err == B_MISMATCHED_VALUES) { return "B_MISMATCHED_VALUES"; } else
#endif
#ifdef B_NAME_NOT_FOUND
  if (err == B_NAME_NOT_FOUND) { return "B_NAME_NOT_FOUND"; } else
#endif
#ifdef B_NAME_IN_USE
  if (err == B_NAME_IN_USE) { return "B_NAME_IN_USE"; } else
#endif
#ifdef B_TIMED_OUT
  if (err == B_TIMED_OUT) { return "B_TIMED_OUT"; } else
#endif
#ifdef B_INTERRUPTED
  if (err == B_INTERRUPTED) { return "B_INTERRUPTED"; } else
#endif
#ifdef B_WOULD_BLOCK
  if (err == B_WOULD_BLOCK) { return "B_WOULD_BLOCK"; } else
#endif
#ifdef B_CANCELED
  if (err == B_CANCELED) { return "B_CANCELED"; } else
#endif
#ifdef B_NO_INIT
  if (err == B_NO_INIT) { return "B_NO_INIT"; } else
#endif
#ifdef B_BUSY
  if (err == B_BUSY) { return "B_BUSY"; } else
#endif
#ifdef B_NOT_ALLOWED
  if (err == B_NOT_ALLOWED) { return "B_NOT_ALLOWED"; } else
#endif
#ifdef B_BAD_DATA
  if (err == B_BAD_DATA) { return "B_BAD_DATA"; } else
#endif
#ifdef B_BAD_SEM_ID
  if (err == B_BAD_SEM_ID) { return "B_BAD_SEM_ID"; } else
#endif
#ifdef B_NO_MORE_SEMS
  if (err == B_NO_MORE_SEMS) { return "B_NO_MORE_SEMS"; } else
#endif
#ifdef B_BAD_THREAD_ID
  if (err == B_BAD_THREAD_ID) { return "B_BAD_THREAD_ID"; } else
#endif
#ifdef B_NO_MORE_THREADS
  if (err == B_NO_MORE_THREADS) { return "B_NO_MORE_THREADS"; } else
#endif
#ifdef B_BAD_THREAD_STATE
  if (err == B_BAD_THREAD_STATE) { return "B_BAD_THREAD_STATE"; } else
#endif
#ifdef B_BAD_TEAM_ID
  if (err == B_BAD_TEAM_ID) { return "B_BAD_TEAM_ID"; } else
#endif
#ifdef B_NO_MORE_TEAMS
  if (err == B_NO_MORE_TEAMS) { return "B_NO_MORE_TEAMS"; } else
#endif
#ifdef B_BAD_PORT_ID
  if (err == B_BAD_PORT_ID) { return "B_BAD_PORT_ID"; } else
#endif
#ifdef B_NO_MORE_PORTS
  if (err == B_NO_MORE_PORTS) { return "B_NO_MORE_PORTS"; } else
#endif
#ifdef B_BAD_IMAGE_ID
  if (err == B_BAD_IMAGE_ID) { return "B_BAD_IMAGE_ID"; } else
#endif
#ifdef B_BAD_ADDRESS
  if (err == B_BAD_ADDRESS) { return "B_BAD_ADDRESS"; } else
#endif
#ifdef B_NOT_AN_EXECUTABLE
  if (err == B_NOT_AN_EXECUTABLE) { return "B_NOT_AN_EXECUTABLE"; } else
#endif
#ifdef B_MISSING_LIBRARY
  if (err == B_MISSING_LIBRARY) { return "B_MISSING_LIBRARY"; } else
#endif
#ifdef B_MISSING_SYMBOL
  if (err == B_MISSING_SYMBOL) { return "B_MISSING_SYMBOL"; } else
#endif
#ifdef B_DEBUGGER_ALREADY_INSTALLED
  if (err == B_DEBUGGER_ALREADY_INSTALLED) { return "B_DEBUGGER_ALREADY_INSTALLED"; } else
#endif
#ifdef B_BAD_REPLY
  if (err == B_BAD_REPLY) { return "B_BAD_REPLY"; } else
#endif
#ifdef B_DUPLICATE_REPLY
  if (err == B_DUPLICATE_REPLY) { return "B_DUPLICATE_REPLY"; } else
#endif
#ifdef B_MESSAGE_TO_SELF
  if (err == B_MESSAGE_TO_SELF) { return "B_MESSAGE_TO_SELF"; } else
#endif
#ifdef B_BAD_HANDLER
  if (err == B_BAD_HANDLER) { return "B_BAD_HANDLER"; } else
#endif
#ifdef B_ALREADY_RUNNING
  if (err == B_ALREADY_RUNNING) { return "B_ALREADY_RUNNING"; } else
#endif
#ifdef B_LAUNCH_FAILED
  if (err == B_LAUNCH_FAILED) { return "B_LAUNCH_FAILED"; } else
#endif
#ifdef B_AMBIGUOUS_APP_LAUNCH
  if (err == B_AMBIGUOUS_APP_LAUNCH) { return "B_AMBIGUOUS_APP_LAUNCH"; } else
#endif
#ifdef B_UNKNOWN_MIME_TYPE
  if (err == B_UNKNOWN_MIME_TYPE) { return "B_UNKNOWN_MIME_TYPE"; } else
#endif
#ifdef B_BAD_SCRIPT_SYNTAX
  if (err == B_BAD_SCRIPT_SYNTAX) { return "B_BAD_SCRIPT_SYNTAX"; } else
#endif
#ifdef B_LAUNCH_FAILED_NO_RESOLVE_LINK
  if (err == B_LAUNCH_FAILED_NO_RESOLVE_LINK) { return "B_LAUNCH_FAILED_NO_RESOLVE_LINK"; } else
#endif
#ifdef B_LAUNCH_FAILED_EXECUTABLE
  if (err == B_LAUNCH_FAILED_EXECUTABLE) { return "B_LAUNCH_FAILED_EXECUTABLE"; } else
#endif
#ifdef B_LAUNCH_FAILED_APP_NOT_FOUND
  if (err == B_LAUNCH_FAILED_APP_NOT_FOUND) { return "B_LAUNCH_FAILED_APP_NOT_FOUND"; } else
#endif
#ifdef B_LAUNCH_FAILED_APP_IN_TRASH
  if (err == B_LAUNCH_FAILED_APP_IN_TRASH) { return "B_LAUNCH_FAILED_APP_IN_TRASH"; } else
#endif
#ifdef B_LAUNCH_FAILED_NO_PREFERRED_APP
  if (err == B_LAUNCH_FAILED_NO_PREFERRED_APP) { return "B_LAUNCH_FAILED_NO_PREFERRED_APP"; } else
#endif
#ifdef B_LAUNCH_FAILED_FILES_APP_NOT_FOUND
  if (err == B_LAUNCH_FAILED_FILES_APP_NOT_FOUND) { return "B_LAUNCH_FAILED_FILES_APP_NOT_FOUND"; } else
#endif
#ifdef B_BAD_MIME_SNIFFER_RULE
  if (err == B_BAD_MIME_SNIFFER_RULE) { return "B_BAD_MIME_SNIFFER_RULE"; } else
#endif
#ifdef B_NOT_A_MESSAGE
  if (err == B_NOT_A_MESSAGE) { return "B_NOT_A_MESSAGE"; } else
#endif
#ifdef B_SHUTDOWN_CANCELLED
  if (err == B_SHUTDOWN_CANCELLED) { return "B_SHUTDOWN_CANCELLED"; } else
#endif
#ifdef B_SHUTTING_DOWN
  if (err == B_SHUTTING_DOWN) { return "B_SHUTTING_DOWN"; } else
#endif
#ifdef B_FILE_ERROR
  if (err == B_FILE_ERROR) { return "B_FILE_ERROR"; } else
#endif
#ifdef B_FILE_NOT_FOUND
  if (err == B_FILE_NOT_FOUND) { return "B_FILE_NOT_FOUND"; } else
#endif
#ifdef B_ENTRY_NOT_FOUND
  if (err == B_ENTRY_NOT_FOUND) { return "B_ENTRY_NOT_FOUND"; } else
#endif
#ifdef B_FILE_EXISTS
  if (err == B_FILE_EXISTS) { return "B_FILE_EXISTS"; } else
#endif
#ifdef B_NAME_TOO_LONG
  if (err == B_NAME_TOO_LONG) { return "B_NAME_TOO_LONG"; } else
#endif
#ifdef B_NOT_A_DIRECTORY
  if (err == B_NOT_A_DIRECTORY) { return "B_NOT_A_DIRECTORY"; } else
#endif
#ifdef B_DIRECTORY_NOT_EMPTY
  if (err == B_DIRECTORY_NOT_EMPTY) { return "B_DIRECTORY_NOT_EMPTY"; } else
#endif
#ifdef B_DEVICE_FULL
  if (err == B_DEVICE_FULL) { return "B_DEVICE_FULL"; } else
#endif
#ifdef B_READ_ONLY_DEVICE
  if (err == B_READ_ONLY_DEVICE) { return "B_READ_ONLY_DEVICE"; } else
#endif
#ifdef B_IS_A_DIRECTORY
  if (err == B_IS_A_DIRECTORY) { return "B_IS_A_DIRECTORY"; } else
#endif
#ifdef B_NO_MORE_FDS
  if (err == B_NO_MORE_FDS) { return "B_NO_MORE_FDS"; } else
#endif
#ifdef B_CROSS_DEVICE_LINK
  if (err == B_CROSS_DEVICE_LINK) { return "B_CROSS_DEVICE_LINK"; } else
#endif
#ifdef B_LINK_LIMIT
  if (err == B_LINK_LIMIT) { return "B_LINK_LIMIT"; } else
#endif
#ifdef B_BUSTED_PIPE
  if (err == B_BUSTED_PIPE) { return "B_BUSTED_PIPE"; } else
#endif
#ifdef B_UNSUPPORTED
  if (err == B_UNSUPPORTED) { return "B_UNSUPPORTED"; } else
#endif
#ifdef B_PARTITION_TOO_SMALL
  if (err == B_PARTITION_TOO_SMALL) { return "B_PARTITION_TOO_SMALL"; } else
#endif
#ifdef B_STREAM_NOT_FOUND
  if (err == B_STREAM_NOT_FOUND) { return "B_STREAM_NOT_FOUND"; } else
#endif
#ifdef B_SERVER_NOT_FOUND
  if (err == B_SERVER_NOT_FOUND) { return "B_SERVER_NOT_FOUND"; } else
#endif
#ifdef B_RESOURCE_NOT_FOUND
  if (err == B_RESOURCE_NOT_FOUND) { return "B_RESOURCE_NOT_FOUND"; } else
#endif
#ifdef B_RESOURCE_UNAVAILABLE
  if (err == B_RESOURCE_UNAVAILABLE) { return "B_RESOURCE_UNAVAILABLE"; } else
#endif
#ifdef B_BAD_SUBSCRIBER
  if (err == B_BAD_SUBSCRIBER) { return "B_BAD_SUBSCRIBER"; } else
#endif
#ifdef B_SUBSCRIBER_NOT_ENTERED
  if (err == B_SUBSCRIBER_NOT_ENTERED) { return "B_SUBSCRIBER_NOT_ENTERED"; } else
#endif
#ifdef B_BUFFER_NOT_AVAILABLE
  if (err == B_BUFFER_NOT_AVAILABLE) { return "B_BUFFER_NOT_AVAILABLE"; } else
#endif
#ifdef B_LAST_BUFFER_ERROR
  if (err == B_LAST_BUFFER_ERROR) { return "B_LAST_BUFFER_ERROR"; } else
#endif
#ifdef B_MEDIA_SYSTEM_FAILURE
  if (err == B_MEDIA_SYSTEM_FAILURE) { return "B_MEDIA_SYSTEM_FAILURE"; } else
#endif
#ifdef B_MEDIA_BAD_NODE
  if (err == B_MEDIA_BAD_NODE) { return "B_MEDIA_BAD_NODE"; } else
#endif
#ifdef B_MEDIA_NODE_BUSY
  if (err == B_MEDIA_NODE_BUSY) { return "B_MEDIA_NODE_BUSY"; } else
#endif
#ifdef B_MEDIA_BAD_FORMAT
  if (err == B_MEDIA_BAD_FORMAT) { return "B_MEDIA_BAD_FORMAT"; } else
#endif
#ifdef B_MEDIA_BAD_BUFFER
  if (err == B_MEDIA_BAD_BUFFER) { return "B_MEDIA_BAD_BUFFER"; } else
#endif
#ifdef B_MEDIA_TOO_MANY_NODES
  if (err == B_MEDIA_TOO_MANY_NODES) { return "B_MEDIA_TOO_MANY_NODES"; } else
#endif
#ifdef B_MEDIA_TOO_MANY_BUFFERS
  if (err == B_MEDIA_TOO_MANY_BUFFERS) { return "B_MEDIA_TOO_MANY_BUFFERS"; } else
#endif
#ifdef B_MEDIA_NODE_ALREADY_EXISTS
  if (err == B_MEDIA_NODE_ALREADY_EXISTS) { return "B_MEDIA_NODE_ALREADY_EXISTS"; } else
#endif
#ifdef B_MEDIA_BUFFER_ALREADY_EXISTS
  if (err == B_MEDIA_BUFFER_ALREADY_EXISTS) { return "B_MEDIA_BUFFER_ALREADY_EXISTS"; } else
#endif
#ifdef B_MEDIA_CANNOT_SEEK
  if (err == B_MEDIA_CANNOT_SEEK) { return "B_MEDIA_CANNOT_SEEK"; } else
#endif
#ifdef B_MEDIA_CANNOT_CHANGE_RUN_MODE
  if (err == B_MEDIA_CANNOT_CHANGE_RUN_MODE) { return "B_MEDIA_CANNOT_CHANGE_RUN_MODE"; } else
#endif
#ifdef B_MEDIA_APP_ALREADY_REGISTERED
  if (err == B_MEDIA_APP_ALREADY_REGISTERED) { return "B_MEDIA_APP_ALREADY_REGISTERED"; } else
#endif
#ifdef B_MEDIA_APP_NOT_REGISTERED
  if (err == B_MEDIA_APP_NOT_REGISTERED) { return "B_MEDIA_APP_NOT_REGISTERED"; } else
#endif
#ifdef B_MEDIA_CANNOT_RECLAIM_BUFFERS
  if (err == B_MEDIA_CANNOT_RECLAIM_BUFFERS) { return "B_MEDIA_CANNOT_RECLAIM_BUFFERS"; } else
#endif
#ifdef B_MEDIA_BUFFERS_NOT_RECLAIMED
  if (err == B_MEDIA_BUFFERS_NOT_RECLAIMED) { return "B_MEDIA_BUFFERS_NOT_RECLAIMED"; } else
#endif
#ifdef B_MEDIA_TIME_SOURCE_STOPPED
  if (err == B_MEDIA_TIME_SOURCE_STOPPED) { return "B_MEDIA_TIME_SOURCE_STOPPED"; } else
#endif
#ifdef B_MEDIA_TIME_SOURCE_BUSY
  if (err == B_MEDIA_TIME_SOURCE_BUSY) { return "B_MEDIA_TIME_SOURCE_BUSY"; } else
#endif
#ifdef B_MEDIA_BAD_SOURCE
  if (err == B_MEDIA_BAD_SOURCE) { return "B_MEDIA_BAD_SOURCE"; } else
#endif
#ifdef B_MEDIA_BAD_DESTINATION
  if (err == B_MEDIA_BAD_DESTINATION) { return "B_MEDIA_BAD_DESTINATION"; } else
#endif
#ifdef B_MEDIA_ALREADY_CONNECTED
  if (err == B_MEDIA_ALREADY_CONNECTED) { return "B_MEDIA_ALREADY_CONNECTED"; } else
#endif
#ifdef B_MEDIA_NOT_CONNECTED
  if (err == B_MEDIA_NOT_CONNECTED) { return "B_MEDIA_NOT_CONNECTED"; } else
#endif
#ifdef B_MEDIA_BAD_CLIP_FORMAT
  if (err == B_MEDIA_BAD_CLIP_FORMAT) { return "B_MEDIA_BAD_CLIP_FORMAT"; } else
#endif
#ifdef B_MEDIA_ADDON_FAILED
  if (err == B_MEDIA_ADDON_FAILED) { return "B_MEDIA_ADDON_FAILED"; } else
#endif
#ifdef B_MEDIA_ADDON_DISABLED
  if (err == B_MEDIA_ADDON_DISABLED) { return "B_MEDIA_ADDON_DISABLED"; } else
#endif
#ifdef B_MEDIA_CHANGE_IN_PROGRESS
  if (err == B_MEDIA_CHANGE_IN_PROGRESS) { return "B_MEDIA_CHANGE_IN_PROGRESS"; } else
#endif
#ifdef B_MEDIA_STALE_CHANGE_COUNT
  if (err == B_MEDIA_STALE_CHANGE_COUNT) { return "B_MEDIA_STALE_CHANGE_COUNT"; } else
#endif
#ifdef B_MEDIA_ADDON_RESTRICTED
  if (err == B_MEDIA_ADDON_RESTRICTED) { return "B_MEDIA_ADDON_RESTRICTED"; } else
#endif
#ifdef B_MEDIA_NO_HANDLER
  if (err == B_MEDIA_NO_HANDLER) { return "B_MEDIA_NO_HANDLER"; } else
#endif
#ifdef B_MEDIA_DUPLICATE_FORMAT
  if (err == B_MEDIA_DUPLICATE_FORMAT) { return "B_MEDIA_DUPLICATE_FORMAT"; } else
#endif
#ifdef B_MEDIA_REALTIME_DISABLED
  if (err == B_MEDIA_REALTIME_DISABLED) { return "B_MEDIA_REALTIME_DISABLED"; } else
#endif
#ifdef B_MEDIA_REALTIME_UNAVAILABLE
  if (err == B_MEDIA_REALTIME_UNAVAILABLE) { return "B_MEDIA_REALTIME_UNAVAILABLE"; } else
#endif
#ifdef B_MAIL_NO_DAEMON
  if (err == B_MAIL_NO_DAEMON) { return "B_MAIL_NO_DAEMON"; } else
#endif
#ifdef B_MAIL_UNKNOWN_USER
  if (err == B_MAIL_UNKNOWN_USER) { return "B_MAIL_UNKNOWN_USER"; } else
#endif
#ifdef B_MAIL_WRONG_PASSWORD
  if (err == B_MAIL_WRONG_PASSWORD) { return "B_MAIL_WRONG_PASSWORD"; } else
#endif
#ifdef B_MAIL_UNKNOWN_HOST
  if (err == B_MAIL_UNKNOWN_HOST) { return "B_MAIL_UNKNOWN_HOST"; } else
#endif
#ifdef B_MAIL_ACCESS_ERROR
  if (err == B_MAIL_ACCESS_ERROR) { return "B_MAIL_ACCESS_ERROR"; } else
#endif
#ifdef B_MAIL_UNKNOWN_FIELD
  if (err == B_MAIL_UNKNOWN_FIELD) { return "B_MAIL_UNKNOWN_FIELD"; } else
#endif
#ifdef B_MAIL_NO_RECIPIENT
  if (err == B_MAIL_NO_RECIPIENT) { return "B_MAIL_NO_RECIPIENT"; } else
#endif
#ifdef B_MAIL_INVALID_MAIL
  if (err == B_MAIL_INVALID_MAIL) { return "B_MAIL_INVALID_MAIL"; } else
#endif
#ifdef B_NO_PRINT_SERVER
  if (err == B_NO_PRINT_SERVER) { return "B_NO_PRINT_SERVER"; } else
#endif
#ifdef B_DEV_INVALID_IOCTL
  if (err == B_DEV_INVALID_IOCTL) { return "B_DEV_INVALID_IOCTL"; } else
#endif
#ifdef B_DEV_NO_MEMORY
  if (err == B_DEV_NO_MEMORY) { return "B_DEV_NO_MEMORY"; } else
#endif
#ifdef B_DEV_BAD_DRIVE_NUM
  if (err == B_DEV_BAD_DRIVE_NUM) { return "B_DEV_BAD_DRIVE_NUM"; } else
#endif
#ifdef B_DEV_NO_MEDIA
  if (err == B_DEV_NO_MEDIA) { return "B_DEV_NO_MEDIA"; } else
#endif
#ifdef B_DEV_UNREADABLE
  if (err == B_DEV_UNREADABLE) { return "B_DEV_UNREADABLE"; } else
#endif
#ifdef B_DEV_FORMAT_ERROR
  if (err == B_DEV_FORMAT_ERROR) { return "B_DEV_FORMAT_ERROR"; } else
#endif
#ifdef B_DEV_TIMEOUT
  if (err == B_DEV_TIMEOUT) { return "B_DEV_TIMEOUT"; } else
#endif
#ifdef B_DEV_RECALIBRATE_ERROR
  if (err == B_DEV_RECALIBRATE_ERROR) { return "B_DEV_RECALIBRATE_ERROR"; } else
#endif
#ifdef B_DEV_SEEK_ERROR
  if (err == B_DEV_SEEK_ERROR) { return "B_DEV_SEEK_ERROR"; } else
#endif
#ifdef B_DEV_ID_ERROR
  if (err == B_DEV_ID_ERROR) { return "B_DEV_ID_ERROR"; } else
#endif
#ifdef B_DEV_READ_ERROR
  if (err == B_DEV_READ_ERROR) { return "B_DEV_READ_ERROR"; } else
#endif
#ifdef B_DEV_WRITE_ERROR
  if (err == B_DEV_WRITE_ERROR) { return "B_DEV_WRITE_ERROR"; } else
#endif
#ifdef B_DEV_NOT_READY
  if (err == B_DEV_NOT_READY) { return "B_DEV_NOT_READY"; } else
#endif
#ifdef B_DEV_MEDIA_CHANGED
  if (err == B_DEV_MEDIA_CHANGED) { return "B_DEV_MEDIA_CHANGED"; } else
#endif
#ifdef B_DEV_MEDIA_CHANGE_REQUESTED
  if (err == B_DEV_MEDIA_CHANGE_REQUESTED) { return "B_DEV_MEDIA_CHANGE_REQUESTED"; } else
#endif
#ifdef B_DEV_RESOURCE_CONFLICT
  if (err == B_DEV_RESOURCE_CONFLICT) { return "B_DEV_RESOURCE_CONFLICT"; } else
#endif
#ifdef B_DEV_CONFIGURATION_ERROR
  if (err == B_DEV_CONFIGURATION_ERROR) { return "B_DEV_CONFIGURATION_ERROR"; } else
#endif
#ifdef B_DEV_DISABLED_BY_USER
  if (err == B_DEV_DISABLED_BY_USER) { return "B_DEV_DISABLED_BY_USER"; } else
#endif
#ifdef B_DEV_DOOR_OPEN
  if (err == B_DEV_DOOR_OPEN) { return "B_DEV_DOOR_OPEN"; } else
#endif
#ifdef B_DEV_INVALID_PIPE
  if (err == B_DEV_INVALID_PIPE) { return "B_DEV_INVALID_PIPE"; } else
#endif
#ifdef B_DEV_CRC_ERROR
  if (err == B_DEV_CRC_ERROR) { return "B_DEV_CRC_ERROR"; } else
#endif
#ifdef B_DEV_STALLED
  if (err == B_DEV_STALLED) { return "B_DEV_STALLED"; } else
#endif
#ifdef B_DEV_BAD_PID
  if (err == B_DEV_BAD_PID) { return "B_DEV_BAD_PID"; } else
#endif
#ifdef B_DEV_UNEXPECTED_PID
  if (err == B_DEV_UNEXPECTED_PID) { return "B_DEV_UNEXPECTED_PID"; } else
#endif
#ifdef B_DEV_DATA_OVERRUN
  if (err == B_DEV_DATA_OVERRUN) { return "B_DEV_DATA_OVERRUN"; } else
#endif
#ifdef B_DEV_DATA_UNDERRUN
  if (err == B_DEV_DATA_UNDERRUN) { return "B_DEV_DATA_UNDERRUN"; } else
#endif
#ifdef B_DEV_FIFO_OVERRUN
  if (err == B_DEV_FIFO_OVERRUN) { return "B_DEV_FIFO_OVERRUN"; } else
#endif
#ifdef B_DEV_FIFO_UNDERRUN
  if (err == B_DEV_FIFO_UNDERRUN) { return "B_DEV_FIFO_UNDERRUN"; } else
#endif
#ifdef B_DEV_PENDING
  if (err == B_DEV_PENDING) { return "B_DEV_PENDING"; } else
#endif
#ifdef B_DEV_MULTIPLE_ERRORS
  if (err == B_DEV_MULTIPLE_ERRORS) { return "B_DEV_MULTIPLE_ERRORS"; } else
#endif
#ifdef B_DEV_TOO_LATE
  if (err == B_DEV_TOO_LATE) { return "B_DEV_TOO_LATE"; } else
#endif
#ifdef B_NO_TRANSLATOR
  if (err == B_NO_TRANSLATOR) { return "B_NO_TRANSLATOR"; } else
#endif
#ifdef B_ILLEGAL_DATA
  if (err == B_ILLEGAL_DATA) { return "B_ILLEGAL_DATA"; } else
#endif
#ifdef EFPOS
  if (err == EFPOS) { return "EFPOS"; } else
#endif
#ifdef ESIGPARM
  if (err == ESIGPARM) { return "ESIGPARM"; } else
#endif
  return NULL;
}

static int intcmp(const void *vp1, const void *vp2)
{
  const int *ip1 =vp1;
  const int *ip2 =vp2;
  if (*ip1 < *ip2)
    return -1;
  if (*ip1 > *ip2)
    return 1;
  return 0;
}

void errno_candidate_each(void (*func)(int errcand, void *arg), void *arg)
{
  static int sorted = 0;
  static int errno_ary[] = {
#ifdef EAGAIN
    EAGAIN,
#endif
#ifdef ENOTSUP
    ENOTSUP,
#endif
#ifdef E2BIG
    E2BIG,
#endif
#ifdef EACCES
    EACCES,
#endif
#ifdef EADDRINUSE
    EADDRINUSE,
#endif
#ifdef EADDRNOTAVAIL
    EADDRNOTAVAIL,
#endif
#ifdef EAFNOSUPPORT
    EAFNOSUPPORT,
#endif
#ifdef EALREADY
    EALREADY,
#endif
#ifdef EBADF
    EBADF,
#endif
#ifdef EBADMSG
    EBADMSG,
#endif
#ifdef EBUSY
    EBUSY,
#endif
#ifdef ECANCELED
    ECANCELED,
#endif
#ifdef ECHILD
    ECHILD,
#endif
#ifdef ECONNABORTED
    ECONNABORTED,
#endif
#ifdef ECONNREFUSED
    ECONNREFUSED,
#endif
#ifdef ECONNRESET
    ECONNRESET,
#endif
#ifdef EDEADLK
    EDEADLK,
#endif
#ifdef EDESTADDRREQ
    EDESTADDRREQ,
#endif
#ifdef EDOM
    EDOM,
#endif
#ifdef EDQUOT
    EDQUOT,
#endif
#ifdef EEXIST
    EEXIST,
#endif
#ifdef EFAULT
    EFAULT,
#endif
#ifdef EFBIG
    EFBIG,
#endif
#ifdef EHOSTUNREACH
    EHOSTUNREACH,
#endif
#ifdef EIDRM
    EIDRM,
#endif
#ifdef EILSEQ
    EILSEQ,
#endif
#ifdef EINPROGRESS
    EINPROGRESS,
#endif
#ifdef EINTR
    EINTR,
#endif
#ifdef EINVAL
    EINVAL,
#endif
#ifdef EIO
    EIO,
#endif
#ifdef EISCONN
    EISCONN,
#endif
#ifdef EISDIR
    EISDIR,
#endif
#ifdef ELOOP
    ELOOP,
#endif
#ifdef EMFILE
    EMFILE,
#endif
#ifdef EMLINK
    EMLINK,
#endif
#ifdef EMSGSIZE
    EMSGSIZE,
#endif
#ifdef EMULTIHOP
    EMULTIHOP,
#endif
#ifdef ENAMETOOLONG
    ENAMETOOLONG,
#endif
#ifdef ENETDOWN
    ENETDOWN,
#endif
#ifdef ENETRESET
    ENETRESET,
#endif
#ifdef ENETUNREACH
    ENETUNREACH,
#endif
#ifdef ENFILE
    ENFILE,
#endif
#ifdef ENOBUFS
    ENOBUFS,
#endif
#ifdef ENODATA
    ENODATA,
#endif
#ifdef ENODEV
    ENODEV,
#endif
#ifdef ENOENT
    ENOENT,
#endif
#ifdef ENOEXEC
    ENOEXEC,
#endif
#ifdef ENOLCK
    ENOLCK,
#endif
#ifdef ENOLINK
    ENOLINK,
#endif
#ifdef ENOMEM
    ENOMEM,
#endif
#ifdef ENOMSG
    ENOMSG,
#endif
#ifdef ENOPROTOOPT
    ENOPROTOOPT,
#endif
#ifdef ENOSPC
    ENOSPC,
#endif
#ifdef ENOSR
    ENOSR,
#endif
#ifdef ENOSTR
    ENOSTR,
#endif
#ifdef ENOSYS
    ENOSYS,
#endif
#ifdef ENOTCONN
    ENOTCONN,
#endif
#ifdef ENOTDIR
    ENOTDIR,
#endif
#ifdef ENOTEMPTY
    ENOTEMPTY,
#endif
#ifdef ENOTRECOVERABLE
    ENOTRECOVERABLE,
#endif
#ifdef ENOTSOCK
    ENOTSOCK,
#endif
#ifdef ENOTTY
    ENOTTY,
#endif
#ifdef ENXIO
    ENXIO,
#endif
#ifdef EOPNOTSUPP
    EOPNOTSUPP,
#endif
#ifdef EOVERFLOW
    EOVERFLOW,
#endif
#ifdef EOWNERDEAD
    EOWNERDEAD,
#endif
#ifdef EPERM
    EPERM,
#endif
#ifdef EPIPE
    EPIPE,
#endif
#ifdef EPROTO
    EPROTO,
#endif
#ifdef EPROTONOSUPPORT
    EPROTONOSUPPORT,
#endif
#ifdef EPROTOTYPE
    EPROTOTYPE,
#endif
#ifdef ERANGE
    ERANGE,
#endif
#ifdef EROFS
    EROFS,
#endif
#ifdef ESPIPE
    ESPIPE,
#endif
#ifdef ESRCH
    ESRCH,
#endif
#ifdef ESTALE
    ESTALE,
#endif
#ifdef ETIME
    ETIME,
#endif
#ifdef ETIMEDOUT
    ETIMEDOUT,
#endif
#ifdef ETXTBSY
    ETXTBSY,
#endif
#ifdef EWOULDBLOCK
    EWOULDBLOCK,
#endif
#ifdef EXDEV
    EXDEV,
#endif
#ifdef ENOTBLK
    ENOTBLK,
#endif
#ifdef ECHRNG
    ECHRNG,
#endif
#ifdef EL2NSYNC
    EL2NSYNC,
#endif
#ifdef EL3HLT
    EL3HLT,
#endif
#ifdef EL3RST
    EL3RST,
#endif
#ifdef ELNRNG
    ELNRNG,
#endif
#ifdef EUNATCH
    EUNATCH,
#endif
#ifdef ENOCSI
    ENOCSI,
#endif
#ifdef EL2HLT
    EL2HLT,
#endif
#ifdef EBADE
    EBADE,
#endif
#ifdef EBADR
    EBADR,
#endif
#ifdef EXFULL
    EXFULL,
#endif
#ifdef ENOANO
    ENOANO,
#endif
#ifdef EBADRQC
    EBADRQC,
#endif
#ifdef EBADSLT
    EBADSLT,
#endif
#ifdef EDEADLOCK
    EDEADLOCK,
#endif
#ifdef EBFONT
    EBFONT,
#endif
#ifdef ENONET
    ENONET,
#endif
#ifdef ENOPKG
    ENOPKG,
#endif
#ifdef EREMOTE
    EREMOTE,
#endif
#ifdef EADV
    EADV,
#endif
#ifdef ESRMNT
    ESRMNT,
#endif
#ifdef ECOMM
    ECOMM,
#endif
#ifdef EDOTDOT
    EDOTDOT,
#endif
#ifdef ENOTUNIQ
    ENOTUNIQ,
#endif
#ifdef EBADFD
    EBADFD,
#endif
#ifdef EREMCHG
    EREMCHG,
#endif
#ifdef ELIBACC
    ELIBACC,
#endif
#ifdef ELIBBAD
    ELIBBAD,
#endif
#ifdef ELIBSCN
    ELIBSCN,
#endif
#ifdef ELIBMAX
    ELIBMAX,
#endif
#ifdef ELIBEXEC
    ELIBEXEC,
#endif
#ifdef ERESTART
    ERESTART,
#endif
#ifdef ESTRPIPE
    ESTRPIPE,
#endif
#ifdef EUSERS
    EUSERS,
#endif
#ifdef ESOCKTNOSUPPORT
    ESOCKTNOSUPPORT,
#endif
#ifdef EPFNOSUPPORT
    EPFNOSUPPORT,
#endif
#ifdef ESHUTDOWN
    ESHUTDOWN,
#endif
#ifdef ETOOMANYREFS
    ETOOMANYREFS,
#endif
#ifdef EHOSTDOWN
    EHOSTDOWN,
#endif
#ifdef EUCLEAN
    EUCLEAN,
#endif
#ifdef ENOTNAM
    ENOTNAM,
#endif
#ifdef ENAVAIL
    ENAVAIL,
#endif
#ifdef EISNAM
    EISNAM,
#endif
#ifdef EREMOTEIO
    EREMOTEIO,
#endif
#ifdef ENOMEDIUM
    ENOMEDIUM,
#endif
#ifdef EMEDIUMTYPE
    EMEDIUMTYPE,
#endif
#ifdef ENOKEY
    ENOKEY,
#endif
#ifdef EKEYEXPIRED
    EKEYEXPIRED,
#endif
#ifdef EKEYREVOKED
    EKEYREVOKED,
#endif
#ifdef EKEYREJECTED
    EKEYREJECTED,
#endif
#ifdef ERFKILL
    ERFKILL,
#endif
#ifdef EHWPOISON
    EHWPOISON,
#endif
#ifdef EAUTH
    EAUTH,
#endif
#ifdef EBACKGROUND
    EBACKGROUND,
#endif
#ifdef EBADRPC
    EBADRPC,
#endif
#ifdef ED
    ED,
#endif
#ifdef EDIED
    EDIED,
#endif
#ifdef EFTYPE
    EFTYPE,
#endif
#ifdef EGRATUITOUS
    EGRATUITOUS,
#endif
#ifdef EGREGIOUS
    EGREGIOUS,
#endif
#ifdef EIEIO
    EIEIO,
#endif
#ifdef ELAST
    ELAST,
#endif
#ifdef ENEEDAUTH
    ENEEDAUTH,
#endif
#ifdef EPROCLIM
    EPROCLIM,
#endif
#ifdef EPROCUNAVAIL
    EPROCUNAVAIL,
#endif
#ifdef EPROGMISMATCH
    EPROGMISMATCH,
#endif
#ifdef EPROGUNAVAIL
    EPROGUNAVAIL,
#endif
#ifdef ERPCMISMATCH
    ERPCMISMATCH,
#endif
#ifdef ENOATTR
    ENOATTR,
#endif
#ifdef EIPSEC
    EIPSEC,
#endif
#ifdef EDOOFUS
    EDOOFUS,
#endif
#ifdef ENOTCAPABLE
    ENOTCAPABLE,
#endif
#ifdef ECAPMODE
    ECAPMODE,
#endif
#ifdef EPWROFF
    EPWROFF,
#endif
#ifdef EDEVERR
    EDEVERR,
#endif
#ifdef EBADEXEC
    EBADEXEC,
#endif
#ifdef EBADARCH
    EBADARCH,
#endif
#ifdef ESHLIBVERS
    ESHLIBVERS,
#endif
#ifdef EBADMACHO
    EBADMACHO,
#endif
#ifdef ENOPOLICY
    ENOPOLICY,
#endif
#ifdef EPACKSIZE
    EPACKSIZE,
#endif
#ifdef EBADIOCTL
    EBADIOCTL,
#endif
#ifdef EBADMODE
    EBADMODE,
#endif
#ifdef EURG
    EURG,
#endif
#ifdef ENOURG
    ENOURG,
#endif
#ifdef ENOCONN
    ENOCONN,
#endif
#ifdef EGENERIC
    EGENERIC,
#endif
#ifdef ELOCKED
    ELOCKED,
#endif
#ifdef EBADCALL
    EBADCALL,
#endif
#ifdef EBADSRCDST
    EBADSRCDST,
#endif
#ifdef ECALLDENIED
    ECALLDENIED,
#endif
#ifdef EDEADSRCDST
    EDEADSRCDST,
#endif
#ifdef ENOTREADY
    ENOTREADY,
#endif
#ifdef EBADREQUEST
    EBADREQUEST,
#endif
#ifdef ETRAPDENIED
    ETRAPDENIED,
#endif
#ifdef EDONTREPLY
    EDONTREPLY,
#endif
#ifdef EBADEPT
    EBADEPT,
#endif
#ifdef EDEADEPT
    EDEADEPT,
#endif
#ifdef EBADCPU
    EBADCPU,
#endif
#ifdef ELBIN
    ELBIN,
#endif
#ifdef ENMFILE
    ENMFILE,
#endif
#ifdef ENOSHARE
    ENOSHARE,
#endif
#ifdef ECASECLASH
    ECASECLASH,
#endif
#ifdef ELOCKUNMAPPED
    ELOCKUNMAPPED,
#endif
#ifdef ENOTACTIVE
    ENOTACTIVE,
#endif
#ifdef B_NO_ERROR
    B_NO_ERROR,
#endif
#ifdef B_ERROR
    B_ERROR,
#endif
#ifdef B_NO_MEMORY
    B_NO_MEMORY,
#endif
#ifdef B_POSIX_ENOMEM
    B_POSIX_ENOMEM,
#endif
#ifdef B_IO_ERROR
    B_IO_ERROR,
#endif
#ifdef B_PERMISSION_DENIED
    B_PERMISSION_DENIED,
#endif
#ifdef B_BAD_INDEX
    B_BAD_INDEX,
#endif
#ifdef B_BAD_TYPE
    B_BAD_TYPE,
#endif
#ifdef B_BAD_VALUE
    B_BAD_VALUE,
#endif
#ifdef B_MISMATCHED_VALUES
    B_MISMATCHED_VALUES,
#endif
#ifdef B_NAME_NOT_FOUND
    B_NAME_NOT_FOUND,
#endif
#ifdef B_NAME_IN_USE
    B_NAME_IN_USE,
#endif
#ifdef B_TIMED_OUT
    B_TIMED_OUT,
#endif
#ifdef B_INTERRUPTED
    B_INTERRUPTED,
#endif
#ifdef B_WOULD_BLOCK
    B_WOULD_BLOCK,
#endif
#ifdef B_CANCELED
    B_CANCELED,
#endif
#ifdef B_NO_INIT
    B_NO_INIT,
#endif
#ifdef B_BUSY
    B_BUSY,
#endif
#ifdef B_NOT_ALLOWED
    B_NOT_ALLOWED,
#endif
#ifdef B_BAD_DATA
    B_BAD_DATA,
#endif
#ifdef B_BAD_SEM_ID
    B_BAD_SEM_ID,
#endif
#ifdef B_NO_MORE_SEMS
    B_NO_MORE_SEMS,
#endif
#ifdef B_BAD_THREAD_ID
    B_BAD_THREAD_ID,
#endif
#ifdef B_NO_MORE_THREADS
    B_NO_MORE_THREADS,
#endif
#ifdef B_BAD_THREAD_STATE
    B_BAD_THREAD_STATE,
#endif
#ifdef B_BAD_TEAM_ID
    B_BAD_TEAM_ID,
#endif
#ifdef B_NO_MORE_TEAMS
    B_NO_MORE_TEAMS,
#endif
#ifdef B_BAD_PORT_ID
    B_BAD_PORT_ID,
#endif
#ifdef B_NO_MORE_PORTS
    B_NO_MORE_PORTS,
#endif
#ifdef B_BAD_IMAGE_ID
    B_BAD_IMAGE_ID,
#endif
#ifdef B_BAD_ADDRESS
    B_BAD_ADDRESS,
#endif
#ifdef B_NOT_AN_EXECUTABLE
    B_NOT_AN_EXECUTABLE,
#endif
#ifdef B_MISSING_LIBRARY
    B_MISSING_LIBRARY,
#endif
#ifdef B_MISSING_SYMBOL
    B_MISSING_SYMBOL,
#endif
#ifdef B_DEBUGGER_ALREADY_INSTALLED
    B_DEBUGGER_ALREADY_INSTALLED,
#endif
#ifdef B_BAD_REPLY
    B_BAD_REPLY,
#endif
#ifdef B_DUPLICATE_REPLY
    B_DUPLICATE_REPLY,
#endif
#ifdef B_MESSAGE_TO_SELF
    B_MESSAGE_TO_SELF,
#endif
#ifdef B_BAD_HANDLER
    B_BAD_HANDLER,
#endif
#ifdef B_ALREADY_RUNNING
    B_ALREADY_RUNNING,
#endif
#ifdef B_LAUNCH_FAILED
    B_LAUNCH_FAILED,
#endif
#ifdef B_AMBIGUOUS_APP_LAUNCH
    B_AMBIGUOUS_APP_LAUNCH,
#endif
#ifdef B_UNKNOWN_MIME_TYPE
    B_UNKNOWN_MIME_TYPE,
#endif
#ifdef B_BAD_SCRIPT_SYNTAX
    B_BAD_SCRIPT_SYNTAX,
#endif
#ifdef B_LAUNCH_FAILED_NO_RESOLVE_LINK
    B_LAUNCH_FAILED_NO_RESOLVE_LINK,
#endif
#ifdef B_LAUNCH_FAILED_EXECUTABLE
    B_LAUNCH_FAILED_EXECUTABLE,
#endif
#ifdef B_LAUNCH_FAILED_APP_NOT_FOUND
    B_LAUNCH_FAILED_APP_NOT_FOUND,
#endif
#ifdef B_LAUNCH_FAILED_APP_IN_TRASH
    B_LAUNCH_FAILED_APP_IN_TRASH,
#endif
#ifdef B_LAUNCH_FAILED_NO_PREFERRED_APP
    B_LAUNCH_FAILED_NO_PREFERRED_APP,
#endif
#ifdef B_LAUNCH_FAILED_FILES_APP_NOT_FOUND
    B_LAUNCH_FAILED_FILES_APP_NOT_FOUND,
#endif
#ifdef B_BAD_MIME_SNIFFER_RULE
    B_BAD_MIME_SNIFFER_RULE,
#endif
#ifdef B_NOT_A_MESSAGE
    B_NOT_A_MESSAGE,
#endif
#ifdef B_SHUTDOWN_CANCELLED
    B_SHUTDOWN_CANCELLED,
#endif
#ifdef B_SHUTTING_DOWN
    B_SHUTTING_DOWN,
#endif
#ifdef B_FILE_ERROR
    B_FILE_ERROR,
#endif
#ifdef B_FILE_NOT_FOUND
    B_FILE_NOT_FOUND,
#endif
#ifdef B_ENTRY_NOT_FOUND
    B_ENTRY_NOT_FOUND,
#endif
#ifdef B_FILE_EXISTS
    B_FILE_EXISTS,
#endif
#ifdef B_NAME_TOO_LONG
    B_NAME_TOO_LONG,
#endif
#ifdef B_NOT_A_DIRECTORY
    B_NOT_A_DIRECTORY,
#endif
#ifdef B_DIRECTORY_NOT_EMPTY
    B_DIRECTORY_NOT_EMPTY,
#endif
#ifdef B_DEVICE_FULL
    B_DEVICE_FULL,
#endif
#ifdef B_READ_ONLY_DEVICE
    B_READ_ONLY_DEVICE,
#endif
#ifdef B_IS_A_DIRECTORY
    B_IS_A_DIRECTORY,
#endif
#ifdef B_NO_MORE_FDS
    B_NO_MORE_FDS,
#endif
#ifdef B_CROSS_DEVICE_LINK
    B_CROSS_DEVICE_LINK,
#endif
#ifdef B_LINK_LIMIT
    B_LINK_LIMIT,
#endif
#ifdef B_BUSTED_PIPE
    B_BUSTED_PIPE,
#endif
#ifdef B_UNSUPPORTED
    B_UNSUPPORTED,
#endif
#ifdef B_PARTITION_TOO_SMALL
    B_PARTITION_TOO_SMALL,
#endif
#ifdef B_STREAM_NOT_FOUND
    B_STREAM_NOT_FOUND,
#endif
#ifdef B_SERVER_NOT_FOUND
    B_SERVER_NOT_FOUND,
#endif
#ifdef B_RESOURCE_NOT_FOUND
    B_RESOURCE_NOT_FOUND,
#endif
#ifdef B_RESOURCE_UNAVAILABLE
    B_RESOURCE_UNAVAILABLE,
#endif
#ifdef B_BAD_SUBSCRIBER
    B_BAD_SUBSCRIBER,
#endif
#ifdef B_SUBSCRIBER_NOT_ENTERED
    B_SUBSCRIBER_NOT_ENTERED,
#endif
#ifdef B_BUFFER_NOT_AVAILABLE
    B_BUFFER_NOT_AVAILABLE,
#endif
#ifdef B_LAST_BUFFER_ERROR
    B_LAST_BUFFER_ERROR,
#endif
#ifdef B_MEDIA_SYSTEM_FAILURE
    B_MEDIA_SYSTEM_FAILURE,
#endif
#ifdef B_MEDIA_BAD_NODE
    B_MEDIA_BAD_NODE,
#endif
#ifdef B_MEDIA_NODE_BUSY
    B_MEDIA_NODE_BUSY,
#endif
#ifdef B_MEDIA_BAD_FORMAT
    B_MEDIA_BAD_FORMAT,
#endif
#ifdef B_MEDIA_BAD_BUFFER
    B_MEDIA_BAD_BUFFER,
#endif
#ifdef B_MEDIA_TOO_MANY_NODES
    B_MEDIA_TOO_MANY_NODES,
#endif
#ifdef B_MEDIA_TOO_MANY_BUFFERS
    B_MEDIA_TOO_MANY_BUFFERS,
#endif
#ifdef B_MEDIA_NODE_ALREADY_EXISTS
    B_MEDIA_NODE_ALREADY_EXISTS,
#endif
#ifdef B_MEDIA_BUFFER_ALREADY_EXISTS
    B_MEDIA_BUFFER_ALREADY_EXISTS,
#endif
#ifdef B_MEDIA_CANNOT_SEEK
    B_MEDIA_CANNOT_SEEK,
#endif
#ifdef B_MEDIA_CANNOT_CHANGE_RUN_MODE
    B_MEDIA_CANNOT_CHANGE_RUN_MODE,
#endif
#ifdef B_MEDIA_APP_ALREADY_REGISTERED
    B_MEDIA_APP_ALREADY_REGISTERED,
#endif
#ifdef B_MEDIA_APP_NOT_REGISTERED
    B_MEDIA_APP_NOT_REGISTERED,
#endif
#ifdef B_MEDIA_CANNOT_RECLAIM_BUFFERS
    B_MEDIA_CANNOT_RECLAIM_BUFFERS,
#endif
#ifdef B_MEDIA_BUFFERS_NOT_RECLAIMED
    B_MEDIA_BUFFERS_NOT_RECLAIMED,
#endif
#ifdef B_MEDIA_TIME_SOURCE_STOPPED
    B_MEDIA_TIME_SOURCE_STOPPED,
#endif
#ifdef B_MEDIA_TIME_SOURCE_BUSY
    B_MEDIA_TIME_SOURCE_BUSY,
#endif
#ifdef B_MEDIA_BAD_SOURCE
    B_MEDIA_BAD_SOURCE,
#endif
#ifdef B_MEDIA_BAD_DESTINATION
    B_MEDIA_BAD_DESTINATION,
#endif
#ifdef B_MEDIA_ALREADY_CONNECTED
    B_MEDIA_ALREADY_CONNECTED,
#endif
#ifdef B_MEDIA_NOT_CONNECTED
    B_MEDIA_NOT_CONNECTED,
#endif
#ifdef B_MEDIA_BAD_CLIP_FORMAT
    B_MEDIA_BAD_CLIP_FORMAT,
#endif
#ifdef B_MEDIA_ADDON_FAILED
    B_MEDIA_ADDON_FAILED,
#endif
#ifdef B_MEDIA_ADDON_DISABLED
    B_MEDIA_ADDON_DISABLED,
#endif
#ifdef B_MEDIA_CHANGE_IN_PROGRESS
    B_MEDIA_CHANGE_IN_PROGRESS,
#endif
#ifdef B_MEDIA_STALE_CHANGE_COUNT
    B_MEDIA_STALE_CHANGE_COUNT,
#endif
#ifdef B_MEDIA_ADDON_RESTRICTED
    B_MEDIA_ADDON_RESTRICTED,
#endif
#ifdef B_MEDIA_NO_HANDLER
    B_MEDIA_NO_HANDLER,
#endif
#ifdef B_MEDIA_DUPLICATE_FORMAT
    B_MEDIA_DUPLICATE_FORMAT,
#endif
#ifdef B_MEDIA_REALTIME_DISABLED
    B_MEDIA_REALTIME_DISABLED,
#endif
#ifdef B_MEDIA_REALTIME_UNAVAILABLE
    B_MEDIA_REALTIME_UNAVAILABLE,
#endif
#ifdef B_MAIL_NO_DAEMON
    B_MAIL_NO_DAEMON,
#endif
#ifdef B_MAIL_UNKNOWN_USER
    B_MAIL_UNKNOWN_USER,
#endif
#ifdef B_MAIL_WRONG_PASSWORD
    B_MAIL_WRONG_PASSWORD,
#endif
#ifdef B_MAIL_UNKNOWN_HOST
    B_MAIL_UNKNOWN_HOST,
#endif
#ifdef B_MAIL_ACCESS_ERROR
    B_MAIL_ACCESS_ERROR,
#endif
#ifdef B_MAIL_UNKNOWN_FIELD
    B_MAIL_UNKNOWN_FIELD,
#endif
#ifdef B_MAIL_NO_RECIPIENT
    B_MAIL_NO_RECIPIENT,
#endif
#ifdef B_MAIL_INVALID_MAIL
    B_MAIL_INVALID_MAIL,
#endif
#ifdef B_NO_PRINT_SERVER
    B_NO_PRINT_SERVER,
#endif
#ifdef B_DEV_INVALID_IOCTL
    B_DEV_INVALID_IOCTL,
#endif
#ifdef B_DEV_NO_MEMORY
    B_DEV_NO_MEMORY,
#endif
#ifdef B_DEV_BAD_DRIVE_NUM
    B_DEV_BAD_DRIVE_NUM,
#endif
#ifdef B_DEV_NO_MEDIA
    B_DEV_NO_MEDIA,
#endif
#ifdef B_DEV_UNREADABLE
    B_DEV_UNREADABLE,
#endif
#ifdef B_DEV_FORMAT_ERROR
    B_DEV_FORMAT_ERROR,
#endif
#ifdef B_DEV_TIMEOUT
    B_DEV_TIMEOUT,
#endif
#ifdef B_DEV_RECALIBRATE_ERROR
    B_DEV_RECALIBRATE_ERROR,
#endif
#ifdef B_DEV_SEEK_ERROR
    B_DEV_SEEK_ERROR,
#endif
#ifdef B_DEV_ID_ERROR
    B_DEV_ID_ERROR,
#endif
#ifdef B_DEV_READ_ERROR
    B_DEV_READ_ERROR,
#endif
#ifdef B_DEV_WRITE_ERROR
    B_DEV_WRITE_ERROR,
#endif
#ifdef B_DEV_NOT_READY
    B_DEV_NOT_READY,
#endif
#ifdef B_DEV_MEDIA_CHANGED
    B_DEV_MEDIA_CHANGED,
#endif
#ifdef B_DEV_MEDIA_CHANGE_REQUESTED
    B_DEV_MEDIA_CHANGE_REQUESTED,
#endif
#ifdef B_DEV_RESOURCE_CONFLICT
    B_DEV_RESOURCE_CONFLICT,
#endif
#ifdef B_DEV_CONFIGURATION_ERROR
    B_DEV_CONFIGURATION_ERROR,
#endif
#ifdef B_DEV_DISABLED_BY_USER
    B_DEV_DISABLED_BY_USER,
#endif
#ifdef B_DEV_DOOR_OPEN
    B_DEV_DOOR_OPEN,
#endif
#ifdef B_DEV_INVALID_PIPE
    B_DEV_INVALID_PIPE,
#endif
#ifdef B_DEV_CRC_ERROR
    B_DEV_CRC_ERROR,
#endif
#ifdef B_DEV_STALLED
    B_DEV_STALLED,
#endif
#ifdef B_DEV_BAD_PID
    B_DEV_BAD_PID,
#endif
#ifdef B_DEV_UNEXPECTED_PID
    B_DEV_UNEXPECTED_PID,
#endif
#ifdef B_DEV_DATA_OVERRUN
    B_DEV_DATA_OVERRUN,
#endif
#ifdef B_DEV_DATA_UNDERRUN
    B_DEV_DATA_UNDERRUN,
#endif
#ifdef B_DEV_FIFO_OVERRUN
    B_DEV_FIFO_OVERRUN,
#endif
#ifdef B_DEV_FIFO_UNDERRUN
    B_DEV_FIFO_UNDERRUN,
#endif
#ifdef B_DEV_PENDING
    B_DEV_PENDING,
#endif
#ifdef B_DEV_MULTIPLE_ERRORS
    B_DEV_MULTIPLE_ERRORS,
#endif
#ifdef B_DEV_TOO_LATE
    B_DEV_TOO_LATE,
#endif
#ifdef B_NO_TRANSLATOR
    B_NO_TRANSLATOR,
#endif
#ifdef B_ILLEGAL_DATA
    B_ILLEGAL_DATA,
#endif
#ifdef EFPOS
    EFPOS,
#endif
#ifdef ESIGPARM
    ESIGPARM,
#endif
  };

  int guess_lo, guess_hi;
  int i;
  int first;
  int errcand;

  if (!sorted) {
    qsort(errno_ary, sizeof(errno_ary)/sizeof(int), sizeof(int), intcmp);
    sorted = 1;
  }

  first = 1;
  errcand = 0;
  for (i = 0; i < sizeof(errno_ary)/sizeof(int); i++) {
    guess_lo = errno_ary[i] < INT_MIN+100 ? INT_MIN : errno_ary[i]-100;
    guess_hi = INT_MAX-100 < errno_ary[i] ? INT_MAX : errno_ary[i]+100;

    if (first) {
      errcand = guess_lo;
      first = 0;
    }
    else {
      if (errcand < guess_lo)
        errcand = guess_lo;
    }
    while (errcand <= guess_hi) {
      if (errcand != 0)
        func(errcand, arg);
      errcand++;
    }
  }
}



int constant_name2int(char *name, int *ret)
{
#ifdef AF_INET
  if (sizeof(AF_INET) <= sizeof(int) && strcmp("AF_INET", name) == 0) {
    *ret = AF_INET;
    return 0;
  }
#endif
#ifdef AF_INET6
  if (sizeof(AF_INET6) <= sizeof(int) && strcmp("AF_INET6", name) == 0) {
    *ret = AF_INET6;
    return 0;
  }
#endif
#ifdef AF_UNIX
  if (sizeof(AF_UNIX) <= sizeof(int) && strcmp("AF_UNIX", name) == 0) {
    *ret = AF_UNIX;
    return 0;
  }
#endif
#ifdef AF_UNSPEC
  if (sizeof(AF_UNSPEC) <= sizeof(int) && strcmp("AF_UNSPEC", name) == 0) {
    *ret = AF_UNSPEC;
    return 0;
  }
#endif
#ifdef SOCK_DGRAM
  if (sizeof(SOCK_DGRAM) <= sizeof(int) && strcmp("SOCK_DGRAM", name) == 0) {
    *ret = SOCK_DGRAM;
    return 0;
  }
#endif
#ifdef SOCK_RAW
  if (sizeof(SOCK_RAW) <= sizeof(int) && strcmp("SOCK_RAW", name) == 0) {
    *ret = SOCK_RAW;
    return 0;
  }
#endif
#ifdef SOCK_SEQPACKET
  if (sizeof(SOCK_SEQPACKET) <= sizeof(int) && strcmp("SOCK_SEQPACKET", name) == 0) {
    *ret = SOCK_SEQPACKET;
    return 0;
  }
#endif
#ifdef SOCK_STREAM
  if (sizeof(SOCK_STREAM) <= sizeof(int) && strcmp("SOCK_STREAM", name) == 0) {
    *ret = SOCK_STREAM;
    return 0;
  }
#endif
#ifdef SHUT_RD
  if (sizeof(SHUT_RD) <= sizeof(int) && strcmp("SHUT_RD", name) == 0) {
    *ret = SHUT_RD;
    return 0;
  }
#endif
#ifdef SHUT_RDWR
  if (sizeof(SHUT_RDWR) <= sizeof(int) && strcmp("SHUT_RDWR", name) == 0) {
    *ret = SHUT_RDWR;
    return 0;
  }
#endif
#ifdef SHUT_WR
  if (sizeof(SHUT_WR) <= sizeof(int) && strcmp("SHUT_WR", name) == 0) {
    *ret = SHUT_WR;
    return 0;
  }
#endif
#ifdef MSG_CTRUNC
  if (sizeof(MSG_CTRUNC) <= sizeof(int) && strcmp("MSG_CTRUNC", name) == 0) {
    *ret = MSG_CTRUNC;
    return 0;
  }
#endif
#ifdef MSG_DONTROUTE
  if (sizeof(MSG_DONTROUTE) <= sizeof(int) && strcmp("MSG_DONTROUTE", name) == 0) {
    *ret = MSG_DONTROUTE;
    return 0;
  }
#endif
#ifdef MSG_EOR
  if (sizeof(MSG_EOR) <= sizeof(int) && strcmp("MSG_EOR", name) == 0) {
    *ret = MSG_EOR;
    return 0;
  }
#endif
#ifdef MSG_OOB
  if (sizeof(MSG_OOB) <= sizeof(int) && strcmp("MSG_OOB", name) == 0) {
    *ret = MSG_OOB;
    return 0;
  }
#endif
#ifdef MSG_NOSIGNAL
  if (sizeof(MSG_NOSIGNAL) <= sizeof(int) && strcmp("MSG_NOSIGNAL", name) == 0) {
    *ret = MSG_NOSIGNAL;
    return 0;
  }
#endif
#ifdef MSG_PEEK
  if (sizeof(MSG_PEEK) <= sizeof(int) && strcmp("MSG_PEEK", name) == 0) {
    *ret = MSG_PEEK;
    return 0;
  }
#endif
#ifdef MSG_TRUNC
  if (sizeof(MSG_TRUNC) <= sizeof(int) && strcmp("MSG_TRUNC", name) == 0) {
    *ret = MSG_TRUNC;
    return 0;
  }
#endif
#ifdef MSG_WAITALL
  if (sizeof(MSG_WAITALL) <= sizeof(int) && strcmp("MSG_WAITALL", name) == 0) {
    *ret = MSG_WAITALL;
    return 0;
  }
#endif
#ifdef SOL_SOCKET
  if (sizeof(SOL_SOCKET) <= sizeof(int) && strcmp("SOL_SOCKET", name) == 0) {
    *ret = SOL_SOCKET;
    return 0;
  }
#endif
#ifdef SO_ACCEPTCONN
  if (sizeof(SO_ACCEPTCONN) <= sizeof(int) && strcmp("SO_ACCEPTCONN", name) == 0) {
    *ret = SO_ACCEPTCONN;
    return 0;
  }
#endif
#ifdef SO_BROADCAST
  if (sizeof(SO_BROADCAST) <= sizeof(int) && strcmp("SO_BROADCAST", name) == 0) {
    *ret = SO_BROADCAST;
    return 0;
  }
#endif
#ifdef SO_DEBUG
  if (sizeof(SO_DEBUG) <= sizeof(int) && strcmp("SO_DEBUG", name) == 0) {
    *ret = SO_DEBUG;
    return 0;
  }
#endif
#ifdef SO_DONTROUTE
  if (sizeof(SO_DONTROUTE) <= sizeof(int) && strcmp("SO_DONTROUTE", name) == 0) {
    *ret = SO_DONTROUTE;
    return 0;
  }
#endif
#ifdef SO_ERROR
  if (sizeof(SO_ERROR) <= sizeof(int) && strcmp("SO_ERROR", name) == 0) {
    *ret = SO_ERROR;
    return 0;
  }
#endif
#ifdef SO_KEEPALIVE
  if (sizeof(SO_KEEPALIVE) <= sizeof(int) && strcmp("SO_KEEPALIVE", name) == 0) {
    *ret = SO_KEEPALIVE;
    return 0;
  }
#endif
#ifdef SO_LINGER
  if (sizeof(SO_LINGER) <= sizeof(int) && strcmp("SO_LINGER", name) == 0) {
    *ret = SO_LINGER;
    return 0;
  }
#endif
#ifdef SO_OOBINLINE
  if (sizeof(SO_OOBINLINE) <= sizeof(int) && strcmp("SO_OOBINLINE", name) == 0) {
    *ret = SO_OOBINLINE;
    return 0;
  }
#endif
#ifdef SO_RCVBUF
  if (sizeof(SO_RCVBUF) <= sizeof(int) && strcmp("SO_RCVBUF", name) == 0) {
    *ret = SO_RCVBUF;
    return 0;
  }
#endif
#ifdef SO_RCVLOWAT
  if (sizeof(SO_RCVLOWAT) <= sizeof(int) && strcmp("SO_RCVLOWAT", name) == 0) {
    *ret = SO_RCVLOWAT;
    return 0;
  }
#endif
#ifdef SO_RCVTIMEO
  if (sizeof(SO_RCVTIMEO) <= sizeof(int) && strcmp("SO_RCVTIMEO", name) == 0) {
    *ret = SO_RCVTIMEO;
    return 0;
  }
#endif
#ifdef SO_REUSEADDR
  if (sizeof(SO_REUSEADDR) <= sizeof(int) && strcmp("SO_REUSEADDR", name) == 0) {
    *ret = SO_REUSEADDR;
    return 0;
  }
#endif
#ifdef SO_SNDBUF
  if (sizeof(SO_SNDBUF) <= sizeof(int) && strcmp("SO_SNDBUF", name) == 0) {
    *ret = SO_SNDBUF;
    return 0;
  }
#endif
#ifdef SO_SNDLOWAT
  if (sizeof(SO_SNDLOWAT) <= sizeof(int) && strcmp("SO_SNDLOWAT", name) == 0) {
    *ret = SO_SNDLOWAT;
    return 0;
  }
#endif
#ifdef SO_SNDTIMEO
  if (sizeof(SO_SNDTIMEO) <= sizeof(int) && strcmp("SO_SNDTIMEO", name) == 0) {
    *ret = SO_SNDTIMEO;
    return 0;
  }
#endif
#ifdef SO_TYPE
  if (sizeof(SO_TYPE) <= sizeof(int) && strcmp("SO_TYPE", name) == 0) {
    *ret = SO_TYPE;
    return 0;
  }
#endif
#ifdef SCM_RIGHTS
  if (sizeof(SCM_RIGHTS) <= sizeof(int) && strcmp("SCM_RIGHTS", name) == 0) {
    *ret = SCM_RIGHTS;
    return 0;
  }
#endif
#ifdef SOMAXCONN
  if (sizeof(SOMAXCONN) <= sizeof(int) && strcmp("SOMAXCONN", name) == 0) {
    *ret = SOMAXCONN;
    return 0;
  }
#endif
  return -1;
}

void *constant_search_names(char *prefix, void *(*func)(char *name, int val, void *arg), void *arg)
{
  size_t prefixlen = strlen(prefix);
#ifdef AF_INET
  if (sizeof(AF_INET) <= sizeof(int) && strncmp("AF_INET", prefix, prefixlen) == 0) {
    void *ret = func("AF_INET", AF_INET, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef AF_INET6
  if (sizeof(AF_INET6) <= sizeof(int) && strncmp("AF_INET6", prefix, prefixlen) == 0) {
    void *ret = func("AF_INET6", AF_INET6, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef AF_UNIX
  if (sizeof(AF_UNIX) <= sizeof(int) && strncmp("AF_UNIX", prefix, prefixlen) == 0) {
    void *ret = func("AF_UNIX", AF_UNIX, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef AF_UNSPEC
  if (sizeof(AF_UNSPEC) <= sizeof(int) && strncmp("AF_UNSPEC", prefix, prefixlen) == 0) {
    void *ret = func("AF_UNSPEC", AF_UNSPEC, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_CTRUNC
  if (sizeof(MSG_CTRUNC) <= sizeof(int) && strncmp("MSG_CTRUNC", prefix, prefixlen) == 0) {
    void *ret = func("MSG_CTRUNC", MSG_CTRUNC, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_DONTROUTE
  if (sizeof(MSG_DONTROUTE) <= sizeof(int) && strncmp("MSG_DONTROUTE", prefix, prefixlen) == 0) {
    void *ret = func("MSG_DONTROUTE", MSG_DONTROUTE, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_EOR
  if (sizeof(MSG_EOR) <= sizeof(int) && strncmp("MSG_EOR", prefix, prefixlen) == 0) {
    void *ret = func("MSG_EOR", MSG_EOR, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_NOSIGNAL
  if (sizeof(MSG_NOSIGNAL) <= sizeof(int) && strncmp("MSG_NOSIGNAL", prefix, prefixlen) == 0) {
    void *ret = func("MSG_NOSIGNAL", MSG_NOSIGNAL, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_OOB
  if (sizeof(MSG_OOB) <= sizeof(int) && strncmp("MSG_OOB", prefix, prefixlen) == 0) {
    void *ret = func("MSG_OOB", MSG_OOB, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_PEEK
  if (sizeof(MSG_PEEK) <= sizeof(int) && strncmp("MSG_PEEK", prefix, prefixlen) == 0) {
    void *ret = func("MSG_PEEK", MSG_PEEK, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_TRUNC
  if (sizeof(MSG_TRUNC) <= sizeof(int) && strncmp("MSG_TRUNC", prefix, prefixlen) == 0) {
    void *ret = func("MSG_TRUNC", MSG_TRUNC, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef MSG_WAITALL
  if (sizeof(MSG_WAITALL) <= sizeof(int) && strncmp("MSG_WAITALL", prefix, prefixlen) == 0) {
    void *ret = func("MSG_WAITALL", MSG_WAITALL, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SCM_RIGHTS
  if (sizeof(SCM_RIGHTS) <= sizeof(int) && strncmp("SCM_RIGHTS", prefix, prefixlen) == 0) {
    void *ret = func("SCM_RIGHTS", SCM_RIGHTS, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SHUT_RD
  if (sizeof(SHUT_RD) <= sizeof(int) && strncmp("SHUT_RD", prefix, prefixlen) == 0) {
    void *ret = func("SHUT_RD", SHUT_RD, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SHUT_RDWR
  if (sizeof(SHUT_RDWR) <= sizeof(int) && strncmp("SHUT_RDWR", prefix, prefixlen) == 0) {
    void *ret = func("SHUT_RDWR", SHUT_RDWR, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SHUT_WR
  if (sizeof(SHUT_WR) <= sizeof(int) && strncmp("SHUT_WR", prefix, prefixlen) == 0) {
    void *ret = func("SHUT_WR", SHUT_WR, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SOCK_DGRAM
  if (sizeof(SOCK_DGRAM) <= sizeof(int) && strncmp("SOCK_DGRAM", prefix, prefixlen) == 0) {
    void *ret = func("SOCK_DGRAM", SOCK_DGRAM, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SOCK_RAW
  if (sizeof(SOCK_RAW) <= sizeof(int) && strncmp("SOCK_RAW", prefix, prefixlen) == 0) {
    void *ret = func("SOCK_RAW", SOCK_RAW, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SOCK_SEQPACKET
  if (sizeof(SOCK_SEQPACKET) <= sizeof(int) && strncmp("SOCK_SEQPACKET", prefix, prefixlen) == 0) {
    void *ret = func("SOCK_SEQPACKET", SOCK_SEQPACKET, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SOCK_STREAM
  if (sizeof(SOCK_STREAM) <= sizeof(int) && strncmp("SOCK_STREAM", prefix, prefixlen) == 0) {
    void *ret = func("SOCK_STREAM", SOCK_STREAM, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SOL_SOCKET
  if (sizeof(SOL_SOCKET) <= sizeof(int) && strncmp("SOL_SOCKET", prefix, prefixlen) == 0) {
    void *ret = func("SOL_SOCKET", SOL_SOCKET, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SOMAXCONN
  if (sizeof(SOMAXCONN) <= sizeof(int) && strncmp("SOMAXCONN", prefix, prefixlen) == 0) {
    void *ret = func("SOMAXCONN", SOMAXCONN, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_ACCEPTCONN
  if (sizeof(SO_ACCEPTCONN) <= sizeof(int) && strncmp("SO_ACCEPTCONN", prefix, prefixlen) == 0) {
    void *ret = func("SO_ACCEPTCONN", SO_ACCEPTCONN, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_BROADCAST
  if (sizeof(SO_BROADCAST) <= sizeof(int) && strncmp("SO_BROADCAST", prefix, prefixlen) == 0) {
    void *ret = func("SO_BROADCAST", SO_BROADCAST, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_DEBUG
  if (sizeof(SO_DEBUG) <= sizeof(int) && strncmp("SO_DEBUG", prefix, prefixlen) == 0) {
    void *ret = func("SO_DEBUG", SO_DEBUG, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_DONTROUTE
  if (sizeof(SO_DONTROUTE) <= sizeof(int) && strncmp("SO_DONTROUTE", prefix, prefixlen) == 0) {
    void *ret = func("SO_DONTROUTE", SO_DONTROUTE, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_ERROR
  if (sizeof(SO_ERROR) <= sizeof(int) && strncmp("SO_ERROR", prefix, prefixlen) == 0) {
    void *ret = func("SO_ERROR", SO_ERROR, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_KEEPALIVE
  if (sizeof(SO_KEEPALIVE) <= sizeof(int) && strncmp("SO_KEEPALIVE", prefix, prefixlen) == 0) {
    void *ret = func("SO_KEEPALIVE", SO_KEEPALIVE, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_LINGER
  if (sizeof(SO_LINGER) <= sizeof(int) && strncmp("SO_LINGER", prefix, prefixlen) == 0) {
    void *ret = func("SO_LINGER", SO_LINGER, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_OOBINLINE
  if (sizeof(SO_OOBINLINE) <= sizeof(int) && strncmp("SO_OOBINLINE", prefix, prefixlen) == 0) {
    void *ret = func("SO_OOBINLINE", SO_OOBINLINE, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_RCVBUF
  if (sizeof(SO_RCVBUF) <= sizeof(int) && strncmp("SO_RCVBUF", prefix, prefixlen) == 0) {
    void *ret = func("SO_RCVBUF", SO_RCVBUF, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_RCVLOWAT
  if (sizeof(SO_RCVLOWAT) <= sizeof(int) && strncmp("SO_RCVLOWAT", prefix, prefixlen) == 0) {
    void *ret = func("SO_RCVLOWAT", SO_RCVLOWAT, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_RCVTIMEO
  if (sizeof(SO_RCVTIMEO) <= sizeof(int) && strncmp("SO_RCVTIMEO", prefix, prefixlen) == 0) {
    void *ret = func("SO_RCVTIMEO", SO_RCVTIMEO, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_REUSEADDR
  if (sizeof(SO_REUSEADDR) <= sizeof(int) && strncmp("SO_REUSEADDR", prefix, prefixlen) == 0) {
    void *ret = func("SO_REUSEADDR", SO_REUSEADDR, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_SNDBUF
  if (sizeof(SO_SNDBUF) <= sizeof(int) && strncmp("SO_SNDBUF", prefix, prefixlen) == 0) {
    void *ret = func("SO_SNDBUF", SO_SNDBUF, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_SNDLOWAT
  if (sizeof(SO_SNDLOWAT) <= sizeof(int) && strncmp("SO_SNDLOWAT", prefix, prefixlen) == 0) {
    void *ret = func("SO_SNDLOWAT", SO_SNDLOWAT, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_SNDTIMEO
  if (sizeof(SO_SNDTIMEO) <= sizeof(int) && strncmp("SO_SNDTIMEO", prefix, prefixlen) == 0) {
    void *ret = func("SO_SNDTIMEO", SO_SNDTIMEO, arg);
    if (ret)
      return ret;
  }
#endif
#ifdef SO_TYPE
  if (sizeof(SO_TYPE) <= sizeof(int) && strncmp("SO_TYPE", prefix, prefixlen) == 0) {
    void *ret = func("SO_TYPE", SO_TYPE, arg);
    if (ret)
      return ret;
  }
#endif
  return NULL;
}
