#include "llist.h"
#include "state.h"

#include <iostream>
#include <cassert>

using namespace Turing;
using namespace List;

int main(void) {
	assert(3 == state<3>::state_);
	assert(3 == (cons<state<3>, nil>::car::state_) );
	assert(4 == (cons<state<3>, cons<state<4>, nil> >::cdr::car::state_) );

	std::cout << "Everything is okay." << std::endl;
	return 0;
}
