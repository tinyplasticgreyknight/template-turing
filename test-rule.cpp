#include "test-helper.h"
#include "rule.h"
#include "state.h"
#include "colour.h"

using namespace Turing;

#define TEST(x) TestCases::add("rule", #x, x)

namespace test_rule {
	void halted(void) {
		assert_eq("<rule 0   -- 0  >", rule<HALT, EMPTY, HALT, EMPTY>::to_str());
	}

	void complex(void) {
		assert_eq("<rule 2 r -- 3 g>", rule<state<2>, colour<'r'>, state<3>, colour<'g'>>::to_str());
	}

	void register_tests(void) {
		TEST(halted);
		TEST(complex);
	}
}
