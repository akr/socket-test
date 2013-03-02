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

./unix-dgram 'foo\0' 'foo\0' 'bar\0'
./unix-dgram 'foo\0' './foo\0' 'bar\0'

./unix-dgram 'foo\0hoge' 'foo\0' 'bar\0'
./unix-dgram 'foo\0' 'foo\0fuga' 'bar\0'
./unix-dgram 'foo\0' 'foo\0' 'bar\0moga'
./unix-dgram 'foo\0hoge' './foo\0fuga' 'bar\0moga'

./unix-dgram '(44*"./")a\0'  '(44*"./")a\0'  'bar\0'
./unix-dgram '(44*"./")ab\0' '(44*"./")ab\0' 'bar\0'
./unix-dgram '(45*"./")a\0'  '(45*"./")a\0'  'bar\0'
./unix-dgram '(45*"./")ab\0' '(45*"./")ab\0' 'bar\0'
./unix-dgram '(46*"./")a\0'  '(46*"./")a\0'  'bar\0'
./unix-dgram '(46*"./")ab\0' '(46*"./")ab\0' 'bar\0'
./unix-dgram '(47*"./")a\0'  '(47*"./")a\0'  'bar\0'
./unix-dgram '(47*"./")ab\0' '(47*"./")ab\0' 'bar\0'
./unix-dgram '(48*"./")a\0'  '(48*"./")a\0'  'bar\0'
./unix-dgram '(48*"./")ab\0' '(48*"./")ab\0' 'bar\0'
./unix-dgram '(49*"./")a\0'  '(49*"./")a\0'  'bar\0'
./unix-dgram '(49*"./")ab\0' '(49*"./")ab\0' 'bar\0'

./unix-dgram '(50*"./")a\0'   '(50*"./")a\0'     'bar\0'
./unix-dgram '(50*"./")ab\0'  '(50*"./")ab\0'    'bar\0'
./unix-dgram '(51*"./")a\0'   '(51*"./")a\0'     'bar\0'
./unix-dgram '(51*"./")ab\0'  '(51*"./")ab\0'    'bar\0'
./unix-dgram '(52*"./")a\0'   '(52*"./")a\0'     'bar\0'
./unix-dgram '(52*"./")ab\0'  '(52*"./")ab\0'    'bar\0'
./unix-dgram '(53*"./")a\0'   '(53*"./")a\0'     'bar\0'
./unix-dgram '(53*"./")ab\0'  '(53*"./")ab\0'    'bar\0'
./unix-dgram '(54*"./")a\0'   '(54*"./")a\0'     'bar\0'
./unix-dgram '(54*"./")ab\0'  '(54*"./")ab\0'    'bar\0'
./unix-dgram '(55*"./")a\0'   '(55*"./")a\0'     'bar\0'
./unix-dgram '(55*"./")ab\0'  '(55*"./")ab\0'    'bar\0'
./unix-dgram '(56*"./")a\0'   '(56*"./")a\0'     'bar\0'
./unix-dgram '(56*"./")ab\0'  '(56*"./")ab\0'    'bar\0'
./unix-dgram '(57*"./")a\0'   '(57*"./")a\0'     'bar\0'
./unix-dgram '(57*"./")ab\0'  '(57*"./")ab\0'    'bar\0'
./unix-dgram '(58*"./")a\0'   '(58*"./")a\0'     'bar\0'
./unix-dgram '(58*"./")ab\0'  '(58*"./")ab\0'    'bar\0'
./unix-dgram '(59*"./")a\0'   '(59*"./")a\0'     'bar\0'
./unix-dgram '(59*"./")ab\0'  '(59*"./")ab\0'    'bar\0'
                                                  
./unix-dgram '(60*"./")a\0'   '(60*"./")a\0'     'bar\0'
./unix-dgram '(60*"./")ab\0'  '(60*"./")ab\0'    'bar\0'
./unix-dgram '(61*"./")a\0'   '(61*"./")a\0'     'bar\0'
./unix-dgram '(61*"./")ab\0'  '(61*"./")ab\0'    'bar\0'
./unix-dgram '(62*"./")a\0'   '(62*"./")a\0'     'bar\0'
./unix-dgram '(62*"./")ab\0'  '(62*"./")ab\0'    'bar\0'
./unix-dgram '(63*"./")a\0'   '(63*"./")a\0'     'bar\0'
./unix-dgram '(63*"./")ab\0'  '(63*"./")ab\0'    'bar\0'
./unix-dgram '(64*"./")a\0'   '(64*"./")a\0'     'bar\0'
./unix-dgram '(64*"./")ab\0'  '(64*"./")ab\0'    'bar\0'
./unix-dgram '(65*"./")a\0'   '(65*"./")a\0'     'bar\0'
./unix-dgram '(65*"./")ab\0'  '(65*"./")ab\0'    'bar\0'
./unix-dgram '(66*"./")a\0'   '(66*"./")a\0'     'bar\0'
./unix-dgram '(66*"./")ab\0'  '(66*"./")ab\0'    'bar\0'
./unix-dgram '(67*"./")a\0'   '(67*"./")a\0'     'bar\0'
./unix-dgram '(67*"./")ab\0'  '(67*"./")ab\0'    'bar\0'
./unix-dgram '(68*"./")a\0'   '(68*"./")a\0'     'bar\0'
./unix-dgram '(68*"./")ab\0'  '(68*"./")ab\0'    'bar\0'
./unix-dgram '(69*"./")a\0'   '(69*"./")a\0'     'bar\0'
./unix-dgram '(69*"./")ab\0'  '(69*"./")ab\0'    'bar\0'
                                                  
./unix-dgram '(120*"./")a\0'  '(120*"./")a\0'    'bar\0'
./unix-dgram '(120*"./")ab\0' '(120*"./")ab\0'   'bar\0'
./unix-dgram '(121*"./")a\0'  '(121*"./")a\0'    'bar\0'
./unix-dgram '(121*"./")ab\0' '(121*"./")ab\0'   'bar\0'
./unix-dgram '(122*"./")a\0'  '(122*"./")a\0'    'bar\0'
./unix-dgram '(122*"./")ab\0' '(122*"./")ab\0'   'bar\0'
./unix-dgram '(123*"./")a\0'  '(123*"./")a\0'    'bar\0'
./unix-dgram '(123*"./")ab\0' '(123*"./")ab\0'   'bar\0'
./unix-dgram '(124*"./")a\0'  '(124*"./")a\0'    'bar\0'
./unix-dgram '(124*"./")ab\0' '(124*"./")ab\0'   'bar\0'
./unix-dgram '(125*"./")a\0'  '(125*"./")a\0'    'bar\0'
./unix-dgram '(125*"./")ab\0' '(125*"./")ab\0'   'bar\0'
./unix-dgram '(126*"./")a\0'  '(126*"./")a\0'    'bar\0'
./unix-dgram '(126*"./")ab\0' '(126*"./")ab\0'   'bar\0'
./unix-dgram '(127*"./")a\0'  '(127*"./")a\0'    'bar\0'
./unix-dgram '(127*"./")ab\0' '(127*"./")ab\0'   'bar\0'
./unix-dgram '(128*"./")a\0'  '(128*"./")a\0'    'bar\0'
./unix-dgram '(128*"./")ab\0' '(128*"./")ab\0'   'bar\0'
./unix-dgram '(129*"./")a\0'  '(129*"./")a\0'    'bar\0'
./unix-dgram '(129*"./")ab\0' '(129*"./")ab\0'   'bar\0'
                                                  
./unix-dgram '(250*"./")a\0'  '(250*"./")a\0'    'bar\0'
./unix-dgram '(250*"./")ab\0' '(250*"./")ab\0'   'bar\0'
./unix-dgram '(251*"./")a\0'  '(251*"./")a\0'    'bar\0'
./unix-dgram '(251*"./")ab\0' '(251*"./")ab\0'   'bar\0'
./unix-dgram '(252*"./")a\0'  '(252*"./")a\0'    'bar\0'
./unix-dgram '(252*"./")ab\0' '(252*"./")ab\0'   'bar\0'
./unix-dgram '(253*"./")a\0'  '(253*"./")a\0'    'bar\0'
./unix-dgram '(253*"./")ab\0' '(253*"./")ab\0'   'bar\0'
./unix-dgram '(254*"./")a\0'  '(254*"./")a\0'    'bar\0'
./unix-dgram '(254*"./")ab\0' '(254*"./")ab\0'   'bar\0'
./unix-dgram '(255*"./")a\0'  '(255*"./")a\0'    'bar\0'
./unix-dgram '(255*"./")ab\0' '(255*"./")ab\0'   'bar\0'
./unix-dgram '(256*"./")a\0'  '(256*"./")a\0'    'bar\0'
./unix-dgram '(256*"./")ab\0' '(256*"./")ab\0'   'bar\0'
./unix-dgram '(257*"./")a\0'  '(257*"./")a\0'    'bar\0'
./unix-dgram '(257*"./")ab\0' '(257*"./")ab\0'   'bar\0'
./unix-dgram '(258*"./")a\0'  '(258*"./")a\0'    'bar\0'
./unix-dgram '(258*"./")ab\0' '(258*"./")ab\0'   'bar\0'
./unix-dgram '(259*"./")a\0'  '(259*"./")a\0'    'bar\0'
./unix-dgram '(259*"./")ab\0' '(259*"./")ab\0'   'bar\0'
                                                  
./unix-dgram '(510*"./")a\0'  '(510*"./")a\0'    'bar\0'
./unix-dgram '(510*"./")ab\0' '(510*"./")ab\0'   'bar\0'
./unix-dgram '(511*"./")a\0'  '(511*"./")a\0'    'bar\0'
./unix-dgram '(511*"./")ab\0' '(511*"./")ab\0'   'bar\0'
./unix-dgram '(512*"./")a\0'  '(512*"./")a\0'    'bar\0'
./unix-dgram '(512*"./")ab\0' '(512*"./")ab\0'   'bar\0'
./unix-dgram '(513*"./")a\0'  '(513*"./")a\0'    'bar\0'
./unix-dgram '(513*"./")ab\0' '(513*"./")ab\0'   'bar\0'
./unix-dgram '(514*"./")a\0'  '(514*"./")a\0'    'bar\0'
./unix-dgram '(514*"./")ab\0' '(514*"./")ab\0'   'bar\0'
./unix-dgram '(515*"./")a\0'  '(515*"./")a\0'    'bar\0'
./unix-dgram '(515*"./")ab\0' '(515*"./")ab\0'   'bar\0'
./unix-dgram '(516*"./")a\0'  '(516*"./")a\0'    'bar\0'
./unix-dgram '(516*"./")ab\0' '(516*"./")ab\0'   'bar\0'
./unix-dgram '(517*"./")a\0'  '(517*"./")a\0'    'bar\0'
./unix-dgram '(517*"./")ab\0' '(517*"./")ab\0'   'bar\0'
./unix-dgram '(518*"./")a\0'  '(518*"./")a\0'    'bar\0'
./unix-dgram '(518*"./")ab\0' '(518*"./")ab\0'   'bar\0'
./unix-dgram '(519*"./")a\0'  '(519*"./")a\0'    'bar\0'
./unix-dgram '(519*"./")ab\0' '(519*"./")ab\0'   'bar\0'

./unix-dgram '(90*"c")\0'  '(90*"c")\0'  'bar\0'
./unix-dgram '(91*"c")\0'  '(91*"c")\0'  'bar\0'
./unix-dgram '(92*"c")\0'  '(92*"c")\0'  'bar\0'
./unix-dgram '(93*"c")\0'  '(93*"c")\0'  'bar\0'
./unix-dgram '(94*"c")\0'  '(94*"c")\0'  'bar\0'
./unix-dgram '(95*"c")\0'  '(95*"c")\0'  'bar\0'
./unix-dgram '(96*"c")\0'  '(96*"c")\0'  'bar\0'
./unix-dgram '(97*"c")\0'  '(97*"c")\0'  'bar\0'
./unix-dgram '(98*"c")\0'  '(98*"c")\0'  'bar\0'
./unix-dgram '(99*"c")\0'  '(99*"c")\0'  'bar\0'
                                         
./unix-dgram '(100*"c")\0' '(100*"c")\0' 'bar\0'
./unix-dgram '(101*"c")\0' '(101*"c")\0' 'bar\0'
./unix-dgram '(102*"c")\0' '(102*"c")\0' 'bar\0'
./unix-dgram '(103*"c")\0' '(103*"c")\0' 'bar\0'
./unix-dgram '(104*"c")\0' '(104*"c")\0' 'bar\0'
./unix-dgram '(105*"c")\0' '(105*"c")\0' 'bar\0'
./unix-dgram '(106*"c")\0' '(106*"c")\0' 'bar\0'
./unix-dgram '(107*"c")\0' '(107*"c")\0' 'bar\0'
./unix-dgram '(108*"c")\0' '(108*"c")\0' 'bar\0'
./unix-dgram '(109*"c")\0' '(109*"c")\0' 'bar\0'
                                         
./unix-dgram '(110*"c")\0' '(110*"c")\0' 'bar\0'
./unix-dgram '(111*"c")\0' '(111*"c")\0' 'bar\0'
./unix-dgram '(112*"c")\0' '(112*"c")\0' 'bar\0'
./unix-dgram '(113*"c")\0' '(113*"c")\0' 'bar\0'
./unix-dgram '(114*"c")\0' '(114*"c")\0' 'bar\0'
./unix-dgram '(115*"c")\0' '(115*"c")\0' 'bar\0'
./unix-dgram '(116*"c")\0' '(116*"c")\0' 'bar\0'
./unix-dgram '(117*"c")\0' '(117*"c")\0' 'bar\0'
./unix-dgram '(118*"c")\0' '(118*"c")\0' 'bar\0'
./unix-dgram '(119*"c")\0' '(119*"c")\0' 'bar\0'
                                         
./unix-dgram '(120*"c")\0' '(120*"c")\0' 'bar\0'
./unix-dgram '(121*"c")\0' '(121*"c")\0' 'bar\0'
./unix-dgram '(122*"c")\0' '(122*"c")\0' 'bar\0'
./unix-dgram '(123*"c")\0' '(123*"c")\0' 'bar\0'
./unix-dgram '(124*"c")\0' '(124*"c")\0' 'bar\0'
./unix-dgram '(125*"c")\0' '(125*"c")\0' 'bar\0'
./unix-dgram '(126*"c")\0' '(126*"c")\0' 'bar\0'
./unix-dgram '(127*"c")\0' '(127*"c")\0' 'bar\0'
./unix-dgram '(128*"c")\0' '(128*"c")\0' 'bar\0'
./unix-dgram '(129*"c")\0' '(129*"c")\0' 'bar\0'
                                         
./unix-dgram '(250*"c")\0' '(250*"c")\0' 'bar\0'
./unix-dgram '(251*"c")\0' '(251*"c")\0' 'bar\0'
./unix-dgram '(252*"c")\0' '(252*"c")\0' 'bar\0'
./unix-dgram '(253*"c")\0' '(253*"c")\0' 'bar\0'
./unix-dgram '(254*"c")\0' '(254*"c")\0' 'bar\0'
./unix-dgram '(255*"c")\0' '(255*"c")\0' 'bar\0'
./unix-dgram '(256*"c")\0' '(256*"c")\0' 'bar\0'
./unix-dgram '(257*"c")\0' '(257*"c")\0' 'bar\0'
./unix-dgram '(258*"c")\0' '(258*"c")\0' 'bar\0'
./unix-dgram '(259*"c")\0' '(259*"c")\0' 'bar\0'

./unix-dgram -p '01234567\0'    '01234567\0'    'bar\0'
./unix-dgram -p '012345678\0'   '012345678\0'   'bar\0'
./unix-dgram -p '0123456789\0'  '0123456789\0'  'bar\0'
./unix-dgram -p '01234567890\0' '01234567890\0' 'bar\0'
        
./unix-dgram -g2048 -p '01234567890\0' '01234567890\0' 'bar\0'
./unix-dgram -g2048 -p 'foo\0' 'foo\0' '01234567890\0'

./unix-dgram -g255 '(125*"./")ab\0' '(125*"./")ab\0' 'bar\0'
./unix-dgram -g1026 '(511*"./")a\0' '(511*"./")a\0' 'bar\0'

./unix-dgram 'foo\0' 'foo\0' '(125*"./")ab\0'
./unix-dgram 'foo\0' 'foo\0' '(511*"./")a\0'
./unix-dgram -g255 'foo\0' 'foo\0' '(125*"./")ab\0'
./unix-dgram -g1026 'foo\0' 'foo\0' '(511*"./")a\0'

./unix-dgram -s '\0'    
./unix-dgram -s '.\0'   
./unix-dgram -s '/\0'   
./unix-dgram -s '/foo\0'        
./unix-dgram -s '/foo/bar\0'    
./unix-dgram -s '/etc\0'        
./unix-dgram -T -s 'README\0'   

