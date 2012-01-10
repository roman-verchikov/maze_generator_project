#ifndef WALL_POSITION_T_H
#define WALL_POSITION_T_H

#include <utility>

#include "location_t.h"

class wall_position_t : public std::pair<location_t, location_t>
{
public:
    wall_position_t();
    wall_position_t(const location_t &loc1, const location_t &loc2);
};

#endif // WALL_POSITION_T_H
