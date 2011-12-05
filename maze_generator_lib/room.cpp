#include "room.h"

#include <algorithm>

room::room(int x, int y)
    : location_(x, y)
{
    clear_walls();
}

room::room(const location_t &rl)
    : location_(rl)
{
    clear_walls();
}

bool room::is_wall(direction_t d) const
{
    return is_wall_.at(d);
}

void room::set_wall(direction_t d)
{
    is_wall_[d] = true;
}

void room::remove_wall(direction_t d)
{
    is_wall_[d] = false;
}

void room::clear_walls()
{
    std::fill(is_wall_.begin(), is_wall_.end(), false);
}

void room::set_walls()
{
    std::fill(is_wall_.begin(), is_wall_.end(), true);
}

location_t room::location() const
{
    return location_;
}

std::vector<direction_t> room::walls() const
{
    std::vector<direction_t> _walls;

    _walls.reserve(direction_t::NUM_DIRECTIONS);

    for(direction_t i; i < direction_t::NUM_DIRECTIONS; ++i) {
        if (is_wall_[i]) {
            _walls.push_back((direction_t)i);
        }
    }

    return _walls;
}

void room::location(int x, int y)
{
    location_.x(x);
    location_.y(y);
}

void room::location(const location_t &rl)
{
    location_ = rl;
}

room& room::operator += (const room& rhs)
{
    std::transform(rhs.is_wall_.begin(),
                   rhs.is_wall_.end(),
                   is_wall_.begin(),
                   is_wall_.begin(),
                   std::logical_or<bool>());

    return *this;
}

room& room::operator -= (const room& rhs)
{
    std::transform(rhs.is_wall_.begin(),
                   rhs.is_wall_.end(),
                   is_wall_.begin(),
                   is_wall_.begin(),
                   std::logical_and<bool>());

    return *this;
}
