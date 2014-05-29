#ifndef H_RULESET
#define H_RULESET

#include "utils.h"
#include <string>
#include <sstream>
#include "llist.h"

namespace Turing {
	template<class A, class D> struct ruleset : public List::cons<A, D> {};
}

#endif
