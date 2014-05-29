#include "test-helper.h"
#include "llist.h"
#include "state.h"

using namespace Turing;
using namespace List;

void extract_car(void) {
	assert_eq(3, (cons<state<3>, nil>::car::state_) );
}
void extract_cadr(void) {
	assert_eq(4, (cons<state<3>, cons<state<4>, nil> >::cdr::car::state_) );
}
void str_nil(void) {
	assert_eq("NIL", nil::to_str() );
}
void str_nilnil(void) {
	assert_eq("(NIL . NIL)", cons<nil, nil>::to_str() );
}
void str_justcar(void) {
	assert_eq("(3 . NIL)", cons<state<3>, nil>::to_str() );
}
void str_justcdr(void) {
	assert_eq("(NIL . 4)", cons<nil, state<4> >::to_str() );
}
void str_proper(void) {
	assert_eq("(3 . (4 . NIL))", (cons<state<3>, cons<state<4>, nil> >::to_str()) );
}

#define TEST(x) TestCases::add("llist", #x, x)

void register_tests_llist(void) {
	TEST(extract_car);
	TEST(extract_cadr);
	TEST(str_nil);
	TEST(str_nilnil);
	TEST(str_justcar);
	TEST(str_justcdr);
	TEST(str_proper);
}
