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

TARGETS = obj/size obj/const obj/errmsg obj/errnum obj/errdup obj/errtest obj/unix-stream obj/unix-dgram
UTILOBJS = obj/util.o obj/genutil.o

all: $(TARGETS)

complete-clean: maintainer-clean
	rm -f configure obj/config.h.in

maintainer-clean: clean
	rm -f .upd-*.args .upd-*.source .upd-*.target
	rm -f obj/.upd-*.args obj/.upd-*.source obj/.upd-*.target
	rm -f obj/genutil.c obj/const.c obj/size.c
	rm -rf autom4te.cache
	rm -f config.status config.log
	rm -f obj/config.h compile.sh link.sh

clean:
	rm -f obj/*.o $(TARGETS)

configure: configure.ac
	./update-files configure -- configure.ac -- autoconf

obj/config.h.in: configure.ac
	./update-files obj/config.h.in -- configure.ac -- autoheader

config.status: configure
	if [ -f config.status ]; then \
	  ./config.status --recheck; \
	else \
	  ./configure --no-create; \
	fi

obj/config.h obj/includes.h compile.sh link.sh: config.status obj/config.h.in src/includes.h.in compile.sh.in link.sh.in
	./config.status && \
	  touch obj/config.h

obj/genutil.c: src/genutil.erb util.rb errno.txt
	./update-files obj/genutil.c -- src/genutil.erb util.rb errno.txt -- \
	  sh -c 'erb -r ./util.rb src/genutil.erb > obj/genutil.c'

obj/size.c: src/size.erb
	./update-files obj/size.c -- src/size.erb -- sh -c 'erb src/size.erb > obj/size.c'

obj/const.c: src/const.erb
	./update-files obj/const.c -- src/const.erb -- sh -c 'erb src/const.erb > obj/const.c'

obj/util.o: src/util.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/genutil.o: obj/genutil.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/size.o: obj/size.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/const.o: obj/const.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/errmsg.o: src/errmsg.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/errnum.o: src/errnum.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/errdup.o: src/errdup.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/errtest.o: src/errtest.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/unix-stream.o: src/unix-stream.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/unix-dgram.o: src/unix-dgram.c src/sockettest.h obj/config.h obj/includes.h compile.sh
	sh ./compile.sh $< -o $@

obj/size: obj/size.o link.sh
	sh ./link.sh obj/size.o -o $@

obj/const: obj/const.o link.sh
	sh ./link.sh obj/const.o -o $@

obj/errmsg: obj/errmsg.o $(UTILOBJS) link.sh
	sh ./link.sh obj/errmsg.o $(UTILOBJS) -o $@

obj/errnum: obj/errnum.o link.sh
	sh ./link.sh obj/errnum.o $(UTILOBJS) -o $@

obj/errdup: obj/errdup.o link.sh
	sh ./link.sh obj/errdup.o $(UTILOBJS) -o $@

obj/errtest: obj/errtest.o $(UTILOBJS) link.sh
	sh ./link.sh obj/errtest.o $(UTILOBJS) -o $@

obj/unix-stream: obj/unix-stream.o $(UTILOBJS) link.sh
	sh ./link.sh obj/unix-stream.o $(UTILOBJS) -o $@

obj/unix-dgram: obj/unix-dgram.o $(UTILOBJS) link.sh
	sh ./link.sh obj/unix-dgram.o $(UTILOBJS) -o $@

results.html : table-result.erb \
  results/cygwin.txt \
  results/darwin.txt \
  results/debian-kfreebsd.txt \
  results/dragonfly.txt \
  results/freebsd.txt \
  results/haiku.txt \
  results/hurd.txt \
  results/linux-arm.txt \
  results/linux.txt \
  results/minix.txt \
  results/miros.txt \
  results/netbsd.txt \
  results/openbsd51.txt \
  results/openbsd52.txt \
  results/sunos.txt
	erb table-result.erb > results.html
