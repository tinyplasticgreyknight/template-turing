#ifndef H_APPLY
#define H_APPLY

#include "utils.h"
#include "machine.h"
#include "ruleset.h"

namespace Turing {
	template<class M, class R, bool smatch, bool cmatch> struct match_rule : public machine<typename M::cur_state, typename M::tape_left, typename M::cell, typename M::tape_right> {
	};

	template<class M, class R> struct match_rule<M, R, true, true> : public machine<typename R::dst_state, typename M::tape_left, typename R::dst_colour, typename M::tape_right> {
	};

	template<class M, class R> struct apply_rule : public match_rule<M, R, (M::cur_state::state_ == R::src_state::state_), (M::cell::colour_ == R::src_colour::colour_)> {
	};

	template<class M, class R, class RS> struct apply_rule<M, ruleset<R, RS> > : public apply_rule<apply_rule<M, R>, RS> {
	};

	template<class M, class R> struct apply_rule<M, ruleset<R, List::nil> > : public apply_rule<M, R> {
	};
}

#endif
