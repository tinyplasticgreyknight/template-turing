#ifndef H_TTURING_UTILS
#define H_TTURING_UTILS

#define WITH_STATE(N) static const unsigned int state_ = N;
#define COPY_STATE(X) WITH_STATE(X::state_)

#define WITH_COLOUR(C) static const unsigned int colour_ = C;
#define COPY_COLOUR(X) WITH_COLOUR(X::colour_)

#define WITH_DEST_STATE(N) static const unsigned int state_dest = N;

#define WITH_DEST_COLOUR(C) static const unsigned int colour_dest = C;

#define WITH_HEAD_STEP(D) static const int step_ = D;

#define WITH_TAPE_LEFT(T) static const

#endif
