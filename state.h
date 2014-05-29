#include "utils.h"

namespace Turing {
	template<unsigned int S> struct state {
		WITH_STATE(S)
	};

	typedef state<0> HALT;
}
