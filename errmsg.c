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
  int min, max, ret, i;

  (void)argc;
  (void)argv;

#ifdef E2BIG
  err = E2BIG; str = "E2BIG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EACCES
  err = EACCES; str = "EACCES";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EADDRINUSE
  err = EADDRINUSE; str = "EADDRINUSE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EADDRNOTAVAIL
  err = EADDRNOTAVAIL; str = "EADDRNOTAVAIL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EADV
  err = EADV; str = "EADV";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EAFNOSUPPORT
  err = EAFNOSUPPORT; str = "EAFNOSUPPORT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EAGAIN
  err = EAGAIN; str = "EAGAIN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EALREADY
  err = EALREADY; str = "EALREADY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EAUTH
  err = EAUTH; str = "EAUTH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBACKGROUND
  err = EBACKGROUND; str = "EBACKGROUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADARCH
  err = EBADARCH; str = "EBADARCH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADCALL
  err = EBADCALL; str = "EBADCALL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADCPU
  err = EBADCPU; str = "EBADCPU";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADE
  err = EBADE; str = "EBADE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADEPT
  err = EBADEPT; str = "EBADEPT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADEXEC
  err = EBADEXEC; str = "EBADEXEC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADF
  err = EBADF; str = "EBADF";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADFD
  err = EBADFD; str = "EBADFD";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADIOCTL
  err = EBADIOCTL; str = "EBADIOCTL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADMACHO
  err = EBADMACHO; str = "EBADMACHO";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADMODE
  err = EBADMODE; str = "EBADMODE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADMSG
  err = EBADMSG; str = "EBADMSG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADR
  err = EBADR; str = "EBADR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADREQUEST
  err = EBADREQUEST; str = "EBADREQUEST";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADRPC
  err = EBADRPC; str = "EBADRPC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADRQC
  err = EBADRQC; str = "EBADRQC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADSLT
  err = EBADSLT; str = "EBADSLT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBADSRCDST
  err = EBADSRCDST; str = "EBADSRCDST";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBFONT
  err = EBFONT; str = "EBFONT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EBUSY
  err = EBUSY; str = "EBUSY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECALLDENIED
  err = ECALLDENIED; str = "ECALLDENIED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECANCELED
  err = ECANCELED; str = "ECANCELED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECAPMODE
  err = ECAPMODE; str = "ECAPMODE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECASECLASH
  err = ECASECLASH; str = "ECASECLASH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECHILD
  err = ECHILD; str = "ECHILD";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECHRNG
  err = ECHRNG; str = "ECHRNG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECOMM
  err = ECOMM; str = "ECOMM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECONNABORTED
  err = ECONNABORTED; str = "ECONNABORTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECONNREFUSED
  err = ECONNREFUSED; str = "ECONNREFUSED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ECONNRESET
  err = ECONNRESET; str = "ECONNRESET";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ED
  err = ED; str = "ED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDEADEPT
  err = EDEADEPT; str = "EDEADEPT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDEADLK
  err = EDEADLK; str = "EDEADLK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDEADLOCK
  err = EDEADLOCK; str = "EDEADLOCK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDEADSRCDST
  err = EDEADSRCDST; str = "EDEADSRCDST";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDESTADDRREQ
  err = EDESTADDRREQ; str = "EDESTADDRREQ";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDEVERR
  err = EDEVERR; str = "EDEVERR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDIED
  err = EDIED; str = "EDIED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDOM
  err = EDOM; str = "EDOM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDONTREPLY
  err = EDONTREPLY; str = "EDONTREPLY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDOOFUS
  err = EDOOFUS; str = "EDOOFUS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDOTDOT
  err = EDOTDOT; str = "EDOTDOT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EDQUOT
  err = EDQUOT; str = "EDQUOT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EEXIST
  err = EEXIST; str = "EEXIST";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EFAULT
  err = EFAULT; str = "EFAULT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EFBIG
  err = EFBIG; str = "EFBIG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EFTYPE
  err = EFTYPE; str = "EFTYPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EGENERIC
  err = EGENERIC; str = "EGENERIC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EGRATUITOUS
  err = EGRATUITOUS; str = "EGRATUITOUS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EGREGIOUS
  err = EGREGIOUS; str = "EGREGIOUS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EHOSTDOWN
  err = EHOSTDOWN; str = "EHOSTDOWN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EHOSTUNREACH
  err = EHOSTUNREACH; str = "EHOSTUNREACH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EHWPOISON
  err = EHWPOISON; str = "EHWPOISON";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EIDRM
  err = EIDRM; str = "EIDRM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EIEIO
  err = EIEIO; str = "EIEIO";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EILSEQ
  err = EILSEQ; str = "EILSEQ";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EINPROGRESS
  err = EINPROGRESS; str = "EINPROGRESS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EINTR
  err = EINTR; str = "EINTR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EINVAL
  err = EINVAL; str = "EINVAL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EIO
  err = EIO; str = "EIO";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EIPSEC
  err = EIPSEC; str = "EIPSEC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EISCONN
  err = EISCONN; str = "EISCONN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EISDIR
  err = EISDIR; str = "EISDIR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EISNAM
  err = EISNAM; str = "EISNAM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EKEYEXPIRED
  err = EKEYEXPIRED; str = "EKEYEXPIRED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EKEYREJECTED
  err = EKEYREJECTED; str = "EKEYREJECTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EKEYREVOKED
  err = EKEYREVOKED; str = "EKEYREVOKED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EL2HLT
  err = EL2HLT; str = "EL2HLT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EL2NSYNC
  err = EL2NSYNC; str = "EL2NSYNC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EL3HLT
  err = EL3HLT; str = "EL3HLT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EL3RST
  err = EL3RST; str = "EL3RST";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELAST
  err = ELAST; str = "ELAST";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELBIN
  err = ELBIN; str = "ELBIN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELIBACC
  err = ELIBACC; str = "ELIBACC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELIBBAD
  err = ELIBBAD; str = "ELIBBAD";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELIBEXEC
  err = ELIBEXEC; str = "ELIBEXEC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELIBMAX
  err = ELIBMAX; str = "ELIBMAX";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELIBSCN
  err = ELIBSCN; str = "ELIBSCN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELNRNG
  err = ELNRNG; str = "ELNRNG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELOCKED
  err = ELOCKED; str = "ELOCKED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELOCKUNMAPPED
  err = ELOCKUNMAPPED; str = "ELOCKUNMAPPED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ELOOP
  err = ELOOP; str = "ELOOP";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EMEDIUMTYPE
  err = EMEDIUMTYPE; str = "EMEDIUMTYPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EMFILE
  err = EMFILE; str = "EMFILE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EMLINK
  err = EMLINK; str = "EMLINK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EMSGSIZE
  err = EMSGSIZE; str = "EMSGSIZE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EMULTIHOP
  err = EMULTIHOP; str = "EMULTIHOP";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENAMETOOLONG
  err = ENAMETOOLONG; str = "ENAMETOOLONG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENAVAIL
  err = ENAVAIL; str = "ENAVAIL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENEEDAUTH
  err = ENEEDAUTH; str = "ENEEDAUTH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENETDOWN
  err = ENETDOWN; str = "ENETDOWN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENETRESET
  err = ENETRESET; str = "ENETRESET";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENETUNREACH
  err = ENETUNREACH; str = "ENETUNREACH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENFILE
  err = ENFILE; str = "ENFILE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENMFILE
  err = ENMFILE; str = "ENMFILE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOANO
  err = ENOANO; str = "ENOANO";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOATTR
  err = ENOATTR; str = "ENOATTR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOBUFS
  err = ENOBUFS; str = "ENOBUFS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOCONN
  err = ENOCONN; str = "ENOCONN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOCSI
  err = ENOCSI; str = "ENOCSI";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENODATA
  err = ENODATA; str = "ENODATA";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENODEV
  err = ENODEV; str = "ENODEV";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOENT
  err = ENOENT; str = "ENOENT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOEXEC
  err = ENOEXEC; str = "ENOEXEC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOKEY
  err = ENOKEY; str = "ENOKEY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOLCK
  err = ENOLCK; str = "ENOLCK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOLINK
  err = ENOLINK; str = "ENOLINK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOMEDIUM
  err = ENOMEDIUM; str = "ENOMEDIUM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOMEM
  err = ENOMEM; str = "ENOMEM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOMSG
  err = ENOMSG; str = "ENOMSG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENONET
  err = ENONET; str = "ENONET";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOPKG
  err = ENOPKG; str = "ENOPKG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOPOLICY
  err = ENOPOLICY; str = "ENOPOLICY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOPROTOOPT
  err = ENOPROTOOPT; str = "ENOPROTOOPT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOSHARE
  err = ENOSHARE; str = "ENOSHARE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOSPC
  err = ENOSPC; str = "ENOSPC";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOSR
  err = ENOSR; str = "ENOSR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOSTR
  err = ENOSTR; str = "ENOSTR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOSYS
  err = ENOSYS; str = "ENOSYS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTACTIVE
  err = ENOTACTIVE; str = "ENOTACTIVE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTBLK
  err = ENOTBLK; str = "ENOTBLK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTCAPABLE
  err = ENOTCAPABLE; str = "ENOTCAPABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTCONN
  err = ENOTCONN; str = "ENOTCONN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTDIR
  err = ENOTDIR; str = "ENOTDIR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTEMPTY
  err = ENOTEMPTY; str = "ENOTEMPTY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTNAM
  err = ENOTNAM; str = "ENOTNAM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTREADY
  err = ENOTREADY; str = "ENOTREADY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTRECOVERABLE
  err = ENOTRECOVERABLE; str = "ENOTRECOVERABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTSOCK
  err = ENOTSOCK; str = "ENOTSOCK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTSUP
  err = ENOTSUP; str = "ENOTSUP";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTTY
  err = ENOTTY; str = "ENOTTY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOTUNIQ
  err = ENOTUNIQ; str = "ENOTUNIQ";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENOURG
  err = ENOURG; str = "ENOURG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ENXIO
  err = ENXIO; str = "ENXIO";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EOPNOTSUPP
  err = EOPNOTSUPP; str = "EOPNOTSUPP";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EOVERFLOW
  err = EOVERFLOW; str = "EOVERFLOW";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EOWNERDEAD
  err = EOWNERDEAD; str = "EOWNERDEAD";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPACKSIZE
  err = EPACKSIZE; str = "EPACKSIZE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPERM
  err = EPERM; str = "EPERM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPFNOSUPPORT
  err = EPFNOSUPPORT; str = "EPFNOSUPPORT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPIPE
  err = EPIPE; str = "EPIPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPROCLIM
  err = EPROCLIM; str = "EPROCLIM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPROCUNAVAIL
  err = EPROCUNAVAIL; str = "EPROCUNAVAIL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPROGMISMATCH
  err = EPROGMISMATCH; str = "EPROGMISMATCH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPROGUNAVAIL
  err = EPROGUNAVAIL; str = "EPROGUNAVAIL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPROTO
  err = EPROTO; str = "EPROTO";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPROTONOSUPPORT
  err = EPROTONOSUPPORT; str = "EPROTONOSUPPORT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPROTOTYPE
  err = EPROTOTYPE; str = "EPROTOTYPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EPWROFF
  err = EPWROFF; str = "EPWROFF";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ERANGE
  err = ERANGE; str = "ERANGE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EREMCHG
  err = EREMCHG; str = "EREMCHG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EREMOTE
  err = EREMOTE; str = "EREMOTE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EREMOTEIO
  err = EREMOTEIO; str = "EREMOTEIO";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ERESTART
  err = ERESTART; str = "ERESTART";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ERFKILL
  err = ERFKILL; str = "ERFKILL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EROFS
  err = EROFS; str = "EROFS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ERPCMISMATCH
  err = ERPCMISMATCH; str = "ERPCMISMATCH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESHLIBVERS
  err = ESHLIBVERS; str = "ESHLIBVERS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESHUTDOWN
  err = ESHUTDOWN; str = "ESHUTDOWN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESOCKTNOSUPPORT
  err = ESOCKTNOSUPPORT; str = "ESOCKTNOSUPPORT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESPIPE
  err = ESPIPE; str = "ESPIPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESRCH
  err = ESRCH; str = "ESRCH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESRMNT
  err = ESRMNT; str = "ESRMNT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESTALE
  err = ESTALE; str = "ESTALE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ESTRPIPE
  err = ESTRPIPE; str = "ESTRPIPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ETIME
  err = ETIME; str = "ETIME";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ETIMEDOUT
  err = ETIMEDOUT; str = "ETIMEDOUT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ETOOMANYREFS
  err = ETOOMANYREFS; str = "ETOOMANYREFS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ETRAPDENIED
  err = ETRAPDENIED; str = "ETRAPDENIED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef ETXTBSY
  err = ETXTBSY; str = "ETXTBSY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EUCLEAN
  err = EUCLEAN; str = "EUCLEAN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EUNATCH
  err = EUNATCH; str = "EUNATCH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EURG
  err = EURG; str = "EURG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EUSERS
  err = EUSERS; str = "EUSERS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EWOULDBLOCK
  err = EWOULDBLOCK; str = "EWOULDBLOCK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EXDEV
  err = EXDEV; str = "EXDEV";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef EXFULL
  err = EXFULL; str = "EXFULL";
  printf("%s = %s\n", str, strerror(err));
#endif

  ret = errno_minmax(&min, &max);
  if (ret == 0) {
    for (i = min; i <= max; i++) {
      char *sym = errsym(i);
      char *msg;
      if (sym)
        continue;
      errno = 0;
      msg = strerror(i);
      if (msg && !errno) {
        /*
         * strerror() return value for unknown error:
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
         */
#define START_WITH(prefix) (strncmp(msg, (prefix), sizeof(prefix)-1) == 0)
        if (START_WITH("Unknown ") ||
            START_WITH("Error ") ||
            START_WITH("Undefined "))
          continue;
#undef START_WITH
        printf("%d = %s\n", i, msg);
      }
    }
  }

  return EXIT_SUCCESS;
}
