#!/bin/sh

set -v

uname -mrsv
./size
./unix-stream 'foo' './foo'
./unix-stream -ps '012345678'
./unix-stream -ps '0123456789'
./unix-stream -ps '01234567890'
./unix-stream -s /etc/hosts
./unix-stream -s /etc
./unix-stream -s /
./unix-stream -s /foo
./unix-stream -s /foo/bar
./unix-stream -s ''

