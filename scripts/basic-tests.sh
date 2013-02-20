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
./unix-stream 'foo\0' './foo\0'
./unix-stream 'foo\0hoge' './foo\0fuga'
./unix-stream 'foo\0hoge' './foo\0fuga' 'bar\0moga'

./unix-stream '(45*"./")0\0'
./unix-stream '(45*"./")01\0'
./unix-stream '(45*"./")012\0'
./unix-stream '(45*"./")0123\0'
./unix-stream '(45*"./")01234\0'
./unix-stream '(45*"./")012345\0'
./unix-stream '(45*"./")0123456\0'
./unix-stream '(45*"./")01234567\0'
./unix-stream '(45*"./")012345678\0'
./unix-stream '(45*"./")0123456789\0'
./unix-stream '(50*"./")0\0'
./unix-stream '(50*"./")01\0'
./unix-stream '(50*"./")012\0'
./unix-stream '(50*"./")0123\0'
./unix-stream '(50*"./")01234\0'
./unix-stream '(50*"./")012345\0'
./unix-stream '(50*"./")0123456\0'
./unix-stream '(50*"./")01234567\0'
./unix-stream '(50*"./")012345678\0'
./unix-stream '(50*"./")0123456789\0'
./unix-stream '(55*"./")0\0'
./unix-stream '(55*"./")01\0'
./unix-stream '(55*"./")012\0'
./unix-stream '(55*"./")0123\0'
./unix-stream '(55*"./")01234\0'
./unix-stream '(55*"./")012345\0'
./unix-stream '(55*"./")0123456\0'
./unix-stream '(55*"./")01234567\0'
./unix-stream '(55*"./")012345678\0'
./unix-stream '(55*"./")0123456789\0'
./unix-stream '(125*"./")0\0'
./unix-stream '(125*"./")01\0'
./unix-stream '(125*"./")012\0'
./unix-stream '(125*"./")0123\0'
./unix-stream '(125*"./")01234\0'
./unix-stream '(125*"./")012345\0'
./unix-stream '(125*"./")0123456\0'
./unix-stream '(125*"./")01234567\0'
./unix-stream '(125*"./")012345678\0'
./unix-stream '(125*"./")0123456789\0'
./unix-stream '(250*"./")0\0'
./unix-stream '(250*"./")01\0'
./unix-stream '(250*"./")012\0'
./unix-stream '(250*"./")0123\0'
./unix-stream '(250*"./")01234\0'
./unix-stream '(250*"./")012345\0'
./unix-stream '(250*"./")0123456\0'
./unix-stream '(250*"./")01234567\0'
./unix-stream '(250*"./")012345678\0'
./unix-stream '(250*"./")0123456789\0'
./unix-stream '(255*"./")0\0'
./unix-stream '(255*"./")01\0'
./unix-stream '(255*"./")012\0'
./unix-stream '(255*"./")0123\0'
./unix-stream '(255*"./")01234\0'
./unix-stream '(255*"./")012345\0'
./unix-stream '(255*"./")0123456\0'
./unix-stream '(255*"./")01234567\0'
./unix-stream '(255*"./")012345678\0'
./unix-stream '(255*"./")0123456789\0'

./unix-stream '(9*"0123456789")0\0'
./unix-stream '(9*"0123456789")01\0'
./unix-stream '(9*"0123456789")012\0'
./unix-stream '(9*"0123456789")0123\0'
./unix-stream '(9*"0123456789")01234\0'
./unix-stream '(9*"0123456789")012345\0'
./unix-stream '(9*"0123456789")0123456\0'
./unix-stream '(9*"0123456789")01234567\0'
./unix-stream '(9*"0123456789")012345678\0'
./unix-stream '(9*"0123456789")0123456789\0'
./unix-stream '(10*"0123456789")0\0'
./unix-stream '(10*"0123456789")01\0'
./unix-stream '(10*"0123456789")012\0'
./unix-stream '(10*"0123456789")0123\0'
./unix-stream '(10*"0123456789")01234\0'
./unix-stream '(10*"0123456789")012345\0'
./unix-stream '(10*"0123456789")0123456\0'
./unix-stream '(10*"0123456789")01234567\0'
./unix-stream '(10*"0123456789")012345678\0'
./unix-stream '(10*"0123456789")0123456789\0'
./unix-stream '(11*"0123456789")0\0'
./unix-stream '(11*"0123456789")01\0'
./unix-stream '(11*"0123456789")012\0'
./unix-stream '(11*"0123456789")0123\0'
./unix-stream '(11*"0123456789")01234\0'
./unix-stream '(11*"0123456789")012345\0'
./unix-stream '(11*"0123456789")0123456\0'
./unix-stream '(11*"0123456789")01234567\0'
./unix-stream '(11*"0123456789")012345678\0'
./unix-stream '(11*"0123456789")0123456789\0'
./unix-stream '(25*"0123456789")0\0'
./unix-stream '(25*"0123456789")01\0'
./unix-stream '(25*"0123456789")012\0'
./unix-stream '(25*"0123456789")0123\0'
./unix-stream '(25*"0123456789")01234\0'
./unix-stream '(25*"0123456789")012345\0'
./unix-stream '(25*"0123456789")0123456\0'
./unix-stream '(25*"0123456789")01234567\0'
./unix-stream '(25*"0123456789")012345678\0'
./unix-stream '(25*"0123456789")0123456789\0'
./unix-stream '(50*"0123456789")0\0'
./unix-stream '(50*"0123456789")01\0'
./unix-stream '(50*"0123456789")012\0'
./unix-stream '(50*"0123456789")0123\0'
./unix-stream '(50*"0123456789")01234\0'
./unix-stream '(50*"0123456789")012345\0'
./unix-stream '(50*"0123456789")0123456\0'
./unix-stream '(50*"0123456789")01234567\0'
./unix-stream '(50*"0123456789")012345678\0'
./unix-stream '(50*"0123456789")0123456789\0'
./unix-stream '(51*"0123456789")0\0'
./unix-stream '(51*"0123456789")01\0'
./unix-stream '(51*"0123456789")012\0'
./unix-stream '(51*"0123456789")0123\0'
./unix-stream '(51*"0123456789")01234\0'
./unix-stream '(51*"0123456789")012345\0'
./unix-stream '(51*"0123456789")0123456\0'
./unix-stream '(51*"0123456789")01234567\0'
./unix-stream '(51*"0123456789")012345678\0'
./unix-stream '(51*"0123456789")0123456789\0'

./unix-stream -p '01234567\0'
./unix-stream -p '012345678\0'
./unix-stream -p '0123456789\0'
./unix-stream -p '01234567890\0'

./unix-stream -g 1024 '(25*"0123456789")012\0'
./unix-stream 'foo\0' 'foo\0' '(200*"b")\0'

./unix-stream -s '/etc/hosts\0'
./unix-stream -s '/etc\0'
./unix-stream -s '/\0'
./unix-stream -s '/foo\0'
./unix-stream -s '/foo/bar\0'
./unix-stream -s '\0'
./unix-stream -s 'foo\0'

