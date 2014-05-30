#include <iostream>
#include "llist.h"
#include "rule.h"
#include "ruleset.h"
#include "state.h"
#include "colour.h"
#include "direction.h"
#include "apply.h"

using namespace Turing;

// states are measured with unsigned ints
// Turing::HALT is a special state
typedef state<5> InitialState;

// rules map from a (state, colour) to a (state, colour, direction)
// Turing::EMPTY is a special colour, the default value of tape cells
// direction can be Turing::go_left, Turing::go_right, or Turing::stay_put
// a ruleset is a linked-list of rules
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

// a machine has an initial state, a current tape cell, and the remaining tape cells are kept in two linked lists (left and right)
// the current head cell isn't on either of the lists, but will be pushed/popped as necessary when the head moves after a rule
// you can make one of the initial left/right tape sides List::nil to have a traditional one-sided Turing machine
// or have them both be List::infinite<EMPTY> for a two-way-infinite tape (computationally equivalent but easier to simulate with our representation)
typedef Turing::machine<
		InitialState, // machine state
		List::infinite<EMPTY>,  // tape going to the left
		EMPTY, // head cell
		List::infinite<EMPTY> // tape going to the right
	> Machine;


int main(void) {
	std::cout << "initial: " << Machine::to_str() << std::endl;

	// fully_apply_rule keeps applying a rule/ruleset until the HALT state is reached
	// you can use apply_rule to apply the rule/ruleset only once
	// rules in a ruleset are applied in turn
	std::cout << "final:   " << Turing::fully_apply_rule<Machine, Rules>::to_str() << std::endl;

	return 0;
}
