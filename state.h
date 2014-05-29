#ifndef H_STATE
#define H_STATE

#include "utils.h"
#include <string>
#include <sstream>

namespace Turing {
	template<unsigned int S> struct state {
		WITH_STATE(S)
		static std::string to_str(void) {
			std::stringstream ss;
			ss << state_;
			return ss.str();
		}
	};

	typedef state<0> HALT;
}

#endif
