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



const iconst_t iconst_table[] = {
#ifdef AF_INET
  INTEGER_CONSTANT_INFO(iconst_af, "AF_INET", AF_INET),
#endif
#ifdef AF_INET6
  INTEGER_CONSTANT_INFO(iconst_af, "AF_INET6", AF_INET6),
#endif
#ifdef AF_UNIX
  INTEGER_CONSTANT_INFO(iconst_af, "AF_UNIX", AF_UNIX),
#endif
#ifdef AF_UNSPEC
  INTEGER_CONSTANT_INFO(iconst_af, "AF_UNSPEC", AF_UNSPEC),
#endif
#ifdef SOCK_DGRAM
  INTEGER_CONSTANT_INFO(iconst_sock, "SOCK_DGRAM", SOCK_DGRAM),
#endif
#ifdef SOCK_RAW
  INTEGER_CONSTANT_INFO(iconst_sock, "SOCK_RAW", SOCK_RAW),
#endif
#ifdef SOCK_SEQPACKET
  INTEGER_CONSTANT_INFO(iconst_sock, "SOCK_SEQPACKET", SOCK_SEQPACKET),
#endif
#ifdef SOCK_STREAM
  INTEGER_CONSTANT_INFO(iconst_sock, "SOCK_STREAM", SOCK_STREAM),
#endif
#ifdef SHUT_RD
  INTEGER_CONSTANT_INFO(iconst_shut, "SHUT_RD", SHUT_RD),
#endif
#ifdef SHUT_RDWR
  INTEGER_CONSTANT_INFO(iconst_shut, "SHUT_RDWR", SHUT_RDWR),
#endif
#ifdef SHUT_WR
  INTEGER_CONSTANT_INFO(iconst_shut, "SHUT_WR", SHUT_WR),
#endif
#ifdef MSG_CTRUNC
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_CTRUNC", MSG_CTRUNC),
#endif
#ifdef MSG_DONTROUTE
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_DONTROUTE", MSG_DONTROUTE),
#endif
#ifdef MSG_EOR
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_EOR", MSG_EOR),
#endif
#ifdef MSG_OOB
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_OOB", MSG_OOB),
#endif
#ifdef MSG_NOSIGNAL
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_NOSIGNAL", MSG_NOSIGNAL),
#endif
#ifdef MSG_PEEK
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_PEEK", MSG_PEEK),
#endif
#ifdef MSG_TRUNC
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_TRUNC", MSG_TRUNC),
#endif
#ifdef MSG_WAITALL
  INTEGER_CONSTANT_INFO(iconst_msg, "MSG_WAITALL", MSG_WAITALL),
#endif
#ifdef SOL_SOCKET
  INTEGER_CONSTANT_INFO(iconst_sol, "SOL_SOCKET", SOL_SOCKET),
#endif
#ifdef SO_ACCEPTCONN
  INTEGER_CONSTANT_INFO(iconst_so, "SO_ACCEPTCONN", SO_ACCEPTCONN),
#endif
#ifdef SO_BROADCAST
  INTEGER_CONSTANT_INFO(iconst_so, "SO_BROADCAST", SO_BROADCAST),
#endif
#ifdef SO_DEBUG
  INTEGER_CONSTANT_INFO(iconst_so, "SO_DEBUG", SO_DEBUG),
#endif
#ifdef SO_DONTROUTE
  INTEGER_CONSTANT_INFO(iconst_so, "SO_DONTROUTE", SO_DONTROUTE),
#endif
#ifdef SO_ERROR
  INTEGER_CONSTANT_INFO(iconst_so, "SO_ERROR", SO_ERROR),
#endif
#ifdef SO_KEEPALIVE
  INTEGER_CONSTANT_INFO(iconst_so, "SO_KEEPALIVE", SO_KEEPALIVE),
#endif
#ifdef SO_LINGER
  INTEGER_CONSTANT_INFO(iconst_so, "SO_LINGER", SO_LINGER),
#endif
#ifdef SO_OOBINLINE
  INTEGER_CONSTANT_INFO(iconst_so, "SO_OOBINLINE", SO_OOBINLINE),
#endif
#ifdef SO_RCVBUF
  INTEGER_CONSTANT_INFO(iconst_so, "SO_RCVBUF", SO_RCVBUF),
#endif
#ifdef SO_RCVLOWAT
  INTEGER_CONSTANT_INFO(iconst_so, "SO_RCVLOWAT", SO_RCVLOWAT),
#endif
#ifdef SO_RCVTIMEO
  INTEGER_CONSTANT_INFO(iconst_so, "SO_RCVTIMEO", SO_RCVTIMEO),
#endif
#ifdef SO_REUSEADDR
  INTEGER_CONSTANT_INFO(iconst_so, "SO_REUSEADDR", SO_REUSEADDR),
#endif
#ifdef SO_SNDBUF
  INTEGER_CONSTANT_INFO(iconst_so, "SO_SNDBUF", SO_SNDBUF),
#endif
#ifdef SO_SNDLOWAT
  INTEGER_CONSTANT_INFO(iconst_so, "SO_SNDLOWAT", SO_SNDLOWAT),
#endif
#ifdef SO_SNDTIMEO
  INTEGER_CONSTANT_INFO(iconst_so, "SO_SNDTIMEO", SO_SNDTIMEO),
#endif
#ifdef SO_TYPE
  INTEGER_CONSTANT_INFO(iconst_so, "SO_TYPE", SO_TYPE),
#endif
#ifdef SCM_RIGHTS
  INTEGER_CONSTANT_INFO(iconst_scm, "SCM_RIGHTS", SCM_RIGHTS),
#endif
#ifdef SOMAXCONN
  INTEGER_CONSTANT_INFO(iconst_misc, "SOMAXCONN", SOMAXCONN),
#endif
#ifdef EAGAIN
  INTEGER_CONSTANT_INFO(iconst_errno, "EAGAIN", EAGAIN),
#endif
#ifdef ENOTSUP
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTSUP", ENOTSUP),
#endif
#ifdef E2BIG
  INTEGER_CONSTANT_INFO(iconst_errno, "E2BIG", E2BIG),
#endif
#ifdef EACCES
  INTEGER_CONSTANT_INFO(iconst_errno, "EACCES", EACCES),
#endif
#ifdef EADDRINUSE
  INTEGER_CONSTANT_INFO(iconst_errno, "EADDRINUSE", EADDRINUSE),
#endif
#ifdef EADDRNOTAVAIL
  INTEGER_CONSTANT_INFO(iconst_errno, "EADDRNOTAVAIL", EADDRNOTAVAIL),
#endif
#ifdef EAFNOSUPPORT
  INTEGER_CONSTANT_INFO(iconst_errno, "EAFNOSUPPORT", EAFNOSUPPORT),
#endif
#ifdef EALREADY
  INTEGER_CONSTANT_INFO(iconst_errno, "EALREADY", EALREADY),
#endif
#ifdef EBADF
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADF", EBADF),
#endif
#ifdef EBADMSG
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADMSG", EBADMSG),
#endif
#ifdef EBUSY
  INTEGER_CONSTANT_INFO(iconst_errno, "EBUSY", EBUSY),
#endif
#ifdef ECANCELED
  INTEGER_CONSTANT_INFO(iconst_errno, "ECANCELED", ECANCELED),
#endif
#ifdef ECHILD
  INTEGER_CONSTANT_INFO(iconst_errno, "ECHILD", ECHILD),
#endif
#ifdef ECONNABORTED
  INTEGER_CONSTANT_INFO(iconst_errno, "ECONNABORTED", ECONNABORTED),
#endif
#ifdef ECONNREFUSED
  INTEGER_CONSTANT_INFO(iconst_errno, "ECONNREFUSED", ECONNREFUSED),
#endif
#ifdef ECONNRESET
  INTEGER_CONSTANT_INFO(iconst_errno, "ECONNRESET", ECONNRESET),
#endif
#ifdef EDEADLK
  INTEGER_CONSTANT_INFO(iconst_errno, "EDEADLK", EDEADLK),
#endif
#ifdef EDESTADDRREQ
  INTEGER_CONSTANT_INFO(iconst_errno, "EDESTADDRREQ", EDESTADDRREQ),
#endif
#ifdef EDOM
  INTEGER_CONSTANT_INFO(iconst_errno, "EDOM", EDOM),
#endif
#ifdef EDQUOT
  INTEGER_CONSTANT_INFO(iconst_errno, "EDQUOT", EDQUOT),
#endif
#ifdef EEXIST
  INTEGER_CONSTANT_INFO(iconst_errno, "EEXIST", EEXIST),
#endif
#ifdef EFAULT
  INTEGER_CONSTANT_INFO(iconst_errno, "EFAULT", EFAULT),
#endif
#ifdef EFBIG
  INTEGER_CONSTANT_INFO(iconst_errno, "EFBIG", EFBIG),
#endif
#ifdef EHOSTUNREACH
  INTEGER_CONSTANT_INFO(iconst_errno, "EHOSTUNREACH", EHOSTUNREACH),
#endif
#ifdef EIDRM
  INTEGER_CONSTANT_INFO(iconst_errno, "EIDRM", EIDRM),
#endif
#ifdef EILSEQ
  INTEGER_CONSTANT_INFO(iconst_errno, "EILSEQ", EILSEQ),
#endif
#ifdef EINPROGRESS
  INTEGER_CONSTANT_INFO(iconst_errno, "EINPROGRESS", EINPROGRESS),
#endif
#ifdef EINTR
  INTEGER_CONSTANT_INFO(iconst_errno, "EINTR", EINTR),
#endif
#ifdef EINVAL
  INTEGER_CONSTANT_INFO(iconst_errno, "EINVAL", EINVAL),
#endif
#ifdef EIO
  INTEGER_CONSTANT_INFO(iconst_errno, "EIO", EIO),
#endif
#ifdef EISCONN
  INTEGER_CONSTANT_INFO(iconst_errno, "EISCONN", EISCONN),
#endif
#ifdef EISDIR
  INTEGER_CONSTANT_INFO(iconst_errno, "EISDIR", EISDIR),
#endif
#ifdef ELOOP
  INTEGER_CONSTANT_INFO(iconst_errno, "ELOOP", ELOOP),
#endif
#ifdef EMFILE
  INTEGER_CONSTANT_INFO(iconst_errno, "EMFILE", EMFILE),
#endif
#ifdef EMLINK
  INTEGER_CONSTANT_INFO(iconst_errno, "EMLINK", EMLINK),
#endif
#ifdef EMSGSIZE
  INTEGER_CONSTANT_INFO(iconst_errno, "EMSGSIZE", EMSGSIZE),
#endif
#ifdef EMULTIHOP
  INTEGER_CONSTANT_INFO(iconst_errno, "EMULTIHOP", EMULTIHOP),
#endif
#ifdef ENAMETOOLONG
  INTEGER_CONSTANT_INFO(iconst_errno, "ENAMETOOLONG", ENAMETOOLONG),
#endif
#ifdef ENETDOWN
  INTEGER_CONSTANT_INFO(iconst_errno, "ENETDOWN", ENETDOWN),
#endif
#ifdef ENETRESET
  INTEGER_CONSTANT_INFO(iconst_errno, "ENETRESET", ENETRESET),
#endif
#ifdef ENETUNREACH
  INTEGER_CONSTANT_INFO(iconst_errno, "ENETUNREACH", ENETUNREACH),
#endif
#ifdef ENFILE
  INTEGER_CONSTANT_INFO(iconst_errno, "ENFILE", ENFILE),
#endif
#ifdef ENOBUFS
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOBUFS", ENOBUFS),
#endif
#ifdef ENODATA
  INTEGER_CONSTANT_INFO(iconst_errno, "ENODATA", ENODATA),
#endif
#ifdef ENODEV
  INTEGER_CONSTANT_INFO(iconst_errno, "ENODEV", ENODEV),
#endif
#ifdef ENOENT
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOENT", ENOENT),
#endif
#ifdef ENOEXEC
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOEXEC", ENOEXEC),
#endif
#ifdef ENOLCK
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOLCK", ENOLCK),
#endif
#ifdef ENOLINK
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOLINK", ENOLINK),
#endif
#ifdef ENOMEM
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOMEM", ENOMEM),
#endif
#ifdef ENOMSG
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOMSG", ENOMSG),
#endif
#ifdef ENOPROTOOPT
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOPROTOOPT", ENOPROTOOPT),
#endif
#ifdef ENOSPC
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOSPC", ENOSPC),
#endif
#ifdef ENOSR
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOSR", ENOSR),
#endif
#ifdef ENOSTR
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOSTR", ENOSTR),
#endif
#ifdef ENOSYS
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOSYS", ENOSYS),
#endif
#ifdef ENOTCONN
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTCONN", ENOTCONN),
#endif
#ifdef ENOTDIR
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTDIR", ENOTDIR),
#endif
#ifdef ENOTEMPTY
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTEMPTY", ENOTEMPTY),
#endif
#ifdef ENOTRECOVERABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTRECOVERABLE", ENOTRECOVERABLE),
#endif
#ifdef ENOTSOCK
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTSOCK", ENOTSOCK),
#endif
#ifdef ENOTTY
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTTY", ENOTTY),
#endif
#ifdef ENXIO
  INTEGER_CONSTANT_INFO(iconst_errno, "ENXIO", ENXIO),
#endif
#ifdef EOPNOTSUPP
  INTEGER_CONSTANT_INFO(iconst_errno, "EOPNOTSUPP", EOPNOTSUPP),
#endif
#ifdef EOVERFLOW
  INTEGER_CONSTANT_INFO(iconst_errno, "EOVERFLOW", EOVERFLOW),
#endif
#ifdef EOWNERDEAD
  INTEGER_CONSTANT_INFO(iconst_errno, "EOWNERDEAD", EOWNERDEAD),
#endif
#ifdef EPERM
  INTEGER_CONSTANT_INFO(iconst_errno, "EPERM", EPERM),
#endif
#ifdef EPIPE
  INTEGER_CONSTANT_INFO(iconst_errno, "EPIPE", EPIPE),
#endif
#ifdef EPROTO
  INTEGER_CONSTANT_INFO(iconst_errno, "EPROTO", EPROTO),
#endif
#ifdef EPROTONOSUPPORT
  INTEGER_CONSTANT_INFO(iconst_errno, "EPROTONOSUPPORT", EPROTONOSUPPORT),
#endif
#ifdef EPROTOTYPE
  INTEGER_CONSTANT_INFO(iconst_errno, "EPROTOTYPE", EPROTOTYPE),
#endif
#ifdef ERANGE
  INTEGER_CONSTANT_INFO(iconst_errno, "ERANGE", ERANGE),
#endif
#ifdef EROFS
  INTEGER_CONSTANT_INFO(iconst_errno, "EROFS", EROFS),
#endif
#ifdef ESPIPE
  INTEGER_CONSTANT_INFO(iconst_errno, "ESPIPE", ESPIPE),
#endif
#ifdef ESRCH
  INTEGER_CONSTANT_INFO(iconst_errno, "ESRCH", ESRCH),
#endif
#ifdef ESTALE
  INTEGER_CONSTANT_INFO(iconst_errno, "ESTALE", ESTALE),
#endif
#ifdef ETIME
  INTEGER_CONSTANT_INFO(iconst_errno, "ETIME", ETIME),
#endif
#ifdef ETIMEDOUT
  INTEGER_CONSTANT_INFO(iconst_errno, "ETIMEDOUT", ETIMEDOUT),
#endif
#ifdef ETXTBSY
  INTEGER_CONSTANT_INFO(iconst_errno, "ETXTBSY", ETXTBSY),
#endif
#ifdef EWOULDBLOCK
  INTEGER_CONSTANT_INFO(iconst_errno, "EWOULDBLOCK", EWOULDBLOCK),
#endif
#ifdef EXDEV
  INTEGER_CONSTANT_INFO(iconst_errno, "EXDEV", EXDEV),
#endif
#ifdef ENOTBLK
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTBLK", ENOTBLK),
#endif
#ifdef ECHRNG
  INTEGER_CONSTANT_INFO(iconst_errno, "ECHRNG", ECHRNG),
#endif
#ifdef EL2NSYNC
  INTEGER_CONSTANT_INFO(iconst_errno, "EL2NSYNC", EL2NSYNC),
#endif
#ifdef EL3HLT
  INTEGER_CONSTANT_INFO(iconst_errno, "EL3HLT", EL3HLT),
#endif
#ifdef EL3RST
  INTEGER_CONSTANT_INFO(iconst_errno, "EL3RST", EL3RST),
#endif
#ifdef ELNRNG
  INTEGER_CONSTANT_INFO(iconst_errno, "ELNRNG", ELNRNG),
#endif
#ifdef EUNATCH
  INTEGER_CONSTANT_INFO(iconst_errno, "EUNATCH", EUNATCH),
#endif
#ifdef ENOCSI
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOCSI", ENOCSI),
#endif
#ifdef EL2HLT
  INTEGER_CONSTANT_INFO(iconst_errno, "EL2HLT", EL2HLT),
#endif
#ifdef EBADE
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADE", EBADE),
#endif
#ifdef EBADR
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADR", EBADR),
#endif
#ifdef EXFULL
  INTEGER_CONSTANT_INFO(iconst_errno, "EXFULL", EXFULL),
#endif
#ifdef ENOANO
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOANO", ENOANO),
#endif
#ifdef EBADRQC
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADRQC", EBADRQC),
#endif
#ifdef EBADSLT
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADSLT", EBADSLT),
#endif
#ifdef EDEADLOCK
  INTEGER_CONSTANT_INFO(iconst_errno, "EDEADLOCK", EDEADLOCK),
#endif
#ifdef EBFONT
  INTEGER_CONSTANT_INFO(iconst_errno, "EBFONT", EBFONT),
#endif
#ifdef ENONET
  INTEGER_CONSTANT_INFO(iconst_errno, "ENONET", ENONET),
#endif
#ifdef ENOPKG
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOPKG", ENOPKG),
#endif
#ifdef EREMOTE
  INTEGER_CONSTANT_INFO(iconst_errno, "EREMOTE", EREMOTE),
#endif
#ifdef EADV
  INTEGER_CONSTANT_INFO(iconst_errno, "EADV", EADV),
#endif
#ifdef ESRMNT
  INTEGER_CONSTANT_INFO(iconst_errno, "ESRMNT", ESRMNT),
#endif
#ifdef ECOMM
  INTEGER_CONSTANT_INFO(iconst_errno, "ECOMM", ECOMM),
#endif
#ifdef EDOTDOT
  INTEGER_CONSTANT_INFO(iconst_errno, "EDOTDOT", EDOTDOT),
#endif
#ifdef ENOTUNIQ
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTUNIQ", ENOTUNIQ),
#endif
#ifdef EBADFD
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADFD", EBADFD),
#endif
#ifdef EREMCHG
  INTEGER_CONSTANT_INFO(iconst_errno, "EREMCHG", EREMCHG),
#endif
#ifdef ELIBACC
  INTEGER_CONSTANT_INFO(iconst_errno, "ELIBACC", ELIBACC),
#endif
#ifdef ELIBBAD
  INTEGER_CONSTANT_INFO(iconst_errno, "ELIBBAD", ELIBBAD),
#endif
#ifdef ELIBSCN
  INTEGER_CONSTANT_INFO(iconst_errno, "ELIBSCN", ELIBSCN),
#endif
#ifdef ELIBMAX
  INTEGER_CONSTANT_INFO(iconst_errno, "ELIBMAX", ELIBMAX),
#endif
#ifdef ELIBEXEC
  INTEGER_CONSTANT_INFO(iconst_errno, "ELIBEXEC", ELIBEXEC),
#endif
#ifdef ERESTART
  INTEGER_CONSTANT_INFO(iconst_errno, "ERESTART", ERESTART),
#endif
#ifdef ESTRPIPE
  INTEGER_CONSTANT_INFO(iconst_errno, "ESTRPIPE", ESTRPIPE),
#endif
#ifdef EUSERS
  INTEGER_CONSTANT_INFO(iconst_errno, "EUSERS", EUSERS),
#endif
#ifdef ESOCKTNOSUPPORT
  INTEGER_CONSTANT_INFO(iconst_errno, "ESOCKTNOSUPPORT", ESOCKTNOSUPPORT),
#endif
#ifdef EPFNOSUPPORT
  INTEGER_CONSTANT_INFO(iconst_errno, "EPFNOSUPPORT", EPFNOSUPPORT),
#endif
#ifdef ESHUTDOWN
  INTEGER_CONSTANT_INFO(iconst_errno, "ESHUTDOWN", ESHUTDOWN),
#endif
#ifdef ETOOMANYREFS
  INTEGER_CONSTANT_INFO(iconst_errno, "ETOOMANYREFS", ETOOMANYREFS),
#endif
#ifdef EHOSTDOWN
  INTEGER_CONSTANT_INFO(iconst_errno, "EHOSTDOWN", EHOSTDOWN),
#endif
#ifdef EUCLEAN
  INTEGER_CONSTANT_INFO(iconst_errno, "EUCLEAN", EUCLEAN),
#endif
#ifdef ENOTNAM
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTNAM", ENOTNAM),
#endif
#ifdef ENAVAIL
  INTEGER_CONSTANT_INFO(iconst_errno, "ENAVAIL", ENAVAIL),
#endif
#ifdef EISNAM
  INTEGER_CONSTANT_INFO(iconst_errno, "EISNAM", EISNAM),
#endif
#ifdef EREMOTEIO
  INTEGER_CONSTANT_INFO(iconst_errno, "EREMOTEIO", EREMOTEIO),
#endif
#ifdef ENOMEDIUM
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOMEDIUM", ENOMEDIUM),
#endif
#ifdef EMEDIUMTYPE
  INTEGER_CONSTANT_INFO(iconst_errno, "EMEDIUMTYPE", EMEDIUMTYPE),
#endif
#ifdef ENOKEY
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOKEY", ENOKEY),
#endif
#ifdef EKEYEXPIRED
  INTEGER_CONSTANT_INFO(iconst_errno, "EKEYEXPIRED", EKEYEXPIRED),
#endif
#ifdef EKEYREVOKED
  INTEGER_CONSTANT_INFO(iconst_errno, "EKEYREVOKED", EKEYREVOKED),
#endif
#ifdef EKEYREJECTED
  INTEGER_CONSTANT_INFO(iconst_errno, "EKEYREJECTED", EKEYREJECTED),
#endif
#ifdef ERFKILL
  INTEGER_CONSTANT_INFO(iconst_errno, "ERFKILL", ERFKILL),
#endif
#ifdef EHWPOISON
  INTEGER_CONSTANT_INFO(iconst_errno, "EHWPOISON", EHWPOISON),
#endif
#ifdef EAUTH
  INTEGER_CONSTANT_INFO(iconst_errno, "EAUTH", EAUTH),
#endif
#ifdef EBACKGROUND
  INTEGER_CONSTANT_INFO(iconst_errno, "EBACKGROUND", EBACKGROUND),
#endif
#ifdef EBADRPC
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADRPC", EBADRPC),
#endif
#ifdef ED
  INTEGER_CONSTANT_INFO(iconst_errno, "ED", ED),
#endif
#ifdef EDIED
  INTEGER_CONSTANT_INFO(iconst_errno, "EDIED", EDIED),
#endif
#ifdef EFTYPE
  INTEGER_CONSTANT_INFO(iconst_errno, "EFTYPE", EFTYPE),
#endif
#ifdef EGRATUITOUS
  INTEGER_CONSTANT_INFO(iconst_errno, "EGRATUITOUS", EGRATUITOUS),
#endif
#ifdef EGREGIOUS
  INTEGER_CONSTANT_INFO(iconst_errno, "EGREGIOUS", EGREGIOUS),
#endif
#ifdef EIEIO
  INTEGER_CONSTANT_INFO(iconst_errno, "EIEIO", EIEIO),
#endif
#ifdef ELAST
  INTEGER_CONSTANT_INFO(iconst_errno, "ELAST", ELAST),
#endif
#ifdef ENEEDAUTH
  INTEGER_CONSTANT_INFO(iconst_errno, "ENEEDAUTH", ENEEDAUTH),
#endif
#ifdef EPROCLIM
  INTEGER_CONSTANT_INFO(iconst_errno, "EPROCLIM", EPROCLIM),
#endif
#ifdef EPROCUNAVAIL
  INTEGER_CONSTANT_INFO(iconst_errno, "EPROCUNAVAIL", EPROCUNAVAIL),
#endif
#ifdef EPROGMISMATCH
  INTEGER_CONSTANT_INFO(iconst_errno, "EPROGMISMATCH", EPROGMISMATCH),
#endif
#ifdef EPROGUNAVAIL
  INTEGER_CONSTANT_INFO(iconst_errno, "EPROGUNAVAIL", EPROGUNAVAIL),
#endif
#ifdef ERPCMISMATCH
  INTEGER_CONSTANT_INFO(iconst_errno, "ERPCMISMATCH", ERPCMISMATCH),
#endif
#ifdef ENOATTR
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOATTR", ENOATTR),
#endif
#ifdef EIPSEC
  INTEGER_CONSTANT_INFO(iconst_errno, "EIPSEC", EIPSEC),
#endif
#ifdef EDOOFUS
  INTEGER_CONSTANT_INFO(iconst_errno, "EDOOFUS", EDOOFUS),
#endif
#ifdef ENOTCAPABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTCAPABLE", ENOTCAPABLE),
#endif
#ifdef ECAPMODE
  INTEGER_CONSTANT_INFO(iconst_errno, "ECAPMODE", ECAPMODE),
#endif
#ifdef EPWROFF
  INTEGER_CONSTANT_INFO(iconst_errno, "EPWROFF", EPWROFF),
#endif
#ifdef EDEVERR
  INTEGER_CONSTANT_INFO(iconst_errno, "EDEVERR", EDEVERR),
#endif
#ifdef EBADEXEC
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADEXEC", EBADEXEC),
#endif
#ifdef EBADARCH
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADARCH", EBADARCH),
#endif
#ifdef ESHLIBVERS
  INTEGER_CONSTANT_INFO(iconst_errno, "ESHLIBVERS", ESHLIBVERS),
#endif
#ifdef EBADMACHO
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADMACHO", EBADMACHO),
#endif
#ifdef ENOPOLICY
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOPOLICY", ENOPOLICY),
#endif
#ifdef EPACKSIZE
  INTEGER_CONSTANT_INFO(iconst_errno, "EPACKSIZE", EPACKSIZE),
#endif
#ifdef EBADIOCTL
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADIOCTL", EBADIOCTL),
#endif
#ifdef EBADMODE
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADMODE", EBADMODE),
#endif
#ifdef EURG
  INTEGER_CONSTANT_INFO(iconst_errno, "EURG", EURG),
#endif
#ifdef ENOURG
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOURG", ENOURG),
#endif
#ifdef ENOCONN
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOCONN", ENOCONN),
#endif
#ifdef EGENERIC
  INTEGER_CONSTANT_INFO(iconst_errno, "EGENERIC", EGENERIC),
#endif
#ifdef ELOCKED
  INTEGER_CONSTANT_INFO(iconst_errno, "ELOCKED", ELOCKED),
#endif
#ifdef EBADCALL
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADCALL", EBADCALL),
#endif
#ifdef EBADSRCDST
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADSRCDST", EBADSRCDST),
#endif
#ifdef ECALLDENIED
  INTEGER_CONSTANT_INFO(iconst_errno, "ECALLDENIED", ECALLDENIED),
#endif
#ifdef EDEADSRCDST
  INTEGER_CONSTANT_INFO(iconst_errno, "EDEADSRCDST", EDEADSRCDST),
#endif
#ifdef ENOTREADY
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTREADY", ENOTREADY),
#endif
#ifdef EBADREQUEST
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADREQUEST", EBADREQUEST),
#endif
#ifdef ETRAPDENIED
  INTEGER_CONSTANT_INFO(iconst_errno, "ETRAPDENIED", ETRAPDENIED),
#endif
#ifdef EDONTREPLY
  INTEGER_CONSTANT_INFO(iconst_errno, "EDONTREPLY", EDONTREPLY),
#endif
#ifdef EBADEPT
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADEPT", EBADEPT),
#endif
#ifdef EDEADEPT
  INTEGER_CONSTANT_INFO(iconst_errno, "EDEADEPT", EDEADEPT),
#endif
#ifdef EBADCPU
  INTEGER_CONSTANT_INFO(iconst_errno, "EBADCPU", EBADCPU),
#endif
#ifdef ELBIN
  INTEGER_CONSTANT_INFO(iconst_errno, "ELBIN", ELBIN),
#endif
#ifdef ENMFILE
  INTEGER_CONSTANT_INFO(iconst_errno, "ENMFILE", ENMFILE),
#endif
#ifdef ENOSHARE
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOSHARE", ENOSHARE),
#endif
#ifdef ECASECLASH
  INTEGER_CONSTANT_INFO(iconst_errno, "ECASECLASH", ECASECLASH),
#endif
#ifdef ELOCKUNMAPPED
  INTEGER_CONSTANT_INFO(iconst_errno, "ELOCKUNMAPPED", ELOCKUNMAPPED),
#endif
#ifdef ENOTACTIVE
  INTEGER_CONSTANT_INFO(iconst_errno, "ENOTACTIVE", ENOTACTIVE),
#endif
#ifdef B_NO_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_ERROR", B_NO_ERROR),
#endif
#ifdef B_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_ERROR", B_ERROR),
#endif
#ifdef B_NO_MEMORY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_MEMORY", B_NO_MEMORY),
#endif
#ifdef B_POSIX_ENOMEM
  INTEGER_CONSTANT_INFO(iconst_errno, "B_POSIX_ENOMEM", B_POSIX_ENOMEM),
#endif
#ifdef B_IO_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_IO_ERROR", B_IO_ERROR),
#endif
#ifdef B_PERMISSION_DENIED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_PERMISSION_DENIED", B_PERMISSION_DENIED),
#endif
#ifdef B_BAD_INDEX
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_INDEX", B_BAD_INDEX),
#endif
#ifdef B_BAD_TYPE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_TYPE", B_BAD_TYPE),
#endif
#ifdef B_BAD_VALUE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_VALUE", B_BAD_VALUE),
#endif
#ifdef B_MISMATCHED_VALUES
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MISMATCHED_VALUES", B_MISMATCHED_VALUES),
#endif
#ifdef B_NAME_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NAME_NOT_FOUND", B_NAME_NOT_FOUND),
#endif
#ifdef B_NAME_IN_USE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NAME_IN_USE", B_NAME_IN_USE),
#endif
#ifdef B_TIMED_OUT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_TIMED_OUT", B_TIMED_OUT),
#endif
#ifdef B_INTERRUPTED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_INTERRUPTED", B_INTERRUPTED),
#endif
#ifdef B_WOULD_BLOCK
  INTEGER_CONSTANT_INFO(iconst_errno, "B_WOULD_BLOCK", B_WOULD_BLOCK),
#endif
#ifdef B_CANCELED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_CANCELED", B_CANCELED),
#endif
#ifdef B_NO_INIT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_INIT", B_NO_INIT),
#endif
#ifdef B_BUSY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BUSY", B_BUSY),
#endif
#ifdef B_NOT_ALLOWED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NOT_ALLOWED", B_NOT_ALLOWED),
#endif
#ifdef B_BAD_DATA
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_DATA", B_BAD_DATA),
#endif
#ifdef B_BAD_SEM_ID
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_SEM_ID", B_BAD_SEM_ID),
#endif
#ifdef B_NO_MORE_SEMS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_MORE_SEMS", B_NO_MORE_SEMS),
#endif
#ifdef B_BAD_THREAD_ID
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_THREAD_ID", B_BAD_THREAD_ID),
#endif
#ifdef B_NO_MORE_THREADS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_MORE_THREADS", B_NO_MORE_THREADS),
#endif
#ifdef B_BAD_THREAD_STATE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_THREAD_STATE", B_BAD_THREAD_STATE),
#endif
#ifdef B_BAD_TEAM_ID
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_TEAM_ID", B_BAD_TEAM_ID),
#endif
#ifdef B_NO_MORE_TEAMS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_MORE_TEAMS", B_NO_MORE_TEAMS),
#endif
#ifdef B_BAD_PORT_ID
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_PORT_ID", B_BAD_PORT_ID),
#endif
#ifdef B_NO_MORE_PORTS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_MORE_PORTS", B_NO_MORE_PORTS),
#endif
#ifdef B_BAD_IMAGE_ID
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_IMAGE_ID", B_BAD_IMAGE_ID),
#endif
#ifdef B_BAD_ADDRESS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_ADDRESS", B_BAD_ADDRESS),
#endif
#ifdef B_NOT_AN_EXECUTABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NOT_AN_EXECUTABLE", B_NOT_AN_EXECUTABLE),
#endif
#ifdef B_MISSING_LIBRARY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MISSING_LIBRARY", B_MISSING_LIBRARY),
#endif
#ifdef B_MISSING_SYMBOL
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MISSING_SYMBOL", B_MISSING_SYMBOL),
#endif
#ifdef B_DEBUGGER_ALREADY_INSTALLED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEBUGGER_ALREADY_INSTALLED", B_DEBUGGER_ALREADY_INSTALLED),
#endif
#ifdef B_BAD_REPLY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_REPLY", B_BAD_REPLY),
#endif
#ifdef B_DUPLICATE_REPLY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DUPLICATE_REPLY", B_DUPLICATE_REPLY),
#endif
#ifdef B_MESSAGE_TO_SELF
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MESSAGE_TO_SELF", B_MESSAGE_TO_SELF),
#endif
#ifdef B_BAD_HANDLER
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_HANDLER", B_BAD_HANDLER),
#endif
#ifdef B_ALREADY_RUNNING
  INTEGER_CONSTANT_INFO(iconst_errno, "B_ALREADY_RUNNING", B_ALREADY_RUNNING),
#endif
#ifdef B_LAUNCH_FAILED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAUNCH_FAILED", B_LAUNCH_FAILED),
#endif
#ifdef B_AMBIGUOUS_APP_LAUNCH
  INTEGER_CONSTANT_INFO(iconst_errno, "B_AMBIGUOUS_APP_LAUNCH", B_AMBIGUOUS_APP_LAUNCH),
#endif
#ifdef B_UNKNOWN_MIME_TYPE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_UNKNOWN_MIME_TYPE", B_UNKNOWN_MIME_TYPE),
#endif
#ifdef B_BAD_SCRIPT_SYNTAX
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_SCRIPT_SYNTAX", B_BAD_SCRIPT_SYNTAX),
#endif
#ifdef B_LAUNCH_FAILED_NO_RESOLVE_LINK
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAUNCH_FAILED_NO_RESOLVE_LINK", B_LAUNCH_FAILED_NO_RESOLVE_LINK),
#endif
#ifdef B_LAUNCH_FAILED_EXECUTABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAUNCH_FAILED_EXECUTABLE", B_LAUNCH_FAILED_EXECUTABLE),
#endif
#ifdef B_LAUNCH_FAILED_APP_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAUNCH_FAILED_APP_NOT_FOUND", B_LAUNCH_FAILED_APP_NOT_FOUND),
#endif
#ifdef B_LAUNCH_FAILED_APP_IN_TRASH
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAUNCH_FAILED_APP_IN_TRASH", B_LAUNCH_FAILED_APP_IN_TRASH),
#endif
#ifdef B_LAUNCH_FAILED_NO_PREFERRED_APP
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAUNCH_FAILED_NO_PREFERRED_APP", B_LAUNCH_FAILED_NO_PREFERRED_APP),
#endif
#ifdef B_LAUNCH_FAILED_FILES_APP_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAUNCH_FAILED_FILES_APP_NOT_FOUND", B_LAUNCH_FAILED_FILES_APP_NOT_FOUND),
#endif
#ifdef B_BAD_MIME_SNIFFER_RULE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_MIME_SNIFFER_RULE", B_BAD_MIME_SNIFFER_RULE),
#endif
#ifdef B_NOT_A_MESSAGE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NOT_A_MESSAGE", B_NOT_A_MESSAGE),
#endif
#ifdef B_SHUTDOWN_CANCELLED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_SHUTDOWN_CANCELLED", B_SHUTDOWN_CANCELLED),
#endif
#ifdef B_SHUTTING_DOWN
  INTEGER_CONSTANT_INFO(iconst_errno, "B_SHUTTING_DOWN", B_SHUTTING_DOWN),
#endif
#ifdef B_FILE_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_FILE_ERROR", B_FILE_ERROR),
#endif
#ifdef B_FILE_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_FILE_NOT_FOUND", B_FILE_NOT_FOUND),
#endif
#ifdef B_ENTRY_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_ENTRY_NOT_FOUND", B_ENTRY_NOT_FOUND),
#endif
#ifdef B_FILE_EXISTS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_FILE_EXISTS", B_FILE_EXISTS),
#endif
#ifdef B_NAME_TOO_LONG
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NAME_TOO_LONG", B_NAME_TOO_LONG),
#endif
#ifdef B_NOT_A_DIRECTORY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NOT_A_DIRECTORY", B_NOT_A_DIRECTORY),
#endif
#ifdef B_DIRECTORY_NOT_EMPTY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DIRECTORY_NOT_EMPTY", B_DIRECTORY_NOT_EMPTY),
#endif
#ifdef B_DEVICE_FULL
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEVICE_FULL", B_DEVICE_FULL),
#endif
#ifdef B_READ_ONLY_DEVICE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_READ_ONLY_DEVICE", B_READ_ONLY_DEVICE),
#endif
#ifdef B_IS_A_DIRECTORY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_IS_A_DIRECTORY", B_IS_A_DIRECTORY),
#endif
#ifdef B_NO_MORE_FDS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_MORE_FDS", B_NO_MORE_FDS),
#endif
#ifdef B_CROSS_DEVICE_LINK
  INTEGER_CONSTANT_INFO(iconst_errno, "B_CROSS_DEVICE_LINK", B_CROSS_DEVICE_LINK),
#endif
#ifdef B_LINK_LIMIT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LINK_LIMIT", B_LINK_LIMIT),
#endif
#ifdef B_BUSTED_PIPE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BUSTED_PIPE", B_BUSTED_PIPE),
#endif
#ifdef B_UNSUPPORTED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_UNSUPPORTED", B_UNSUPPORTED),
#endif
#ifdef B_PARTITION_TOO_SMALL
  INTEGER_CONSTANT_INFO(iconst_errno, "B_PARTITION_TOO_SMALL", B_PARTITION_TOO_SMALL),
#endif
#ifdef B_STREAM_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_STREAM_NOT_FOUND", B_STREAM_NOT_FOUND),
#endif
#ifdef B_SERVER_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_SERVER_NOT_FOUND", B_SERVER_NOT_FOUND),
#endif
#ifdef B_RESOURCE_NOT_FOUND
  INTEGER_CONSTANT_INFO(iconst_errno, "B_RESOURCE_NOT_FOUND", B_RESOURCE_NOT_FOUND),
#endif
#ifdef B_RESOURCE_UNAVAILABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_RESOURCE_UNAVAILABLE", B_RESOURCE_UNAVAILABLE),
#endif
#ifdef B_BAD_SUBSCRIBER
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BAD_SUBSCRIBER", B_BAD_SUBSCRIBER),
#endif
#ifdef B_SUBSCRIBER_NOT_ENTERED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_SUBSCRIBER_NOT_ENTERED", B_SUBSCRIBER_NOT_ENTERED),
#endif
#ifdef B_BUFFER_NOT_AVAILABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_BUFFER_NOT_AVAILABLE", B_BUFFER_NOT_AVAILABLE),
#endif
#ifdef B_LAST_BUFFER_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_LAST_BUFFER_ERROR", B_LAST_BUFFER_ERROR),
#endif
#ifdef B_MEDIA_SYSTEM_FAILURE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_SYSTEM_FAILURE", B_MEDIA_SYSTEM_FAILURE),
#endif
#ifdef B_MEDIA_BAD_NODE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BAD_NODE", B_MEDIA_BAD_NODE),
#endif
#ifdef B_MEDIA_NODE_BUSY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_NODE_BUSY", B_MEDIA_NODE_BUSY),
#endif
#ifdef B_MEDIA_BAD_FORMAT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BAD_FORMAT", B_MEDIA_BAD_FORMAT),
#endif
#ifdef B_MEDIA_BAD_BUFFER
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BAD_BUFFER", B_MEDIA_BAD_BUFFER),
#endif
#ifdef B_MEDIA_TOO_MANY_NODES
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_TOO_MANY_NODES", B_MEDIA_TOO_MANY_NODES),
#endif
#ifdef B_MEDIA_TOO_MANY_BUFFERS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_TOO_MANY_BUFFERS", B_MEDIA_TOO_MANY_BUFFERS),
#endif
#ifdef B_MEDIA_NODE_ALREADY_EXISTS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_NODE_ALREADY_EXISTS", B_MEDIA_NODE_ALREADY_EXISTS),
#endif
#ifdef B_MEDIA_BUFFER_ALREADY_EXISTS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BUFFER_ALREADY_EXISTS", B_MEDIA_BUFFER_ALREADY_EXISTS),
#endif
#ifdef B_MEDIA_CANNOT_SEEK
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_CANNOT_SEEK", B_MEDIA_CANNOT_SEEK),
#endif
#ifdef B_MEDIA_CANNOT_CHANGE_RUN_MODE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_CANNOT_CHANGE_RUN_MODE", B_MEDIA_CANNOT_CHANGE_RUN_MODE),
#endif
#ifdef B_MEDIA_APP_ALREADY_REGISTERED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_APP_ALREADY_REGISTERED", B_MEDIA_APP_ALREADY_REGISTERED),
#endif
#ifdef B_MEDIA_APP_NOT_REGISTERED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_APP_NOT_REGISTERED", B_MEDIA_APP_NOT_REGISTERED),
#endif
#ifdef B_MEDIA_CANNOT_RECLAIM_BUFFERS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_CANNOT_RECLAIM_BUFFERS", B_MEDIA_CANNOT_RECLAIM_BUFFERS),
#endif
#ifdef B_MEDIA_BUFFERS_NOT_RECLAIMED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BUFFERS_NOT_RECLAIMED", B_MEDIA_BUFFERS_NOT_RECLAIMED),
#endif
#ifdef B_MEDIA_TIME_SOURCE_STOPPED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_TIME_SOURCE_STOPPED", B_MEDIA_TIME_SOURCE_STOPPED),
#endif
#ifdef B_MEDIA_TIME_SOURCE_BUSY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_TIME_SOURCE_BUSY", B_MEDIA_TIME_SOURCE_BUSY),
#endif
#ifdef B_MEDIA_BAD_SOURCE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BAD_SOURCE", B_MEDIA_BAD_SOURCE),
#endif
#ifdef B_MEDIA_BAD_DESTINATION
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BAD_DESTINATION", B_MEDIA_BAD_DESTINATION),
#endif
#ifdef B_MEDIA_ALREADY_CONNECTED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_ALREADY_CONNECTED", B_MEDIA_ALREADY_CONNECTED),
#endif
#ifdef B_MEDIA_NOT_CONNECTED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_NOT_CONNECTED", B_MEDIA_NOT_CONNECTED),
#endif
#ifdef B_MEDIA_BAD_CLIP_FORMAT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_BAD_CLIP_FORMAT", B_MEDIA_BAD_CLIP_FORMAT),
#endif
#ifdef B_MEDIA_ADDON_FAILED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_ADDON_FAILED", B_MEDIA_ADDON_FAILED),
#endif
#ifdef B_MEDIA_ADDON_DISABLED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_ADDON_DISABLED", B_MEDIA_ADDON_DISABLED),
#endif
#ifdef B_MEDIA_CHANGE_IN_PROGRESS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_CHANGE_IN_PROGRESS", B_MEDIA_CHANGE_IN_PROGRESS),
#endif
#ifdef B_MEDIA_STALE_CHANGE_COUNT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_STALE_CHANGE_COUNT", B_MEDIA_STALE_CHANGE_COUNT),
#endif
#ifdef B_MEDIA_ADDON_RESTRICTED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_ADDON_RESTRICTED", B_MEDIA_ADDON_RESTRICTED),
#endif
#ifdef B_MEDIA_NO_HANDLER
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_NO_HANDLER", B_MEDIA_NO_HANDLER),
#endif
#ifdef B_MEDIA_DUPLICATE_FORMAT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_DUPLICATE_FORMAT", B_MEDIA_DUPLICATE_FORMAT),
#endif
#ifdef B_MEDIA_REALTIME_DISABLED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_REALTIME_DISABLED", B_MEDIA_REALTIME_DISABLED),
#endif
#ifdef B_MEDIA_REALTIME_UNAVAILABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MEDIA_REALTIME_UNAVAILABLE", B_MEDIA_REALTIME_UNAVAILABLE),
#endif
#ifdef B_MAIL_NO_DAEMON
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_NO_DAEMON", B_MAIL_NO_DAEMON),
#endif
#ifdef B_MAIL_UNKNOWN_USER
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_UNKNOWN_USER", B_MAIL_UNKNOWN_USER),
#endif
#ifdef B_MAIL_WRONG_PASSWORD
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_WRONG_PASSWORD", B_MAIL_WRONG_PASSWORD),
#endif
#ifdef B_MAIL_UNKNOWN_HOST
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_UNKNOWN_HOST", B_MAIL_UNKNOWN_HOST),
#endif
#ifdef B_MAIL_ACCESS_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_ACCESS_ERROR", B_MAIL_ACCESS_ERROR),
#endif
#ifdef B_MAIL_UNKNOWN_FIELD
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_UNKNOWN_FIELD", B_MAIL_UNKNOWN_FIELD),
#endif
#ifdef B_MAIL_NO_RECIPIENT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_NO_RECIPIENT", B_MAIL_NO_RECIPIENT),
#endif
#ifdef B_MAIL_INVALID_MAIL
  INTEGER_CONSTANT_INFO(iconst_errno, "B_MAIL_INVALID_MAIL", B_MAIL_INVALID_MAIL),
#endif
#ifdef B_NO_PRINT_SERVER
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_PRINT_SERVER", B_NO_PRINT_SERVER),
#endif
#ifdef B_DEV_INVALID_IOCTL
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_INVALID_IOCTL", B_DEV_INVALID_IOCTL),
#endif
#ifdef B_DEV_NO_MEMORY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_NO_MEMORY", B_DEV_NO_MEMORY),
#endif
#ifdef B_DEV_BAD_DRIVE_NUM
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_BAD_DRIVE_NUM", B_DEV_BAD_DRIVE_NUM),
#endif
#ifdef B_DEV_NO_MEDIA
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_NO_MEDIA", B_DEV_NO_MEDIA),
#endif
#ifdef B_DEV_UNREADABLE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_UNREADABLE", B_DEV_UNREADABLE),
#endif
#ifdef B_DEV_FORMAT_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_FORMAT_ERROR", B_DEV_FORMAT_ERROR),
#endif
#ifdef B_DEV_TIMEOUT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_TIMEOUT", B_DEV_TIMEOUT),
#endif
#ifdef B_DEV_RECALIBRATE_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_RECALIBRATE_ERROR", B_DEV_RECALIBRATE_ERROR),
#endif
#ifdef B_DEV_SEEK_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_SEEK_ERROR", B_DEV_SEEK_ERROR),
#endif
#ifdef B_DEV_ID_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_ID_ERROR", B_DEV_ID_ERROR),
#endif
#ifdef B_DEV_READ_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_READ_ERROR", B_DEV_READ_ERROR),
#endif
#ifdef B_DEV_WRITE_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_WRITE_ERROR", B_DEV_WRITE_ERROR),
#endif
#ifdef B_DEV_NOT_READY
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_NOT_READY", B_DEV_NOT_READY),
#endif
#ifdef B_DEV_MEDIA_CHANGED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_MEDIA_CHANGED", B_DEV_MEDIA_CHANGED),
#endif
#ifdef B_DEV_MEDIA_CHANGE_REQUESTED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_MEDIA_CHANGE_REQUESTED", B_DEV_MEDIA_CHANGE_REQUESTED),
#endif
#ifdef B_DEV_RESOURCE_CONFLICT
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_RESOURCE_CONFLICT", B_DEV_RESOURCE_CONFLICT),
#endif
#ifdef B_DEV_CONFIGURATION_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_CONFIGURATION_ERROR", B_DEV_CONFIGURATION_ERROR),
#endif
#ifdef B_DEV_DISABLED_BY_USER
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_DISABLED_BY_USER", B_DEV_DISABLED_BY_USER),
#endif
#ifdef B_DEV_DOOR_OPEN
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_DOOR_OPEN", B_DEV_DOOR_OPEN),
#endif
#ifdef B_DEV_INVALID_PIPE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_INVALID_PIPE", B_DEV_INVALID_PIPE),
#endif
#ifdef B_DEV_CRC_ERROR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_CRC_ERROR", B_DEV_CRC_ERROR),
#endif
#ifdef B_DEV_STALLED
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_STALLED", B_DEV_STALLED),
#endif
#ifdef B_DEV_BAD_PID
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_BAD_PID", B_DEV_BAD_PID),
#endif
#ifdef B_DEV_UNEXPECTED_PID
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_UNEXPECTED_PID", B_DEV_UNEXPECTED_PID),
#endif
#ifdef B_DEV_DATA_OVERRUN
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_DATA_OVERRUN", B_DEV_DATA_OVERRUN),
#endif
#ifdef B_DEV_DATA_UNDERRUN
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_DATA_UNDERRUN", B_DEV_DATA_UNDERRUN),
#endif
#ifdef B_DEV_FIFO_OVERRUN
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_FIFO_OVERRUN", B_DEV_FIFO_OVERRUN),
#endif
#ifdef B_DEV_FIFO_UNDERRUN
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_FIFO_UNDERRUN", B_DEV_FIFO_UNDERRUN),
#endif
#ifdef B_DEV_PENDING
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_PENDING", B_DEV_PENDING),
#endif
#ifdef B_DEV_MULTIPLE_ERRORS
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_MULTIPLE_ERRORS", B_DEV_MULTIPLE_ERRORS),
#endif
#ifdef B_DEV_TOO_LATE
  INTEGER_CONSTANT_INFO(iconst_errno, "B_DEV_TOO_LATE", B_DEV_TOO_LATE),
#endif
#ifdef B_NO_TRANSLATOR
  INTEGER_CONSTANT_INFO(iconst_errno, "B_NO_TRANSLATOR", B_NO_TRANSLATOR),
#endif
#ifdef B_ILLEGAL_DATA
  INTEGER_CONSTANT_INFO(iconst_errno, "B_ILLEGAL_DATA", B_ILLEGAL_DATA),
#endif
#ifdef EFPOS
  INTEGER_CONSTANT_INFO(iconst_errno, "EFPOS", EFPOS),
#endif
#ifdef ESIGPARM
  INTEGER_CONSTANT_INFO(iconst_errno, "ESIGPARM", ESIGPARM),
#endif
  { iconst_unspecified, NULL, 0, 0, 0, 0 }
};

const int iconst_numents =
  sizeof(iconst_table) / sizeof(*iconst_table) - 1;
