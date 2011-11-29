#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <vector>
#include <stdexcept>

using std::size_t;
using std::vector;

template<class T>
class vector2d
{
public:
    vector2d(size_t w, size_t h) : width_(w), height_(h), elements_(w*h) {}

    T& element_at(const location_t &l) throw (std::out_of_range)
    {

    }

    const T& element_at(const location_t &l) const throw(std::out_of_range)
    {
    }

private:

    inline size_t index(size_t x, size_t y) const
    {
        return (width_*y + x);
    }

    size_t width_;
    size_t height_;

    vector<T> elements_;

};

#endif // VECTOR2D_H
