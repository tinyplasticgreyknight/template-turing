#include "test-colour.h"
#include "colour.h"
#include "colour.h"

using namespace Turing;

void valueR(void) {
	assert_eq('r', colour<'r'>::colour_ );
}
void empty(void) {
	assert_eq(' ', EMPTY::colour_ );
}
void valueG(void) {
	assert_eq('g', colour<'g'>::colour_ );
}

#define TEST(x) TestCases::add("colour", #x, x)

void register_tests_colour(void) {
	TEST(valueR);
	TEST(empty);
	TEST(valueG);
}
