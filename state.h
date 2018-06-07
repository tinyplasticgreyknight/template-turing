#ifndef H_STATE
#define H_STATE

#include <string>
#include <sstream>

namespace Turing {
	typedef struct s_halt {
		static const unsigned int state_ = static_cast<unsigned int>(-1);
		static std::string to_str(void) { return "H"; }
	} HALT;

	template<unsigned int S> struct state {
		static const unsigned int state_ = S;

		static std::string to_str(void) {
			std::stringstream ss;
			ss << state_;
			return ss.str();
		}
	};
}

#endif
