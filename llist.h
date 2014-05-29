#ifndef H_LLIST
#define H_LLIST

#include <string>

namespace List {
	struct nil {
		static std::string to_str(void) { return "NIL"; }
	};

	template<class A> struct mcar {
		typedef A car;
	};

	template<class D> struct mcdr {
		typedef D cdr;
	};

	template<class A, class D> struct cons : public mcar<A>, public mcdr<D> {
		static std::string to_str(void) {
			return "(" + A::to_str() + " . " + D::to_str() + ")";
		}
	};

	template<class E> struct infinite : public mcar<E>, public mcdr<infinite<E> > {
		static std::string to_str(void) {
			return "(" + E::to_str() + "...)";
		}
	};
}

#endif
