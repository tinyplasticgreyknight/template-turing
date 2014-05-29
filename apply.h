#ifndef H_APPLY
#define H_APPLY

#include "utils.h"
#include "machine.h"

namespace Turing {
	template<class M, class R, bool smatch, bool cmatch> struct match_rule : public machine<typename M::cur_state, typename M::cell> {
	};

	template<class M, class R> struct match_rule<M, R, true, true> : public machine<typename R::dst_state, typename R::dst_colour> {
	};

	template<class M, class R> struct apply_rule : public match_rule<M, R, (M::cur_state::state_ == R::src_state::state_), (M::cell::colour_ == R::src_colour::colour_)> {
	};
}

#endif
