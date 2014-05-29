#include "test-helper.h"
#include "tests-all.h"
#include <iostream>

std::vector<Testcase> TestCases::cases;

int test_ok(unsigned int num_failed, unsigned int num_executed) {
	std::cout << "Executed: " << num_executed << std::endl;
	std::cout << "Passed:   " << (num_executed - num_failed) << std::endl;
	std::cout << "Failed:   " << num_failed << std::endl;
	if(num_failed == 0) {
		std::cout << "Everything is okay." << std::endl;
		return 0;
	} else {
		return 1;
	}
}

int main(void) {
	unsigned int num_failed=0, num_executed=0;

	register_tests();

	TestCases::run(num_failed, num_executed, std::cout);

	return test_ok(num_failed, num_executed);
}
