/* errmsg.c is generated from errsym.erb. */

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

int main(int argc, char *argv[])
{
  int err;
  char *str;

  (void)argc;
  (void)argv;

#ifdef E2BIG
  err = E2BIG; str = "E2BIG";
  printf("%s = %d\n", str, err);
#endif
#ifdef EACCES
  err = EACCES; str = "EACCES";
  printf("%s = %d\n", str, err);
#endif
#ifdef EADDRINUSE
  err = EADDRINUSE; str = "EADDRINUSE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EADDRNOTAVAIL
  err = EADDRNOTAVAIL; str = "EADDRNOTAVAIL";
  printf("%s = %d\n", str, err);
#endif
#ifdef EADV
  err = EADV; str = "EADV";
  printf("%s = %d\n", str, err);
#endif
#ifdef EAFNOSUPPORT
  err = EAFNOSUPPORT; str = "EAFNOSUPPORT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EAGAIN
  err = EAGAIN; str = "EAGAIN";
  printf("%s = %d\n", str, err);
#endif
#ifdef EALREADY
  err = EALREADY; str = "EALREADY";
  printf("%s = %d\n", str, err);
#endif
#ifdef EAUTH
  err = EAUTH; str = "EAUTH";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBACKGROUND
  err = EBACKGROUND; str = "EBACKGROUND";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADARCH
  err = EBADARCH; str = "EBADARCH";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADCALL
  err = EBADCALL; str = "EBADCALL";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADCPU
  err = EBADCPU; str = "EBADCPU";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADE
  err = EBADE; str = "EBADE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADEPT
  err = EBADEPT; str = "EBADEPT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADEXEC
  err = EBADEXEC; str = "EBADEXEC";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADF
  err = EBADF; str = "EBADF";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADFD
  err = EBADFD; str = "EBADFD";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADIOCTL
  err = EBADIOCTL; str = "EBADIOCTL";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADMACHO
  err = EBADMACHO; str = "EBADMACHO";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADMODE
  err = EBADMODE; str = "EBADMODE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADMSG
  err = EBADMSG; str = "EBADMSG";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADR
  err = EBADR; str = "EBADR";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADREQUEST
  err = EBADREQUEST; str = "EBADREQUEST";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADRPC
  err = EBADRPC; str = "EBADRPC";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADRQC
  err = EBADRQC; str = "EBADRQC";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADSLT
  err = EBADSLT; str = "EBADSLT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBADSRCDST
  err = EBADSRCDST; str = "EBADSRCDST";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBFONT
  err = EBFONT; str = "EBFONT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EBUSY
  err = EBUSY; str = "EBUSY";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECALLDENIED
  err = ECALLDENIED; str = "ECALLDENIED";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECANCELED
  err = ECANCELED; str = "ECANCELED";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECAPMODE
  err = ECAPMODE; str = "ECAPMODE";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECHILD
  err = ECHILD; str = "ECHILD";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECHRNG
  err = ECHRNG; str = "ECHRNG";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECOMM
  err = ECOMM; str = "ECOMM";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECONNABORTED
  err = ECONNABORTED; str = "ECONNABORTED";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECONNREFUSED
  err = ECONNREFUSED; str = "ECONNREFUSED";
  printf("%s = %d\n", str, err);
#endif
#ifdef ECONNRESET
  err = ECONNRESET; str = "ECONNRESET";
  printf("%s = %d\n", str, err);
#endif
#ifdef ED
  err = ED; str = "ED";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDEADEPT
  err = EDEADEPT; str = "EDEADEPT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDEADLK
  err = EDEADLK; str = "EDEADLK";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDEADLOCK
  err = EDEADLOCK; str = "EDEADLOCK";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDEADSRCDST
  err = EDEADSRCDST; str = "EDEADSRCDST";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDESTADDRREQ
  err = EDESTADDRREQ; str = "EDESTADDRREQ";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDEVERR
  err = EDEVERR; str = "EDEVERR";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDIED
  err = EDIED; str = "EDIED";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDOM
  err = EDOM; str = "EDOM";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDONTREPLY
  err = EDONTREPLY; str = "EDONTREPLY";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDOOFUS
  err = EDOOFUS; str = "EDOOFUS";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDOTDOT
  err = EDOTDOT; str = "EDOTDOT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EDQUOT
  err = EDQUOT; str = "EDQUOT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EEXIST
  err = EEXIST; str = "EEXIST";
  printf("%s = %d\n", str, err);
#endif
#ifdef EFAULT
  err = EFAULT; str = "EFAULT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EFBIG
  err = EFBIG; str = "EFBIG";
  printf("%s = %d\n", str, err);
#endif
#ifdef EFTYPE
  err = EFTYPE; str = "EFTYPE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EGENERIC
  err = EGENERIC; str = "EGENERIC";
  printf("%s = %d\n", str, err);
#endif
#ifdef EGRATUITOUS
  err = EGRATUITOUS; str = "EGRATUITOUS";
  printf("%s = %d\n", str, err);
#endif
#ifdef EGREGIOUS
  err = EGREGIOUS; str = "EGREGIOUS";
  printf("%s = %d\n", str, err);
#endif
#ifdef EHOSTDOWN
  err = EHOSTDOWN; str = "EHOSTDOWN";
  printf("%s = %d\n", str, err);
#endif
#ifdef EHOSTUNREACH
  err = EHOSTUNREACH; str = "EHOSTUNREACH";
  printf("%s = %d\n", str, err);
#endif
#ifdef EHWPOISON
  err = EHWPOISON; str = "EHWPOISON";
  printf("%s = %d\n", str, err);
#endif
#ifdef EIDRM
  err = EIDRM; str = "EIDRM";
  printf("%s = %d\n", str, err);
#endif
#ifdef EIEIO
  err = EIEIO; str = "EIEIO";
  printf("%s = %d\n", str, err);
#endif
#ifdef EILSEQ
  err = EILSEQ; str = "EILSEQ";
  printf("%s = %d\n", str, err);
#endif
#ifdef EINPROGRESS
  err = EINPROGRESS; str = "EINPROGRESS";
  printf("%s = %d\n", str, err);
#endif
#ifdef EINTR
  err = EINTR; str = "EINTR";
  printf("%s = %d\n", str, err);
#endif
#ifdef EINVAL
  err = EINVAL; str = "EINVAL";
  printf("%s = %d\n", str, err);
#endif
#ifdef EIO
  err = EIO; str = "EIO";
  printf("%s = %d\n", str, err);
#endif
#ifdef EIPSEC
  err = EIPSEC; str = "EIPSEC";
  printf("%s = %d\n", str, err);
#endif
#ifdef EISCONN
  err = EISCONN; str = "EISCONN";
  printf("%s = %d\n", str, err);
#endif
#ifdef EISDIR
  err = EISDIR; str = "EISDIR";
  printf("%s = %d\n", str, err);
#endif
#ifdef EISNAM
  err = EISNAM; str = "EISNAM";
  printf("%s = %d\n", str, err);
#endif
#ifdef EKEYEXPIRED
  err = EKEYEXPIRED; str = "EKEYEXPIRED";
  printf("%s = %d\n", str, err);
#endif
#ifdef EKEYREJECTED
  err = EKEYREJECTED; str = "EKEYREJECTED";
  printf("%s = %d\n", str, err);
#endif
#ifdef EKEYREVOKED
  err = EKEYREVOKED; str = "EKEYREVOKED";
  printf("%s = %d\n", str, err);
#endif
#ifdef EL2HLT
  err = EL2HLT; str = "EL2HLT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EL2NSYNC
  err = EL2NSYNC; str = "EL2NSYNC";
  printf("%s = %d\n", str, err);
#endif
#ifdef EL3HLT
  err = EL3HLT; str = "EL3HLT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EL3RST
  err = EL3RST; str = "EL3RST";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELAST
  err = ELAST; str = "ELAST";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELIBACC
  err = ELIBACC; str = "ELIBACC";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELIBBAD
  err = ELIBBAD; str = "ELIBBAD";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELIBEXEC
  err = ELIBEXEC; str = "ELIBEXEC";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELIBMAX
  err = ELIBMAX; str = "ELIBMAX";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELIBSCN
  err = ELIBSCN; str = "ELIBSCN";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELNRNG
  err = ELNRNG; str = "ELNRNG";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELOCKED
  err = ELOCKED; str = "ELOCKED";
  printf("%s = %d\n", str, err);
#endif
#ifdef ELOOP
  err = ELOOP; str = "ELOOP";
  printf("%s = %d\n", str, err);
#endif
#ifdef EMEDIUMTYPE
  err = EMEDIUMTYPE; str = "EMEDIUMTYPE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EMFILE
  err = EMFILE; str = "EMFILE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EMLINK
  err = EMLINK; str = "EMLINK";
  printf("%s = %d\n", str, err);
#endif
#ifdef EMSGSIZE
  err = EMSGSIZE; str = "EMSGSIZE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EMULTIHOP
  err = EMULTIHOP; str = "EMULTIHOP";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENAMETOOLONG
  err = ENAMETOOLONG; str = "ENAMETOOLONG";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENAVAIL
  err = ENAVAIL; str = "ENAVAIL";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENEEDAUTH
  err = ENEEDAUTH; str = "ENEEDAUTH";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENETDOWN
  err = ENETDOWN; str = "ENETDOWN";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENETRESET
  err = ENETRESET; str = "ENETRESET";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENETUNREACH
  err = ENETUNREACH; str = "ENETUNREACH";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENFILE
  err = ENFILE; str = "ENFILE";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOANO
  err = ENOANO; str = "ENOANO";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOATTR
  err = ENOATTR; str = "ENOATTR";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOBUFS
  err = ENOBUFS; str = "ENOBUFS";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOCONN
  err = ENOCONN; str = "ENOCONN";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOCSI
  err = ENOCSI; str = "ENOCSI";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENODATA
  err = ENODATA; str = "ENODATA";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENODEV
  err = ENODEV; str = "ENODEV";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOENT
  err = ENOENT; str = "ENOENT";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOEXEC
  err = ENOEXEC; str = "ENOEXEC";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOKEY
  err = ENOKEY; str = "ENOKEY";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOLCK
  err = ENOLCK; str = "ENOLCK";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOLINK
  err = ENOLINK; str = "ENOLINK";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOMEDIUM
  err = ENOMEDIUM; str = "ENOMEDIUM";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOMEM
  err = ENOMEM; str = "ENOMEM";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOMSG
  err = ENOMSG; str = "ENOMSG";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENONET
  err = ENONET; str = "ENONET";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOPKG
  err = ENOPKG; str = "ENOPKG";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOPOLICY
  err = ENOPOLICY; str = "ENOPOLICY";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOPROTOOPT
  err = ENOPROTOOPT; str = "ENOPROTOOPT";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOSPC
  err = ENOSPC; str = "ENOSPC";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOSR
  err = ENOSR; str = "ENOSR";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOSTR
  err = ENOSTR; str = "ENOSTR";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOSYS
  err = ENOSYS; str = "ENOSYS";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTBLK
  err = ENOTBLK; str = "ENOTBLK";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTCAPABLE
  err = ENOTCAPABLE; str = "ENOTCAPABLE";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTCONN
  err = ENOTCONN; str = "ENOTCONN";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTDIR
  err = ENOTDIR; str = "ENOTDIR";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTEMPTY
  err = ENOTEMPTY; str = "ENOTEMPTY";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTNAM
  err = ENOTNAM; str = "ENOTNAM";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTREADY
  err = ENOTREADY; str = "ENOTREADY";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTRECOVERABLE
  err = ENOTRECOVERABLE; str = "ENOTRECOVERABLE";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTSOCK
  err = ENOTSOCK; str = "ENOTSOCK";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTSUP
  err = ENOTSUP; str = "ENOTSUP";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTTY
  err = ENOTTY; str = "ENOTTY";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOTUNIQ
  err = ENOTUNIQ; str = "ENOTUNIQ";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENOURG
  err = ENOURG; str = "ENOURG";
  printf("%s = %d\n", str, err);
#endif
#ifdef ENXIO
  err = ENXIO; str = "ENXIO";
  printf("%s = %d\n", str, err);
#endif
#ifdef EOPNOTSUPP
  err = EOPNOTSUPP; str = "EOPNOTSUPP";
  printf("%s = %d\n", str, err);
#endif
#ifdef EOVERFLOW
  err = EOVERFLOW; str = "EOVERFLOW";
  printf("%s = %d\n", str, err);
#endif
#ifdef EOWNERDEAD
  err = EOWNERDEAD; str = "EOWNERDEAD";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPACKSIZE
  err = EPACKSIZE; str = "EPACKSIZE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPERM
  err = EPERM; str = "EPERM";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPFNOSUPPORT
  err = EPFNOSUPPORT; str = "EPFNOSUPPORT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPIPE
  err = EPIPE; str = "EPIPE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPROCLIM
  err = EPROCLIM; str = "EPROCLIM";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPROCUNAVAIL
  err = EPROCUNAVAIL; str = "EPROCUNAVAIL";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPROGMISMATCH
  err = EPROGMISMATCH; str = "EPROGMISMATCH";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPROGUNAVAIL
  err = EPROGUNAVAIL; str = "EPROGUNAVAIL";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPROTO
  err = EPROTO; str = "EPROTO";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPROTONOSUPPORT
  err = EPROTONOSUPPORT; str = "EPROTONOSUPPORT";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPROTOTYPE
  err = EPROTOTYPE; str = "EPROTOTYPE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EPWROFF
  err = EPWROFF; str = "EPWROFF";
  printf("%s = %d\n", str, err);
#endif
#ifdef ERANGE
  err = ERANGE; str = "ERANGE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EREMCHG
  err = EREMCHG; str = "EREMCHG";
  printf("%s = %d\n", str, err);
#endif
#ifdef EREMOTE
  err = EREMOTE; str = "EREMOTE";
  printf("%s = %d\n", str, err);
#endif
#ifdef EREMOTEIO
  err = EREMOTEIO; str = "EREMOTEIO";
  printf("%s = %d\n", str, err);
#endif
#ifdef ERESTART
  err = ERESTART; str = "ERESTART";
  printf("%s = %d\n", str, err);
#endif
#ifdef ERFKILL
  err = ERFKILL; str = "ERFKILL";
  printf("%s = %d\n", str, err);
#endif
#ifdef EROFS
  err = EROFS; str = "EROFS";
  printf("%s = %d\n", str, err);
#endif
#ifdef ERPCMISMATCH
  err = ERPCMISMATCH; str = "ERPCMISMATCH";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESHLIBVERS
  err = ESHLIBVERS; str = "ESHLIBVERS";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESHUTDOWN
  err = ESHUTDOWN; str = "ESHUTDOWN";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESOCKTNOSUPPORT
  err = ESOCKTNOSUPPORT; str = "ESOCKTNOSUPPORT";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESPIPE
  err = ESPIPE; str = "ESPIPE";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESRCH
  err = ESRCH; str = "ESRCH";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESRMNT
  err = ESRMNT; str = "ESRMNT";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESTALE
  err = ESTALE; str = "ESTALE";
  printf("%s = %d\n", str, err);
#endif
#ifdef ESTRPIPE
  err = ESTRPIPE; str = "ESTRPIPE";
  printf("%s = %d\n", str, err);
#endif
#ifdef ETIME
  err = ETIME; str = "ETIME";
  printf("%s = %d\n", str, err);
#endif
#ifdef ETIMEDOUT
  err = ETIMEDOUT; str = "ETIMEDOUT";
  printf("%s = %d\n", str, err);
#endif
#ifdef ETOOMANYREFS
  err = ETOOMANYREFS; str = "ETOOMANYREFS";
  printf("%s = %d\n", str, err);
#endif
#ifdef ETRAPDENIED
  err = ETRAPDENIED; str = "ETRAPDENIED";
  printf("%s = %d\n", str, err);
#endif
#ifdef ETXTBSY
  err = ETXTBSY; str = "ETXTBSY";
  printf("%s = %d\n", str, err);
#endif
#ifdef EUCLEAN
  err = EUCLEAN; str = "EUCLEAN";
  printf("%s = %d\n", str, err);
#endif
#ifdef EUNATCH
  err = EUNATCH; str = "EUNATCH";
  printf("%s = %d\n", str, err);
#endif
#ifdef EURG
  err = EURG; str = "EURG";
  printf("%s = %d\n", str, err);
#endif
#ifdef EUSERS
  err = EUSERS; str = "EUSERS";
  printf("%s = %d\n", str, err);
#endif
#ifdef EWOULDBLOCK
  err = EWOULDBLOCK; str = "EWOULDBLOCK";
  printf("%s = %d\n", str, err);
#endif
#ifdef EXDEV
  err = EXDEV; str = "EXDEV";
  printf("%s = %d\n", str, err);
#endif
#ifdef EXFULL
  err = EXFULL; str = "EXFULL";
  printf("%s = %d\n", str, err);
#endif
  return EXIT_SUCCESS;
}
