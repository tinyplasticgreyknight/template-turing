#include "rule.h"
#include "state.h"
#include "colour.h"
#include "test-helper.h"

using namespace Turing;

int main(void) {
	assert_eq(1,   rule<state<1>, colour<'A'>, state<2>, colour<'B'> >::src_state::state_);
	assert_eq('A', rule<state<1>, colour<'A'>, state<2>, colour<'B'> >::src_colour::colour_);
	assert_eq(2,   rule<state<1>, colour<'A'>, state<2>, colour<'B'> >::dst_state::state_);
	assert_eq('B', rule<state<1>, colour<'A'>, state<2>, colour<'B'> >::dst_colour::colour_);

	assert_eq("<rule 1 A -- 2 B>", rule<state<1>, colour<'A'>, state<2>, colour<'B'> >::to_str());

	return test_ok();
}
