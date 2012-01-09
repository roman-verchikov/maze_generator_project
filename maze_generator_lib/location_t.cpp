#include "location_t.h"
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
    return (x() == rhs.x()) && (y() == rhs.y());
}

bool location_t::operator != (const location_t &rhs) const
{
    return !(*this == rhs);
}

void location_t::set(int x, int y)
{
    this->x(x);
    this->y(y);
}

bool location_t::operator < (const location_t &rhs) const
{
    return x() < rhs.x() || (!(rhs.x() < x()) && y() < rhs.y() );
}

location_t location_t::operator + (const location_t &rhs) const
{
    return location_t(x() + rhs.x(), y() + rhs.y());
}

unsigned long location_t::distance(const location_t &rhs) const
{
    const unsigned long dx = x() - rhs.x();
    const unsigned long dy = y() - rhs.y();

    return (dx*dx + dy*dy);
}
