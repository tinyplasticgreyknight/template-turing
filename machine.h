#ifndef H_MACHINE
#define H_MACHINE

#include "utils.h"
#include "llist.h"

#include <string>
#include <sstream>

namespace Turing {
	template<class S, class C> struct machine {
		typedef S cur_state;
		typedef C cell;

		static std::string to_str(void) {
			return "<machine state=" + cur_state::to_str() + ", cell=" + cell::to_str() + ">";
		}
	};
}

#endif
