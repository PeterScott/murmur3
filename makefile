CFLAGS = -O3 -Wall

.PHONY: all clean tests static

all: example
example: example.o murmur3.o
tests: test.o murmur3.o
	$(CC) $^ -o $@
	./tests

shared: murmur3.c murmur3.h
	$(CC) -fPIC -O3 -c murmur3.c
	$(CC) -shared -Wl,--export-dynamic murmur3.o -o libmurmur3.so

static: murmur3.c murmur3.h
	$(CC) -fPIC -O3 -c murmur3.c
	$(AR) rcs libmurmur3.a murmur3.o

clean:
	rm -rf example *.o *.so *.a
