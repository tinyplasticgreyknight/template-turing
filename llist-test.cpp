#include "llist.h"
#include "state.h"
#include "test-helper.h"

using namespace Turing;
using namespace List;

int main(void) {
	assert_eq(3, (cons<state<3>, nil>::car::state_) );
	assert_eq(4, (cons<state<3>, cons<state<4>, nil> >::cdr::car::state_) );
	assert_eq("NIL", nil::to_str() );
	assert_eq("(NIL . NIL)", cons<nil, nil>::to_str() );
	assert_eq("(3 . NIL)", cons<state<3>, nil>::to_str() );
	assert_eq("(NIL . 4)", cons<nil, state<4> >::to_str() );
	assert_eq("(3 . (4 . NIL))", (cons<state<3>, cons<state<4>, nil> >::to_str()) );

	return test_ok();
}
