#include "test-helper.h"
#include "apply.h"
#include "rule.h"
#include "state.h"
#include "colour.h"
#include "machine.h"

using namespace Turing;

#define TEST(x) TestCases::add("apply", #x, x)

namespace test_apply {
	void identity(void) {
		assert_eq("<machine state=3, cell=r>", apply_rule<
			machine<state<3>, colour<'r'> >,
			rule<state<3>, colour<'r'>, state<3>, colour<'r'> >
			>::to_str() );
	}

	void not_applicable(void) {
		assert_eq("<machine state=3, cell=r>", apply_rule<
			machine<state<3>, colour<'r'> >,
			rule<state<4>, colour<'a'>, state<5>, colour<'b'> >
			>::to_str() );
	}

	void juststate(void) {
		assert_eq("<machine state=4, cell=r>", apply_rule<
			machine<state<3>, colour<'r'> >,
			rule<state<3>, colour<'r'>, state<4>, colour<'r'> >
			>::to_str() );
	}

	void justcolour(void) {
		assert_eq("<machine state=3, cell=g>", apply_rule<
			machine<state<3>, colour<'r'> >,
			rule<state<3>, colour<'r'>, state<3>, colour<'g'> >
			>::to_str() );
	}

	void change_both(void) {
		assert_eq("<machine state=4, cell=g>", apply_rule<
			machine<state<3>, colour<'r'> >,
			rule<state<3>, colour<'r'>, state<4>, colour<'g'> >
			>::to_str() );
	}

	void register_tests(void) {
		TEST(identity);
		TEST(not_applicable);
		TEST(juststate);
		TEST(justcolour);
		TEST(change_both);
	}
}
