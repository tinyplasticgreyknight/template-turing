#ifndef H_COLOUR
#define H_COLOUR

#include "utils.h"
#include <string>
#include <sstream>

namespace Turing {
	template<char c> struct colour {
		WITH_COLOUR(c)
		static std::string to_str(void) {
			std::stringstream ss;
			ss << colour_;
			return ss.str();
		}
	};

	typedef colour<' '> EMPTY;
}

#endif
