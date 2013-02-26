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

./unix-stream 'foo'
./unix-stream 'foo' './foo'
./unix-stream 'foo' './foo' 'bar'

./unix-stream '(44*"./")a'
./unix-stream '(44*"./")ab'
./unix-stream '(45*"./")a'
./unix-stream '(45*"./")ab'
./unix-stream '(46*"./")a'
./unix-stream '(46*"./")ab'
./unix-stream '(47*"./")a'
./unix-stream '(47*"./")ab'
./unix-stream '(48*"./")a'
./unix-stream '(48*"./")ab'
./unix-stream '(49*"./")a'
./unix-stream '(49*"./")ab'

./unix-stream '(50*"./")a'
./unix-stream '(50*"./")ab'
./unix-stream '(51*"./")a'
./unix-stream '(51*"./")ab'
./unix-stream '(52*"./")a'
./unix-stream '(52*"./")ab'
./unix-stream '(53*"./")a'
./unix-stream '(53*"./")ab'
./unix-stream '(54*"./")a'
./unix-stream '(54*"./")ab'
./unix-stream '(55*"./")a'
./unix-stream '(55*"./")ab'
./unix-stream '(56*"./")a'
./unix-stream '(56*"./")ab'
./unix-stream '(57*"./")a'
./unix-stream '(57*"./")ab'
./unix-stream '(58*"./")a'
./unix-stream '(58*"./")ab'
./unix-stream '(59*"./")a'
./unix-stream '(59*"./")ab'

./unix-stream '(60*"./")a'
./unix-stream '(60*"./")ab'
./unix-stream '(61*"./")a'
./unix-stream '(61*"./")ab'
./unix-stream '(62*"./")a'
./unix-stream '(62*"./")ab'
./unix-stream '(63*"./")a'
./unix-stream '(63*"./")ab'
./unix-stream '(64*"./")a'
./unix-stream '(64*"./")ab'
./unix-stream '(65*"./")a'
./unix-stream '(65*"./")ab'
./unix-stream '(66*"./")a'
./unix-stream '(66*"./")ab'
./unix-stream '(67*"./")a'
./unix-stream '(67*"./")ab'
./unix-stream '(68*"./")a'
./unix-stream '(68*"./")ab'
./unix-stream '(69*"./")a'
./unix-stream '(69*"./")ab'

./unix-stream '(120*"./")a'
./unix-stream '(120*"./")ab'
./unix-stream '(121*"./")a'
./unix-stream '(121*"./")ab'
./unix-stream '(122*"./")a'
./unix-stream '(122*"./")ab'
./unix-stream '(123*"./")a'
./unix-stream '(123*"./")ab'
./unix-stream '(124*"./")a'
./unix-stream '(124*"./")ab'
./unix-stream '(125*"./")a'
./unix-stream '(125*"./")ab'
./unix-stream '(126*"./")a'
./unix-stream '(126*"./")ab'
./unix-stream '(127*"./")a'
./unix-stream '(127*"./")ab'
./unix-stream '(128*"./")a'
./unix-stream '(128*"./")ab'
./unix-stream '(129*"./")a'
./unix-stream '(129*"./")ab'

./unix-stream '(250*"./")a'
./unix-stream '(250*"./")ab'
./unix-stream '(251*"./")a'
./unix-stream '(251*"./")ab'
./unix-stream '(252*"./")a'
./unix-stream '(252*"./")ab'
./unix-stream '(253*"./")a'
./unix-stream '(253*"./")ab'
./unix-stream '(254*"./")a'
./unix-stream '(254*"./")ab'
./unix-stream '(255*"./")a'
./unix-stream '(255*"./")ab'
./unix-stream '(256*"./")a'
./unix-stream '(256*"./")ab'
./unix-stream '(257*"./")a'
./unix-stream '(257*"./")ab'
./unix-stream '(258*"./")a'
./unix-stream '(258*"./")ab'
./unix-stream '(259*"./")a'
./unix-stream '(259*"./")ab'

./unix-stream '(90*"c")'
./unix-stream '(91*"c")'
./unix-stream '(92*"c")'
./unix-stream '(93*"c")'
./unix-stream '(94*"c")'
./unix-stream '(95*"c")'
./unix-stream '(96*"c")'
./unix-stream '(97*"c")'
./unix-stream '(98*"c")'
./unix-stream '(99*"c")'

./unix-stream '(100*"c")'
./unix-stream '(101*"c")'
./unix-stream '(102*"c")'
./unix-stream '(103*"c")'
./unix-stream '(104*"c")'
./unix-stream '(105*"c")'
./unix-stream '(106*"c")'
./unix-stream '(107*"c")'
./unix-stream '(108*"c")'
./unix-stream '(109*"c")'

./unix-stream '(110*"c")'
./unix-stream '(111*"c")'
./unix-stream '(112*"c")'
./unix-stream '(113*"c")'
./unix-stream '(114*"c")'
./unix-stream '(115*"c")'
./unix-stream '(116*"c")'
./unix-stream '(117*"c")'
./unix-stream '(118*"c")'
./unix-stream '(119*"c")'

./unix-stream '(120*"c")'
./unix-stream '(121*"c")'
./unix-stream '(122*"c")'
./unix-stream '(123*"c")'
./unix-stream '(124*"c")'
./unix-stream '(125*"c")'
./unix-stream '(126*"c")'
./unix-stream '(127*"c")'
./unix-stream '(128*"c")'
./unix-stream '(129*"c")'

./unix-stream '(250*"c")'
./unix-stream '(251*"c")'
./unix-stream '(252*"c")'
./unix-stream '(253*"c")'
./unix-stream '(254*"c")'
./unix-stream '(255*"c")'
./unix-stream '(256*"c")'
./unix-stream '(257*"c")'
./unix-stream '(258*"c")'
./unix-stream '(259*"c")'

./unix-stream '(500*"c")'
./unix-stream '(501*"c")'
./unix-stream '(502*"c")'
./unix-stream '(503*"c")'
./unix-stream '(504*"c")'
./unix-stream '(505*"c")'
./unix-stream '(506*"c")'
./unix-stream '(507*"c")'
./unix-stream '(508*"c")'
./unix-stream '(509*"c")'

./unix-stream '(510*"c")'
./unix-stream '(511*"c")'
./unix-stream '(512*"c")'
./unix-stream '(513*"c")'
./unix-stream '(514*"c")'
./unix-stream '(515*"c")'
./unix-stream '(516*"c")'
./unix-stream '(517*"c")'
./unix-stream '(518*"c")'
./unix-stream '(519*"c")'

./unix-stream -p '012345678'
./unix-stream -p '0123456789'
./unix-stream -p '01234567890'

./unix-stream -g 1024 '(25*"0123456789")012'
./unix-stream 'foo' 'foo' '(200*"b")'

./unix-stream -s ''
./unix-stream -s '.'
./unix-stream -s '/'
./unix-stream -s '/foo'
./unix-stream -s '/foo/bar'
./unix-stream -s '/etc'
./unix-stream -s 'foo'
./unix-stream -s 'README'
