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

# Create macOS Architecture Specific Binaries 
static_macos: murmur3.c murmur3.h
	$(CC) -fPIC -O3 -c murmur3.c -target x86_64-apple-macos10.12 -o murmur3-x86_64.o
	$(CC) -fPIC -O3 -c murmur3.c -target arm64-apple-macos11 -o murmur3-arm64.o
	$(AR) rcs libmurmur3-x86_64.a murmur3-x86_64.o
	$(AR) rcs libmurmur3-arm64.a murmur3-arm64.o
	lipo -create -output libmurmur3.a libmurmur3-x86_64.a libmurmur3-arm64.a
	
clean:
	rm -rf example *.o *.so *.a
