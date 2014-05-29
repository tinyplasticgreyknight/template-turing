#include "test-helper.h"
#include "colour.h"

using namespace Turing;

#define TEST(x) TestCases::add("colour", #x, x)

namespace test_colour {
	void valueR(void) {
		assert_eq('r', colour<'r'>::colour_ );
	}
	void empty(void) {
		assert_eq(' ', EMPTY::colour_ );
	}
	void valueG(void) {
		assert_eq('g', colour<'g'>::colour_ );
	}

	void register_tests(void) {
		TEST(valueR);
		TEST(empty);
		TEST(valueG);
	}
}
