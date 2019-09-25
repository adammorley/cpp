CC=clang++
CFLAGS=-I. -g

all: test

clean:
	rm -f test *.o

test: test.cc linkedList.cc
	$(CC) -o test test.cc $(CFLAGS)


