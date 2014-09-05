CFLAGS = -O3 -Wall

.PHONY: all clean tests

all: example
example: example.o murmur3.o
tests: test.o murmur3.o
	$(CC) $^ -o $@
	./tests

clean:
	rm -rf example *.o
