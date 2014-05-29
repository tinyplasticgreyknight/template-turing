#include "test-helper.h"
#include "state.h"

using namespace Turing;

#define TEST(x) TestCases::add("state", #x, x)

namespace test_state {
	void value3(void) {
		assert_eq(3, state<3>::state_ );
	}
	void halt(void) {
		assert_eq(0, HALT::state_ );
	}
	void value4(void) {
		assert_eq(4, state<4>::state_ );
	}

	void register_tests(void) {
		TEST(value3);
		TEST(halt);
		TEST(value4);
	}
}
