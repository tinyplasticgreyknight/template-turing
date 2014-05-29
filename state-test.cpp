#include "state.h"

#include <iostream>
#include <cassert>

using namespace Turing;

int main(void) {
	assert(3 == state<3>::state_);
	assert(0 == HALT::state_);
	assert(4 == state<4>::state_);

	std::cout << "Everything is okay." << std::endl;
	return 0;
}
