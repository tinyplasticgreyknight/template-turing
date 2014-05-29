#include "test-helper.h"
#include "apply.h"
#include "rule.h"
#include "ruleset.h"
#include "state.h"
#include "colour.h"
#include "direction.h"
#include "machine.h"

using namespace Turing;
using namespace List;

#define TEST(x) TestCases::add("apply", #x, x)

namespace test_apply {
	void identity(void) {
		assert_eq("<machine state=3, cell=r, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			rule<state<3>, colour<'r'>, state<3>, colour<'r'>, stay_put>
			>::to_str() );
	}

	void not_applicable(void) {
		assert_eq("<machine state=3, cell=r, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			rule<state<4>, colour<'a'>, state<5>, colour<'b'>, stay_put>
			>::to_str() );
	}

	void juststate(void) {
		assert_eq("<machine state=4, cell=r, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			rule<state<3>, colour<'r'>, state<4>, colour<'r'>, stay_put>
			>::to_str() );
	}

	void justcolour(void) {
		assert_eq("<machine state=3, cell=g, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			rule<state<3>, colour<'r'>, state<3>, colour<'g'>, stay_put>
			>::to_str() );
	}

	void change_both(void) {
		assert_eq("<machine state=4, cell=g, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			rule<state<3>, colour<'r'>, state<4>, colour<'g'>, stay_put>
			>::to_str() );
	}

	void justdir(void) {
		assert_eq("<machine state=3, cell=r, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			rule<state<3>, colour<'r'>, state<3>, colour<'r'>, go_left>
			>::to_str() );
	}

	void change_all(void) {
		assert_eq("<machine state=4, cell=g, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			rule<state<3>, colour<'r'>, state<4>, colour<'g'>, go_left>
			>::to_str() );
	}

	void ruleset_double(void) {
		assert_eq("<machine state=5, cell=b, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			ruleset<
				rule<state<3>, colour<'r'>, state<4>, colour<'g'>, stay_put>,
				ruleset<
					rule<state<4>, colour<'g'>, state<5>, colour<'b'>, stay_put>,
					List::nil
					>
				>
			>::to_str() );
	}

	void ruleset_order(void) {
		assert_eq("<machine state=4, cell=g, tape-left=NIL, tape-right=NIL>", apply_rule<
			machine<state<3>, nil, colour<'r'>, nil>,
			ruleset<
				rule<state<4>, colour<'g'>, state<5>, colour<'b'>, stay_put>,
				ruleset<
					rule<state<3>, colour<'r'>, state<4>, colour<'g'>, stay_put>,
					List::nil
					>
				>
			>::to_str() );
	}

	void register_tests(void) {
		TEST(identity);
		TEST(not_applicable);
		TEST(juststate);
		TEST(justcolour);
		TEST(change_both);
		TEST(justdir);
		TEST(change_all);
		TEST(ruleset_double);
		TEST(ruleset_order);
	}
}
