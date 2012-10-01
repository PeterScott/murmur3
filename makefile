CFLAGS = -O3 -Wall

all: example
example: example.o murmur3.o

clean:
	rm -rf example *.o
