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

void func(int errcand, void *arg)
{
  char *sym = errsym(errcand);
  char *msg;
  if (sym)
    return;
  errno = 0;
  msg = strerror(errcand);
  if (msg && !errno) {
    /*
     * strerror() return value for unknown errors:
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
     *   "No Error (NNN)"
     */
#define START_WITH(prefix) (strncmp(msg, (prefix), sizeof(prefix)-1) == 0)
    if (START_WITH("Unknown ") ||
        START_WITH("No Error (") ||
        START_WITH("Error ") ||
        START_WITH("Undefined "))
      return;
#undef START_WITH
    printf("%d = %s\n", errcand, msg);
  }
}


int main(int argc, char *argv[])
{
  int err;
  char *str;

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
#ifdef EFPOS
  err = EFPOS; str = "EFPOS";
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
#ifdef ESIGPARM
  err = ESIGPARM; str = "ESIGPARM";
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
#ifdef B_ALREADY_RUNNING
  err = B_ALREADY_RUNNING; str = "B_ALREADY_RUNNING";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_AMBIGUOUS_APP_LAUNCH
  err = B_AMBIGUOUS_APP_LAUNCH; str = "B_AMBIGUOUS_APP_LAUNCH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_ADDRESS
  err = B_BAD_ADDRESS; str = "B_BAD_ADDRESS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_DATA
  err = B_BAD_DATA; str = "B_BAD_DATA";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_HANDLER
  err = B_BAD_HANDLER; str = "B_BAD_HANDLER";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_IMAGE_ID
  err = B_BAD_IMAGE_ID; str = "B_BAD_IMAGE_ID";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_INDEX
  err = B_BAD_INDEX; str = "B_BAD_INDEX";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_MIME_SNIFFER_RULE
  err = B_BAD_MIME_SNIFFER_RULE; str = "B_BAD_MIME_SNIFFER_RULE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_PORT_ID
  err = B_BAD_PORT_ID; str = "B_BAD_PORT_ID";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_REPLY
  err = B_BAD_REPLY; str = "B_BAD_REPLY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_SCRIPT_SYNTAX
  err = B_BAD_SCRIPT_SYNTAX; str = "B_BAD_SCRIPT_SYNTAX";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_SEM_ID
  err = B_BAD_SEM_ID; str = "B_BAD_SEM_ID";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_SUBSCRIBER
  err = B_BAD_SUBSCRIBER; str = "B_BAD_SUBSCRIBER";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_TEAM_ID
  err = B_BAD_TEAM_ID; str = "B_BAD_TEAM_ID";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_THREAD_ID
  err = B_BAD_THREAD_ID; str = "B_BAD_THREAD_ID";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_THREAD_STATE
  err = B_BAD_THREAD_STATE; str = "B_BAD_THREAD_STATE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_TYPE
  err = B_BAD_TYPE; str = "B_BAD_TYPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BAD_VALUE
  err = B_BAD_VALUE; str = "B_BAD_VALUE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BUFFER_NOT_AVAILABLE
  err = B_BUFFER_NOT_AVAILABLE; str = "B_BUFFER_NOT_AVAILABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BUSTED_PIPE
  err = B_BUSTED_PIPE; str = "B_BUSTED_PIPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_BUSY
  err = B_BUSY; str = "B_BUSY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_CANCELED
  err = B_CANCELED; str = "B_CANCELED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_CROSS_DEVICE_LINK
  err = B_CROSS_DEVICE_LINK; str = "B_CROSS_DEVICE_LINK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEBUGGER_ALREADY_INSTALLED
  err = B_DEBUGGER_ALREADY_INSTALLED; str = "B_DEBUGGER_ALREADY_INSTALLED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEVICE_FULL
  err = B_DEVICE_FULL; str = "B_DEVICE_FULL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_BAD_DRIVE_NUM
  err = B_DEV_BAD_DRIVE_NUM; str = "B_DEV_BAD_DRIVE_NUM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_BAD_PID
  err = B_DEV_BAD_PID; str = "B_DEV_BAD_PID";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_CONFIGURATION_ERROR
  err = B_DEV_CONFIGURATION_ERROR; str = "B_DEV_CONFIGURATION_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_CRC_ERROR
  err = B_DEV_CRC_ERROR; str = "B_DEV_CRC_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_DATA_OVERRUN
  err = B_DEV_DATA_OVERRUN; str = "B_DEV_DATA_OVERRUN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_DATA_UNDERRUN
  err = B_DEV_DATA_UNDERRUN; str = "B_DEV_DATA_UNDERRUN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_DISABLED_BY_USER
  err = B_DEV_DISABLED_BY_USER; str = "B_DEV_DISABLED_BY_USER";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_DOOR_OPEN
  err = B_DEV_DOOR_OPEN; str = "B_DEV_DOOR_OPEN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_FIFO_OVERRUN
  err = B_DEV_FIFO_OVERRUN; str = "B_DEV_FIFO_OVERRUN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_FIFO_UNDERRUN
  err = B_DEV_FIFO_UNDERRUN; str = "B_DEV_FIFO_UNDERRUN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_FORMAT_ERROR
  err = B_DEV_FORMAT_ERROR; str = "B_DEV_FORMAT_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_ID_ERROR
  err = B_DEV_ID_ERROR; str = "B_DEV_ID_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_INVALID_IOCTL
  err = B_DEV_INVALID_IOCTL; str = "B_DEV_INVALID_IOCTL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_INVALID_PIPE
  err = B_DEV_INVALID_PIPE; str = "B_DEV_INVALID_PIPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_MEDIA_CHANGED
  err = B_DEV_MEDIA_CHANGED; str = "B_DEV_MEDIA_CHANGED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_MEDIA_CHANGE_REQUESTED
  err = B_DEV_MEDIA_CHANGE_REQUESTED; str = "B_DEV_MEDIA_CHANGE_REQUESTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_MULTIPLE_ERRORS
  err = B_DEV_MULTIPLE_ERRORS; str = "B_DEV_MULTIPLE_ERRORS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_NOT_READY
  err = B_DEV_NOT_READY; str = "B_DEV_NOT_READY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_NO_MEDIA
  err = B_DEV_NO_MEDIA; str = "B_DEV_NO_MEDIA";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_NO_MEMORY
  err = B_DEV_NO_MEMORY; str = "B_DEV_NO_MEMORY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_PENDING
  err = B_DEV_PENDING; str = "B_DEV_PENDING";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_READ_ERROR
  err = B_DEV_READ_ERROR; str = "B_DEV_READ_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_RECALIBRATE_ERROR
  err = B_DEV_RECALIBRATE_ERROR; str = "B_DEV_RECALIBRATE_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_RESOURCE_CONFLICT
  err = B_DEV_RESOURCE_CONFLICT; str = "B_DEV_RESOURCE_CONFLICT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_SEEK_ERROR
  err = B_DEV_SEEK_ERROR; str = "B_DEV_SEEK_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_STALLED
  err = B_DEV_STALLED; str = "B_DEV_STALLED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_TIMEOUT
  err = B_DEV_TIMEOUT; str = "B_DEV_TIMEOUT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_TOO_LATE
  err = B_DEV_TOO_LATE; str = "B_DEV_TOO_LATE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_UNEXPECTED_PID
  err = B_DEV_UNEXPECTED_PID; str = "B_DEV_UNEXPECTED_PID";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_UNREADABLE
  err = B_DEV_UNREADABLE; str = "B_DEV_UNREADABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DEV_WRITE_ERROR
  err = B_DEV_WRITE_ERROR; str = "B_DEV_WRITE_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DIRECTORY_NOT_EMPTY
  err = B_DIRECTORY_NOT_EMPTY; str = "B_DIRECTORY_NOT_EMPTY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_DUPLICATE_REPLY
  err = B_DUPLICATE_REPLY; str = "B_DUPLICATE_REPLY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_ENTRY_NOT_FOUND
  err = B_ENTRY_NOT_FOUND; str = "B_ENTRY_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_ERROR
  err = B_ERROR; str = "B_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_FILE_ERROR
  err = B_FILE_ERROR; str = "B_FILE_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_FILE_EXISTS
  err = B_FILE_EXISTS; str = "B_FILE_EXISTS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_FILE_NOT_FOUND
  err = B_FILE_NOT_FOUND; str = "B_FILE_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_ILLEGAL_DATA
  err = B_ILLEGAL_DATA; str = "B_ILLEGAL_DATA";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_INTERRUPTED
  err = B_INTERRUPTED; str = "B_INTERRUPTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_IO_ERROR
  err = B_IO_ERROR; str = "B_IO_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_IS_A_DIRECTORY
  err = B_IS_A_DIRECTORY; str = "B_IS_A_DIRECTORY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAST_BUFFER_ERROR
  err = B_LAST_BUFFER_ERROR; str = "B_LAST_BUFFER_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAUNCH_FAILED
  err = B_LAUNCH_FAILED; str = "B_LAUNCH_FAILED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAUNCH_FAILED_APP_IN_TRASH
  err = B_LAUNCH_FAILED_APP_IN_TRASH; str = "B_LAUNCH_FAILED_APP_IN_TRASH";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAUNCH_FAILED_APP_NOT_FOUND
  err = B_LAUNCH_FAILED_APP_NOT_FOUND; str = "B_LAUNCH_FAILED_APP_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAUNCH_FAILED_EXECUTABLE
  err = B_LAUNCH_FAILED_EXECUTABLE; str = "B_LAUNCH_FAILED_EXECUTABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAUNCH_FAILED_FILES_APP_NOT_FOUND
  err = B_LAUNCH_FAILED_FILES_APP_NOT_FOUND; str = "B_LAUNCH_FAILED_FILES_APP_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAUNCH_FAILED_NO_PREFERRED_APP
  err = B_LAUNCH_FAILED_NO_PREFERRED_APP; str = "B_LAUNCH_FAILED_NO_PREFERRED_APP";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LAUNCH_FAILED_NO_RESOLVE_LINK
  err = B_LAUNCH_FAILED_NO_RESOLVE_LINK; str = "B_LAUNCH_FAILED_NO_RESOLVE_LINK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_LINK_LIMIT
  err = B_LINK_LIMIT; str = "B_LINK_LIMIT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_ACCESS_ERROR
  err = B_MAIL_ACCESS_ERROR; str = "B_MAIL_ACCESS_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_INVALID_MAIL
  err = B_MAIL_INVALID_MAIL; str = "B_MAIL_INVALID_MAIL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_NO_DAEMON
  err = B_MAIL_NO_DAEMON; str = "B_MAIL_NO_DAEMON";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_NO_RECIPIENT
  err = B_MAIL_NO_RECIPIENT; str = "B_MAIL_NO_RECIPIENT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_UNKNOWN_FIELD
  err = B_MAIL_UNKNOWN_FIELD; str = "B_MAIL_UNKNOWN_FIELD";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_UNKNOWN_HOST
  err = B_MAIL_UNKNOWN_HOST; str = "B_MAIL_UNKNOWN_HOST";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_UNKNOWN_USER
  err = B_MAIL_UNKNOWN_USER; str = "B_MAIL_UNKNOWN_USER";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MAIL_WRONG_PASSWORD
  err = B_MAIL_WRONG_PASSWORD; str = "B_MAIL_WRONG_PASSWORD";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_ADDON_DISABLED
  err = B_MEDIA_ADDON_DISABLED; str = "B_MEDIA_ADDON_DISABLED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_ADDON_FAILED
  err = B_MEDIA_ADDON_FAILED; str = "B_MEDIA_ADDON_FAILED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_ADDON_RESTRICTED
  err = B_MEDIA_ADDON_RESTRICTED; str = "B_MEDIA_ADDON_RESTRICTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_ALREADY_CONNECTED
  err = B_MEDIA_ALREADY_CONNECTED; str = "B_MEDIA_ALREADY_CONNECTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_APP_ALREADY_REGISTERED
  err = B_MEDIA_APP_ALREADY_REGISTERED; str = "B_MEDIA_APP_ALREADY_REGISTERED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_APP_NOT_REGISTERED
  err = B_MEDIA_APP_NOT_REGISTERED; str = "B_MEDIA_APP_NOT_REGISTERED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BAD_BUFFER
  err = B_MEDIA_BAD_BUFFER; str = "B_MEDIA_BAD_BUFFER";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BAD_CLIP_FORMAT
  err = B_MEDIA_BAD_CLIP_FORMAT; str = "B_MEDIA_BAD_CLIP_FORMAT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BAD_DESTINATION
  err = B_MEDIA_BAD_DESTINATION; str = "B_MEDIA_BAD_DESTINATION";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BAD_FORMAT
  err = B_MEDIA_BAD_FORMAT; str = "B_MEDIA_BAD_FORMAT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BAD_NODE
  err = B_MEDIA_BAD_NODE; str = "B_MEDIA_BAD_NODE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BAD_SOURCE
  err = B_MEDIA_BAD_SOURCE; str = "B_MEDIA_BAD_SOURCE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BUFFERS_NOT_RECLAIMED
  err = B_MEDIA_BUFFERS_NOT_RECLAIMED; str = "B_MEDIA_BUFFERS_NOT_RECLAIMED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_BUFFER_ALREADY_EXISTS
  err = B_MEDIA_BUFFER_ALREADY_EXISTS; str = "B_MEDIA_BUFFER_ALREADY_EXISTS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_CANNOT_CHANGE_RUN_MODE
  err = B_MEDIA_CANNOT_CHANGE_RUN_MODE; str = "B_MEDIA_CANNOT_CHANGE_RUN_MODE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_CANNOT_RECLAIM_BUFFERS
  err = B_MEDIA_CANNOT_RECLAIM_BUFFERS; str = "B_MEDIA_CANNOT_RECLAIM_BUFFERS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_CANNOT_SEEK
  err = B_MEDIA_CANNOT_SEEK; str = "B_MEDIA_CANNOT_SEEK";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_CHANGE_IN_PROGRESS
  err = B_MEDIA_CHANGE_IN_PROGRESS; str = "B_MEDIA_CHANGE_IN_PROGRESS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_DUPLICATE_FORMAT
  err = B_MEDIA_DUPLICATE_FORMAT; str = "B_MEDIA_DUPLICATE_FORMAT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_NODE_ALREADY_EXISTS
  err = B_MEDIA_NODE_ALREADY_EXISTS; str = "B_MEDIA_NODE_ALREADY_EXISTS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_NODE_BUSY
  err = B_MEDIA_NODE_BUSY; str = "B_MEDIA_NODE_BUSY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_NOT_CONNECTED
  err = B_MEDIA_NOT_CONNECTED; str = "B_MEDIA_NOT_CONNECTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_NO_HANDLER
  err = B_MEDIA_NO_HANDLER; str = "B_MEDIA_NO_HANDLER";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_REALTIME_DISABLED
  err = B_MEDIA_REALTIME_DISABLED; str = "B_MEDIA_REALTIME_DISABLED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_REALTIME_UNAVAILABLE
  err = B_MEDIA_REALTIME_UNAVAILABLE; str = "B_MEDIA_REALTIME_UNAVAILABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_STALE_CHANGE_COUNT
  err = B_MEDIA_STALE_CHANGE_COUNT; str = "B_MEDIA_STALE_CHANGE_COUNT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_SYSTEM_FAILURE
  err = B_MEDIA_SYSTEM_FAILURE; str = "B_MEDIA_SYSTEM_FAILURE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_TIME_SOURCE_BUSY
  err = B_MEDIA_TIME_SOURCE_BUSY; str = "B_MEDIA_TIME_SOURCE_BUSY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_TIME_SOURCE_STOPPED
  err = B_MEDIA_TIME_SOURCE_STOPPED; str = "B_MEDIA_TIME_SOURCE_STOPPED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_TOO_MANY_BUFFERS
  err = B_MEDIA_TOO_MANY_BUFFERS; str = "B_MEDIA_TOO_MANY_BUFFERS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MEDIA_TOO_MANY_NODES
  err = B_MEDIA_TOO_MANY_NODES; str = "B_MEDIA_TOO_MANY_NODES";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MESSAGE_TO_SELF
  err = B_MESSAGE_TO_SELF; str = "B_MESSAGE_TO_SELF";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MISMATCHED_VALUES
  err = B_MISMATCHED_VALUES; str = "B_MISMATCHED_VALUES";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MISSING_LIBRARY
  err = B_MISSING_LIBRARY; str = "B_MISSING_LIBRARY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_MISSING_SYMBOL
  err = B_MISSING_SYMBOL; str = "B_MISSING_SYMBOL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NAME_IN_USE
  err = B_NAME_IN_USE; str = "B_NAME_IN_USE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NAME_NOT_FOUND
  err = B_NAME_NOT_FOUND; str = "B_NAME_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NAME_TOO_LONG
  err = B_NAME_TOO_LONG; str = "B_NAME_TOO_LONG";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NOT_ALLOWED
  err = B_NOT_ALLOWED; str = "B_NOT_ALLOWED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NOT_AN_EXECUTABLE
  err = B_NOT_AN_EXECUTABLE; str = "B_NOT_AN_EXECUTABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NOT_A_DIRECTORY
  err = B_NOT_A_DIRECTORY; str = "B_NOT_A_DIRECTORY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NOT_A_MESSAGE
  err = B_NOT_A_MESSAGE; str = "B_NOT_A_MESSAGE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_ERROR
  err = B_NO_ERROR; str = "B_NO_ERROR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_INIT
  err = B_NO_INIT; str = "B_NO_INIT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_MEMORY
  err = B_NO_MEMORY; str = "B_NO_MEMORY";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_MORE_FDS
  err = B_NO_MORE_FDS; str = "B_NO_MORE_FDS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_MORE_PORTS
  err = B_NO_MORE_PORTS; str = "B_NO_MORE_PORTS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_MORE_SEMS
  err = B_NO_MORE_SEMS; str = "B_NO_MORE_SEMS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_MORE_TEAMS
  err = B_NO_MORE_TEAMS; str = "B_NO_MORE_TEAMS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_MORE_THREADS
  err = B_NO_MORE_THREADS; str = "B_NO_MORE_THREADS";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_PRINT_SERVER
  err = B_NO_PRINT_SERVER; str = "B_NO_PRINT_SERVER";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_NO_TRANSLATOR
  err = B_NO_TRANSLATOR; str = "B_NO_TRANSLATOR";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_PARTITION_TOO_SMALL
  err = B_PARTITION_TOO_SMALL; str = "B_PARTITION_TOO_SMALL";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_PERMISSION_DENIED
  err = B_PERMISSION_DENIED; str = "B_PERMISSION_DENIED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_POSIX_ENOMEM
  err = B_POSIX_ENOMEM; str = "B_POSIX_ENOMEM";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_READ_ONLY_DEVICE
  err = B_READ_ONLY_DEVICE; str = "B_READ_ONLY_DEVICE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_RESOURCE_NOT_FOUND
  err = B_RESOURCE_NOT_FOUND; str = "B_RESOURCE_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_RESOURCE_UNAVAILABLE
  err = B_RESOURCE_UNAVAILABLE; str = "B_RESOURCE_UNAVAILABLE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_SERVER_NOT_FOUND
  err = B_SERVER_NOT_FOUND; str = "B_SERVER_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_SHUTDOWN_CANCELLED
  err = B_SHUTDOWN_CANCELLED; str = "B_SHUTDOWN_CANCELLED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_SHUTTING_DOWN
  err = B_SHUTTING_DOWN; str = "B_SHUTTING_DOWN";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_STREAM_NOT_FOUND
  err = B_STREAM_NOT_FOUND; str = "B_STREAM_NOT_FOUND";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_SUBSCRIBER_NOT_ENTERED
  err = B_SUBSCRIBER_NOT_ENTERED; str = "B_SUBSCRIBER_NOT_ENTERED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_TIMED_OUT
  err = B_TIMED_OUT; str = "B_TIMED_OUT";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_UNKNOWN_MIME_TYPE
  err = B_UNKNOWN_MIME_TYPE; str = "B_UNKNOWN_MIME_TYPE";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_UNSUPPORTED
  err = B_UNSUPPORTED; str = "B_UNSUPPORTED";
  printf("%s = %s\n", str, strerror(err));
#endif
#ifdef B_WOULD_BLOCK
  err = B_WOULD_BLOCK; str = "B_WOULD_BLOCK";
  printf("%s = %s\n", str, strerror(err));
#endif

  {
    char *msg;
    msg = strerror(0);
    if (msg)
      printf("0 = %s\n", msg);
  }

  errno_candidate_each(func, NULL);

  return EXIT_SUCCESS;
}
