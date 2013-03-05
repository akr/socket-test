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

const string_integer_pair_t internal_errno_to_name[] = {
#ifdef EAGAIN
  { "EAGAIN", (uintmax_t)EAGAIN, 0 < EAGAIN },
#endif
#ifdef ENOTSUP
  { "ENOTSUP", (uintmax_t)ENOTSUP, 0 < ENOTSUP },
#endif
#ifdef E2BIG
  { "E2BIG", (uintmax_t)E2BIG, 0 < E2BIG },
#endif
#ifdef EACCES
  { "EACCES", (uintmax_t)EACCES, 0 < EACCES },
#endif
#ifdef EADDRINUSE
  { "EADDRINUSE", (uintmax_t)EADDRINUSE, 0 < EADDRINUSE },
#endif
#ifdef EADDRNOTAVAIL
  { "EADDRNOTAVAIL", (uintmax_t)EADDRNOTAVAIL, 0 < EADDRNOTAVAIL },
#endif
#ifdef EAFNOSUPPORT
  { "EAFNOSUPPORT", (uintmax_t)EAFNOSUPPORT, 0 < EAFNOSUPPORT },
#endif
#ifdef EALREADY
  { "EALREADY", (uintmax_t)EALREADY, 0 < EALREADY },
#endif
#ifdef EBADF
  { "EBADF", (uintmax_t)EBADF, 0 < EBADF },
#endif
#ifdef EBADMSG
  { "EBADMSG", (uintmax_t)EBADMSG, 0 < EBADMSG },
#endif
#ifdef EBUSY
  { "EBUSY", (uintmax_t)EBUSY, 0 < EBUSY },
#endif
#ifdef ECANCELED
  { "ECANCELED", (uintmax_t)ECANCELED, 0 < ECANCELED },
#endif
#ifdef ECHILD
  { "ECHILD", (uintmax_t)ECHILD, 0 < ECHILD },
#endif
#ifdef ECONNABORTED
  { "ECONNABORTED", (uintmax_t)ECONNABORTED, 0 < ECONNABORTED },
#endif
#ifdef ECONNREFUSED
  { "ECONNREFUSED", (uintmax_t)ECONNREFUSED, 0 < ECONNREFUSED },
#endif
#ifdef ECONNRESET
  { "ECONNRESET", (uintmax_t)ECONNRESET, 0 < ECONNRESET },
#endif
#ifdef EDEADLK
  { "EDEADLK", (uintmax_t)EDEADLK, 0 < EDEADLK },
#endif
#ifdef EDESTADDRREQ
  { "EDESTADDRREQ", (uintmax_t)EDESTADDRREQ, 0 < EDESTADDRREQ },
#endif
#ifdef EDOM
  { "EDOM", (uintmax_t)EDOM, 0 < EDOM },
#endif
#ifdef EDQUOT
  { "EDQUOT", (uintmax_t)EDQUOT, 0 < EDQUOT },
#endif
#ifdef EEXIST
  { "EEXIST", (uintmax_t)EEXIST, 0 < EEXIST },
#endif
#ifdef EFAULT
  { "EFAULT", (uintmax_t)EFAULT, 0 < EFAULT },
#endif
#ifdef EFBIG
  { "EFBIG", (uintmax_t)EFBIG, 0 < EFBIG },
#endif
#ifdef EHOSTUNREACH
  { "EHOSTUNREACH", (uintmax_t)EHOSTUNREACH, 0 < EHOSTUNREACH },
#endif
#ifdef EIDRM
  { "EIDRM", (uintmax_t)EIDRM, 0 < EIDRM },
#endif
#ifdef EILSEQ
  { "EILSEQ", (uintmax_t)EILSEQ, 0 < EILSEQ },
#endif
#ifdef EINPROGRESS
  { "EINPROGRESS", (uintmax_t)EINPROGRESS, 0 < EINPROGRESS },
#endif
#ifdef EINTR
  { "EINTR", (uintmax_t)EINTR, 0 < EINTR },
#endif
#ifdef EINVAL
  { "EINVAL", (uintmax_t)EINVAL, 0 < EINVAL },
#endif
#ifdef EIO
  { "EIO", (uintmax_t)EIO, 0 < EIO },
#endif
#ifdef EISCONN
  { "EISCONN", (uintmax_t)EISCONN, 0 < EISCONN },
#endif
#ifdef EISDIR
  { "EISDIR", (uintmax_t)EISDIR, 0 < EISDIR },
#endif
#ifdef ELOOP
  { "ELOOP", (uintmax_t)ELOOP, 0 < ELOOP },
#endif
#ifdef EMFILE
  { "EMFILE", (uintmax_t)EMFILE, 0 < EMFILE },
#endif
#ifdef EMLINK
  { "EMLINK", (uintmax_t)EMLINK, 0 < EMLINK },
#endif
#ifdef EMSGSIZE
  { "EMSGSIZE", (uintmax_t)EMSGSIZE, 0 < EMSGSIZE },
#endif
#ifdef EMULTIHOP
  { "EMULTIHOP", (uintmax_t)EMULTIHOP, 0 < EMULTIHOP },
#endif
#ifdef ENAMETOOLONG
  { "ENAMETOOLONG", (uintmax_t)ENAMETOOLONG, 0 < ENAMETOOLONG },
#endif
#ifdef ENETDOWN
  { "ENETDOWN", (uintmax_t)ENETDOWN, 0 < ENETDOWN },
#endif
#ifdef ENETRESET
  { "ENETRESET", (uintmax_t)ENETRESET, 0 < ENETRESET },
#endif
#ifdef ENETUNREACH
  { "ENETUNREACH", (uintmax_t)ENETUNREACH, 0 < ENETUNREACH },
#endif
#ifdef ENFILE
  { "ENFILE", (uintmax_t)ENFILE, 0 < ENFILE },
#endif
#ifdef ENOBUFS
  { "ENOBUFS", (uintmax_t)ENOBUFS, 0 < ENOBUFS },
#endif
#ifdef ENODATA
  { "ENODATA", (uintmax_t)ENODATA, 0 < ENODATA },
#endif
#ifdef ENODEV
  { "ENODEV", (uintmax_t)ENODEV, 0 < ENODEV },
#endif
#ifdef ENOENT
  { "ENOENT", (uintmax_t)ENOENT, 0 < ENOENT },
#endif
#ifdef ENOEXEC
  { "ENOEXEC", (uintmax_t)ENOEXEC, 0 < ENOEXEC },
#endif
#ifdef ENOLCK
  { "ENOLCK", (uintmax_t)ENOLCK, 0 < ENOLCK },
#endif
#ifdef ENOLINK
  { "ENOLINK", (uintmax_t)ENOLINK, 0 < ENOLINK },
#endif
#ifdef ENOMEM
  { "ENOMEM", (uintmax_t)ENOMEM, 0 < ENOMEM },
#endif
#ifdef ENOMSG
  { "ENOMSG", (uintmax_t)ENOMSG, 0 < ENOMSG },
#endif
#ifdef ENOPROTOOPT
  { "ENOPROTOOPT", (uintmax_t)ENOPROTOOPT, 0 < ENOPROTOOPT },
#endif
#ifdef ENOSPC
  { "ENOSPC", (uintmax_t)ENOSPC, 0 < ENOSPC },
#endif
#ifdef ENOSR
  { "ENOSR", (uintmax_t)ENOSR, 0 < ENOSR },
#endif
#ifdef ENOSTR
  { "ENOSTR", (uintmax_t)ENOSTR, 0 < ENOSTR },
#endif
#ifdef ENOSYS
  { "ENOSYS", (uintmax_t)ENOSYS, 0 < ENOSYS },
#endif
#ifdef ENOTCONN
  { "ENOTCONN", (uintmax_t)ENOTCONN, 0 < ENOTCONN },
#endif
#ifdef ENOTDIR
  { "ENOTDIR", (uintmax_t)ENOTDIR, 0 < ENOTDIR },
#endif
#ifdef ENOTEMPTY
  { "ENOTEMPTY", (uintmax_t)ENOTEMPTY, 0 < ENOTEMPTY },
#endif
#ifdef ENOTRECOVERABLE
  { "ENOTRECOVERABLE", (uintmax_t)ENOTRECOVERABLE, 0 < ENOTRECOVERABLE },
#endif
#ifdef ENOTSOCK
  { "ENOTSOCK", (uintmax_t)ENOTSOCK, 0 < ENOTSOCK },
#endif
#ifdef ENOTTY
  { "ENOTTY", (uintmax_t)ENOTTY, 0 < ENOTTY },
#endif
#ifdef ENXIO
  { "ENXIO", (uintmax_t)ENXIO, 0 < ENXIO },
#endif
#ifdef EOPNOTSUPP
  { "EOPNOTSUPP", (uintmax_t)EOPNOTSUPP, 0 < EOPNOTSUPP },
#endif
#ifdef EOVERFLOW
  { "EOVERFLOW", (uintmax_t)EOVERFLOW, 0 < EOVERFLOW },
#endif
#ifdef EOWNERDEAD
  { "EOWNERDEAD", (uintmax_t)EOWNERDEAD, 0 < EOWNERDEAD },
#endif
#ifdef EPERM
  { "EPERM", (uintmax_t)EPERM, 0 < EPERM },
#endif
#ifdef EPIPE
  { "EPIPE", (uintmax_t)EPIPE, 0 < EPIPE },
#endif
#ifdef EPROTO
  { "EPROTO", (uintmax_t)EPROTO, 0 < EPROTO },
#endif
#ifdef EPROTONOSUPPORT
  { "EPROTONOSUPPORT", (uintmax_t)EPROTONOSUPPORT, 0 < EPROTONOSUPPORT },
#endif
#ifdef EPROTOTYPE
  { "EPROTOTYPE", (uintmax_t)EPROTOTYPE, 0 < EPROTOTYPE },
#endif
#ifdef ERANGE
  { "ERANGE", (uintmax_t)ERANGE, 0 < ERANGE },
#endif
#ifdef EROFS
  { "EROFS", (uintmax_t)EROFS, 0 < EROFS },
#endif
#ifdef ESPIPE
  { "ESPIPE", (uintmax_t)ESPIPE, 0 < ESPIPE },
#endif
#ifdef ESRCH
  { "ESRCH", (uintmax_t)ESRCH, 0 < ESRCH },
#endif
#ifdef ESTALE
  { "ESTALE", (uintmax_t)ESTALE, 0 < ESTALE },
#endif
#ifdef ETIME
  { "ETIME", (uintmax_t)ETIME, 0 < ETIME },
#endif
#ifdef ETIMEDOUT
  { "ETIMEDOUT", (uintmax_t)ETIMEDOUT, 0 < ETIMEDOUT },
#endif
#ifdef ETXTBSY
  { "ETXTBSY", (uintmax_t)ETXTBSY, 0 < ETXTBSY },
#endif
#ifdef EWOULDBLOCK
  { "EWOULDBLOCK", (uintmax_t)EWOULDBLOCK, 0 < EWOULDBLOCK },
#endif
#ifdef EXDEV
  { "EXDEV", (uintmax_t)EXDEV, 0 < EXDEV },
#endif
#ifdef ENOTBLK
  { "ENOTBLK", (uintmax_t)ENOTBLK, 0 < ENOTBLK },
#endif
#ifdef ECHRNG
  { "ECHRNG", (uintmax_t)ECHRNG, 0 < ECHRNG },
#endif
#ifdef EL2NSYNC
  { "EL2NSYNC", (uintmax_t)EL2NSYNC, 0 < EL2NSYNC },
#endif
#ifdef EL3HLT
  { "EL3HLT", (uintmax_t)EL3HLT, 0 < EL3HLT },
#endif
#ifdef EL3RST
  { "EL3RST", (uintmax_t)EL3RST, 0 < EL3RST },
#endif
#ifdef ELNRNG
  { "ELNRNG", (uintmax_t)ELNRNG, 0 < ELNRNG },
#endif
#ifdef EUNATCH
  { "EUNATCH", (uintmax_t)EUNATCH, 0 < EUNATCH },
#endif
#ifdef ENOCSI
  { "ENOCSI", (uintmax_t)ENOCSI, 0 < ENOCSI },
#endif
#ifdef EL2HLT
  { "EL2HLT", (uintmax_t)EL2HLT, 0 < EL2HLT },
#endif
#ifdef EBADE
  { "EBADE", (uintmax_t)EBADE, 0 < EBADE },
#endif
#ifdef EBADR
  { "EBADR", (uintmax_t)EBADR, 0 < EBADR },
#endif
#ifdef EXFULL
  { "EXFULL", (uintmax_t)EXFULL, 0 < EXFULL },
#endif
#ifdef ENOANO
  { "ENOANO", (uintmax_t)ENOANO, 0 < ENOANO },
#endif
#ifdef EBADRQC
  { "EBADRQC", (uintmax_t)EBADRQC, 0 < EBADRQC },
#endif
#ifdef EBADSLT
  { "EBADSLT", (uintmax_t)EBADSLT, 0 < EBADSLT },
#endif
#ifdef EDEADLOCK
  { "EDEADLOCK", (uintmax_t)EDEADLOCK, 0 < EDEADLOCK },
#endif
#ifdef EBFONT
  { "EBFONT", (uintmax_t)EBFONT, 0 < EBFONT },
#endif
#ifdef ENONET
  { "ENONET", (uintmax_t)ENONET, 0 < ENONET },
#endif
#ifdef ENOPKG
  { "ENOPKG", (uintmax_t)ENOPKG, 0 < ENOPKG },
#endif
#ifdef EREMOTE
  { "EREMOTE", (uintmax_t)EREMOTE, 0 < EREMOTE },
#endif
#ifdef EADV
  { "EADV", (uintmax_t)EADV, 0 < EADV },
#endif
#ifdef ESRMNT
  { "ESRMNT", (uintmax_t)ESRMNT, 0 < ESRMNT },
#endif
#ifdef ECOMM
  { "ECOMM", (uintmax_t)ECOMM, 0 < ECOMM },
#endif
#ifdef EDOTDOT
  { "EDOTDOT", (uintmax_t)EDOTDOT, 0 < EDOTDOT },
#endif
#ifdef ENOTUNIQ
  { "ENOTUNIQ", (uintmax_t)ENOTUNIQ, 0 < ENOTUNIQ },
#endif
#ifdef EBADFD
  { "EBADFD", (uintmax_t)EBADFD, 0 < EBADFD },
#endif
#ifdef EREMCHG
  { "EREMCHG", (uintmax_t)EREMCHG, 0 < EREMCHG },
#endif
#ifdef ELIBACC
  { "ELIBACC", (uintmax_t)ELIBACC, 0 < ELIBACC },
#endif
#ifdef ELIBBAD
  { "ELIBBAD", (uintmax_t)ELIBBAD, 0 < ELIBBAD },
#endif
#ifdef ELIBSCN
  { "ELIBSCN", (uintmax_t)ELIBSCN, 0 < ELIBSCN },
#endif
#ifdef ELIBMAX
  { "ELIBMAX", (uintmax_t)ELIBMAX, 0 < ELIBMAX },
#endif
#ifdef ELIBEXEC
  { "ELIBEXEC", (uintmax_t)ELIBEXEC, 0 < ELIBEXEC },
#endif
#ifdef ERESTART
  { "ERESTART", (uintmax_t)ERESTART, 0 < ERESTART },
#endif
#ifdef ESTRPIPE
  { "ESTRPIPE", (uintmax_t)ESTRPIPE, 0 < ESTRPIPE },
#endif
#ifdef EUSERS
  { "EUSERS", (uintmax_t)EUSERS, 0 < EUSERS },
#endif
#ifdef ESOCKTNOSUPPORT
  { "ESOCKTNOSUPPORT", (uintmax_t)ESOCKTNOSUPPORT, 0 < ESOCKTNOSUPPORT },
#endif
#ifdef EPFNOSUPPORT
  { "EPFNOSUPPORT", (uintmax_t)EPFNOSUPPORT, 0 < EPFNOSUPPORT },
#endif
#ifdef ESHUTDOWN
  { "ESHUTDOWN", (uintmax_t)ESHUTDOWN, 0 < ESHUTDOWN },
#endif
#ifdef ETOOMANYREFS
  { "ETOOMANYREFS", (uintmax_t)ETOOMANYREFS, 0 < ETOOMANYREFS },
#endif
#ifdef EHOSTDOWN
  { "EHOSTDOWN", (uintmax_t)EHOSTDOWN, 0 < EHOSTDOWN },
#endif
#ifdef EUCLEAN
  { "EUCLEAN", (uintmax_t)EUCLEAN, 0 < EUCLEAN },
#endif
#ifdef ENOTNAM
  { "ENOTNAM", (uintmax_t)ENOTNAM, 0 < ENOTNAM },
#endif
#ifdef ENAVAIL
  { "ENAVAIL", (uintmax_t)ENAVAIL, 0 < ENAVAIL },
#endif
#ifdef EISNAM
  { "EISNAM", (uintmax_t)EISNAM, 0 < EISNAM },
#endif
#ifdef EREMOTEIO
  { "EREMOTEIO", (uintmax_t)EREMOTEIO, 0 < EREMOTEIO },
#endif
#ifdef ENOMEDIUM
  { "ENOMEDIUM", (uintmax_t)ENOMEDIUM, 0 < ENOMEDIUM },
#endif
#ifdef EMEDIUMTYPE
  { "EMEDIUMTYPE", (uintmax_t)EMEDIUMTYPE, 0 < EMEDIUMTYPE },
#endif
#ifdef ENOKEY
  { "ENOKEY", (uintmax_t)ENOKEY, 0 < ENOKEY },
#endif
#ifdef EKEYEXPIRED
  { "EKEYEXPIRED", (uintmax_t)EKEYEXPIRED, 0 < EKEYEXPIRED },
#endif
#ifdef EKEYREVOKED
  { "EKEYREVOKED", (uintmax_t)EKEYREVOKED, 0 < EKEYREVOKED },
#endif
#ifdef EKEYREJECTED
  { "EKEYREJECTED", (uintmax_t)EKEYREJECTED, 0 < EKEYREJECTED },
#endif
#ifdef ERFKILL
  { "ERFKILL", (uintmax_t)ERFKILL, 0 < ERFKILL },
#endif
#ifdef EHWPOISON
  { "EHWPOISON", (uintmax_t)EHWPOISON, 0 < EHWPOISON },
#endif
#ifdef EAUTH
  { "EAUTH", (uintmax_t)EAUTH, 0 < EAUTH },
#endif
#ifdef EBACKGROUND
  { "EBACKGROUND", (uintmax_t)EBACKGROUND, 0 < EBACKGROUND },
#endif
#ifdef EBADRPC
  { "EBADRPC", (uintmax_t)EBADRPC, 0 < EBADRPC },
#endif
#ifdef ED
  { "ED", (uintmax_t)ED, 0 < ED },
#endif
#ifdef EDIED
  { "EDIED", (uintmax_t)EDIED, 0 < EDIED },
#endif
#ifdef EFTYPE
  { "EFTYPE", (uintmax_t)EFTYPE, 0 < EFTYPE },
#endif
#ifdef EGRATUITOUS
  { "EGRATUITOUS", (uintmax_t)EGRATUITOUS, 0 < EGRATUITOUS },
#endif
#ifdef EGREGIOUS
  { "EGREGIOUS", (uintmax_t)EGREGIOUS, 0 < EGREGIOUS },
#endif
#ifdef EIEIO
  { "EIEIO", (uintmax_t)EIEIO, 0 < EIEIO },
#endif
#ifdef ELAST
  { "ELAST", (uintmax_t)ELAST, 0 < ELAST },
#endif
#ifdef ENEEDAUTH
  { "ENEEDAUTH", (uintmax_t)ENEEDAUTH, 0 < ENEEDAUTH },
#endif
#ifdef EPROCLIM
  { "EPROCLIM", (uintmax_t)EPROCLIM, 0 < EPROCLIM },
#endif
#ifdef EPROCUNAVAIL
  { "EPROCUNAVAIL", (uintmax_t)EPROCUNAVAIL, 0 < EPROCUNAVAIL },
#endif
#ifdef EPROGMISMATCH
  { "EPROGMISMATCH", (uintmax_t)EPROGMISMATCH, 0 < EPROGMISMATCH },
#endif
#ifdef EPROGUNAVAIL
  { "EPROGUNAVAIL", (uintmax_t)EPROGUNAVAIL, 0 < EPROGUNAVAIL },
#endif
#ifdef ERPCMISMATCH
  { "ERPCMISMATCH", (uintmax_t)ERPCMISMATCH, 0 < ERPCMISMATCH },
#endif
#ifdef ENOATTR
  { "ENOATTR", (uintmax_t)ENOATTR, 0 < ENOATTR },
#endif
#ifdef EIPSEC
  { "EIPSEC", (uintmax_t)EIPSEC, 0 < EIPSEC },
#endif
#ifdef EDOOFUS
  { "EDOOFUS", (uintmax_t)EDOOFUS, 0 < EDOOFUS },
#endif
#ifdef ENOTCAPABLE
  { "ENOTCAPABLE", (uintmax_t)ENOTCAPABLE, 0 < ENOTCAPABLE },
#endif
#ifdef ECAPMODE
  { "ECAPMODE", (uintmax_t)ECAPMODE, 0 < ECAPMODE },
#endif
#ifdef EPWROFF
  { "EPWROFF", (uintmax_t)EPWROFF, 0 < EPWROFF },
#endif
#ifdef EDEVERR
  { "EDEVERR", (uintmax_t)EDEVERR, 0 < EDEVERR },
#endif
#ifdef EBADEXEC
  { "EBADEXEC", (uintmax_t)EBADEXEC, 0 < EBADEXEC },
#endif
#ifdef EBADARCH
  { "EBADARCH", (uintmax_t)EBADARCH, 0 < EBADARCH },
#endif
#ifdef ESHLIBVERS
  { "ESHLIBVERS", (uintmax_t)ESHLIBVERS, 0 < ESHLIBVERS },
#endif
#ifdef EBADMACHO
  { "EBADMACHO", (uintmax_t)EBADMACHO, 0 < EBADMACHO },
#endif
#ifdef ENOPOLICY
  { "ENOPOLICY", (uintmax_t)ENOPOLICY, 0 < ENOPOLICY },
#endif
#ifdef EPACKSIZE
  { "EPACKSIZE", (uintmax_t)EPACKSIZE, 0 < EPACKSIZE },
#endif
#ifdef EBADIOCTL
  { "EBADIOCTL", (uintmax_t)EBADIOCTL, 0 < EBADIOCTL },
#endif
#ifdef EBADMODE
  { "EBADMODE", (uintmax_t)EBADMODE, 0 < EBADMODE },
#endif
#ifdef EURG
  { "EURG", (uintmax_t)EURG, 0 < EURG },
#endif
#ifdef ENOURG
  { "ENOURG", (uintmax_t)ENOURG, 0 < ENOURG },
#endif
#ifdef ENOCONN
  { "ENOCONN", (uintmax_t)ENOCONN, 0 < ENOCONN },
#endif
#ifdef EGENERIC
  { "EGENERIC", (uintmax_t)EGENERIC, 0 < EGENERIC },
#endif
#ifdef ELOCKED
  { "ELOCKED", (uintmax_t)ELOCKED, 0 < ELOCKED },
#endif
#ifdef EBADCALL
  { "EBADCALL", (uintmax_t)EBADCALL, 0 < EBADCALL },
#endif
#ifdef EBADSRCDST
  { "EBADSRCDST", (uintmax_t)EBADSRCDST, 0 < EBADSRCDST },
#endif
#ifdef ECALLDENIED
  { "ECALLDENIED", (uintmax_t)ECALLDENIED, 0 < ECALLDENIED },
#endif
#ifdef EDEADSRCDST
  { "EDEADSRCDST", (uintmax_t)EDEADSRCDST, 0 < EDEADSRCDST },
#endif
#ifdef ENOTREADY
  { "ENOTREADY", (uintmax_t)ENOTREADY, 0 < ENOTREADY },
#endif
#ifdef EBADREQUEST
  { "EBADREQUEST", (uintmax_t)EBADREQUEST, 0 < EBADREQUEST },
#endif
#ifdef ETRAPDENIED
  { "ETRAPDENIED", (uintmax_t)ETRAPDENIED, 0 < ETRAPDENIED },
#endif
#ifdef EDONTREPLY
  { "EDONTREPLY", (uintmax_t)EDONTREPLY, 0 < EDONTREPLY },
#endif
#ifdef EBADEPT
  { "EBADEPT", (uintmax_t)EBADEPT, 0 < EBADEPT },
#endif
#ifdef EDEADEPT
  { "EDEADEPT", (uintmax_t)EDEADEPT, 0 < EDEADEPT },
#endif
#ifdef EBADCPU
  { "EBADCPU", (uintmax_t)EBADCPU, 0 < EBADCPU },
#endif
#ifdef ELBIN
  { "ELBIN", (uintmax_t)ELBIN, 0 < ELBIN },
#endif
#ifdef ENMFILE
  { "ENMFILE", (uintmax_t)ENMFILE, 0 < ENMFILE },
#endif
#ifdef ENOSHARE
  { "ENOSHARE", (uintmax_t)ENOSHARE, 0 < ENOSHARE },
#endif
#ifdef ECASECLASH
  { "ECASECLASH", (uintmax_t)ECASECLASH, 0 < ECASECLASH },
#endif
#ifdef ELOCKUNMAPPED
  { "ELOCKUNMAPPED", (uintmax_t)ELOCKUNMAPPED, 0 < ELOCKUNMAPPED },
#endif
#ifdef ENOTACTIVE
  { "ENOTACTIVE", (uintmax_t)ENOTACTIVE, 0 < ENOTACTIVE },
#endif
#ifdef B_NO_ERROR
  { "B_NO_ERROR", (uintmax_t)B_NO_ERROR, 0 < B_NO_ERROR },
#endif
#ifdef B_ERROR
  { "B_ERROR", (uintmax_t)B_ERROR, 0 < B_ERROR },
#endif
#ifdef B_NO_MEMORY
  { "B_NO_MEMORY", (uintmax_t)B_NO_MEMORY, 0 < B_NO_MEMORY },
#endif
#ifdef B_POSIX_ENOMEM
  { "B_POSIX_ENOMEM", (uintmax_t)B_POSIX_ENOMEM, 0 < B_POSIX_ENOMEM },
#endif
#ifdef B_IO_ERROR
  { "B_IO_ERROR", (uintmax_t)B_IO_ERROR, 0 < B_IO_ERROR },
#endif
#ifdef B_PERMISSION_DENIED
  { "B_PERMISSION_DENIED", (uintmax_t)B_PERMISSION_DENIED, 0 < B_PERMISSION_DENIED },
#endif
#ifdef B_BAD_INDEX
  { "B_BAD_INDEX", (uintmax_t)B_BAD_INDEX, 0 < B_BAD_INDEX },
#endif
#ifdef B_BAD_TYPE
  { "B_BAD_TYPE", (uintmax_t)B_BAD_TYPE, 0 < B_BAD_TYPE },
#endif
#ifdef B_BAD_VALUE
  { "B_BAD_VALUE", (uintmax_t)B_BAD_VALUE, 0 < B_BAD_VALUE },
#endif
#ifdef B_MISMATCHED_VALUES
  { "B_MISMATCHED_VALUES", (uintmax_t)B_MISMATCHED_VALUES, 0 < B_MISMATCHED_VALUES },
#endif
#ifdef B_NAME_NOT_FOUND
  { "B_NAME_NOT_FOUND", (uintmax_t)B_NAME_NOT_FOUND, 0 < B_NAME_NOT_FOUND },
#endif
#ifdef B_NAME_IN_USE
  { "B_NAME_IN_USE", (uintmax_t)B_NAME_IN_USE, 0 < B_NAME_IN_USE },
#endif
#ifdef B_TIMED_OUT
  { "B_TIMED_OUT", (uintmax_t)B_TIMED_OUT, 0 < B_TIMED_OUT },
#endif
#ifdef B_INTERRUPTED
  { "B_INTERRUPTED", (uintmax_t)B_INTERRUPTED, 0 < B_INTERRUPTED },
#endif
#ifdef B_WOULD_BLOCK
  { "B_WOULD_BLOCK", (uintmax_t)B_WOULD_BLOCK, 0 < B_WOULD_BLOCK },
#endif
#ifdef B_CANCELED
  { "B_CANCELED", (uintmax_t)B_CANCELED, 0 < B_CANCELED },
#endif
#ifdef B_NO_INIT
  { "B_NO_INIT", (uintmax_t)B_NO_INIT, 0 < B_NO_INIT },
#endif
#ifdef B_BUSY
  { "B_BUSY", (uintmax_t)B_BUSY, 0 < B_BUSY },
#endif
#ifdef B_NOT_ALLOWED
  { "B_NOT_ALLOWED", (uintmax_t)B_NOT_ALLOWED, 0 < B_NOT_ALLOWED },
#endif
#ifdef B_BAD_DATA
  { "B_BAD_DATA", (uintmax_t)B_BAD_DATA, 0 < B_BAD_DATA },
#endif
#ifdef B_BAD_SEM_ID
  { "B_BAD_SEM_ID", (uintmax_t)B_BAD_SEM_ID, 0 < B_BAD_SEM_ID },
#endif
#ifdef B_NO_MORE_SEMS
  { "B_NO_MORE_SEMS", (uintmax_t)B_NO_MORE_SEMS, 0 < B_NO_MORE_SEMS },
#endif
#ifdef B_BAD_THREAD_ID
  { "B_BAD_THREAD_ID", (uintmax_t)B_BAD_THREAD_ID, 0 < B_BAD_THREAD_ID },
#endif
#ifdef B_NO_MORE_THREADS
  { "B_NO_MORE_THREADS", (uintmax_t)B_NO_MORE_THREADS, 0 < B_NO_MORE_THREADS },
#endif
#ifdef B_BAD_THREAD_STATE
  { "B_BAD_THREAD_STATE", (uintmax_t)B_BAD_THREAD_STATE, 0 < B_BAD_THREAD_STATE },
#endif
#ifdef B_BAD_TEAM_ID
  { "B_BAD_TEAM_ID", (uintmax_t)B_BAD_TEAM_ID, 0 < B_BAD_TEAM_ID },
#endif
#ifdef B_NO_MORE_TEAMS
  { "B_NO_MORE_TEAMS", (uintmax_t)B_NO_MORE_TEAMS, 0 < B_NO_MORE_TEAMS },
#endif
#ifdef B_BAD_PORT_ID
  { "B_BAD_PORT_ID", (uintmax_t)B_BAD_PORT_ID, 0 < B_BAD_PORT_ID },
#endif
#ifdef B_NO_MORE_PORTS
  { "B_NO_MORE_PORTS", (uintmax_t)B_NO_MORE_PORTS, 0 < B_NO_MORE_PORTS },
#endif
#ifdef B_BAD_IMAGE_ID
  { "B_BAD_IMAGE_ID", (uintmax_t)B_BAD_IMAGE_ID, 0 < B_BAD_IMAGE_ID },
#endif
#ifdef B_BAD_ADDRESS
  { "B_BAD_ADDRESS", (uintmax_t)B_BAD_ADDRESS, 0 < B_BAD_ADDRESS },
#endif
#ifdef B_NOT_AN_EXECUTABLE
  { "B_NOT_AN_EXECUTABLE", (uintmax_t)B_NOT_AN_EXECUTABLE, 0 < B_NOT_AN_EXECUTABLE },
#endif
#ifdef B_MISSING_LIBRARY
  { "B_MISSING_LIBRARY", (uintmax_t)B_MISSING_LIBRARY, 0 < B_MISSING_LIBRARY },
#endif
#ifdef B_MISSING_SYMBOL
  { "B_MISSING_SYMBOL", (uintmax_t)B_MISSING_SYMBOL, 0 < B_MISSING_SYMBOL },
#endif
#ifdef B_DEBUGGER_ALREADY_INSTALLED
  { "B_DEBUGGER_ALREADY_INSTALLED", (uintmax_t)B_DEBUGGER_ALREADY_INSTALLED, 0 < B_DEBUGGER_ALREADY_INSTALLED },
#endif
#ifdef B_BAD_REPLY
  { "B_BAD_REPLY", (uintmax_t)B_BAD_REPLY, 0 < B_BAD_REPLY },
#endif
#ifdef B_DUPLICATE_REPLY
  { "B_DUPLICATE_REPLY", (uintmax_t)B_DUPLICATE_REPLY, 0 < B_DUPLICATE_REPLY },
#endif
#ifdef B_MESSAGE_TO_SELF
  { "B_MESSAGE_TO_SELF", (uintmax_t)B_MESSAGE_TO_SELF, 0 < B_MESSAGE_TO_SELF },
#endif
#ifdef B_BAD_HANDLER
  { "B_BAD_HANDLER", (uintmax_t)B_BAD_HANDLER, 0 < B_BAD_HANDLER },
#endif
#ifdef B_ALREADY_RUNNING
  { "B_ALREADY_RUNNING", (uintmax_t)B_ALREADY_RUNNING, 0 < B_ALREADY_RUNNING },
#endif
#ifdef B_LAUNCH_FAILED
  { "B_LAUNCH_FAILED", (uintmax_t)B_LAUNCH_FAILED, 0 < B_LAUNCH_FAILED },
#endif
#ifdef B_AMBIGUOUS_APP_LAUNCH
  { "B_AMBIGUOUS_APP_LAUNCH", (uintmax_t)B_AMBIGUOUS_APP_LAUNCH, 0 < B_AMBIGUOUS_APP_LAUNCH },
#endif
#ifdef B_UNKNOWN_MIME_TYPE
  { "B_UNKNOWN_MIME_TYPE", (uintmax_t)B_UNKNOWN_MIME_TYPE, 0 < B_UNKNOWN_MIME_TYPE },
#endif
#ifdef B_BAD_SCRIPT_SYNTAX
  { "B_BAD_SCRIPT_SYNTAX", (uintmax_t)B_BAD_SCRIPT_SYNTAX, 0 < B_BAD_SCRIPT_SYNTAX },
#endif
#ifdef B_LAUNCH_FAILED_NO_RESOLVE_LINK
  { "B_LAUNCH_FAILED_NO_RESOLVE_LINK", (uintmax_t)B_LAUNCH_FAILED_NO_RESOLVE_LINK, 0 < B_LAUNCH_FAILED_NO_RESOLVE_LINK },
#endif
#ifdef B_LAUNCH_FAILED_EXECUTABLE
  { "B_LAUNCH_FAILED_EXECUTABLE", (uintmax_t)B_LAUNCH_FAILED_EXECUTABLE, 0 < B_LAUNCH_FAILED_EXECUTABLE },
#endif
#ifdef B_LAUNCH_FAILED_APP_NOT_FOUND
  { "B_LAUNCH_FAILED_APP_NOT_FOUND", (uintmax_t)B_LAUNCH_FAILED_APP_NOT_FOUND, 0 < B_LAUNCH_FAILED_APP_NOT_FOUND },
#endif
#ifdef B_LAUNCH_FAILED_APP_IN_TRASH
  { "B_LAUNCH_FAILED_APP_IN_TRASH", (uintmax_t)B_LAUNCH_FAILED_APP_IN_TRASH, 0 < B_LAUNCH_FAILED_APP_IN_TRASH },
#endif
#ifdef B_LAUNCH_FAILED_NO_PREFERRED_APP
  { "B_LAUNCH_FAILED_NO_PREFERRED_APP", (uintmax_t)B_LAUNCH_FAILED_NO_PREFERRED_APP, 0 < B_LAUNCH_FAILED_NO_PREFERRED_APP },
#endif
#ifdef B_LAUNCH_FAILED_FILES_APP_NOT_FOUND
  { "B_LAUNCH_FAILED_FILES_APP_NOT_FOUND", (uintmax_t)B_LAUNCH_FAILED_FILES_APP_NOT_FOUND, 0 < B_LAUNCH_FAILED_FILES_APP_NOT_FOUND },
#endif
#ifdef B_BAD_MIME_SNIFFER_RULE
  { "B_BAD_MIME_SNIFFER_RULE", (uintmax_t)B_BAD_MIME_SNIFFER_RULE, 0 < B_BAD_MIME_SNIFFER_RULE },
#endif
#ifdef B_NOT_A_MESSAGE
  { "B_NOT_A_MESSAGE", (uintmax_t)B_NOT_A_MESSAGE, 0 < B_NOT_A_MESSAGE },
#endif
#ifdef B_SHUTDOWN_CANCELLED
  { "B_SHUTDOWN_CANCELLED", (uintmax_t)B_SHUTDOWN_CANCELLED, 0 < B_SHUTDOWN_CANCELLED },
#endif
#ifdef B_SHUTTING_DOWN
  { "B_SHUTTING_DOWN", (uintmax_t)B_SHUTTING_DOWN, 0 < B_SHUTTING_DOWN },
#endif
#ifdef B_FILE_ERROR
  { "B_FILE_ERROR", (uintmax_t)B_FILE_ERROR, 0 < B_FILE_ERROR },
#endif
#ifdef B_FILE_NOT_FOUND
  { "B_FILE_NOT_FOUND", (uintmax_t)B_FILE_NOT_FOUND, 0 < B_FILE_NOT_FOUND },
#endif
#ifdef B_ENTRY_NOT_FOUND
  { "B_ENTRY_NOT_FOUND", (uintmax_t)B_ENTRY_NOT_FOUND, 0 < B_ENTRY_NOT_FOUND },
#endif
#ifdef B_FILE_EXISTS
  { "B_FILE_EXISTS", (uintmax_t)B_FILE_EXISTS, 0 < B_FILE_EXISTS },
#endif
#ifdef B_NAME_TOO_LONG
  { "B_NAME_TOO_LONG", (uintmax_t)B_NAME_TOO_LONG, 0 < B_NAME_TOO_LONG },
#endif
#ifdef B_NOT_A_DIRECTORY
  { "B_NOT_A_DIRECTORY", (uintmax_t)B_NOT_A_DIRECTORY, 0 < B_NOT_A_DIRECTORY },
#endif
#ifdef B_DIRECTORY_NOT_EMPTY
  { "B_DIRECTORY_NOT_EMPTY", (uintmax_t)B_DIRECTORY_NOT_EMPTY, 0 < B_DIRECTORY_NOT_EMPTY },
#endif
#ifdef B_DEVICE_FULL
  { "B_DEVICE_FULL", (uintmax_t)B_DEVICE_FULL, 0 < B_DEVICE_FULL },
#endif
#ifdef B_READ_ONLY_DEVICE
  { "B_READ_ONLY_DEVICE", (uintmax_t)B_READ_ONLY_DEVICE, 0 < B_READ_ONLY_DEVICE },
#endif
#ifdef B_IS_A_DIRECTORY
  { "B_IS_A_DIRECTORY", (uintmax_t)B_IS_A_DIRECTORY, 0 < B_IS_A_DIRECTORY },
#endif
#ifdef B_NO_MORE_FDS
  { "B_NO_MORE_FDS", (uintmax_t)B_NO_MORE_FDS, 0 < B_NO_MORE_FDS },
#endif
#ifdef B_CROSS_DEVICE_LINK
  { "B_CROSS_DEVICE_LINK", (uintmax_t)B_CROSS_DEVICE_LINK, 0 < B_CROSS_DEVICE_LINK },
#endif
#ifdef B_LINK_LIMIT
  { "B_LINK_LIMIT", (uintmax_t)B_LINK_LIMIT, 0 < B_LINK_LIMIT },
#endif
#ifdef B_BUSTED_PIPE
  { "B_BUSTED_PIPE", (uintmax_t)B_BUSTED_PIPE, 0 < B_BUSTED_PIPE },
#endif
#ifdef B_UNSUPPORTED
  { "B_UNSUPPORTED", (uintmax_t)B_UNSUPPORTED, 0 < B_UNSUPPORTED },
#endif
#ifdef B_PARTITION_TOO_SMALL
  { "B_PARTITION_TOO_SMALL", (uintmax_t)B_PARTITION_TOO_SMALL, 0 < B_PARTITION_TOO_SMALL },
#endif
#ifdef B_STREAM_NOT_FOUND
  { "B_STREAM_NOT_FOUND", (uintmax_t)B_STREAM_NOT_FOUND, 0 < B_STREAM_NOT_FOUND },
#endif
#ifdef B_SERVER_NOT_FOUND
  { "B_SERVER_NOT_FOUND", (uintmax_t)B_SERVER_NOT_FOUND, 0 < B_SERVER_NOT_FOUND },
#endif
#ifdef B_RESOURCE_NOT_FOUND
  { "B_RESOURCE_NOT_FOUND", (uintmax_t)B_RESOURCE_NOT_FOUND, 0 < B_RESOURCE_NOT_FOUND },
#endif
#ifdef B_RESOURCE_UNAVAILABLE
  { "B_RESOURCE_UNAVAILABLE", (uintmax_t)B_RESOURCE_UNAVAILABLE, 0 < B_RESOURCE_UNAVAILABLE },
#endif
#ifdef B_BAD_SUBSCRIBER
  { "B_BAD_SUBSCRIBER", (uintmax_t)B_BAD_SUBSCRIBER, 0 < B_BAD_SUBSCRIBER },
#endif
#ifdef B_SUBSCRIBER_NOT_ENTERED
  { "B_SUBSCRIBER_NOT_ENTERED", (uintmax_t)B_SUBSCRIBER_NOT_ENTERED, 0 < B_SUBSCRIBER_NOT_ENTERED },
#endif
#ifdef B_BUFFER_NOT_AVAILABLE
  { "B_BUFFER_NOT_AVAILABLE", (uintmax_t)B_BUFFER_NOT_AVAILABLE, 0 < B_BUFFER_NOT_AVAILABLE },
#endif
#ifdef B_LAST_BUFFER_ERROR
  { "B_LAST_BUFFER_ERROR", (uintmax_t)B_LAST_BUFFER_ERROR, 0 < B_LAST_BUFFER_ERROR },
#endif
#ifdef B_MEDIA_SYSTEM_FAILURE
  { "B_MEDIA_SYSTEM_FAILURE", (uintmax_t)B_MEDIA_SYSTEM_FAILURE, 0 < B_MEDIA_SYSTEM_FAILURE },
#endif
#ifdef B_MEDIA_BAD_NODE
  { "B_MEDIA_BAD_NODE", (uintmax_t)B_MEDIA_BAD_NODE, 0 < B_MEDIA_BAD_NODE },
#endif
#ifdef B_MEDIA_NODE_BUSY
  { "B_MEDIA_NODE_BUSY", (uintmax_t)B_MEDIA_NODE_BUSY, 0 < B_MEDIA_NODE_BUSY },
#endif
#ifdef B_MEDIA_BAD_FORMAT
  { "B_MEDIA_BAD_FORMAT", (uintmax_t)B_MEDIA_BAD_FORMAT, 0 < B_MEDIA_BAD_FORMAT },
#endif
#ifdef B_MEDIA_BAD_BUFFER
  { "B_MEDIA_BAD_BUFFER", (uintmax_t)B_MEDIA_BAD_BUFFER, 0 < B_MEDIA_BAD_BUFFER },
#endif
#ifdef B_MEDIA_TOO_MANY_NODES
  { "B_MEDIA_TOO_MANY_NODES", (uintmax_t)B_MEDIA_TOO_MANY_NODES, 0 < B_MEDIA_TOO_MANY_NODES },
#endif
#ifdef B_MEDIA_TOO_MANY_BUFFERS
  { "B_MEDIA_TOO_MANY_BUFFERS", (uintmax_t)B_MEDIA_TOO_MANY_BUFFERS, 0 < B_MEDIA_TOO_MANY_BUFFERS },
#endif
#ifdef B_MEDIA_NODE_ALREADY_EXISTS
  { "B_MEDIA_NODE_ALREADY_EXISTS", (uintmax_t)B_MEDIA_NODE_ALREADY_EXISTS, 0 < B_MEDIA_NODE_ALREADY_EXISTS },
#endif
#ifdef B_MEDIA_BUFFER_ALREADY_EXISTS
  { "B_MEDIA_BUFFER_ALREADY_EXISTS", (uintmax_t)B_MEDIA_BUFFER_ALREADY_EXISTS, 0 < B_MEDIA_BUFFER_ALREADY_EXISTS },
#endif
#ifdef B_MEDIA_CANNOT_SEEK
  { "B_MEDIA_CANNOT_SEEK", (uintmax_t)B_MEDIA_CANNOT_SEEK, 0 < B_MEDIA_CANNOT_SEEK },
#endif
#ifdef B_MEDIA_CANNOT_CHANGE_RUN_MODE
  { "B_MEDIA_CANNOT_CHANGE_RUN_MODE", (uintmax_t)B_MEDIA_CANNOT_CHANGE_RUN_MODE, 0 < B_MEDIA_CANNOT_CHANGE_RUN_MODE },
#endif
#ifdef B_MEDIA_APP_ALREADY_REGISTERED
  { "B_MEDIA_APP_ALREADY_REGISTERED", (uintmax_t)B_MEDIA_APP_ALREADY_REGISTERED, 0 < B_MEDIA_APP_ALREADY_REGISTERED },
#endif
#ifdef B_MEDIA_APP_NOT_REGISTERED
  { "B_MEDIA_APP_NOT_REGISTERED", (uintmax_t)B_MEDIA_APP_NOT_REGISTERED, 0 < B_MEDIA_APP_NOT_REGISTERED },
#endif
#ifdef B_MEDIA_CANNOT_RECLAIM_BUFFERS
  { "B_MEDIA_CANNOT_RECLAIM_BUFFERS", (uintmax_t)B_MEDIA_CANNOT_RECLAIM_BUFFERS, 0 < B_MEDIA_CANNOT_RECLAIM_BUFFERS },
#endif
#ifdef B_MEDIA_BUFFERS_NOT_RECLAIMED
  { "B_MEDIA_BUFFERS_NOT_RECLAIMED", (uintmax_t)B_MEDIA_BUFFERS_NOT_RECLAIMED, 0 < B_MEDIA_BUFFERS_NOT_RECLAIMED },
#endif
#ifdef B_MEDIA_TIME_SOURCE_STOPPED
  { "B_MEDIA_TIME_SOURCE_STOPPED", (uintmax_t)B_MEDIA_TIME_SOURCE_STOPPED, 0 < B_MEDIA_TIME_SOURCE_STOPPED },
#endif
#ifdef B_MEDIA_TIME_SOURCE_BUSY
  { "B_MEDIA_TIME_SOURCE_BUSY", (uintmax_t)B_MEDIA_TIME_SOURCE_BUSY, 0 < B_MEDIA_TIME_SOURCE_BUSY },
#endif
#ifdef B_MEDIA_BAD_SOURCE
  { "B_MEDIA_BAD_SOURCE", (uintmax_t)B_MEDIA_BAD_SOURCE, 0 < B_MEDIA_BAD_SOURCE },
#endif
#ifdef B_MEDIA_BAD_DESTINATION
  { "B_MEDIA_BAD_DESTINATION", (uintmax_t)B_MEDIA_BAD_DESTINATION, 0 < B_MEDIA_BAD_DESTINATION },
#endif
#ifdef B_MEDIA_ALREADY_CONNECTED
  { "B_MEDIA_ALREADY_CONNECTED", (uintmax_t)B_MEDIA_ALREADY_CONNECTED, 0 < B_MEDIA_ALREADY_CONNECTED },
#endif
#ifdef B_MEDIA_NOT_CONNECTED
  { "B_MEDIA_NOT_CONNECTED", (uintmax_t)B_MEDIA_NOT_CONNECTED, 0 < B_MEDIA_NOT_CONNECTED },
#endif
#ifdef B_MEDIA_BAD_CLIP_FORMAT
  { "B_MEDIA_BAD_CLIP_FORMAT", (uintmax_t)B_MEDIA_BAD_CLIP_FORMAT, 0 < B_MEDIA_BAD_CLIP_FORMAT },
#endif
#ifdef B_MEDIA_ADDON_FAILED
  { "B_MEDIA_ADDON_FAILED", (uintmax_t)B_MEDIA_ADDON_FAILED, 0 < B_MEDIA_ADDON_FAILED },
#endif
#ifdef B_MEDIA_ADDON_DISABLED
  { "B_MEDIA_ADDON_DISABLED", (uintmax_t)B_MEDIA_ADDON_DISABLED, 0 < B_MEDIA_ADDON_DISABLED },
#endif
#ifdef B_MEDIA_CHANGE_IN_PROGRESS
  { "B_MEDIA_CHANGE_IN_PROGRESS", (uintmax_t)B_MEDIA_CHANGE_IN_PROGRESS, 0 < B_MEDIA_CHANGE_IN_PROGRESS },
#endif
#ifdef B_MEDIA_STALE_CHANGE_COUNT
  { "B_MEDIA_STALE_CHANGE_COUNT", (uintmax_t)B_MEDIA_STALE_CHANGE_COUNT, 0 < B_MEDIA_STALE_CHANGE_COUNT },
#endif
#ifdef B_MEDIA_ADDON_RESTRICTED
  { "B_MEDIA_ADDON_RESTRICTED", (uintmax_t)B_MEDIA_ADDON_RESTRICTED, 0 < B_MEDIA_ADDON_RESTRICTED },
#endif
#ifdef B_MEDIA_NO_HANDLER
  { "B_MEDIA_NO_HANDLER", (uintmax_t)B_MEDIA_NO_HANDLER, 0 < B_MEDIA_NO_HANDLER },
#endif
#ifdef B_MEDIA_DUPLICATE_FORMAT
  { "B_MEDIA_DUPLICATE_FORMAT", (uintmax_t)B_MEDIA_DUPLICATE_FORMAT, 0 < B_MEDIA_DUPLICATE_FORMAT },
#endif
#ifdef B_MEDIA_REALTIME_DISABLED
  { "B_MEDIA_REALTIME_DISABLED", (uintmax_t)B_MEDIA_REALTIME_DISABLED, 0 < B_MEDIA_REALTIME_DISABLED },
#endif
#ifdef B_MEDIA_REALTIME_UNAVAILABLE
  { "B_MEDIA_REALTIME_UNAVAILABLE", (uintmax_t)B_MEDIA_REALTIME_UNAVAILABLE, 0 < B_MEDIA_REALTIME_UNAVAILABLE },
#endif
#ifdef B_MAIL_NO_DAEMON
  { "B_MAIL_NO_DAEMON", (uintmax_t)B_MAIL_NO_DAEMON, 0 < B_MAIL_NO_DAEMON },
#endif
#ifdef B_MAIL_UNKNOWN_USER
  { "B_MAIL_UNKNOWN_USER", (uintmax_t)B_MAIL_UNKNOWN_USER, 0 < B_MAIL_UNKNOWN_USER },
#endif
#ifdef B_MAIL_WRONG_PASSWORD
  { "B_MAIL_WRONG_PASSWORD", (uintmax_t)B_MAIL_WRONG_PASSWORD, 0 < B_MAIL_WRONG_PASSWORD },
#endif
#ifdef B_MAIL_UNKNOWN_HOST
  { "B_MAIL_UNKNOWN_HOST", (uintmax_t)B_MAIL_UNKNOWN_HOST, 0 < B_MAIL_UNKNOWN_HOST },
#endif
#ifdef B_MAIL_ACCESS_ERROR
  { "B_MAIL_ACCESS_ERROR", (uintmax_t)B_MAIL_ACCESS_ERROR, 0 < B_MAIL_ACCESS_ERROR },
#endif
#ifdef B_MAIL_UNKNOWN_FIELD
  { "B_MAIL_UNKNOWN_FIELD", (uintmax_t)B_MAIL_UNKNOWN_FIELD, 0 < B_MAIL_UNKNOWN_FIELD },
#endif
#ifdef B_MAIL_NO_RECIPIENT
  { "B_MAIL_NO_RECIPIENT", (uintmax_t)B_MAIL_NO_RECIPIENT, 0 < B_MAIL_NO_RECIPIENT },
#endif
#ifdef B_MAIL_INVALID_MAIL
  { "B_MAIL_INVALID_MAIL", (uintmax_t)B_MAIL_INVALID_MAIL, 0 < B_MAIL_INVALID_MAIL },
#endif
#ifdef B_NO_PRINT_SERVER
  { "B_NO_PRINT_SERVER", (uintmax_t)B_NO_PRINT_SERVER, 0 < B_NO_PRINT_SERVER },
#endif
#ifdef B_DEV_INVALID_IOCTL
  { "B_DEV_INVALID_IOCTL", (uintmax_t)B_DEV_INVALID_IOCTL, 0 < B_DEV_INVALID_IOCTL },
#endif
#ifdef B_DEV_NO_MEMORY
  { "B_DEV_NO_MEMORY", (uintmax_t)B_DEV_NO_MEMORY, 0 < B_DEV_NO_MEMORY },
#endif
#ifdef B_DEV_BAD_DRIVE_NUM
  { "B_DEV_BAD_DRIVE_NUM", (uintmax_t)B_DEV_BAD_DRIVE_NUM, 0 < B_DEV_BAD_DRIVE_NUM },
#endif
#ifdef B_DEV_NO_MEDIA
  { "B_DEV_NO_MEDIA", (uintmax_t)B_DEV_NO_MEDIA, 0 < B_DEV_NO_MEDIA },
#endif
#ifdef B_DEV_UNREADABLE
  { "B_DEV_UNREADABLE", (uintmax_t)B_DEV_UNREADABLE, 0 < B_DEV_UNREADABLE },
#endif
#ifdef B_DEV_FORMAT_ERROR
  { "B_DEV_FORMAT_ERROR", (uintmax_t)B_DEV_FORMAT_ERROR, 0 < B_DEV_FORMAT_ERROR },
#endif
#ifdef B_DEV_TIMEOUT
  { "B_DEV_TIMEOUT", (uintmax_t)B_DEV_TIMEOUT, 0 < B_DEV_TIMEOUT },
#endif
#ifdef B_DEV_RECALIBRATE_ERROR
  { "B_DEV_RECALIBRATE_ERROR", (uintmax_t)B_DEV_RECALIBRATE_ERROR, 0 < B_DEV_RECALIBRATE_ERROR },
#endif
#ifdef B_DEV_SEEK_ERROR
  { "B_DEV_SEEK_ERROR", (uintmax_t)B_DEV_SEEK_ERROR, 0 < B_DEV_SEEK_ERROR },
#endif
#ifdef B_DEV_ID_ERROR
  { "B_DEV_ID_ERROR", (uintmax_t)B_DEV_ID_ERROR, 0 < B_DEV_ID_ERROR },
#endif
#ifdef B_DEV_READ_ERROR
  { "B_DEV_READ_ERROR", (uintmax_t)B_DEV_READ_ERROR, 0 < B_DEV_READ_ERROR },
#endif
#ifdef B_DEV_WRITE_ERROR
  { "B_DEV_WRITE_ERROR", (uintmax_t)B_DEV_WRITE_ERROR, 0 < B_DEV_WRITE_ERROR },
#endif
#ifdef B_DEV_NOT_READY
  { "B_DEV_NOT_READY", (uintmax_t)B_DEV_NOT_READY, 0 < B_DEV_NOT_READY },
#endif
#ifdef B_DEV_MEDIA_CHANGED
  { "B_DEV_MEDIA_CHANGED", (uintmax_t)B_DEV_MEDIA_CHANGED, 0 < B_DEV_MEDIA_CHANGED },
#endif
#ifdef B_DEV_MEDIA_CHANGE_REQUESTED
  { "B_DEV_MEDIA_CHANGE_REQUESTED", (uintmax_t)B_DEV_MEDIA_CHANGE_REQUESTED, 0 < B_DEV_MEDIA_CHANGE_REQUESTED },
#endif
#ifdef B_DEV_RESOURCE_CONFLICT
  { "B_DEV_RESOURCE_CONFLICT", (uintmax_t)B_DEV_RESOURCE_CONFLICT, 0 < B_DEV_RESOURCE_CONFLICT },
#endif
#ifdef B_DEV_CONFIGURATION_ERROR
  { "B_DEV_CONFIGURATION_ERROR", (uintmax_t)B_DEV_CONFIGURATION_ERROR, 0 < B_DEV_CONFIGURATION_ERROR },
#endif
#ifdef B_DEV_DISABLED_BY_USER
  { "B_DEV_DISABLED_BY_USER", (uintmax_t)B_DEV_DISABLED_BY_USER, 0 < B_DEV_DISABLED_BY_USER },
#endif
#ifdef B_DEV_DOOR_OPEN
  { "B_DEV_DOOR_OPEN", (uintmax_t)B_DEV_DOOR_OPEN, 0 < B_DEV_DOOR_OPEN },
#endif
#ifdef B_DEV_INVALID_PIPE
  { "B_DEV_INVALID_PIPE", (uintmax_t)B_DEV_INVALID_PIPE, 0 < B_DEV_INVALID_PIPE },
#endif
#ifdef B_DEV_CRC_ERROR
  { "B_DEV_CRC_ERROR", (uintmax_t)B_DEV_CRC_ERROR, 0 < B_DEV_CRC_ERROR },
#endif
#ifdef B_DEV_STALLED
  { "B_DEV_STALLED", (uintmax_t)B_DEV_STALLED, 0 < B_DEV_STALLED },
#endif
#ifdef B_DEV_BAD_PID
  { "B_DEV_BAD_PID", (uintmax_t)B_DEV_BAD_PID, 0 < B_DEV_BAD_PID },
#endif
#ifdef B_DEV_UNEXPECTED_PID
  { "B_DEV_UNEXPECTED_PID", (uintmax_t)B_DEV_UNEXPECTED_PID, 0 < B_DEV_UNEXPECTED_PID },
#endif
#ifdef B_DEV_DATA_OVERRUN
  { "B_DEV_DATA_OVERRUN", (uintmax_t)B_DEV_DATA_OVERRUN, 0 < B_DEV_DATA_OVERRUN },
#endif
#ifdef B_DEV_DATA_UNDERRUN
  { "B_DEV_DATA_UNDERRUN", (uintmax_t)B_DEV_DATA_UNDERRUN, 0 < B_DEV_DATA_UNDERRUN },
#endif
#ifdef B_DEV_FIFO_OVERRUN
  { "B_DEV_FIFO_OVERRUN", (uintmax_t)B_DEV_FIFO_OVERRUN, 0 < B_DEV_FIFO_OVERRUN },
#endif
#ifdef B_DEV_FIFO_UNDERRUN
  { "B_DEV_FIFO_UNDERRUN", (uintmax_t)B_DEV_FIFO_UNDERRUN, 0 < B_DEV_FIFO_UNDERRUN },
#endif
#ifdef B_DEV_PENDING
  { "B_DEV_PENDING", (uintmax_t)B_DEV_PENDING, 0 < B_DEV_PENDING },
#endif
#ifdef B_DEV_MULTIPLE_ERRORS
  { "B_DEV_MULTIPLE_ERRORS", (uintmax_t)B_DEV_MULTIPLE_ERRORS, 0 < B_DEV_MULTIPLE_ERRORS },
#endif
#ifdef B_DEV_TOO_LATE
  { "B_DEV_TOO_LATE", (uintmax_t)B_DEV_TOO_LATE, 0 < B_DEV_TOO_LATE },
#endif
#ifdef B_NO_TRANSLATOR
  { "B_NO_TRANSLATOR", (uintmax_t)B_NO_TRANSLATOR, 0 < B_NO_TRANSLATOR },
#endif
#ifdef B_ILLEGAL_DATA
  { "B_ILLEGAL_DATA", (uintmax_t)B_ILLEGAL_DATA, 0 < B_ILLEGAL_DATA },
#endif
#ifdef EFPOS
  { "EFPOS", (uintmax_t)EFPOS, 0 < EFPOS },
#endif
#ifdef ESIGPARM
  { "ESIGPARM", (uintmax_t)ESIGPARM, 0 < ESIGPARM },
#endif
  { NULL, 0, 0 }
};

const int num_errno = sizeof(internal_errno_to_name) / sizeof(*internal_errno_to_name) - 1;



const string_integer_pair_t internal_constant_val_to_name[] = {
#ifdef AF_INET
  { "AF_INET", AF_INET, 0 <  AF_INET },
#endif
#ifdef AF_INET6
  { "AF_INET6", AF_INET6, 0 <  AF_INET6 },
#endif
#ifdef AF_UNIX
  { "AF_UNIX", AF_UNIX, 0 <  AF_UNIX },
#endif
#ifdef AF_UNSPEC
  { "AF_UNSPEC", AF_UNSPEC, 0 <  AF_UNSPEC },
#endif
#ifdef SOCK_DGRAM
  { "SOCK_DGRAM", SOCK_DGRAM, 0 <  SOCK_DGRAM },
#endif
#ifdef SOCK_RAW
  { "SOCK_RAW", SOCK_RAW, 0 <  SOCK_RAW },
#endif
#ifdef SOCK_SEQPACKET
  { "SOCK_SEQPACKET", SOCK_SEQPACKET, 0 <  SOCK_SEQPACKET },
#endif
#ifdef SOCK_STREAM
  { "SOCK_STREAM", SOCK_STREAM, 0 <  SOCK_STREAM },
#endif
#ifdef SHUT_RD
  { "SHUT_RD", SHUT_RD, 0 <  SHUT_RD },
#endif
#ifdef SHUT_RDWR
  { "SHUT_RDWR", SHUT_RDWR, 0 <  SHUT_RDWR },
#endif
#ifdef SHUT_WR
  { "SHUT_WR", SHUT_WR, 0 <  SHUT_WR },
#endif
#ifdef MSG_CTRUNC
  { "MSG_CTRUNC", MSG_CTRUNC, 0 <  MSG_CTRUNC },
#endif
#ifdef MSG_DONTROUTE
  { "MSG_DONTROUTE", MSG_DONTROUTE, 0 <  MSG_DONTROUTE },
#endif
#ifdef MSG_EOR
  { "MSG_EOR", MSG_EOR, 0 <  MSG_EOR },
#endif
#ifdef MSG_OOB
  { "MSG_OOB", MSG_OOB, 0 <  MSG_OOB },
#endif
#ifdef MSG_NOSIGNAL
  { "MSG_NOSIGNAL", MSG_NOSIGNAL, 0 <  MSG_NOSIGNAL },
#endif
#ifdef MSG_PEEK
  { "MSG_PEEK", MSG_PEEK, 0 <  MSG_PEEK },
#endif
#ifdef MSG_TRUNC
  { "MSG_TRUNC", MSG_TRUNC, 0 <  MSG_TRUNC },
#endif
#ifdef MSG_WAITALL
  { "MSG_WAITALL", MSG_WAITALL, 0 <  MSG_WAITALL },
#endif
#ifdef SOL_SOCKET
  { "SOL_SOCKET", SOL_SOCKET, 0 <  SOL_SOCKET },
#endif
#ifdef SO_ACCEPTCONN
  { "SO_ACCEPTCONN", SO_ACCEPTCONN, 0 <  SO_ACCEPTCONN },
#endif
#ifdef SO_BROADCAST
  { "SO_BROADCAST", SO_BROADCAST, 0 <  SO_BROADCAST },
#endif
#ifdef SO_DEBUG
  { "SO_DEBUG", SO_DEBUG, 0 <  SO_DEBUG },
#endif
#ifdef SO_DONTROUTE
  { "SO_DONTROUTE", SO_DONTROUTE, 0 <  SO_DONTROUTE },
#endif
#ifdef SO_ERROR
  { "SO_ERROR", SO_ERROR, 0 <  SO_ERROR },
#endif
#ifdef SO_KEEPALIVE
  { "SO_KEEPALIVE", SO_KEEPALIVE, 0 <  SO_KEEPALIVE },
#endif
#ifdef SO_LINGER
  { "SO_LINGER", SO_LINGER, 0 <  SO_LINGER },
#endif
#ifdef SO_OOBINLINE
  { "SO_OOBINLINE", SO_OOBINLINE, 0 <  SO_OOBINLINE },
#endif
#ifdef SO_RCVBUF
  { "SO_RCVBUF", SO_RCVBUF, 0 <  SO_RCVBUF },
#endif
#ifdef SO_RCVLOWAT
  { "SO_RCVLOWAT", SO_RCVLOWAT, 0 <  SO_RCVLOWAT },
#endif
#ifdef SO_RCVTIMEO
  { "SO_RCVTIMEO", SO_RCVTIMEO, 0 <  SO_RCVTIMEO },
#endif
#ifdef SO_REUSEADDR
  { "SO_REUSEADDR", SO_REUSEADDR, 0 <  SO_REUSEADDR },
#endif
#ifdef SO_SNDBUF
  { "SO_SNDBUF", SO_SNDBUF, 0 <  SO_SNDBUF },
#endif
#ifdef SO_SNDLOWAT
  { "SO_SNDLOWAT", SO_SNDLOWAT, 0 <  SO_SNDLOWAT },
#endif
#ifdef SO_SNDTIMEO
  { "SO_SNDTIMEO", SO_SNDTIMEO, 0 <  SO_SNDTIMEO },
#endif
#ifdef SO_TYPE
  { "SO_TYPE", SO_TYPE, 0 <  SO_TYPE },
#endif
#ifdef SCM_RIGHTS
  { "SCM_RIGHTS", SCM_RIGHTS, 0 <  SCM_RIGHTS },
#endif
#ifdef SOMAXCONN
  { "SOMAXCONN", SOMAXCONN, 0 <  SOMAXCONN },
#endif
  { NULL, 0, 0 }
};

const int num_constants = sizeof(internal_constant_val_to_name) / sizeof(*internal_constant_val_to_name) - 1;

