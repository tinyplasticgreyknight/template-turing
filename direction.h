#ifndef H_DIRECTION
#define H_DIRECTION

#include "utils.h"

namespace Turing {
	struct stay_put {
		static std::string to_str(void) { return "-o-"; }
	};

	struct go_left {
		static std::string to_str(void) { return "<--"; }
	};

	struct go_right {
		static std::string to_str(void) { return "-->"; }
	};
}

#endif
