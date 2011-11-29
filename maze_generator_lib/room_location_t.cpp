#include "room_location_t.h"
#include "direction_t.h"

location_t::location_t(int x, int y) : x_(x), y_(y)
{
}

int location_t::x()const
{
    return x_;
}

int location_t::y()const
{
    return y_;
}

void location_t::x(const int &val)
{
    x_ = val;
}

void location_t::y(const int &val)
{
    y_ = val;
}

bool location_t::operator == (const location_t &rhs) const
{
    return ((x_ == rhs.x_) && (y_ == rhs.y_));
}

bool location_t::operator != (const location_t &rhs) const
{
    return !(*this == rhs);
}

void location_t::set(int x, int y)
{
    x_ = x;
    y_ = y;
}

bool location_t::operator < (const location_t &rhs) const
{
    return (this->distance(location_t(0,0)) < rhs.distance(location_t(0,0)));
}

location_t location_t::operator + (direction_t d) const
{
    int dx = x_;
    int dy = y_;

    switch (d) {
        case direction_t::NORTH:
            --dy;
            break;

        case direction_t::SOUTH:
            ++dy;
            break;

        case direction_t::WEST:
            --dx;
            break;

        case direction_t::EAST:
            ++dx;
            break;
    }

    return location_t(dx, dy);
}

unsigned long location_t::distance(const location_t &rhs) const
{
    const unsigned long dx = x_ - rhs.x_;
    const unsigned long dy = y_ - rhs.y_;

    return (dx*dx + dy*dy);
}
