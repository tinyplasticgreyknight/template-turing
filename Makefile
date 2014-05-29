CC=g++
CFLAGS=-std=c++11
TESTFILES=$(shell find . -iname 'test-*.cpp')
ALLFILES=$(shell find . -iname '*.h' -or -iname '*.cpp')
TESTEXE=runtests

all: test

clean:
	-rm $(TESTEXE)

spotless: clean
	-rm *~

test: $(TESTEXE)
	./$(TESTEXE)

$(TESTEXE): $(ALLFILES)
	$(CC) $(CFLAGS) test.cpp $(TESTFILES) -o $@
