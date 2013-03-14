#!/bin/sh

# usage:
#   echo name [host] | scripts/remote-test.sh

REMOTE_DIRECTORY=test.socket-test

D=/tmp/tst.$$
mkdir $D || exit 1
trap "rm -rf $D" EXIT

git ls-files |
grep -v '^results/' |
xargs tar rf $D/tst.tar
gzip $D/tst.tar

mv z.run.log z.run.log-

while read line
do
  set $line
  name=$1
  host=${2:-$name}
  if [ "$name" = exit ]; then
    exit
  fi
  echo "name:[$name] host:[$host]"
  (
    echo "REMOTE_DIRECTORY=\"$REMOTE_DIRECTORY\""
    cat <<'End1'
LANG=C
export LANG
LC_ALL=C
export LC_ALL
D2=/tmp/tst.$$
mkdir $D2 || exit 1
trap "rm -rf $D2" EXIT
cat <<"EndOfUU" | (cd $D2; uudecode)
End1
    uuencode tst.tar.gz < $D/tst.tar.gz
    cat <<'End2'
EndOfUU
(cd $D2; gzip -dc tst.tar.gz | tar xf - )
rm $D2/tst.tar.gz
(cd $D2; find . -type f -print) | while read fn;
do
  if [ -f "$REMOTE_DIRECTORY/$fn" ] &&
     cmp -s "$REMOTE_DIRECTORY/$fn" "$D2/$fn"; then
    :
  else
    mkdir -p `dirname "$REMOTE_DIRECTORY/$fn"`
    cp "$D2/$fn" "$REMOTE_DIRECTORY/$fn"
  fi
done
cd $REMOTE_DIRECTORY
( make clean-old all ) | tee z.log 1>&2 &&
sh scripts/run-test.sh 2>&1
End2
) | tee z.remote.sh | ssh "$host" sh -s > results/$name.txt
done 2>&1 | tee z.run.log
