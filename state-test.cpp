#include "state.h"
#include "test-helper.h"

using namespace Turing;

int main(void) {
	assert_eq(3, state<3>::state_);
	assert_eq(0, HALT::state_);
	assert_eq(4, state<4>::state_);

	return test_ok();
}
