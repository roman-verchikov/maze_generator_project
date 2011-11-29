#ifndef DIRECTION_T_H
#define DIRECTION_T_H

#if 1

#include <cstdlib>

class direction_t {
    public:
        enum {
            FIRST_DIRECTION,
            WEST = FIRST_DIRECTION,
            NORTH,
            EAST,
            SOUTH,
            NUM_DIRECTIONS
        };

        direction_t(int dir = FIRST_DIRECTION) : dir_(dir) {}

        direction_t operator ++ ()
        {
            return direction_t((++dir_) % NUM_DIRECTIONS);
        }

        operator int () {
            return dir_;
        }

        direction_t opposite() const {
            return (dir_ + 2) % NUM_DIRECTIONS;
        }

//        operator const int () {
//            return dir_;
//        }

        static direction_t random_direction()
        {
            return direction_t(rand() % NUM_DIRECTIONS);
        }

    private:
        int dir_;
};

#else

enum {
    FIRST_DIRECTION,
    WEST = FIRST_DIRECTION,
    NORTH,
    EAST,
    SOUTH,
    NUM_DIRECTIONS
};

#endif

#endif // DIRECTION_T_H
