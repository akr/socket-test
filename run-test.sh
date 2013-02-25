#!/bin/sh

case "`uname -srvm`" in
Linux*)
  sh scripts/basic-tests.sh
  sh scripts/nullless-tests.sh
  sh scripts/linux-tests.sh
  ;;
NetBSD*|FreeBSD*|OpenBSD*|DragonFly*|MirBSD*|GNU/kFreeBSD*|*Hurd*|Darwin*|Haiku*)
  sh scripts/basic-tests.sh
  sh scripts/nullless-tests.sh
  sh scripts/44bsd-tests.sh
  ;;
SunOS*|Minix*)
  sh scripts/basic-tests.sh
  sh scripts/nullless-tests.sh
  ;;
CYGWIN*)
  sh scripts/basic-tests.sh
  sh scripts/cygwin-tests.sh
  ;;
*)
  sh scripts/basic-tests.sh
  ;;
esac
