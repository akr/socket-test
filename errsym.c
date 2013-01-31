/* errsym.c is generated from errsym.erb. */

#include "sockettest.h"

char *errsym(int err)
{
  if (err == EAGAIN) return "EAGAIN"; /* may be equal to EWOULDBLOCK */
  if (err == ENOTSUP) return "ENOTSUP"; /* may be equal to EOPNOTSUPP */

  switch (err) {

#ifdef E2BIG
  case E2BIG: return "E2BIG";
#endif
#ifdef EACCES
  case EACCES: return "EACCES";
#endif
#ifdef EADDRINUSE
  case EADDRINUSE: return "EADDRINUSE";
#endif
#ifdef EADDRNOTAVAIL
  case EADDRNOTAVAIL: return "EADDRNOTAVAIL";
#endif
#ifdef EAFNOSUPPORT
  case EAFNOSUPPORT: return "EAFNOSUPPORT";
#endif
#ifdef EALREADY
  case EALREADY: return "EALREADY";
#endif
#ifdef EBADF
  case EBADF: return "EBADF";
#endif
#ifdef EBADMSG
  case EBADMSG: return "EBADMSG";
#endif
#ifdef EBUSY
  case EBUSY: return "EBUSY";
#endif
#ifdef ECANCELED
  case ECANCELED: return "ECANCELED";
#endif
#ifdef ECHILD
  case ECHILD: return "ECHILD";
#endif
#ifdef ECONNABORTED
  case ECONNABORTED: return "ECONNABORTED";
#endif
#ifdef ECONNREFUSED
  case ECONNREFUSED: return "ECONNREFUSED";
#endif
#ifdef ECONNRESET
  case ECONNRESET: return "ECONNRESET";
#endif
#ifdef EDEADLK
  case EDEADLK: return "EDEADLK";
#endif
#ifdef EDESTADDRREQ
  case EDESTADDRREQ: return "EDESTADDRREQ";
#endif
#ifdef EDOM
  case EDOM: return "EDOM";
#endif
#ifdef EDQUOT
  case EDQUOT: return "EDQUOT";
#endif
#ifdef EEXIST
  case EEXIST: return "EEXIST";
#endif
#ifdef EFAULT
  case EFAULT: return "EFAULT";
#endif
#ifdef EFBIG
  case EFBIG: return "EFBIG";
#endif
#ifdef EHOSTUNREACH
  case EHOSTUNREACH: return "EHOSTUNREACH";
#endif
#ifdef EIDRM
  case EIDRM: return "EIDRM";
#endif
#ifdef EILSEQ
  case EILSEQ: return "EILSEQ";
#endif
#ifdef EINPROGRESS
  case EINPROGRESS: return "EINPROGRESS";
#endif
#ifdef EINTR
  case EINTR: return "EINTR";
#endif
#ifdef EINVAL
  case EINVAL: return "EINVAL";
#endif
#ifdef EIO
  case EIO: return "EIO";
#endif
#ifdef EISCONN
  case EISCONN: return "EISCONN";
#endif
#ifdef EISDIR
  case EISDIR: return "EISDIR";
#endif
#ifdef ELOOP
  case ELOOP: return "ELOOP";
#endif
#ifdef EMFILE
  case EMFILE: return "EMFILE";
#endif
#ifdef EMLINK
  case EMLINK: return "EMLINK";
#endif
#ifdef EMSGSIZE
  case EMSGSIZE: return "EMSGSIZE";
#endif
#ifdef EMULTIHOP
  case EMULTIHOP: return "EMULTIHOP";
#endif
#ifdef ENAMETOOLONG
  case ENAMETOOLONG: return "ENAMETOOLONG";
#endif
#ifdef ENETDOWN
  case ENETDOWN: return "ENETDOWN";
#endif
#ifdef ENETRESET
  case ENETRESET: return "ENETRESET";
#endif
#ifdef ENETUNREACH
  case ENETUNREACH: return "ENETUNREACH";
#endif
#ifdef ENFILE
  case ENFILE: return "ENFILE";
#endif
#ifdef ENOBUFS
  case ENOBUFS: return "ENOBUFS";
#endif
#ifdef ENODATA
  case ENODATA: return "ENODATA";
#endif
#ifdef ENODEV
  case ENODEV: return "ENODEV";
#endif
#ifdef ENOENT
  case ENOENT: return "ENOENT";
#endif
#ifdef ENOEXEC
  case ENOEXEC: return "ENOEXEC";
#endif
#ifdef ENOLCK
  case ENOLCK: return "ENOLCK";
#endif
#ifdef ENOLINK
  case ENOLINK: return "ENOLINK";
#endif
#ifdef ENOMEM
  case ENOMEM: return "ENOMEM";
#endif
#ifdef ENOMSG
  case ENOMSG: return "ENOMSG";
#endif
#ifdef ENOPROTOOPT
  case ENOPROTOOPT: return "ENOPROTOOPT";
#endif
#ifdef ENOSPC
  case ENOSPC: return "ENOSPC";
#endif
#ifdef ENOSR
  case ENOSR: return "ENOSR";
#endif
#ifdef ENOSTR
  case ENOSTR: return "ENOSTR";
#endif
#ifdef ENOSYS
  case ENOSYS: return "ENOSYS";
#endif
#ifdef ENOTCONN
  case ENOTCONN: return "ENOTCONN";
#endif
#ifdef ENOTDIR
  case ENOTDIR: return "ENOTDIR";
#endif
#ifdef ENOTEMPTY
  case ENOTEMPTY: return "ENOTEMPTY";
#endif
#ifdef ENOTRECOVERABLE
  case ENOTRECOVERABLE: return "ENOTRECOVERABLE";
#endif
#ifdef ENOTSOCK
  case ENOTSOCK: return "ENOTSOCK";
#endif
#ifdef ENOTTY
  case ENOTTY: return "ENOTTY";
#endif
#ifdef ENXIO
  case ENXIO: return "ENXIO";
#endif
#ifdef EOPNOTSUPP
  case EOPNOTSUPP: return "EOPNOTSUPP";
#endif
#ifdef EOVERFLOW
  case EOVERFLOW: return "EOVERFLOW";
#endif
#ifdef EOWNERDEAD
  case EOWNERDEAD: return "EOWNERDEAD";
#endif
#ifdef EPERM
  case EPERM: return "EPERM";
#endif
#ifdef EPIPE
  case EPIPE: return "EPIPE";
#endif
#ifdef EPROTO
  case EPROTO: return "EPROTO";
#endif
#ifdef EPROTONOSUPPORT
  case EPROTONOSUPPORT: return "EPROTONOSUPPORT";
#endif
#ifdef EPROTOTYPE
  case EPROTOTYPE: return "EPROTOTYPE";
#endif
#ifdef ERANGE
  case ERANGE: return "ERANGE";
#endif
#ifdef EROFS
  case EROFS: return "EROFS";
#endif
#ifdef ESPIPE
  case ESPIPE: return "ESPIPE";
#endif
#ifdef ESRCH
  case ESRCH: return "ESRCH";
#endif
#ifdef ESTALE
  case ESTALE: return "ESTALE";
#endif
#ifdef ETIME
  case ETIME: return "ETIME";
#endif
#ifdef ETIMEDOUT
  case ETIMEDOUT: return "ETIMEDOUT";
#endif
#ifdef ETXTBSY
  case ETXTBSY: return "ETXTBSY";
#endif
#ifdef EWOULDBLOCK
  case EWOULDBLOCK: return "EWOULDBLOCK";
#endif
#ifdef EXDEV
  case EXDEV: return "EXDEV";
#endif

  }
  return NULL;
}

