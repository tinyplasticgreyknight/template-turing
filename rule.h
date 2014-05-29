#ifndef H_RULE
#define H_RULE

#include "utils.h"
#include <string>
#include <sstream>

namespace Turing {
	template<class S0, class C0, class S1, class C1> struct rule {
		typedef S0 src_state;
		typedef C0 src_colour;
		typedef S1 dst_state;
		typedef C1 dst_colour;

		static std::string to_str(void) {
			return "<rule " + src_state::to_str() + " " + src_colour::to_str() + " -- " + dst_state::to_str() + " " + dst_colour::to_str() + ">";
		}
	};
}

#endif
