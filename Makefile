CC=g++
CFLAGS=-std=c++11

test: llist-test

llist-test: llist.h state.h utils.h llist-test.cpp
	$(CC) $(CFLAGS) $+ -o $@
	./llist-test
