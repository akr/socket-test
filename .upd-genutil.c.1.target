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

string_integer_pair_t internal_errno_to_name[] = {
#ifdef EAGAIN
  { "EAGAIN", EAGAIN },
#endif
#ifdef ENOTSUP
  { "ENOTSUP", ENOTSUP },
#endif
#ifdef E2BIG
  { "E2BIG", E2BIG },
#endif
#ifdef EACCES
  { "EACCES", EACCES },
#endif
#ifdef EADDRINUSE
  { "EADDRINUSE", EADDRINUSE },
#endif
#ifdef EADDRNOTAVAIL
  { "EADDRNOTAVAIL", EADDRNOTAVAIL },
#endif
#ifdef EAFNOSUPPORT
  { "EAFNOSUPPORT", EAFNOSUPPORT },
#endif
#ifdef EALREADY
  { "EALREADY", EALREADY },
#endif
#ifdef EBADF
  { "EBADF", EBADF },
#endif
#ifdef EBADMSG
  { "EBADMSG", EBADMSG },
#endif
#ifdef EBUSY
  { "EBUSY", EBUSY },
#endif
#ifdef ECANCELED
  { "ECANCELED", ECANCELED },
#endif
#ifdef ECHILD
  { "ECHILD", ECHILD },
#endif
#ifdef ECONNABORTED
  { "ECONNABORTED", ECONNABORTED },
#endif
#ifdef ECONNREFUSED
  { "ECONNREFUSED", ECONNREFUSED },
#endif
#ifdef ECONNRESET
  { "ECONNRESET", ECONNRESET },
#endif
#ifdef EDEADLK
  { "EDEADLK", EDEADLK },
#endif
#ifdef EDESTADDRREQ
  { "EDESTADDRREQ", EDESTADDRREQ },
#endif
#ifdef EDOM
  { "EDOM", EDOM },
#endif
#ifdef EDQUOT
  { "EDQUOT", EDQUOT },
#endif
#ifdef EEXIST
  { "EEXIST", EEXIST },
#endif
#ifdef EFAULT
  { "EFAULT", EFAULT },
#endif
#ifdef EFBIG
  { "EFBIG", EFBIG },
#endif
#ifdef EHOSTUNREACH
  { "EHOSTUNREACH", EHOSTUNREACH },
#endif
#ifdef EIDRM
  { "EIDRM", EIDRM },
#endif
#ifdef EILSEQ
  { "EILSEQ", EILSEQ },
#endif
#ifdef EINPROGRESS
  { "EINPROGRESS", EINPROGRESS },
#endif
#ifdef EINTR
  { "EINTR", EINTR },
#endif
#ifdef EINVAL
  { "EINVAL", EINVAL },
#endif
#ifdef EIO
  { "EIO", EIO },
#endif
#ifdef EISCONN
  { "EISCONN", EISCONN },
#endif
#ifdef EISDIR
  { "EISDIR", EISDIR },
#endif
#ifdef ELOOP
  { "ELOOP", ELOOP },
#endif
#ifdef EMFILE
  { "EMFILE", EMFILE },
#endif
#ifdef EMLINK
  { "EMLINK", EMLINK },
#endif
#ifdef EMSGSIZE
  { "EMSGSIZE", EMSGSIZE },
#endif
#ifdef EMULTIHOP
  { "EMULTIHOP", EMULTIHOP },
#endif
#ifdef ENAMETOOLONG
  { "ENAMETOOLONG", ENAMETOOLONG },
#endif
#ifdef ENETDOWN
  { "ENETDOWN", ENETDOWN },
#endif
#ifdef ENETRESET
  { "ENETRESET", ENETRESET },
#endif
#ifdef ENETUNREACH
  { "ENETUNREACH", ENETUNREACH },
#endif
#ifdef ENFILE
  { "ENFILE", ENFILE },
#endif
#ifdef ENOBUFS
  { "ENOBUFS", ENOBUFS },
#endif
#ifdef ENODATA
  { "ENODATA", ENODATA },
#endif
#ifdef ENODEV
  { "ENODEV", ENODEV },
#endif
#ifdef ENOENT
  { "ENOENT", ENOENT },
#endif
#ifdef ENOEXEC
  { "ENOEXEC", ENOEXEC },
#endif
#ifdef ENOLCK
  { "ENOLCK", ENOLCK },
#endif
#ifdef ENOLINK
  { "ENOLINK", ENOLINK },
#endif
#ifdef ENOMEM
  { "ENOMEM", ENOMEM },
#endif
#ifdef ENOMSG
  { "ENOMSG", ENOMSG },
#endif
#ifdef ENOPROTOOPT
  { "ENOPROTOOPT", ENOPROTOOPT },
#endif
#ifdef ENOSPC
  { "ENOSPC", ENOSPC },
#endif
#ifdef ENOSR
  { "ENOSR", ENOSR },
#endif
#ifdef ENOSTR
  { "ENOSTR", ENOSTR },
#endif
#ifdef ENOSYS
  { "ENOSYS", ENOSYS },
#endif
#ifdef ENOTCONN
  { "ENOTCONN", ENOTCONN },
#endif
#ifdef ENOTDIR
  { "ENOTDIR", ENOTDIR },
#endif
#ifdef ENOTEMPTY
  { "ENOTEMPTY", ENOTEMPTY },
#endif
#ifdef ENOTRECOVERABLE
  { "ENOTRECOVERABLE", ENOTRECOVERABLE },
#endif
#ifdef ENOTSOCK
  { "ENOTSOCK", ENOTSOCK },
#endif
#ifdef ENOTTY
  { "ENOTTY", ENOTTY },
#endif
#ifdef ENXIO
  { "ENXIO", ENXIO },
#endif
#ifdef EOPNOTSUPP
  { "EOPNOTSUPP", EOPNOTSUPP },
#endif
#ifdef EOVERFLOW
  { "EOVERFLOW", EOVERFLOW },
#endif
#ifdef EOWNERDEAD
  { "EOWNERDEAD", EOWNERDEAD },
#endif
#ifdef EPERM
  { "EPERM", EPERM },
#endif
#ifdef EPIPE
  { "EPIPE", EPIPE },
#endif
#ifdef EPROTO
  { "EPROTO", EPROTO },
#endif
#ifdef EPROTONOSUPPORT
  { "EPROTONOSUPPORT", EPROTONOSUPPORT },
#endif
#ifdef EPROTOTYPE
  { "EPROTOTYPE", EPROTOTYPE },
#endif
#ifdef ERANGE
  { "ERANGE", ERANGE },
#endif
#ifdef EROFS
  { "EROFS", EROFS },
#endif
#ifdef ESPIPE
  { "ESPIPE", ESPIPE },
#endif
#ifdef ESRCH
  { "ESRCH", ESRCH },
#endif
#ifdef ESTALE
  { "ESTALE", ESTALE },
#endif
#ifdef ETIME
  { "ETIME", ETIME },
#endif
#ifdef ETIMEDOUT
  { "ETIMEDOUT", ETIMEDOUT },
#endif
#ifdef ETXTBSY
  { "ETXTBSY", ETXTBSY },
#endif
#ifdef EWOULDBLOCK
  { "EWOULDBLOCK", EWOULDBLOCK },
#endif
#ifdef EXDEV
  { "EXDEV", EXDEV },
#endif
#ifdef ENOTBLK
  { "ENOTBLK", ENOTBLK },
#endif
#ifdef ECHRNG
  { "ECHRNG", ECHRNG },
#endif
#ifdef EL2NSYNC
  { "EL2NSYNC", EL2NSYNC },
#endif
#ifdef EL3HLT
  { "EL3HLT", EL3HLT },
#endif
#ifdef EL3RST
  { "EL3RST", EL3RST },
#endif
#ifdef ELNRNG
  { "ELNRNG", ELNRNG },
#endif
#ifdef EUNATCH
  { "EUNATCH", EUNATCH },
#endif
#ifdef ENOCSI
  { "ENOCSI", ENOCSI },
#endif
#ifdef EL2HLT
  { "EL2HLT", EL2HLT },
#endif
#ifdef EBADE
  { "EBADE", EBADE },
#endif
#ifdef EBADR
  { "EBADR", EBADR },
#endif
#ifdef EXFULL
  { "EXFULL", EXFULL },
#endif
#ifdef ENOANO
  { "ENOANO", ENOANO },
#endif
#ifdef EBADRQC
  { "EBADRQC", EBADRQC },
#endif
#ifdef EBADSLT
  { "EBADSLT", EBADSLT },
#endif
#ifdef EDEADLOCK
  { "EDEADLOCK", EDEADLOCK },
#endif
#ifdef EBFONT
  { "EBFONT", EBFONT },
#endif
#ifdef ENONET
  { "ENONET", ENONET },
#endif
#ifdef ENOPKG
  { "ENOPKG", ENOPKG },
#endif
#ifdef EREMOTE
  { "EREMOTE", EREMOTE },
#endif
#ifdef EADV
  { "EADV", EADV },
#endif
#ifdef ESRMNT
  { "ESRMNT", ESRMNT },
#endif
#ifdef ECOMM
  { "ECOMM", ECOMM },
#endif
#ifdef EDOTDOT
  { "EDOTDOT", EDOTDOT },
#endif
#ifdef ENOTUNIQ
  { "ENOTUNIQ", ENOTUNIQ },
#endif
#ifdef EBADFD
  { "EBADFD", EBADFD },
#endif
#ifdef EREMCHG
  { "EREMCHG", EREMCHG },
#endif
#ifdef ELIBACC
  { "ELIBACC", ELIBACC },
#endif
#ifdef ELIBBAD
  { "ELIBBAD", ELIBBAD },
#endif
#ifdef ELIBSCN
  { "ELIBSCN", ELIBSCN },
#endif
#ifdef ELIBMAX
  { "ELIBMAX", ELIBMAX },
#endif
#ifdef ELIBEXEC
  { "ELIBEXEC", ELIBEXEC },
#endif
#ifdef ERESTART
  { "ERESTART", ERESTART },
#endif
#ifdef ESTRPIPE
  { "ESTRPIPE", ESTRPIPE },
#endif
#ifdef EUSERS
  { "EUSERS", EUSERS },
#endif
#ifdef ESOCKTNOSUPPORT
  { "ESOCKTNOSUPPORT", ESOCKTNOSUPPORT },
#endif
#ifdef EPFNOSUPPORT
  { "EPFNOSUPPORT", EPFNOSUPPORT },
#endif
#ifdef ESHUTDOWN
  { "ESHUTDOWN", ESHUTDOWN },
#endif
#ifdef ETOOMANYREFS
  { "ETOOMANYREFS", ETOOMANYREFS },
#endif
#ifdef EHOSTDOWN
  { "EHOSTDOWN", EHOSTDOWN },
#endif
#ifdef EUCLEAN
  { "EUCLEAN", EUCLEAN },
#endif
#ifdef ENOTNAM
  { "ENOTNAM", ENOTNAM },
#endif
#ifdef ENAVAIL
  { "ENAVAIL", ENAVAIL },
#endif
#ifdef EISNAM
  { "EISNAM", EISNAM },
#endif
#ifdef EREMOTEIO
  { "EREMOTEIO", EREMOTEIO },
#endif
#ifdef ENOMEDIUM
  { "ENOMEDIUM", ENOMEDIUM },
#endif
#ifdef EMEDIUMTYPE
  { "EMEDIUMTYPE", EMEDIUMTYPE },
#endif
#ifdef ENOKEY
  { "ENOKEY", ENOKEY },
#endif
#ifdef EKEYEXPIRED
  { "EKEYEXPIRED", EKEYEXPIRED },
#endif
#ifdef EKEYREVOKED
  { "EKEYREVOKED", EKEYREVOKED },
#endif
#ifdef EKEYREJECTED
  { "EKEYREJECTED", EKEYREJECTED },
#endif
#ifdef ERFKILL
  { "ERFKILL", ERFKILL },
#endif
#ifdef EHWPOISON
  { "EHWPOISON", EHWPOISON },
#endif
#ifdef EAUTH
  { "EAUTH", EAUTH },
#endif
#ifdef EBACKGROUND
  { "EBACKGROUND", EBACKGROUND },
#endif
#ifdef EBADRPC
  { "EBADRPC", EBADRPC },
#endif
#ifdef ED
  { "ED", ED },
#endif
#ifdef EDIED
  { "EDIED", EDIED },
#endif
#ifdef EFTYPE
  { "EFTYPE", EFTYPE },
#endif
#ifdef EGRATUITOUS
  { "EGRATUITOUS", EGRATUITOUS },
#endif
#ifdef EGREGIOUS
  { "EGREGIOUS", EGREGIOUS },
#endif
#ifdef EIEIO
  { "EIEIO", EIEIO },
#endif
#ifdef ELAST
  { "ELAST", ELAST },
#endif
#ifdef ENEEDAUTH
  { "ENEEDAUTH", ENEEDAUTH },
#endif
#ifdef EPROCLIM
  { "EPROCLIM", EPROCLIM },
#endif
#ifdef EPROCUNAVAIL
  { "EPROCUNAVAIL", EPROCUNAVAIL },
#endif
#ifdef EPROGMISMATCH
  { "EPROGMISMATCH", EPROGMISMATCH },
#endif
#ifdef EPROGUNAVAIL
  { "EPROGUNAVAIL", EPROGUNAVAIL },
#endif
#ifdef ERPCMISMATCH
  { "ERPCMISMATCH", ERPCMISMATCH },
#endif
#ifdef ENOATTR
  { "ENOATTR", ENOATTR },
#endif
#ifdef EIPSEC
  { "EIPSEC", EIPSEC },
#endif
#ifdef EDOOFUS
  { "EDOOFUS", EDOOFUS },
#endif
#ifdef ENOTCAPABLE
  { "ENOTCAPABLE", ENOTCAPABLE },
#endif
#ifdef ECAPMODE
  { "ECAPMODE", ECAPMODE },
#endif
#ifdef EPWROFF
  { "EPWROFF", EPWROFF },
#endif
#ifdef EDEVERR
  { "EDEVERR", EDEVERR },
#endif
#ifdef EBADEXEC
  { "EBADEXEC", EBADEXEC },
#endif
#ifdef EBADARCH
  { "EBADARCH", EBADARCH },
#endif
#ifdef ESHLIBVERS
  { "ESHLIBVERS", ESHLIBVERS },
#endif
#ifdef EBADMACHO
  { "EBADMACHO", EBADMACHO },
#endif
#ifdef ENOPOLICY
  { "ENOPOLICY", ENOPOLICY },
#endif
#ifdef EPACKSIZE
  { "EPACKSIZE", EPACKSIZE },
#endif
#ifdef EBADIOCTL
  { "EBADIOCTL", EBADIOCTL },
#endif
#ifdef EBADMODE
  { "EBADMODE", EBADMODE },
#endif
#ifdef EURG
  { "EURG", EURG },
#endif
#ifdef ENOURG
  { "ENOURG", ENOURG },
#endif
#ifdef ENOCONN
  { "ENOCONN", ENOCONN },
#endif
#ifdef EGENERIC
  { "EGENERIC", EGENERIC },
#endif
#ifdef ELOCKED
  { "ELOCKED", ELOCKED },
#endif
#ifdef EBADCALL
  { "EBADCALL", EBADCALL },
#endif
#ifdef EBADSRCDST
  { "EBADSRCDST", EBADSRCDST },
#endif
#ifdef ECALLDENIED
  { "ECALLDENIED", ECALLDENIED },
#endif
#ifdef EDEADSRCDST
  { "EDEADSRCDST", EDEADSRCDST },
#endif
#ifdef ENOTREADY
  { "ENOTREADY", ENOTREADY },
#endif
#ifdef EBADREQUEST
  { "EBADREQUEST", EBADREQUEST },
#endif
#ifdef ETRAPDENIED
  { "ETRAPDENIED", ETRAPDENIED },
#endif
#ifdef EDONTREPLY
  { "EDONTREPLY", EDONTREPLY },
#endif
#ifdef EBADEPT
  { "EBADEPT", EBADEPT },
#endif
#ifdef EDEADEPT
  { "EDEADEPT", EDEADEPT },
#endif
#ifdef EBADCPU
  { "EBADCPU", EBADCPU },
#endif
#ifdef ELBIN
  { "ELBIN", ELBIN },
#endif
#ifdef ENMFILE
  { "ENMFILE", ENMFILE },
#endif
#ifdef ENOSHARE
  { "ENOSHARE", ENOSHARE },
#endif
#ifdef ECASECLASH
  { "ECASECLASH", ECASECLASH },
#endif
#ifdef ELOCKUNMAPPED
  { "ELOCKUNMAPPED", ELOCKUNMAPPED },
#endif
#ifdef ENOTACTIVE
  { "ENOTACTIVE", ENOTACTIVE },
#endif
#ifdef B_NO_ERROR
  { "B_NO_ERROR", B_NO_ERROR },
#endif
#ifdef B_ERROR
  { "B_ERROR", B_ERROR },
#endif
#ifdef B_NO_MEMORY
  { "B_NO_MEMORY", B_NO_MEMORY },
#endif
#ifdef B_POSIX_ENOMEM
  { "B_POSIX_ENOMEM", B_POSIX_ENOMEM },
#endif
#ifdef B_IO_ERROR
  { "B_IO_ERROR", B_IO_ERROR },
#endif
#ifdef B_PERMISSION_DENIED
  { "B_PERMISSION_DENIED", B_PERMISSION_DENIED },
#endif
#ifdef B_BAD_INDEX
  { "B_BAD_INDEX", B_BAD_INDEX },
#endif
#ifdef B_BAD_TYPE
  { "B_BAD_TYPE", B_BAD_TYPE },
#endif
#ifdef B_BAD_VALUE
  { "B_BAD_VALUE", B_BAD_VALUE },
#endif
#ifdef B_MISMATCHED_VALUES
  { "B_MISMATCHED_VALUES", B_MISMATCHED_VALUES },
#endif
#ifdef B_NAME_NOT_FOUND
  { "B_NAME_NOT_FOUND", B_NAME_NOT_FOUND },
#endif
#ifdef B_NAME_IN_USE
  { "B_NAME_IN_USE", B_NAME_IN_USE },
#endif
#ifdef B_TIMED_OUT
  { "B_TIMED_OUT", B_TIMED_OUT },
#endif
#ifdef B_INTERRUPTED
  { "B_INTERRUPTED", B_INTERRUPTED },
#endif
#ifdef B_WOULD_BLOCK
  { "B_WOULD_BLOCK", B_WOULD_BLOCK },
#endif
#ifdef B_CANCELED
  { "B_CANCELED", B_CANCELED },
#endif
#ifdef B_NO_INIT
  { "B_NO_INIT", B_NO_INIT },
#endif
#ifdef B_BUSY
  { "B_BUSY", B_BUSY },
#endif
#ifdef B_NOT_ALLOWED
  { "B_NOT_ALLOWED", B_NOT_ALLOWED },
#endif
#ifdef B_BAD_DATA
  { "B_BAD_DATA", B_BAD_DATA },
#endif
#ifdef B_BAD_SEM_ID
  { "B_BAD_SEM_ID", B_BAD_SEM_ID },
#endif
#ifdef B_NO_MORE_SEMS
  { "B_NO_MORE_SEMS", B_NO_MORE_SEMS },
#endif
#ifdef B_BAD_THREAD_ID
  { "B_BAD_THREAD_ID", B_BAD_THREAD_ID },
#endif
#ifdef B_NO_MORE_THREADS
  { "B_NO_MORE_THREADS", B_NO_MORE_THREADS },
#endif
#ifdef B_BAD_THREAD_STATE
  { "B_BAD_THREAD_STATE", B_BAD_THREAD_STATE },
#endif
#ifdef B_BAD_TEAM_ID
  { "B_BAD_TEAM_ID", B_BAD_TEAM_ID },
#endif
#ifdef B_NO_MORE_TEAMS
  { "B_NO_MORE_TEAMS", B_NO_MORE_TEAMS },
#endif
#ifdef B_BAD_PORT_ID
  { "B_BAD_PORT_ID", B_BAD_PORT_ID },
#endif
#ifdef B_NO_MORE_PORTS
  { "B_NO_MORE_PORTS", B_NO_MORE_PORTS },
#endif
#ifdef B_BAD_IMAGE_ID
  { "B_BAD_IMAGE_ID", B_BAD_IMAGE_ID },
#endif
#ifdef B_BAD_ADDRESS
  { "B_BAD_ADDRESS", B_BAD_ADDRESS },
#endif
#ifdef B_NOT_AN_EXECUTABLE
  { "B_NOT_AN_EXECUTABLE", B_NOT_AN_EXECUTABLE },
#endif
#ifdef B_MISSING_LIBRARY
  { "B_MISSING_LIBRARY", B_MISSING_LIBRARY },
#endif
#ifdef B_MISSING_SYMBOL
  { "B_MISSING_SYMBOL", B_MISSING_SYMBOL },
#endif
#ifdef B_DEBUGGER_ALREADY_INSTALLED
  { "B_DEBUGGER_ALREADY_INSTALLED", B_DEBUGGER_ALREADY_INSTALLED },
#endif
#ifdef B_BAD_REPLY
  { "B_BAD_REPLY", B_BAD_REPLY },
#endif
#ifdef B_DUPLICATE_REPLY
  { "B_DUPLICATE_REPLY", B_DUPLICATE_REPLY },
#endif
#ifdef B_MESSAGE_TO_SELF
  { "B_MESSAGE_TO_SELF", B_MESSAGE_TO_SELF },
#endif
#ifdef B_BAD_HANDLER
  { "B_BAD_HANDLER", B_BAD_HANDLER },
#endif
#ifdef B_ALREADY_RUNNING
  { "B_ALREADY_RUNNING", B_ALREADY_RUNNING },
#endif
#ifdef B_LAUNCH_FAILED
  { "B_LAUNCH_FAILED", B_LAUNCH_FAILED },
#endif
#ifdef B_AMBIGUOUS_APP_LAUNCH
  { "B_AMBIGUOUS_APP_LAUNCH", B_AMBIGUOUS_APP_LAUNCH },
#endif
#ifdef B_UNKNOWN_MIME_TYPE
  { "B_UNKNOWN_MIME_TYPE", B_UNKNOWN_MIME_TYPE },
#endif
#ifdef B_BAD_SCRIPT_SYNTAX
  { "B_BAD_SCRIPT_SYNTAX", B_BAD_SCRIPT_SYNTAX },
#endif
#ifdef B_LAUNCH_FAILED_NO_RESOLVE_LINK
  { "B_LAUNCH_FAILED_NO_RESOLVE_LINK", B_LAUNCH_FAILED_NO_RESOLVE_LINK },
#endif
#ifdef B_LAUNCH_FAILED_EXECUTABLE
  { "B_LAUNCH_FAILED_EXECUTABLE", B_LAUNCH_FAILED_EXECUTABLE },
#endif
#ifdef B_LAUNCH_FAILED_APP_NOT_FOUND
  { "B_LAUNCH_FAILED_APP_NOT_FOUND", B_LAUNCH_FAILED_APP_NOT_FOUND },
#endif
#ifdef B_LAUNCH_FAILED_APP_IN_TRASH
  { "B_LAUNCH_FAILED_APP_IN_TRASH", B_LAUNCH_FAILED_APP_IN_TRASH },
#endif
#ifdef B_LAUNCH_FAILED_NO_PREFERRED_APP
  { "B_LAUNCH_FAILED_NO_PREFERRED_APP", B_LAUNCH_FAILED_NO_PREFERRED_APP },
#endif
#ifdef B_LAUNCH_FAILED_FILES_APP_NOT_FOUND
  { "B_LAUNCH_FAILED_FILES_APP_NOT_FOUND", B_LAUNCH_FAILED_FILES_APP_NOT_FOUND },
#endif
#ifdef B_BAD_MIME_SNIFFER_RULE
  { "B_BAD_MIME_SNIFFER_RULE", B_BAD_MIME_SNIFFER_RULE },
#endif
#ifdef B_NOT_A_MESSAGE
  { "B_NOT_A_MESSAGE", B_NOT_A_MESSAGE },
#endif
#ifdef B_SHUTDOWN_CANCELLED
  { "B_SHUTDOWN_CANCELLED", B_SHUTDOWN_CANCELLED },
#endif
#ifdef B_SHUTTING_DOWN
  { "B_SHUTTING_DOWN", B_SHUTTING_DOWN },
#endif
#ifdef B_FILE_ERROR
  { "B_FILE_ERROR", B_FILE_ERROR },
#endif
#ifdef B_FILE_NOT_FOUND
  { "B_FILE_NOT_FOUND", B_FILE_NOT_FOUND },
#endif
#ifdef B_ENTRY_NOT_FOUND
  { "B_ENTRY_NOT_FOUND", B_ENTRY_NOT_FOUND },
#endif
#ifdef B_FILE_EXISTS
  { "B_FILE_EXISTS", B_FILE_EXISTS },
#endif
#ifdef B_NAME_TOO_LONG
  { "B_NAME_TOO_LONG", B_NAME_TOO_LONG },
#endif
#ifdef B_NOT_A_DIRECTORY
  { "B_NOT_A_DIRECTORY", B_NOT_A_DIRECTORY },
#endif
#ifdef B_DIRECTORY_NOT_EMPTY
  { "B_DIRECTORY_NOT_EMPTY", B_DIRECTORY_NOT_EMPTY },
#endif
#ifdef B_DEVICE_FULL
  { "B_DEVICE_FULL", B_DEVICE_FULL },
#endif
#ifdef B_READ_ONLY_DEVICE
  { "B_READ_ONLY_DEVICE", B_READ_ONLY_DEVICE },
#endif
#ifdef B_IS_A_DIRECTORY
  { "B_IS_A_DIRECTORY", B_IS_A_DIRECTORY },
#endif
#ifdef B_NO_MORE_FDS
  { "B_NO_MORE_FDS", B_NO_MORE_FDS },
#endif
#ifdef B_CROSS_DEVICE_LINK
  { "B_CROSS_DEVICE_LINK", B_CROSS_DEVICE_LINK },
#endif
#ifdef B_LINK_LIMIT
  { "B_LINK_LIMIT", B_LINK_LIMIT },
#endif
#ifdef B_BUSTED_PIPE
  { "B_BUSTED_PIPE", B_BUSTED_PIPE },
#endif
#ifdef B_UNSUPPORTED
  { "B_UNSUPPORTED", B_UNSUPPORTED },
#endif
#ifdef B_PARTITION_TOO_SMALL
  { "B_PARTITION_TOO_SMALL", B_PARTITION_TOO_SMALL },
#endif
#ifdef B_STREAM_NOT_FOUND
  { "B_STREAM_NOT_FOUND", B_STREAM_NOT_FOUND },
#endif
#ifdef B_SERVER_NOT_FOUND
  { "B_SERVER_NOT_FOUND", B_SERVER_NOT_FOUND },
#endif
#ifdef B_RESOURCE_NOT_FOUND
  { "B_RESOURCE_NOT_FOUND", B_RESOURCE_NOT_FOUND },
#endif
#ifdef B_RESOURCE_UNAVAILABLE
  { "B_RESOURCE_UNAVAILABLE", B_RESOURCE_UNAVAILABLE },
#endif
#ifdef B_BAD_SUBSCRIBER
  { "B_BAD_SUBSCRIBER", B_BAD_SUBSCRIBER },
#endif
#ifdef B_SUBSCRIBER_NOT_ENTERED
  { "B_SUBSCRIBER_NOT_ENTERED", B_SUBSCRIBER_NOT_ENTERED },
#endif
#ifdef B_BUFFER_NOT_AVAILABLE
  { "B_BUFFER_NOT_AVAILABLE", B_BUFFER_NOT_AVAILABLE },
#endif
#ifdef B_LAST_BUFFER_ERROR
  { "B_LAST_BUFFER_ERROR", B_LAST_BUFFER_ERROR },
#endif
#ifdef B_MEDIA_SYSTEM_FAILURE
  { "B_MEDIA_SYSTEM_FAILURE", B_MEDIA_SYSTEM_FAILURE },
#endif
#ifdef B_MEDIA_BAD_NODE
  { "B_MEDIA_BAD_NODE", B_MEDIA_BAD_NODE },
#endif
#ifdef B_MEDIA_NODE_BUSY
  { "B_MEDIA_NODE_BUSY", B_MEDIA_NODE_BUSY },
#endif
#ifdef B_MEDIA_BAD_FORMAT
  { "B_MEDIA_BAD_FORMAT", B_MEDIA_BAD_FORMAT },
#endif
#ifdef B_MEDIA_BAD_BUFFER
  { "B_MEDIA_BAD_BUFFER", B_MEDIA_BAD_BUFFER },
#endif
#ifdef B_MEDIA_TOO_MANY_NODES
  { "B_MEDIA_TOO_MANY_NODES", B_MEDIA_TOO_MANY_NODES },
#endif
#ifdef B_MEDIA_TOO_MANY_BUFFERS
  { "B_MEDIA_TOO_MANY_BUFFERS", B_MEDIA_TOO_MANY_BUFFERS },
#endif
#ifdef B_MEDIA_NODE_ALREADY_EXISTS
  { "B_MEDIA_NODE_ALREADY_EXISTS", B_MEDIA_NODE_ALREADY_EXISTS },
#endif
#ifdef B_MEDIA_BUFFER_ALREADY_EXISTS
  { "B_MEDIA_BUFFER_ALREADY_EXISTS", B_MEDIA_BUFFER_ALREADY_EXISTS },
#endif
#ifdef B_MEDIA_CANNOT_SEEK
  { "B_MEDIA_CANNOT_SEEK", B_MEDIA_CANNOT_SEEK },
#endif
#ifdef B_MEDIA_CANNOT_CHANGE_RUN_MODE
  { "B_MEDIA_CANNOT_CHANGE_RUN_MODE", B_MEDIA_CANNOT_CHANGE_RUN_MODE },
#endif
#ifdef B_MEDIA_APP_ALREADY_REGISTERED
  { "B_MEDIA_APP_ALREADY_REGISTERED", B_MEDIA_APP_ALREADY_REGISTERED },
#endif
#ifdef B_MEDIA_APP_NOT_REGISTERED
  { "B_MEDIA_APP_NOT_REGISTERED", B_MEDIA_APP_NOT_REGISTERED },
#endif
#ifdef B_MEDIA_CANNOT_RECLAIM_BUFFERS
  { "B_MEDIA_CANNOT_RECLAIM_BUFFERS", B_MEDIA_CANNOT_RECLAIM_BUFFERS },
#endif
#ifdef B_MEDIA_BUFFERS_NOT_RECLAIMED
  { "B_MEDIA_BUFFERS_NOT_RECLAIMED", B_MEDIA_BUFFERS_NOT_RECLAIMED },
#endif
#ifdef B_MEDIA_TIME_SOURCE_STOPPED
  { "B_MEDIA_TIME_SOURCE_STOPPED", B_MEDIA_TIME_SOURCE_STOPPED },
#endif
#ifdef B_MEDIA_TIME_SOURCE_BUSY
  { "B_MEDIA_TIME_SOURCE_BUSY", B_MEDIA_TIME_SOURCE_BUSY },
#endif
#ifdef B_MEDIA_BAD_SOURCE
  { "B_MEDIA_BAD_SOURCE", B_MEDIA_BAD_SOURCE },
#endif
#ifdef B_MEDIA_BAD_DESTINATION
  { "B_MEDIA_BAD_DESTINATION", B_MEDIA_BAD_DESTINATION },
#endif
#ifdef B_MEDIA_ALREADY_CONNECTED
  { "B_MEDIA_ALREADY_CONNECTED", B_MEDIA_ALREADY_CONNECTED },
#endif
#ifdef B_MEDIA_NOT_CONNECTED
  { "B_MEDIA_NOT_CONNECTED", B_MEDIA_NOT_CONNECTED },
#endif
#ifdef B_MEDIA_BAD_CLIP_FORMAT
  { "B_MEDIA_BAD_CLIP_FORMAT", B_MEDIA_BAD_CLIP_FORMAT },
#endif
#ifdef B_MEDIA_ADDON_FAILED
  { "B_MEDIA_ADDON_FAILED", B_MEDIA_ADDON_FAILED },
#endif
#ifdef B_MEDIA_ADDON_DISABLED
  { "B_MEDIA_ADDON_DISABLED", B_MEDIA_ADDON_DISABLED },
#endif
#ifdef B_MEDIA_CHANGE_IN_PROGRESS
  { "B_MEDIA_CHANGE_IN_PROGRESS", B_MEDIA_CHANGE_IN_PROGRESS },
#endif
#ifdef B_MEDIA_STALE_CHANGE_COUNT
  { "B_MEDIA_STALE_CHANGE_COUNT", B_MEDIA_STALE_CHANGE_COUNT },
#endif
#ifdef B_MEDIA_ADDON_RESTRICTED
  { "B_MEDIA_ADDON_RESTRICTED", B_MEDIA_ADDON_RESTRICTED },
#endif
#ifdef B_MEDIA_NO_HANDLER
  { "B_MEDIA_NO_HANDLER", B_MEDIA_NO_HANDLER },
#endif
#ifdef B_MEDIA_DUPLICATE_FORMAT
  { "B_MEDIA_DUPLICATE_FORMAT", B_MEDIA_DUPLICATE_FORMAT },
#endif
#ifdef B_MEDIA_REALTIME_DISABLED
  { "B_MEDIA_REALTIME_DISABLED", B_MEDIA_REALTIME_DISABLED },
#endif
#ifdef B_MEDIA_REALTIME_UNAVAILABLE
  { "B_MEDIA_REALTIME_UNAVAILABLE", B_MEDIA_REALTIME_UNAVAILABLE },
#endif
#ifdef B_MAIL_NO_DAEMON
  { "B_MAIL_NO_DAEMON", B_MAIL_NO_DAEMON },
#endif
#ifdef B_MAIL_UNKNOWN_USER
  { "B_MAIL_UNKNOWN_USER", B_MAIL_UNKNOWN_USER },
#endif
#ifdef B_MAIL_WRONG_PASSWORD
  { "B_MAIL_WRONG_PASSWORD", B_MAIL_WRONG_PASSWORD },
#endif
#ifdef B_MAIL_UNKNOWN_HOST
  { "B_MAIL_UNKNOWN_HOST", B_MAIL_UNKNOWN_HOST },
#endif
#ifdef B_MAIL_ACCESS_ERROR
  { "B_MAIL_ACCESS_ERROR", B_MAIL_ACCESS_ERROR },
#endif
#ifdef B_MAIL_UNKNOWN_FIELD
  { "B_MAIL_UNKNOWN_FIELD", B_MAIL_UNKNOWN_FIELD },
#endif
#ifdef B_MAIL_NO_RECIPIENT
  { "B_MAIL_NO_RECIPIENT", B_MAIL_NO_RECIPIENT },
#endif
#ifdef B_MAIL_INVALID_MAIL
  { "B_MAIL_INVALID_MAIL", B_MAIL_INVALID_MAIL },
#endif
#ifdef B_NO_PRINT_SERVER
  { "B_NO_PRINT_SERVER", B_NO_PRINT_SERVER },
#endif
#ifdef B_DEV_INVALID_IOCTL
  { "B_DEV_INVALID_IOCTL", B_DEV_INVALID_IOCTL },
#endif
#ifdef B_DEV_NO_MEMORY
  { "B_DEV_NO_MEMORY", B_DEV_NO_MEMORY },
#endif
#ifdef B_DEV_BAD_DRIVE_NUM
  { "B_DEV_BAD_DRIVE_NUM", B_DEV_BAD_DRIVE_NUM },
#endif
#ifdef B_DEV_NO_MEDIA
  { "B_DEV_NO_MEDIA", B_DEV_NO_MEDIA },
#endif
#ifdef B_DEV_UNREADABLE
  { "B_DEV_UNREADABLE", B_DEV_UNREADABLE },
#endif
#ifdef B_DEV_FORMAT_ERROR
  { "B_DEV_FORMAT_ERROR", B_DEV_FORMAT_ERROR },
#endif
#ifdef B_DEV_TIMEOUT
  { "B_DEV_TIMEOUT", B_DEV_TIMEOUT },
#endif
#ifdef B_DEV_RECALIBRATE_ERROR
  { "B_DEV_RECALIBRATE_ERROR", B_DEV_RECALIBRATE_ERROR },
#endif
#ifdef B_DEV_SEEK_ERROR
  { "B_DEV_SEEK_ERROR", B_DEV_SEEK_ERROR },
#endif
#ifdef B_DEV_ID_ERROR
  { "B_DEV_ID_ERROR", B_DEV_ID_ERROR },
#endif
#ifdef B_DEV_READ_ERROR
  { "B_DEV_READ_ERROR", B_DEV_READ_ERROR },
#endif
#ifdef B_DEV_WRITE_ERROR
  { "B_DEV_WRITE_ERROR", B_DEV_WRITE_ERROR },
#endif
#ifdef B_DEV_NOT_READY
  { "B_DEV_NOT_READY", B_DEV_NOT_READY },
#endif
#ifdef B_DEV_MEDIA_CHANGED
  { "B_DEV_MEDIA_CHANGED", B_DEV_MEDIA_CHANGED },
#endif
#ifdef B_DEV_MEDIA_CHANGE_REQUESTED
  { "B_DEV_MEDIA_CHANGE_REQUESTED", B_DEV_MEDIA_CHANGE_REQUESTED },
#endif
#ifdef B_DEV_RESOURCE_CONFLICT
  { "B_DEV_RESOURCE_CONFLICT", B_DEV_RESOURCE_CONFLICT },
#endif
#ifdef B_DEV_CONFIGURATION_ERROR
  { "B_DEV_CONFIGURATION_ERROR", B_DEV_CONFIGURATION_ERROR },
#endif
#ifdef B_DEV_DISABLED_BY_USER
  { "B_DEV_DISABLED_BY_USER", B_DEV_DISABLED_BY_USER },
#endif
#ifdef B_DEV_DOOR_OPEN
  { "B_DEV_DOOR_OPEN", B_DEV_DOOR_OPEN },
#endif
#ifdef B_DEV_INVALID_PIPE
  { "B_DEV_INVALID_PIPE", B_DEV_INVALID_PIPE },
#endif
#ifdef B_DEV_CRC_ERROR
  { "B_DEV_CRC_ERROR", B_DEV_CRC_ERROR },
#endif
#ifdef B_DEV_STALLED
  { "B_DEV_STALLED", B_DEV_STALLED },
#endif
#ifdef B_DEV_BAD_PID
  { "B_DEV_BAD_PID", B_DEV_BAD_PID },
#endif
#ifdef B_DEV_UNEXPECTED_PID
  { "B_DEV_UNEXPECTED_PID", B_DEV_UNEXPECTED_PID },
#endif
#ifdef B_DEV_DATA_OVERRUN
  { "B_DEV_DATA_OVERRUN", B_DEV_DATA_OVERRUN },
#endif
#ifdef B_DEV_DATA_UNDERRUN
  { "B_DEV_DATA_UNDERRUN", B_DEV_DATA_UNDERRUN },
#endif
#ifdef B_DEV_FIFO_OVERRUN
  { "B_DEV_FIFO_OVERRUN", B_DEV_FIFO_OVERRUN },
#endif
#ifdef B_DEV_FIFO_UNDERRUN
  { "B_DEV_FIFO_UNDERRUN", B_DEV_FIFO_UNDERRUN },
#endif
#ifdef B_DEV_PENDING
  { "B_DEV_PENDING", B_DEV_PENDING },
#endif
#ifdef B_DEV_MULTIPLE_ERRORS
  { "B_DEV_MULTIPLE_ERRORS", B_DEV_MULTIPLE_ERRORS },
#endif
#ifdef B_DEV_TOO_LATE
  { "B_DEV_TOO_LATE", B_DEV_TOO_LATE },
#endif
#ifdef B_NO_TRANSLATOR
  { "B_NO_TRANSLATOR", B_NO_TRANSLATOR },
#endif
#ifdef B_ILLEGAL_DATA
  { "B_ILLEGAL_DATA", B_ILLEGAL_DATA },
#endif
#ifdef EFPOS
  { "EFPOS", EFPOS },
#endif
#ifdef ESIGPARM
  { "ESIGPARM", ESIGPARM },
#endif
  { NULL, 0 }
};

int num_errno = sizeof(internal_errno_to_name) / sizeof(*internal_errno_to_name) - 1;

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
  for (i = 0; i < (int)(sizeof(errno_ary)/sizeof(int)); i++) {
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
