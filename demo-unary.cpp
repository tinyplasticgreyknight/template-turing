#include "llist.h"
#include "rule.h"
#include "ruleset.h"
#include "state.h"
#include "colour.h"
#include "direction.h"
#include "apply.h"

#include <iostream>

using namespace Turing;

typedef state<5> InitialState;

typedef ruleset<
		rule<state<4>, EMPTY, state<3>, colour<'1'>, go_left>,
		ruleset<
		rule<state<3>, EMPTY, state<2>, colour<'1'>, go_left>,
		ruleset<
		rule<state<2>, EMPTY, state<1>, colour<'1'>, go_left>,
		ruleset<
		rule<state<5>, EMPTY, state<4>, colour<'1'>, go_left>,
		ruleset<
		rule<state<1>, EMPTY, HALT, colour<'1'>, stay_put>,
		List::nil> > > > >
	Rules;

typedef Turing::machine<
		InitialState, // machine state
		List::infinite<EMPTY>,  // tape going to the left
		EMPTY, // head cell
		List::infinite<EMPTY> // tape going to the right
	> Machine;

int main(void) {
	std::cout << "initial: " << Machine::to_str() << std::endl;
	std::cout << "final:   " << Turing::fully_apply_rule<Machine, Rules>::to_str() << std::endl;
	return 0;
}
