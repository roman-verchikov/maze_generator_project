#include <algorithm>

#include "direction_t.h"
#include "maze.h"
#include "room.h"
#include "random_maze_generator.h"
#include "location_t.h"

using std::size_t;

maze::maze(size_t w,
           size_t h,
           const location_t &entrance,
           const location_t &exit)
:
    rooms_at_current_step_   (vector2d<room>(w, h)),
    current_step_            (0),
    entrance_                (entrance),
    exit_                    (exit)
{
    commands_.reserve(w*h);

    initial_state_();

    set_valid_entrance_location_();
    set_valid_entrance_walls_();
}

void maze::initial_state_()
{
    remove_all_walls();
    set_borders_();
}

void maze::set_borders_()
{
    size_t w = rooms_at_current_step_.width();
    size_t h = rooms_at_current_step_.height();

    for(size_t i = 0; i < w; ++i) {
        rooms_at_current_step_.element_at(i, 0).set_wall(direction_t::NORTH);
        rooms_at_current_step_.element_at(0, i).set_wall(direction_t::WEST);
        rooms_at_current_step_.element_at(i, h-1).set_wall(direction_t::SOUTH);
        rooms_at_current_step_.element_at(w-1, i).set_wall(direction_t::EAST);

        for (size_t j = 0; j < h; ++j) {
            rooms_at_current_step_.element_at(i, j).location(i, j);
        }
    }
}

void maze::set_valid_entrance_walls_()
{
#if 0
    rooms_at_current_step_.element_at(entrance_).clear_walls();
    rooms_at_current_step_.element_at(exit_).clear_walls();
#endif
}

void maze::set_valid_entrance_location_()
{
#if 0
    if (!rooms_at_current_step_.is_on_border(entrance_)) {
        entrance_ = location_t(0, 0);
    }

    if (!rooms_at_current_step_.is_on_border(exit_)) {
        exit_ = location_t(rooms_at_current_step_.width()-1,
                           rooms_at_current_step_.height()-1);
    }

    if (entrance_ == exit_) {
        entrance_ = location_t(0, 0);
        exit_     = location_t(rooms_at_current_step_.width()-1,
                               rooms_at_current_step_.height()-1);
    }
#endif
}

std::size_t maze::width() const
{
    return rooms_at_current_step_.width();
}

std::size_t maze::height() const
{
    return rooms_at_current_step_.height();
}

void maze::set_wall_at(const location_t &l, const direction_t &d)
{
    commands_.push_back(change_command(l, d));
}
void maze::remove_wall_at(const location_t &l, const direction_t &d)
{
    commands_.push_back(change_command(l, d));
}

const vector2d<room>& maze::all_cells() const
{
    return rooms_at_current_step_;
}

void maze::next_step()
{
    room r = commands_.at(current_step_).get_room();
    rooms_at_current_step_.element_at(r.location()) += r;

    // current_step_ should never be greater than number of modifications made
    // on generation step
    current_step_ = ((current_step_ + 1) - commands_.size()) ? current_step_  + 1 : current_step_;
}

void maze::prev_step()
{
    current_step_ = (current_step_ - 1) % commands_.size();

    room r = commands_.at(current_step_).get_room();
    rooms_at_current_step_.element_at(r.location()) -= r;
}

void maze::remove_all_walls()
{
    std::for_each(rooms_at_current_step_.begin(),
                  rooms_at_current_step_.end(),
                  std::mem_fun_ref(&room::clear_walls));
}

void maze::set_walls_everywhere()
{
    std::for_each(rooms_at_current_step_.begin(),
                  rooms_at_current_step_.end(),
                  std::mem_fun_ref(&room::set_walls));
}
