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

all: Makefile2
	$(MAKE) -f Makefile2 all

clean:
	$(MAKE) -f Makefile2 clean

maintainer-clean:
	rm -f .update-*.src .update-*.blt
	rm -f Makefile2 config.h
	rm -f config.status config.log
	rm -rf autom4te.cache
	$(MAKE) -f Makefile2.in maintainer-clean

complete-clean: maintainer-clean
	rm -f configure config.h.in

Makefile2 config.h: configure Makefile2.in config.h.in
	./update-file-direct \
	  configure.ac \
	  Makefile2 \
	  sh -c 'if [ -f config.status ]; then ./config.status --recheck && ./config.status; else ./configure; fi'

configure: configure.ac
	./update-file-direct configure.ac configure autoconf

config.h.in: configure.ac
	./update-file-direct configure.ac config.h.in autoheader

.PHONY: results.html
tools: Makefile2
	$(MAKE) -f Makefile2 tools

.PHONY: results.html
results.html: Makefile2
	$(MAKE) -f Makefile2 results.html
