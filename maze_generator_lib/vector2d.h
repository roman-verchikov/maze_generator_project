#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <vector>
#include <stdexcept>

#include "location_t.h"

using std::size_t;
using std::vector;

template<class T>
class vector2d
{
public:
    typedef typename vector<T>::iterator        element_iterator;
    typedef typename vector<T>::const_iterator  const_element_iterator;

    vector2d(size_t w = 0, size_t h = 0) :
        width_(w),
        height_(h),
        elements_(w*h)
    {}

    const_element_iterator begin() const
    {
        return elements_.begin();
    }

    element_iterator begin()
    {
        return elements_.begin();
    }

    const_element_iterator end() const
    {
        return elements_.end();
    }

    element_iterator end()
    {
        return elements_.end();
    }

    T& element_at(const location_t &l) throw (std::out_of_range)
    {
        return element_at(l.x(), l.y());
    }

    const T& element_at(const location_t &l) const throw(std::out_of_range)
    {
        return element_at(l);
    }

    T& element_at(int x, int y) throw (std::out_of_range)
    {
        return elements_[index_(x, y)];
    }

    const T& element_at(int x, int y) const throw(std::out_of_range)
    {
        return element_at(x, y);
    }

    size_t width() const
    {
        return width_;
    }

    size_t height() const
    {
        return height_;
    }

    bool belongs(const location_t &l) const
    {
        return belongs(l.x(), l.y());
    }

    bool belongs(int x, int y) const
    {
        return (x >= 0 &&  y >= 0 &&
                x < width() && y < height());
    }

    bool is_on_border(int x, int y) const
    {
        return (x == 0 || y == 0 || x == width()-1 || y == height()-1);
    }

    bool is_on_border(const location_t &l) const
    {
        return is_on_border(l.x(), l.y());
    }

private:

    inline size_t index_(size_t x, size_t y) const
    {
        return (width_*y + x);
    }

    inline size_t index_(const location_t &l) const
    {
        return index_(l.x(), l.y());
    }

    size_t width_;
    size_t height_;

    vector<T> elements_;

};

#endif // VECTOR2D_H
