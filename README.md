# C++ Template Turing Machine
It's well-known that the C++ template language is Turing-complete, but I realised I'd never actually seen anybody implement a Turing Machine using it.  I decided to take that as a challenge, and here you see the results.

## Files
All the really significant templates are in the following files:

* `state.h` contains a trivial template for wrapping up `unsigned int`s to make a machine state.  Also defines `HALT`.
* `colour.h` is another trivial template that wraps `char`s: these represent the colour of the various tape cells.  `EMPTY` is defined here.
* `direction.h` defines three types: `go_left`, `go_right`, and `stay_put`.  These are used in `rule`s to tell the head which way to move.
* `llist.h` is a simple linked-list implementation.  Linked-lists are used to hold the tape cells as well as the ruleset.  This file also defines the `infinite<E>` type, which can be used to pretend you have an infinitely-long list of the same value (handy for the infinite extent of `EMPTY` cells on the end of a tape).
* `machine.h` defines a type for the current machine state.  The `machine<S, TL, C, TR>` type holds a current state `S`, the tape cell currently under the head (`C`), the tape cells to the left of that one (`TL`), and the tape cells to the right (`TR`).  Notice that `C` isn't on either list.  When the head moves, `C` is pushed onto one of these lists, and the next cell is popped from the other list.
* `rule.h` defines a type that represents one of the Turing Machine's update rules.  These have the form `rule<S0, C0, S1, C0, D>`, where (`S0`, `C0`) is the inital state and tape cell colour, while (`S1`, `C1`) is the resulting state/colour.  The direction `D` tells the head which way to move after updating the state and cell colour.
* `ruleset.h` defines the `ruleset` type, which is actually just a synonym for a `cons` from `llist.h`.
* `apply.h` contains the actual update algorithms.  `apply_rule<M, R>` takes a machine state `M` and a rule `R`, and tries to apply the rule.  If the rule is inapplicable, the machine state is unchanged.  You can also give `apply_rule` a ruleset in place of just a rule, in which case it will apply each rule in turn.  `move_head` takes care of moving to the next cell (or staying put) after a successful rule.  `fully_apply_rule<M, R>` takes a machine state and rule/ruleset, and keeps applying them until the machine state reaches `HALT`.

## Demos
Execute `make demos` to build some demo programs in the `bin` subdirectory.

* `demo-unary` is a very simple machine that prints a `1` symbol in the first five cells of its tape.
* `demo-minsky` is a 7-state 4-colour Universal Turing Machine (discovered by Marvin Minsky in 1962).

Of course, all the actual Turing Machine execution happens during compile time, so running the demo programs will merely print the initial and final states!

## Hacking
If you want to hack on this code, you might find the test cases in the `tests` subdirectory useful.  Run `make test` from the top-level directory to build and run the test suite.  As above, the distinction between "build" and "run" is a bit weird in this project.

Some things that would be nice to hack in:

* a prettier machine-state representation (particularly the tape)
* the possibility of printing out the intermediate machine states while reduction is proceeding, perhaps using compiler warnings as our printing medium?
* in particular, the above will help us cater for Turing Machines which don't actually terminate (in particular Alex Smith's UTM, which is bugging me)

The home repository is at <https://github.com/tinyplasticgreyknight/template-turing>

## Further Reading
Edward Rosten bears some of the blame for getting me interested in this sort of thing, thanks to his [template implementation of floating-point numbers](http://www.edwardrosten.com/code/fp_template.html).

Stuart Golodetz wrote some good articles on *Functional Programming Using C++ Templates* which you may like to read:

* [part 1](http://accu.org/index.php/journals/1422)
* [part 2](http://accu.org/index.php/journals/1616)

Here are some Turing-complete systems implemented in Haskell's typesystem.  As far as I can tell both of these need certain compiler extensions and Haskell's typesystem *isn't* Turing-complete by itself: I'm not sure what computational class the standard typesystem is.  I would welcome input from a Haskell expert on this.

* [Turing machine](http://www.lochan.org/keith/publications/undec.html) (needs hugs)
* [SK combinator calculus](http://www.haskell.org/haskellwiki/Type_SK) (needs GHC)

## Contact
* [e-mail](mailto:tinyplasticgreyknight@yahoo.com)
* google+: [Grey Knight](https://plus.google.com/u/0/116271131160818845979)
* irc: `GreyKnight` on freenode

