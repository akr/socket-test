#!/bin/sh

UNAME="`uname -srvm`"

sh scripts/unix-stream-basic-tests.sh

case "$UNAME" in
CYGWIN*|Haiku*|Minix*) sh scripts/unix-stream-nullless-simple-tests.sh ;;
*Hurd*) sh scripts/unix-stream-nullless-simple2-tests.sh ;;
*) sh scripts/unix-stream-nullless-tests.sh ;;
esac

case "$UNAME" in
Linux*) sh scripts/unix-stream-linux-tests.sh ;;
NetBSD*|FreeBSD*|OpenBSD*|DragonFly*|MirBSD*|GNU/kFreeBSD*|*Hurd*|Darwin*|Haiku*) sh scripts/unix-stream-44bsd-tests.sh ;;
esac

case "$UNAME" in
*Hurd*|Haiku*) : ;;
*) sh scripts/unix-dgram-basic-tests.sh;;
esac

case "$UNAME" in
CYGWIN*|Haiku*|Minix*) sh scripts/unix-dgram-nullless-simple-tests.sh ;;
*Hurd*) sh scripts/unix-dgram-nullless-simple2-tests.sh ;;
*) sh scripts/unix-dgram-nullless-tests.sh ;;
esac

case "$UNAME" in
Linux*) sh scripts/unix-dgram-linux-tests.sh ;;
NetBSD*|FreeBSD*|OpenBSD*|DragonFly*|MirBSD*|GNU/kFreeBSD*|*Hurd*|Darwin*|Haiku*) sh scripts/unix-dgram-44bsd-tests.sh ;;
esac

case "$UNAME" in
CYGWIN*|Minix*) : ;;
*) sh ./scripts/unix-accept-after-close.sh ;;
esac

sh scripts/ipv4-stream-basic-tests.sh

sh scripts/additional-tests.sh
