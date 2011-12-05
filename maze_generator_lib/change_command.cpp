#include "change_command.h"

change_command::change_command(const location_t &l, const direction_t &d)
    : location_(l),
      wall_at_(d)
{
}

room change_command::get_room() const
{
    room r(location_);
    r.set_wall(wall_at_);

    return r;
}
