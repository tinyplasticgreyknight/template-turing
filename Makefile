CC=g++
CFLAGS=-std=c++11 -I.
TESTFILES=$(shell find tests -iname 'test-*.cpp')
DEMOFILES=$(shell find . -iname 'demo-*.cpp')
HDRFILES=$(shell find . -maxdepth 1 -iname '*.h')
TESTEXE=bin/runtests
DEMOEXE=$(addprefix bin/, $(notdir $(basename $(DEMOFILES))) )

all: demos

demos: $(DEMOEXE)

bin/demo-%: demo-%.cpp $(ALLFILES)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm bin/*

spotless: clean
	-rm *~

test: $(TESTEXE)
	./$(TESTEXE)

$(TESTEXE): $(HDRFILES) $(TESTFILES)
	$(CC) $(CFLAGS) -o $@ tests/test.cpp $(TESTFILES)
