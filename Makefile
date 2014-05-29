CC=g++
CFLAGS=-std=c++11

test: llist-test state-test colour-test

llist-test: llist.h state.h utils.h llist-test.cpp
	$(CC) $(CFLAGS) $+ -o $@
	./$@

state-test: state.h utils.h state-test.cpp
	$(CC) $(CFLAGS) $+ -o $@
	./$@

colour-test: colour.h utils.h colour-test.cpp
	$(CC) $(CFLAGS) $+ -o $@
	./$@
