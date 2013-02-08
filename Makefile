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

TARGETS = size const unix-stream
UTILOBJS = util.o errsym.o

all: $(TARGETS)

complete-clean: maintainer-clean
	rm -f configure config.h.in

maintainer-clean: clean
	rm -f .upd-*.args .upd-*.source .upd-*.target
	rm -f errsym.c const.c size.c
	rm -rf autom4te.cache
	rm -f config.status config.log
	rm -f config.h compile.sh link.sh

clean:
	rm -f *.o $(TARGETS)

configure: configure.ac
	./update-files configure -- configure.ac -- autoconf

config.h.in: configure.ac
	./update-files config.h.in -- configure.ac -- autoheader

config.status: configure
	if [ -f config.status ]; then \
	  ./config.status --recheck; \
	else \
	  ./configure --no-create; \
	fi

config.h compile.sh link.sh: config.status config.h.in compile.sh.in link.sh.in
	./config.status && \
	  touch config.h && \
	  chmod +x compile.sh && \
	  chmod +x link.sh

errsym.c: errsym.erb
	./update-files errsym.c -- errsym.erb -- sh -c 'erb errsym.erb > errsym.c'

size.c: size.erb
	./update-files size.c -- size.erb -- sh -c 'erb size.erb > size.c'

const.c: const.erb
	./update-files const.c -- const.erb -- sh -c 'erb const.erb > const.c'

util.o: util.c sockettest.h config.h compile.sh
	./compile.sh $< -o $@

errsym.o: errsym.c sockettest.h config.h compile.sh
	./compile.sh $< -o $@

size.o: size.c sockettest.h config.h compile.sh
	./compile.sh $< -o $@

const.o: const.c sockettest.h config.h compile.sh
	./compile.sh $< -o $@

unix-stream.o: unix-stream.c sockettest.h config.h compile.sh
	./compile.sh $< -o $@

size: size.o link.sh
	./link.sh size.o -o $@

const: const.o link.sh
	./link.sh const.o -o $@

unix-stream: unix-stream.o $(UTILOBJS) link.sh
	./link.sh unix-stream.o $(UTILOBJS) -o $@

results.html : table-result.erb \
  results/linux.txt \
  results/freebsd.txt \
  results/netbsd.txt \
  results/openbsd.txt \
  results/dragonfly.txt \
  results/miros.txt \
  results/sunos.txt \
  results/cygwin.txt
	erb table-result.erb > results.html
