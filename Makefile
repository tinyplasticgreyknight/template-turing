CC=g++
CFLAGS=-std=c++11

test: llist-test state-test colour-test
	./llist-test
	./state-test
	./colour-test


llist-test: llist-test.cpp test-helper.h llist.h state.h utils.h
	$(CC) $(CFLAGS) $+ -o $@

state-test: state-test.cpp test-helper.h state.h utils.h
	$(CC) $(CFLAGS) $+ -o $@

colour-test: colour-test.cpp test-helper.h colour.h utils.h
	$(CC) $(CFLAGS) $+ -o $@
