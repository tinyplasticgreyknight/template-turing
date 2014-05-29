#include "test-helper.h"
#include "machine.h"
#include "state.h"
#include "colour.h"

using namespace Turing;

void blank(void) {
	assert_eq(0, (machine<HALT, EMPTY>::cur_state::state_) );
	assert_eq(' ', (machine<HALT, EMPTY>::cell::colour_) );
}

void juststate(void) {
	assert_eq(3, (machine<state<3>, EMPTY>::cur_state::state_) );
	assert_eq(' ', (machine<state<3>, EMPTY>::cell::colour_) );
}

void justcolour(void) {
	assert_eq(0, (machine<HALT, colour<'r'> >::cur_state::state_) );
	assert_eq('r', (machine<HALT, colour<'r'> >::cell::colour_) );
}

void bothfields(void) {
	assert_eq(3, (machine<state<3>, colour<'r'> >::cur_state::state_) );
	assert_eq('r', (machine<state<3>, colour<'r'> >::cell::colour_) );
}

void tostring(void) {
	assert_eq("<machine state=3, cell=r>", (machine<state<3>, colour<'r'>>::to_str()));
}

#define TEST(x) TestCases::add("machine", #x, x)

void register_tests_machine(void) {
	TEST(blank);
	TEST(juststate);
	TEST(justcolour);
	TEST(bothfields);
	TEST(tostring);
}
