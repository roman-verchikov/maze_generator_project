#include "change_command.h"
#include "maze.h"

//------------------------------------------------------------------------------

change_command::change_command(maze* m, const wall_position_t &wall_pos)
    : wall_pos_(wall_pos),
      maze_(m)
{}

//------------------------------------------------------------------------------

add_wall_command::add_wall_command (maze* m, const wall_position_t &wall_pos)
    : change_command(m, wall_pos)
{}

void add_wall_command::execute()
{
    maze_->set_wall_at(wall_pos_);
}

void add_wall_command::undo()
{
    maze_->remove_wall_at(wall_pos_);
}

//------------------------------------------------------------------------------

remove_wall_command::remove_wall_command (maze* m, const wall_position_t &wall_pos)
    : change_command(m, wall_pos)
{}

void remove_wall_command::execute()
{
    maze_->remove_wall_at(wall_pos_);
}

void remove_wall_command::undo()
{
    maze_->set_wall_at(wall_pos_);
}
