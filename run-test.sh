#!/bin/sh

UNAME="`uname -srvm`"

sh scripts/unix-stream-basic-tests.sh

case "$UNAME" in
CYGWIN*|Haiku*|Minix*)
  sh scripts/unix-stream-nullless-simple-tests.sh
  ;;
*Hurd*)
  sh scripts/unix-stream-nullless-simple2-tests.sh
  ;;
*)
  sh scripts/unix-stream-nullless-tests.sh
  ;;
esac

case "$UNAME" in
Linux*)
  sh scripts/unix-stream-linux-tests.sh
  ;;
NetBSD*|FreeBSD*|OpenBSD*|DragonFly*|MirBSD*|GNU/kFreeBSD*|*Hurd*|Darwin*|Haiku*)
  sh scripts/unix-stream-44bsd-tests.sh
  ;;
esac

sh scripts/additional-tests.sh
