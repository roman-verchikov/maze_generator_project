#include "wall_position_t.h"

wall_position_t::wall_position_t() {}

wall_position_t::wall_position_t(const location_t &loc1, const location_t &loc2)
    : std::pair<location_t, location_t>(loc1, loc2)
{ }

wall_position_t
wall_position_t::wall_position_with(const location_t &loc1, const location_t &loc2)
{
    if ( ( (loc1.x() == loc2.x()) && (loc1.y() < loc2.y()) ) ||
         ( (loc1.y() == loc2.y()) && (loc1.x() < loc2.x()) ) )
    {
        return wall_position_t(loc1, loc2);
    }
    else
    {
        return wall_position_t(loc2, loc1);
    }
}
