#include "llist.h"
#include "rule.h"
#include "ruleset.h"
#include "state.h"
#include "colour.h"
#include "direction.h"
#include "apply.h"

#define S(x) Turing::state<x>
#define C(x) Turing::colour<x>
#define RULE(c0, s0, c1, s1, d) Turing::rule<c0, s0, c1, s1, d>

#define RULES0 List::nil
#define RULES(R1, R2) Turing::ruleset<R1, R2>

#define NILTAPE() List::nil
#define INFTAPE List::infinite<Turing::EMPTY>

#define MACHINE_(INIT_STATE, TAPE_LEFT, CELL, TAPE_RIGHT) Turing::machine<INIT_STATE, TAPE_LEFT, CELL, TAPE_RIGHT>
#define MACHINE_INF_R(INIT_STATE, TAPE_RIGHT) Turing::move_head<MACHINE_(INIT_STATE, INFTAPE, Turing::EMPTY, TAPE_RIGHT), Turing::go_right>
#define MACHINE0(INIT_STATE) MACHINE_INF_R(INIT_STATE, INFTAPE)
#define MACHINE_HALFINF(INIT_STATE, TAPE_RIGHT) Turing::move_head<MACHINE_(INIT_STATE, NILTAPE, Turing::EMPTY, TAPE_RIGHT), Turing::go_right>
