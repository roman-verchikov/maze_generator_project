#include "wall_position_t.h"

wall_position_t::wall_position_t() {}

wall_position_t::wall_position_t(const location_t &loc1, const location_t &loc2)
{
    // There should be no difference between the order of rooms given
    if ( ( (loc1.x() == loc2.x()) && (loc1.y() < loc2.y()) ) ||
         ( (loc1.y() == loc2.y()) && (loc1.x() < loc2.x()) ) )
    {
        first = loc1;
        second = loc2;
    }
    else
    {
        first = loc2;
        second = loc1;
    }
}
