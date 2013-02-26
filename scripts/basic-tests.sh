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
set -v

uname -mrsv
./size
./const

./unix-stream 'foo\0'
./unix-stream 'foo\0' './foo\0'
./unix-stream 'foo\0' './foo\0' 'bar\0'
./unix-stream 'foo\0hoge' './foo\0fuga'
./unix-stream 'foo\0hoge' './foo\0fuga' 'bar\0moga'

./unix-stream '(44*"./")a\0'
./unix-stream '(44*"./")ab\0'
./unix-stream '(45*"./")a\0'
./unix-stream '(45*"./")ab\0'
./unix-stream '(46*"./")a\0'
./unix-stream '(46*"./")ab\0'
./unix-stream '(47*"./")a\0'
./unix-stream '(47*"./")ab\0'
./unix-stream '(48*"./")a\0'
./unix-stream '(48*"./")ab\0'
./unix-stream '(49*"./")a\0'
./unix-stream '(49*"./")ab\0'

./unix-stream '(50*"./")a\0'
./unix-stream '(50*"./")ab\0'
./unix-stream '(51*"./")a\0'
./unix-stream '(51*"./")ab\0'
./unix-stream '(52*"./")a\0'
./unix-stream '(52*"./")ab\0'
./unix-stream '(53*"./")a\0'
./unix-stream '(53*"./")ab\0'
./unix-stream '(54*"./")a\0'
./unix-stream '(54*"./")ab\0'
./unix-stream '(55*"./")a\0'
./unix-stream '(55*"./")ab\0'
./unix-stream '(56*"./")a\0'
./unix-stream '(56*"./")ab\0'
./unix-stream '(57*"./")a\0'
./unix-stream '(57*"./")ab\0'
./unix-stream '(58*"./")a\0'
./unix-stream '(58*"./")ab\0'
./unix-stream '(59*"./")a\0'
./unix-stream '(59*"./")ab\0'

./unix-stream '(60*"./")a\0'
./unix-stream '(60*"./")ab\0'
./unix-stream '(61*"./")a\0'
./unix-stream '(61*"./")ab\0'
./unix-stream '(62*"./")a\0'
./unix-stream '(62*"./")ab\0'
./unix-stream '(63*"./")a\0'
./unix-stream '(63*"./")ab\0'
./unix-stream '(64*"./")a\0'
./unix-stream '(64*"./")ab\0'
./unix-stream '(65*"./")a\0'
./unix-stream '(65*"./")ab\0'
./unix-stream '(66*"./")a\0'
./unix-stream '(66*"./")ab\0'
./unix-stream '(67*"./")a\0'
./unix-stream '(67*"./")ab\0'
./unix-stream '(68*"./")a\0'
./unix-stream '(68*"./")ab\0'
./unix-stream '(69*"./")a\0'
./unix-stream '(69*"./")ab\0'

./unix-stream '(120*"./")a\0'
./unix-stream '(120*"./")ab\0'
./unix-stream '(121*"./")a\0'
./unix-stream '(121*"./")ab\0'
./unix-stream '(122*"./")a\0'
./unix-stream '(122*"./")ab\0'
./unix-stream '(123*"./")a\0'
./unix-stream '(123*"./")ab\0'
./unix-stream '(124*"./")a\0'
./unix-stream '(124*"./")ab\0'
./unix-stream '(125*"./")a\0'
./unix-stream '(125*"./")ab\0'
./unix-stream '(126*"./")a\0'
./unix-stream '(126*"./")ab\0'
./unix-stream '(127*"./")a\0'
./unix-stream '(127*"./")ab\0'
./unix-stream '(128*"./")a\0'
./unix-stream '(128*"./")ab\0'
./unix-stream '(129*"./")a\0'
./unix-stream '(129*"./")ab\0'

./unix-stream '(250*"./")a\0'
./unix-stream '(250*"./")ab\0'
./unix-stream '(251*"./")a\0'
./unix-stream '(251*"./")ab\0'
./unix-stream '(252*"./")a\0'
./unix-stream '(252*"./")ab\0'
./unix-stream '(253*"./")a\0'
./unix-stream '(253*"./")ab\0'
./unix-stream '(254*"./")a\0'
./unix-stream '(254*"./")ab\0'
./unix-stream '(255*"./")a\0'
./unix-stream '(255*"./")ab\0'
./unix-stream '(256*"./")a\0'
./unix-stream '(256*"./")ab\0'
./unix-stream '(257*"./")a\0'
./unix-stream '(257*"./")ab\0'
./unix-stream '(258*"./")a\0'
./unix-stream '(258*"./")ab\0'
./unix-stream '(259*"./")a\0'
./unix-stream '(259*"./")ab\0'

./unix-stream '(90*"c")\0'
./unix-stream '(91*"c")\0'
./unix-stream '(92*"c")\0'
./unix-stream '(93*"c")\0'
./unix-stream '(94*"c")\0'
./unix-stream '(95*"c")\0'
./unix-stream '(96*"c")\0'
./unix-stream '(97*"c")\0'
./unix-stream '(98*"c")\0'
./unix-stream '(99*"c")\0'

./unix-stream '(100*"c")\0'
./unix-stream '(101*"c")\0'
./unix-stream '(102*"c")\0'
./unix-stream '(103*"c")\0'
./unix-stream '(104*"c")\0'
./unix-stream '(105*"c")\0'
./unix-stream '(106*"c")\0'
./unix-stream '(107*"c")\0'
./unix-stream '(108*"c")\0'
./unix-stream '(109*"c")\0'

./unix-stream '(110*"c")\0'
./unix-stream '(111*"c")\0'
./unix-stream '(112*"c")\0'
./unix-stream '(113*"c")\0'
./unix-stream '(114*"c")\0'
./unix-stream '(115*"c")\0'
./unix-stream '(116*"c")\0'
./unix-stream '(117*"c")\0'
./unix-stream '(118*"c")\0'
./unix-stream '(119*"c")\0'

./unix-stream '(120*"c")\0'
./unix-stream '(121*"c")\0'
./unix-stream '(122*"c")\0'
./unix-stream '(123*"c")\0'
./unix-stream '(124*"c")\0'
./unix-stream '(125*"c")\0'
./unix-stream '(126*"c")\0'
./unix-stream '(127*"c")\0'
./unix-stream '(128*"c")\0'
./unix-stream '(129*"c")\0'

./unix-stream '(250*"c")\0'
./unix-stream '(251*"c")\0'
./unix-stream '(252*"c")\0'
./unix-stream '(253*"c")\0'
./unix-stream '(254*"c")\0'
./unix-stream '(255*"c")\0'
./unix-stream '(256*"c")\0'
./unix-stream '(257*"c")\0'
./unix-stream '(258*"c")\0'
./unix-stream '(259*"c")\0'

./unix-stream '(500*"c")\0'
./unix-stream '(501*"c")\0'
./unix-stream '(502*"c")\0'
./unix-stream '(503*"c")\0'
./unix-stream '(504*"c")\0'
./unix-stream '(505*"c")\0'
./unix-stream '(506*"c")\0'
./unix-stream '(507*"c")\0'
./unix-stream '(508*"c")\0'
./unix-stream '(509*"c")\0'

./unix-stream '(510*"c")\0'
./unix-stream '(511*"c")\0'
./unix-stream '(512*"c")\0'
./unix-stream '(513*"c")\0'
./unix-stream '(514*"c")\0'
./unix-stream '(515*"c")\0'
./unix-stream '(516*"c")\0'
./unix-stream '(517*"c")\0'
./unix-stream '(518*"c")\0'
./unix-stream '(519*"c")\0'

./unix-stream -p '01234567\0'
./unix-stream -p '012345678\0'
./unix-stream -p '0123456789\0'
./unix-stream -p '01234567890\0'

./unix-stream -g 1024 '(25*"0123456789")012\0'
./unix-stream 'foo\0' 'foo\0' '(200*"b")\0'

./unix-stream -s '\0'
./unix-stream -s '.\0'
./unix-stream -s '/\0'
./unix-stream -s '/foo\0'
./unix-stream -s '/foo/bar\0'
./unix-stream -s '/etc\0'
./unix-stream -c -s 'README\0'


