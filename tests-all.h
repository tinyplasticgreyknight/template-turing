extern void register_tests_llist(void);
extern void register_tests_state(void);
extern void register_tests_colour(void);
extern void register_tests_machine(void);

void register_tests(void) {
	register_tests_llist();
	register_tests_state();
	register_tests_colour();
	register_tests_machine();
}
