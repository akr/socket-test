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
./unix-stream 'foo' './foo'
./unix-stream 'foo\0bar' './foo\0hoge'
./unix-stream -p '012345678'
./unix-stream -p '0123456789'
./unix-stream -p '01234567890'
./unix-stream '(25*"0123456789")012'
./unix-stream -g 1024 '(25*"0123456789")012'
./unix-stream '(25*"0123456789")0123'
./unix-stream '(25*"0123456789")01234'    
./unix-stream '(25*"0123456789")012345'
./unix-stream '(300*"./")a'      
./unix-stream 'foo' 'foo' '(200*"b")'
./unix-stream -s /etc/hosts
./unix-stream -s /etc
./unix-stream -s /
./unix-stream -s /foo
./unix-stream -s /foo/bar
./unix-stream -s ''
./unix-stream -s 'foo'
