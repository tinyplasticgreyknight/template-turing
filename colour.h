#ifndef H_COLOUR
#define H_COLOUR

#include <string>
#include <sstream>

namespace Turing {
	template<char c> struct colour {
		static const char colour_ = c;

		static std::string to_str(void) {
			std::stringstream ss;
			ss << colour_;
			return ss.str();
		}
	};

	typedef colour<'~'> EMPTY;
}

#endif
