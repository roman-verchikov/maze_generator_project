#ifndef ROOM_H
#define ROOM_H

#include <boost/array.hpp>
#include <vector>
#include "maze_generator_lib_global.h"

#include "direction_t.h"
#include "room_location_t.h"

class room
{
public:
    room(int x = 0, int y = 0);
    room(const location_t &rl);

    bool is_wall     (direction_t d) const;
    void set_wall    (direction_t d);
    void remove_wall (direction_t d);

    std::vector<direction_t> walls() const;

    location_t location() const;
    void location(int x, int y);
    void location(const location_t &rl);

    void clear_walls();
    void set_walls();

private:
    boost::array<bool, direction_t::NUM_DIRECTIONS> is_wall_;

    location_t location_;
};

#endif // ROOM_H
