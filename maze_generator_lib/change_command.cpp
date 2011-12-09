#include "change_command.h"
#include "maze.h"

//------------------------------------------------------------------------------

change_command::change_command(maze* m, const location_t &l, const direction_t &d)
    : location_(l),
      wall_at_(d),
      maze_(m)
{}

room change_command::get_room_()
{
    room r(location_);
    r.set_wall(wall_at_);

    return r;
}
//------------------------------------------------------------------------------

add_wall_command::add_wall_command (maze* m, const location_t &l, const direction_t &d)
    : change_command(m, l, d)
{}

void add_wall_command::execute()
{
    maze_->room_at(location_) += get_room_();
}

void add_wall_command::undo()
{
    maze_->room_at(location_) -= get_room_();
}

//------------------------------------------------------------------------------

remove_wall_command::remove_wall_command (maze* m, const location_t &l, const direction_t &d)
    : change_command(m, l, d)
{}

void remove_wall_command::execute()
{
    maze_->room_at(location_) -= get_room_();
}

void remove_wall_command::undo()
{
    maze_->room_at(location_) += get_room_();
}
