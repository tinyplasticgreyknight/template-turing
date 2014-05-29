#include "test-helper.h"
#include "machine.h"
#include "state.h"
#include "colour.h"
#include "llist.h"

using namespace Turing;
using namespace List;

#define TEST(x) TestCases::add("machine", #x, x)

namespace test_machine {
	void blank(void) {
		assert_eq(0, (machine<HALT, nil, EMPTY, nil>::cur_state::state_) );
		assert_eq('~', (machine<HALT, nil, EMPTY, nil>::cell::colour_) );
	}

	void juststate(void) {
		assert_eq(3, (machine<state<3>, nil, EMPTY, nil>::cur_state::state_) );
		assert_eq('~', (machine<state<3>, nil, EMPTY, nil>::cell::colour_) );
	}

	void justcolour(void) {
		assert_eq(0, (machine<HALT, nil, colour<'r'>, nil>::cur_state::state_) );
		assert_eq('r', (machine<HALT, nil, colour<'r'>, nil>::cell::colour_) );
	}

	void bothfields(void) {
		assert_eq(3, (machine<state<3>, nil, colour<'r'>, nil>::cur_state::state_) );
		assert_eq('r', (machine<state<3>, nil, colour<'r'>, nil>::cell::colour_) );
	}

	void tostring(void) {
		assert_eq("<machine state=3, cell=r, tape-left=NIL, tape-right=NIL>", (machine<state<3>, nil, colour<'r'>, nil>::to_str()));
	}

	void register_tests(void) {
		TEST(blank);
		TEST(juststate);
		TEST(justcolour);
		TEST(bothfields);
		TEST(tostring);
	}
}
