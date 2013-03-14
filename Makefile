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

TARGETS = build/size \
	  build/const \
	  build/errmsg \
	  build/errnum \
	  build/errdup \
	  build/errtest \
	  build/ipv4-stream \
	  build/unix-stream \
	  build/unix-dgram \
	  build/unix-accept-after-close

UTILOBJS = build/util.o \
	   build/genutil.o

all: $(TARGETS)

complete-clean:
	rm -f build/* build/.upd-*
	rm -f configure config.log config.status
	rm -rf autom4te.cache

maintainer-clean: distclean
	rm -f build/.upd-*.args build/.upd-*.source build/.upd-*.target
	rm -f build/genutil.c build/const.c build/size.c
	rm -rf autom4te.cache

distclean: clean
	rm -f config.log config.status
	rm -f build/config.h build/includes.h
	rm -f build/compile.sh build/link.sh

clean:
	rm -f build/*.o $(TARGETS)

clean-old:
	rm -rf obj
	rm -f compile.sh config.h includes.h link.sh
	rm -f *.o
	rm -f const errmsg errnum errdup errtest size ipv4-stream unix-dgram unix-stream

configure: configure.ac
	./tool/update-files -b build/.upd configure -- configure.ac -- autoconf

build/config.h.in: configure.ac
	./tool/update-files build/config.h.in -- configure.ac -- autoheader

config.status: configure
	if [ -f config.status ]; then \
	  ./config.status --recheck; \
	else \
	  ./configure --no-create; \
	fi

build/config.h build/includes.h build/compile.sh build/link.sh: build/stamp-h
build/stamp-h: config.status build/config.h.in src/includes.h.in src/compile.sh.in src/link.sh.in
	./config.status
	echo > build/stamp-h

build/genutil.c: src/genutil.erb src/util.rb src/errno.txt
	./tool/update-files build/genutil.c -- src/genutil.erb src/util.rb src/errno.txt -- \
	  sh -c 'erb -r ./src/util.rb src/genutil.erb > build/genutil.c'

build/size.c: src/size.erb
	./tool/update-files build/size.c -- src/size.erb -- sh -c 'erb src/size.erb > build/size.c'

build/const.c: src/const.erb
	./tool/update-files build/const.c -- src/const.erb -- sh -c 'erb src/const.erb > build/const.c'

build/util.o: build/compile.sh; sh build/compile.sh src/util.c -o $@
build/genutil.o: build/compile.sh; sh build/compile.sh build/genutil.c -o $@
build/size.o: build/compile.sh; sh build/compile.sh build/size.c -o $@
build/const.o: build/compile.sh; sh build/compile.sh build/const.c -o $@
build/errmsg.o: build/compile.sh; sh build/compile.sh src/errmsg.c -o $@
build/errnum.o: build/compile.sh; sh build/compile.sh src/errnum.c -o $@
build/errdup.o: build/compile.sh; sh build/compile.sh src/errdup.c -o $@
build/errtest.o: build/compile.sh; sh build/compile.sh src/errtest.c -o $@
build/ipv4-stream.o: build/compile.sh; sh build/compile.sh src/ipv4-stream.c -o $@
build/unix-stream.o: build/compile.sh; sh build/compile.sh src/unix-stream.c -o $@
build/unix-dgram.o: build/compile.sh; sh build/compile.sh src/unix-dgram.c -o $@
build/unix-accept-after-close.o: build/compile.sh; sh build/compile.sh src/unix-accept-after-close.c -o $@

build/size: build/size.o build/link.sh
	sh build/link.sh build/size.o -o $@

build/const: build/const.o build/link.sh
	sh build/link.sh build/const.o -o $@

build/errmsg: build/errmsg.o $(UTILOBJS) build/link.sh
	sh build/link.sh build/errmsg.o $(UTILOBJS) -o $@

build/errnum: build/errnum.o build/link.sh
	sh build/link.sh build/errnum.o $(UTILOBJS) -o $@

build/errdup: build/errdup.o build/link.sh
	sh build/link.sh build/errdup.o $(UTILOBJS) -o $@

build/errtest: build/errtest.o $(UTILOBJS) build/link.sh
	sh build/link.sh build/errtest.o $(UTILOBJS) -o $@

build/ipv4-stream: build/ipv4-stream.o $(UTILOBJS) build/link.sh
	sh build/link.sh build/ipv4-stream.o $(UTILOBJS) -o $@

build/unix-stream: build/unix-stream.o $(UTILOBJS) build/link.sh
	sh build/link.sh build/unix-stream.o $(UTILOBJS) -o $@

build/unix-dgram: build/unix-dgram.o $(UTILOBJS) build/link.sh
	sh build/link.sh build/unix-dgram.o $(UTILOBJS) -o $@

build/unix-accept-after-close: build/unix-accept-after-close.o $(UTILOBJS) build/link.sh
	sh build/link.sh build/unix-accept-after-close.o $(UTILOBJS) -o $@

results/index.html : src/table-result.erb \
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
	erb src/table-result.erb > results/index.html

# gcc -MM -Ibuild -Isrc src/*.c build/*.c | sed 's/^[^ ]/build\/&/' 
build/errdup.o: src/errdup.c src/sockettest.h build/config.h build/includes.h
build/errmsg.o: src/errmsg.c src/sockettest.h build/config.h build/includes.h
build/errnum.o: src/errnum.c src/sockettest.h build/config.h build/includes.h
build/errtest.o: src/errtest.c src/sockettest.h build/config.h build/includes.h
build/ipv4-stream.o: src/ipv4-stream.c src/sockettest.h build/config.h \
 build/includes.h
build/unix-accept-after-close.o: src/unix-accept-after-close.c src/sockettest.h \
 build/config.h build/includes.h
build/unix-dgram.o: src/unix-dgram.c src/sockettest.h build/config.h \
 build/includes.h
build/unix-stream.o: src/unix-stream.c src/sockettest.h build/config.h \
 build/includes.h
build/util.o: src/util.c src/sockettest.h build/config.h build/includes.h
build/const.o: build/const.c src/sockettest.h build/config.h build/includes.h
build/genutil.o: build/genutil.c src/sockettest.h build/config.h \
 build/includes.h
build/size.o: build/size.c src/sockettest.h build/config.h build/includes.h
