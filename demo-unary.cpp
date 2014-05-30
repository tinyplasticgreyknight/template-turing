#include "demo.h"
#include <iostream>

typedef Turing::machine<S(5), INFTAPE, Turing::EMPTY, INFTAPE> Machine;

typedef RULES(
	      RULE(S(5), Turing::EMPTY, S(4), C('!'), Turing::go_left),
	      RULES(
		    RULE(S(4), Turing::EMPTY, S(3), C('!'), Turing::go_left),
		    RULES(
			  RULE(S(2), Turing::EMPTY, S(1), C('!'), Turing::go_left),
			  RULES(
				RULE(S(3), Turing::EMPTY, S(2), C('!'), Turing::go_left),
				RULES(
				      RULE(S(1), Turing::EMPTY, Turing::HALT, C('!'), Turing::stay_put),
				      RULES0
				      )
				)
			  )
		    )
	      ) Rules;

int main(void) {
	std::cout << Machine::to_str() << std::endl;
	std::cout << Turing::fully_apply_rule<Machine, Rules>::to_str() << std::endl;
	return 0;
}
