#include <string>
#include <cassert>
#include <iostream>

int test_ok(void) {
	std::cout << "Everything is okay." << std::endl;
	return 0;
}

template<class A, class B>
void assert_typeeq(A a, B b, std::string message="") {
	std::cout << "Types are not equal: " << message << std::endl;
	assert(0);
}

template<class A>
void assert_typeeq(A a, A b, std::string message="") {
	return; // ok
}

template<class A, class B>
void assert_eq(A a, B b, std::string message="") {
	if(a == b) return;
	std::cout << "Not equal: " << message << std::endl;
	std::cout << "\tA: " << a << std::endl;
	std::cout << "\tB: " << b << std::endl;
	assert(0);
}
