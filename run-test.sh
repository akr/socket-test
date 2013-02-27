#!/bin/sh

UNAME="`uname -srvm`"

sh scripts/basic-tests.sh

case "$UNAME" in
CYGWIN*|Haiku*|Minix*|*Hurd*)
  sh scripts/nullless-simple-tests.sh
  ;;
*)
  sh scripts/nullless-tests.sh
  ;;
esac

case "$UNAME" in
Linux*)
  sh scripts/linux-tests.sh
  ;;
NetBSD*|FreeBSD*|OpenBSD*|DragonFly*|MirBSD*|GNU/kFreeBSD*|*Hurd*|Darwin*|Haiku*)
  sh scripts/44bsd-tests.sh
  ;;
esac
