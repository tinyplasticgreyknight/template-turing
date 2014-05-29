namespace List {
	struct nil;

	template<class A> struct mcar {
		typedef A car;
	};

	template<class D> struct mcdr {
		typedef D cdr;
	};

	template<class A, class D> struct cons : mcar<A>, mcdr<D> {
	};
}
