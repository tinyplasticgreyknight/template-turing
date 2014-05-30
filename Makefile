CC=g++
CFLAGS=-std=c++11
TESTFILES=$(shell find . -iname 'test-*.cpp')
DEMOFILES=$(shell find . -iname 'demo-*.cpp')
ALLFILES=$(shell find . -iname '*.h' -or -iname '*.cpp')
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

$(TESTEXE): $(ALLFILES)
	$(CC) $(CFLAGS) -o $@ test.cpp $(TESTFILES)
