#include "colour.h"
#include "test-helper.h"

using namespace Turing;

int main(void) {
	assert_eq('r', colour<'r'>::colour_);
	assert_eq(' ', EMPTY::colour_);
	assert_eq('g', colour<'g'>::colour_);

	return test_ok();
}
