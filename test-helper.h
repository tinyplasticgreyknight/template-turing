#ifndef H_TEST_HELPER
#define H_TEST_HELPER

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

template<class A, class B>
void assert_typeeq(A a, B b, std::string message="") {
	std::stringstream ss;
	ss << "Types are not equal: " << message;
	throw ss.str();
}

template<class A>
void assert_typeeq(A a, A b, std::string message="") {
	return; // ok
}

template<class A, class B>
void assert_eq(A a, B b, std::string message="") {
	if(a == b) return;
	std::stringstream ss;
	ss << "Not equal: " << message << std::endl;
	ss << "\tA: " << a << std::endl;
	ss << "\tB: " << b << std::endl;
	throw ss.str();
}

typedef void (*TestFunc)(void);

class Testcase {
public:
	TestFunc func;
	std::string category;
	std::string shortname;
	std::string name;

	Testcase(std::string category, std::string shortname, TestFunc func) {
		this->category = category;
		this->shortname = shortname;
		this->name = (category + "::" + shortname);
		this->func = func;
	}
};

class TestCases {
public:
	static std::vector<Testcase> cases;
public:
	static void add(std::string cat, std::string name, TestFunc func) {
		cases.emplace_back(cat, name, func);
	}

	static void add(Testcase test) {
		cases.push_back(test);
	}

	static void add(std::vector<Testcase> tests) {
		for(std::vector<Testcase>::const_iterator iter = tests.begin(); iter != tests.end(); iter++) {
			cases.push_back(*iter);
		}
	}

	static void run(unsigned int& num_failed, unsigned int& num_executed, std::ostream& output) {
		std::string result;
		for(std::vector<Testcase>::const_iterator iter = cases.begin(); iter != cases.end(); iter++) {
			result = "FAIL";
			try {
				(*(iter->func))();
				result = "ok  ";
			} catch(std::string& ex) {
				num_failed++;
			}
			output << result << " " << (iter->name) << std::endl;
			num_executed++;
		}
	}
};

#endif
