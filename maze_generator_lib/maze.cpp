#include <algorithm>

#include "direction_t.h"
#include "maze.h"
#include "random_maze_generator.h"
#include "wall_position_t.h"

using std::size_t;

maze::maze(size_t w,
           size_t h,
           const wall_position_t &entrance,
           const wall_position_t &exit)
:
    current_step_  (0),
    prev_step_     (0),
    width_         (w),
    height_        (h),
    entrance_      (entrance),
    exit_          (exit)
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
    // Borders are walls between (-1, y) and (0, y), (x, -1) and (x, 0), etc.
    for(size_t i = 0; i < width_; i++) {
        wall_position_t wp_top    = wall_position_t(location_t(i, 0), location_t(i, -1));
        wall_position_t wp_bottom = wall_position_t(location_t(i, height_-1), location_t(i, height_));

        set_wall_at(wp_top);
        set_wall_at(wp_bottom);
    }

    for(size_t i = 0; i < height_; ++i) {
        wall_position_t wp_left = wall_position_t(location_t(0, i), location_t(-1, i));
        wall_position_t wp_right = wall_position_t(location_t(width_-1, i), location_t(width_, i));

        set_wall_at(wp_left);
        set_wall_at(wp_right);
    }
}

void maze::set_valid_entrance_walls_()
{
    // TODO
#if 0
    rooms_at_current_step_.element_at(entrance_).clear_walls();
    rooms_at_current_step_.element_at(exit_).clear_walls();
#endif
}

void maze::set_valid_entrance_location_()
{
    // TODO
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

size_t maze::width() const
{
    return width_;
}

size_t maze::height() const
{
    return height_;
}

// TODO: Think on passing callbacks as arguments to change_command.
//       That would eliminate derived classes and set/remove_wall_between
//       functions could be made private.
void maze::record_set_wall_at(const wall_position_t &wp)
{
    commands_.push_back(shared_ptr<change_command_t>(
                            new add_wall_command(this, wp)));
}

void maze::record_remove_wall_at(const wall_position_t &wp)
{
    commands_.push_back(shared_ptr<change_command_t>(
                            new remove_wall_command(this, wp)));
}

void maze::set_wall_at(const wall_position_t &wp)
{
    walls_.insert(wp);
}

void maze::remove_wall_at(const wall_position_t &wp)
{
    walls_.erase(wp);
}

void maze::next_step()
{
    if (!commands_.empty()) {

        commands_.at(current_step_)->execute();

        // current_step_ should never be greater than number of modifications made
        // on generation step
        if (current_step_ != (commands_.size()-1)) {
            ++current_step_;
        }
    }
}

void maze::prev_step()
{
    if (!commands_.empty()) {
        if (current_step_ != 0) {
            --current_step_;
        }

        commands_.at(current_step_)->undo();
    }
}

void maze::remove_all_walls()
{
    walls_.clear();
}

void maze::set_walls_everywhere()
{
    for (size_t i = 0; i < width_; ++i) {
        for (size_t j = 0; j < height_; ++j) {
            // vertical walls positions
            location_t room1_pos_v(i, j);
            location_t room2_pos_v(i+1, j);

            // horizontal walls position
            location_t room1_pos_h(i, j);
            location_t room2_pos_h(i, j+1);

            if (i != width_-1) {
                record_set_wall_at(wall_position_t(room1_pos_v, room2_pos_v));
            }
            record_set_wall_at(wall_position_t(room1_pos_h, room2_pos_h));
        }
    }
}

vector<location_t> maze::valid_neighbours(const location_t &l) const
{
    const int max_neighbours = 4;
    const location_t neighbour_diffs[max_neighbours] = {
        location_t(-1, 0),
        location_t(1, 0),
        location_t(0, -1),
        location_t(0, 1)
    };

    vector<location_t> valid_neighbours;
    valid_neighbours.reserve(max_neighbours);

    for (int i = 0; i < max_neighbours; ++i) {
        location_t cur_neighbour = l + neighbour_diffs[i];
        if (is_valid(cur_neighbour)) {
            valid_neighbours.push_back(cur_neighbour);
        }
    }

    return valid_neighbours;
}

location_t maze::random_location() const
{
    return location_t(rand() % width(), rand() % height());
}

location_t maze::random_neighbour(const location_t &l) const
{
    vector<location_t> vn = valid_neighbours(l);
    if (vn.empty()) return l;
    return vn.at(rand() % vn.size());
}

bool maze::is_valid(const location_t &l) const
{
    return (l.x() >= 0 && l.x() < width() &&
            l.y() >= 0 && l.y() < height());
}

maze::wall_iterator maze::walls_begin()
{
    return walls_.begin();
}

maze::wall_iterator maze::walls_end()
{
    return walls_.end();
}

maze::const_wall_iterator maze::walls_begin() const
{
    return walls_begin();
}

maze::const_wall_iterator maze::walls_end() const
{
    return walls_end();
}

void maze::restore_previous_step()
{
    while (prev_step_ != current_step_) {
        prev_step();
    }
}

void maze::goto_last_step()
{
    prev_step_ = current_step_;

    while (commands_.size() && current_step_ != commands_.size()-1) {
        next_step();
    }
}
