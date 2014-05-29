#include "test-helper.h"
#include "rule.h"
#include "state.h"
#include "colour.h"
#include "machine.h"

using namespace Turing;

void halted(void) {
	assert_eq("<rule 0   -- 0  >", rule<HALT, EMPTY, HALT, EMPTY>::to_str());
}

void complex(void) {
	assert_eq("<rule 2 r -- 3 g>", rule<state<2>, colour<'r'>, state<3>, colour<'g'>>::to_str());
}

#define TEST(x) TestCases::add("rule", #x, x)

void register_tests_rule(void) {
	TEST(halted);
	TEST(complex);
}
