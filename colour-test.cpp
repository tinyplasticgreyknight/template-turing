#include "colour.h"

#include <iostream>
#include <cassert>

using namespace Turing;

int main(void) {
	assert('r' == colour<'r'>::colour_);
	assert(' ' == EMPTY::colour_);
	assert('g' == colour<'g'>::colour_);

	std::cout << "Everything is okay." << std::endl;
	return 0;
}
