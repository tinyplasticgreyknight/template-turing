#ifndef H_TESTS_ALL
#define H_TESTS_ALL

#define DEFCAT(nm) namespace test_##nm{void register_tests(void);}
#define RUNCAT(nm) test_##nm::register_tests()

DEFCAT(llist);
DEFCAT(state);
DEFCAT(colour);
DEFCAT(machine);
DEFCAT(rule);
DEFCAT(apply);
DEFCAT(ruleset);

void register_tests(void) {
	RUNCAT(llist);
	RUNCAT(state);
	RUNCAT(colour);
	RUNCAT(machine);
	RUNCAT(rule);
	RUNCAT(apply);
	RUNCAT(ruleset);
}

#endif
