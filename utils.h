#ifndef H_TTURING_UTILS
#define H_TTURING_UTILS

#include <string>
#include <sstream>

#define WITH_STATE(N) static const unsigned int state_ = N;
#define COPY_STATE(X) WITH_STATE(X::state_)

#define WITH_COLOUR(c) static const char colour_ = c;
#define COPY_COLOUR(X) WITH_COLOUR(X::colour_)

#define WITH_DEST_STATE(N) static const unsigned int state_dest = N;

#define WITH_DEST_COLOUR(c) static const char colour_dest = c;

#define WITH_HEAD_STEP(D) static const int step_ = D;

#endif
