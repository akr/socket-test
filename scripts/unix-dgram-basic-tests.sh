#!/bin/sh

# Copyright (C) 2013 Tanaka Akira  <akr@fsij.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#  1. Redistributions of source code must retain the above copyright notice, this
#     list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright notice,
#     this list of conditions and the following disclaimer in the documentation
#     and/or other materials provided with the distribution.
#  3. The name of the author may not be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
# EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
# OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
# OF SUCH DAMAGE.

exec 2>&1

UNAME="`uname -srvm`"

cat <<'End' | sh -sv
./obj/unix-dgram 'foo\0' 'foo\0' 'bar\0'
./obj/unix-dgram 'foo\0' './foo\0' 'bar\0'

./obj/unix-dgram -c 'foo\0' 'foo\0' 'bar\0'
./obj/unix-dgram -M 'foo\0' 'foo\0' 'bar\0'
./obj/unix-dgram -m 'foo\0' 'foo\0' 'bar\0'

./obj/unix-dgram 'foo\0hoge' 'foo\0' 'bar\0'
./obj/unix-dgram 'foo\0' 'foo\0fuga' 'bar\0'
./obj/unix-dgram 'foo\0' 'foo\0' 'bar\0moga'
./obj/unix-dgram 'foo\0hoge' './foo\0fuga' 'bar\0moga'
End

for n in \
  44 45 46 47 48 49 \
  50 51 52 53 54 55 56 57 58 59 \
  60 61 62 63 64 65 66 67 68 69 \
  120 121 122 123 124 125 126 127 128 129 \
  250 251 252 253 254 255 256 257 258 259 \
  510 511 512 513 514 515 516 517 518 519
do
  cat <<End
./obj/unix-dgram '($n*"./")a\0'  '($n*"./")a\0'  'bar\0'
./obj/unix-dgram '($n*"./")ab\0' '($n*"./")ab\0' 'bar\0'
End
done | sh -sv

for n in \
  90 91 92 93 94 95 96 97 98 99 \
  100 101 102 103 104 105 106 107 108 109 \
  110 111 112 113 114 115 116 117 118 119 \
  120 121 122 123 124 125 126 127 128 129 \
  250 251 252 253 254 255 256 257 258 259
do
  cat <<End
./obj/unix-dgram '($n*"c")\0'  '($n*"c")\0'  'bar\0'
End
done | sh -sv

cat <<'End' | sh -sv
./obj/unix-dgram -p '01234567\0'    '01234567\0'    'bar\0'
./obj/unix-dgram -p '012345678\0'   '012345678\0'   'bar\0'
./obj/unix-dgram -p '0123456789\0'  '0123456789\0'  'bar\0'
./obj/unix-dgram -p '01234567890\0' '01234567890\0' 'bar\0'
End

case "$UNAME" in
MirBSD*) : ;;
*)
cat <<'End' | sh -sv
./obj/unix-dgram -g2048 -p '01234567890\0' '01234567890\0' 'bar\0'
./obj/unix-dgram -g2048 -p 'foo\0' 'foo\0' '01234567890\0'
End
;;
esac

case "$UNAME" in
MirBSD*) : ;;
*)
for n in \
  115 116 117 118 119 \
  120 121 122 123 124 125 126 127 128 129 \
  250 251 252 253 254 255 256 257 258 259 \
  510 511 512 513 514 515 516 517 518 519
do
  cat <<End
./obj/unix-dgram -g255 '($n*"./")a\0' '($n*"./")a\0' 'bar\0'
./obj/unix-dgram -g255 '($n*"./")ab\0' '($n*"./")ab\0' 'bar\0'
End
done | sh -sv
;;
esac

cat <<'End' | sh -sv
./obj/unix-dgram 'foo\0' 'foo\0' '(125*"./")ab\0'
./obj/unix-dgram 'foo\0' 'foo\0' '(126*"./")a\0'
./obj/unix-dgram 'foo\0' 'foo\0' '(511*"./")a\0'
./obj/unix-dgram 'foo\0' 'foo\0' '(511*"./")ab\0'
End

case "$UNAME" in
MirBSD*) : ;;
*)
cat <<'End' | sh -sv
./obj/unix-dgram -g255 'foo\0' 'foo\0' '(125*"./")ab\0'
./obj/unix-dgram -g1026 'foo\0' 'foo\0' '(511*"./")a\0'
End
;;
esac

cat <<'End' | sh -sv
./obj/unix-dgram -s '\0'
./obj/unix-dgram -s '.\0'
./obj/unix-dgram -s '/\0'
./obj/unix-dgram -s '/foo\0'
./obj/unix-dgram -s '/foo/bar\0'
./obj/unix-dgram -s '/etc\0'
./obj/unix-dgram -T -s 'README\0'
End
