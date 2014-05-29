#include "test-helper.h"
#include "machine.h"
#include "state.h"
#include "colour.h"

using namespace Turing;

void blank(void) {
	assert_eq(0, (machine<HALT, EMPTY>::cur_state::state_) );
	assert_eq(' ', (machine<HALT, EMPTY>::cell::colour_) );
}

#define TEST(x) TestCases::add("machine", #x, x)

void register_tests_machine(void) {
	TEST(blank);
}
