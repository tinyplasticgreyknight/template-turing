#include "utils.h"

namespace Turing {
	template<char c> struct colour {
		WITH_COLOUR(c)
	};

	typedef colour<' '> EMPTY;
}
