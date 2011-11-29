#include "direction_t.h"
#include "maze.h"
#include "room.h"
#include "random_maze_generator.h"
#include "room_location_t.h"

using std::size_t;

maze::maze(size_t w,
           size_t h,
           const location_t &entrance,
           const location_t &exit)
:
    rooms_   (std::vector<room>(w*h)),
    width_   (w),
    height_  (h),
    entrance_(entrance),
    exit_    (exit)
{
    for(size_t i = 0; i < w; ++i) {
        // Set border walls
        rooms_[room_index_(i, 0)].set_wall(direction_t::NORTH);
        rooms_[room_index_(0, i)].set_wall(direction_t::WEST);
        rooms_[room_index_(i, h-1)].set_wall(direction_t::SOUTH);
        rooms_[room_index_(w-1, i)].set_wall(direction_t::EAST);

        for (size_t j = 0; j < h; ++j) {
            this->rooms_[room_index_(i, j)].location(i, j);
        }
    }

    set_valid_entrance_location_();
    set_valid_entrance_walls_();
}

void maze::set_valid_entrance_walls_()
{
    room_at(entrance_).clear_walls();
    room_at(exit_).clear_walls();
}

void maze::set_valid_entrance_location_()
{
    if (entrance_ == exit_) {
        entrance_ = location_t(0, 0);
        exit_     = location_t(width_-1, height_-1);
    } else {
        if (!is_valid_entrance_(entrance_)) {
            entrance_ = location_t(0, 0);
        }

        if (!is_valid_entrance_(exit_)) {
            exit_ = location_t(width_-1, height_-1);
        }
    }
}

size_t maze::room_index_(size_t x, size_t y) const
{
    return (y * width_ + x);
}

bool maze::is_valid_entrance_(const location_t &rl) const
{
    return (rl.x() == 0 || rl.x() == (width_-1) ||
            rl.y() == 0 || rl.y() == (height_-1));
}

room& maze::room_at(int x, int y) throw (std::out_of_range)
{
    return rooms_.at(room_index_(x, y));
}

room& maze::room_at(const location_t &rl) throw (std::out_of_range)
{
    return room_at(rl.x(), rl.y());
}

std::size_t maze::width() const
{
    return width_;
}

std::size_t maze::height() const
{
    return height_;
}

maze::rooms_iterator maze::rooms_begin()
{
    return rooms_.begin();
}

maze::rooms_iterator maze::rooms_end()
{
    return rooms_.end();
}

maze::const_rooms_iterator maze::rooms_cbegin()
{
    return rooms_.begin();
}

maze::const_rooms_iterator maze::rooms_cend()
{
    return rooms_.end();
}

bool maze::is_valid_room(const location_t &rl) const
{
    return (rl.x() >= 0     && rl.y() >= 0 &&
            rl.x() < width_ && rl.y() < height_);
}

class waller {
    public:
        void operator () (room& r) {
            r.set_walls();
        }
};

void maze::set_walls_everywhere()
{
    std::for_each(rooms_begin(), rooms_end(), waller());
}
