#include <iostream>
#include "llist.h"
#include "rule.h"
#include "ruleset.h"
#include "state.h"
#include "colour.h"
#include "direction.h"
#include "apply.h"

using namespace Turing;

// this is the 7-state 4-colour Universal Turing Machine discovered by Marvin Minsky in 1962.
typedef state<1> InitialState;

typedef ruleset<
		rule<state<1>, colour<'A'>, state<5>, colour<'B'>, go_left>,
		ruleset<
		rule<state<1>, colour<'B'>, state<2>, EMPTY, go_left>,
		ruleset<
		rule<state<1>, colour<'C'>, state<1>, colour<'A'>, go_right>,
		ruleset<
		rule<state<1>, EMPTY, state<1>, colour<'B'>, go_right>,
		ruleset<

		rule<state<2>, colour<'A'>, state<2>, colour<'C'>, go_left>,
		ruleset<
		rule<state<2>, colour<'B'>, state<2>, EMPTY, go_left>,
		ruleset<
		rule<state<2>, colour<'C'>, state<1>, colour<'A'>, go_right>,
		ruleset<
		rule<state<2>, EMPTY, state<2>, EMPTY, go_left>,
		ruleset<

		rule<state<3>, colour<'A'>, state<3>, colour<'C'>, go_right>,
		ruleset<
		rule<state<3>, colour<'B'>, state<3>, colour<'B'>, go_right>,
		ruleset<
		rule<state<3>, colour<'C'>, state<3>, colour<'A'>, go_right>,
		ruleset<
		rule<state<3>, EMPTY, state<5>, colour<'B'>, go_left>,
		ruleset<

		rule<state<4>, colour<'A'>, state<4>, colour<'C'>, go_right>,
		ruleset<
		rule<state<4>, colour<'B'>, state<4>, colour<'B'>, go_right>,
		ruleset<
		rule<state<4>, colour<'C'>, state<4>, colour<'A'>, go_right>,
		ruleset<
		rule<state<4>, EMPTY, state<5>, colour<'A'>, go_left>,
		ruleset<

		rule<state<5>, colour<'A'>, state<6>, colour<'C'>, go_left>,
		ruleset<
		rule<state<5>, colour<'B'>, state<5>, colour<'B'>, go_left>,
		ruleset<
		rule<state<5>, colour<'C'>, state<5>, colour<'A'>, go_left>,
		ruleset<
		rule<state<5>, EMPTY, HALT, EMPTY, stay_put>,
		ruleset<

		rule<state<6>, colour<'A'>, state<6>, colour<'C'>, go_left>,
		ruleset<
		rule<state<6>, colour<'B'>, state<6>, colour<'B'>, go_left>,
		ruleset<
		rule<state<6>, colour<'C'>, state<7>, colour<'C'>, go_left>,
		ruleset<
		rule<state<6>, EMPTY, state<3>, colour<'B'>, go_right>,
		ruleset<

		rule<state<7>, colour<'A'>, state<1>, EMPTY, go_right>,
		ruleset<
		rule<state<7>, colour<'B'>, state<7>, EMPTY, go_right>,
		ruleset<
		rule<state<7>, colour<'C'>, state<7>, colour<'C'>, go_right>,
		ruleset<
		rule<state<7>, EMPTY, state<4>, colour<'B'>, go_right>,

		List::nil> > > > > > > > > > > > > > > > > > > > > > > > > > > >
	Rules;

typedef Turing::machine<
		InitialState,
		List::infinite<EMPTY>,
		colour<'A'>,
		List::infinite<EMPTY>
	> Machine;


int main(void) {
	std::cout << "initial: " << Machine::to_str() << std::endl;
	std::cout << "final:   " << Turing::fully_apply_rule<Machine, Rules>::to_str() << std::endl;

	return 0;
}
