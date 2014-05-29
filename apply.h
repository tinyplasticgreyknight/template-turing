#ifndef H_APPLY
#define H_APPLY

#include "utils.h"
#include "machine.h"
#include "ruleset.h"
#include "direction.h"

namespace Turing {
	template<class M, class D> struct move_head;
	template<class M> struct move_head<M, stay_put> : public machine<typename M::cur_state, typename M::tape_left, typename M::cell, typename M::tape_right> {
	};

	template<class M> struct move_head<M, go_left> : public machine<typename M::cur_state, typename M::tape_left::cdr, typename M::tape_left::car, List::cons<typename M::cell, typename M::tape_right> > {
	};

	template<class M> struct move_head<M, go_right> : public machine<typename M::cur_state, List::cons<typename M::cell, typename M::tape_left>, typename M::tape_right::car, typename M::tape_right::cdr> {
	};

	template<class M, class R, bool smatch, bool cmatch> struct match_rule : public move_head<M, stay_put> {
	};

	template<class M, class R> struct match_rule<M, R, true, true> : public move_head<machine<typename R::dst_state, typename M::tape_left, typename R::dst_colour, typename M::tape_right>, typename R::dir> {
	};

	template<class M, class R> struct apply_rule : public match_rule<M, R, (M::cur_state::state_ == R::src_state::state_), (M::cell::colour_ == R::src_colour::colour_)> {
	};

	template<class M, class R, class RS> struct apply_rule<M, ruleset<R, RS> > : public apply_rule<apply_rule<M, R>, RS> {
	};

	template<class M, class R> struct apply_rule<M, ruleset<R, List::nil> > : public apply_rule<M, R> {
	};
}

#endif
