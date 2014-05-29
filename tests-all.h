#include "test-llist.h"
#include "test-state.h"
#include "test-colour.h"

void register_tests(void) {
	register_tests_llist();
	register_tests_state();
	register_tests_colour();
}
