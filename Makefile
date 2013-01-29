CFLAGS = -g -Wall

all: size bind-getsockname

size: size.c

bind-getsockname: bind-getsockname.o util.o

bind-getsockname.o: bind-getsockname.c sockettest.h
util.o: util.c sockettest.h
