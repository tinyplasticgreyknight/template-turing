CC=g++
CFLAGS=-std=c++11
TESTFILES=$(shell find . -iname 'test-*.cpp')
TESTEXE=runtests

clean:
	-rm $(TESTEXE)

spotless: clean
	-rm *~

test: $(TESTEXE)
	./$(TESTEXE)

$(TESTEXE): $(TESTFILES)
	$(CC) $(CFLAGS) test.cpp $(TESTFILES) -o $@
