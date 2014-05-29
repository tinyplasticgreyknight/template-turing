#ifndef H_MACHINE
#define H_MACHINE

#include "utils.h"
#include "llist.h"

#include <string>
#include <sstream>

namespace Turing {
	template<class S, class TL, class C, class TR> struct machine {
		typedef S cur_state;
		typedef TL tape_left;
		typedef C cell;
		typedef TR tape_right;

		static std::string to_str(void) {
			return "<machine state=" + cur_state::to_str() + ", cell=" + cell::to_str() + ", tape-left=" + tape_left::to_str() + ", tape-right=" + tape_right::to_str() + ">";
		}
	};
}

#endif
