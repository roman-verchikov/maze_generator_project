#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <stdexcept>

#include "room_location_t.h"
#include "maze_generator_lib_global.h"
#include "room.h"


using std::size_t;

class MAZE_GENERATOR_LIBSHARED_EXPORT  maze
{
public:
    enum {
        DEFAULT_WIDTH = 10,
        DEFAULT_HEIGHT = 10
    };

    typedef std::vector<room>::iterator         rooms_iterator;
    typedef std::vector<room>::const_iterator   const_rooms_iterator;

    maze(size_t w,
         size_t h,
         const location_t &entrance,
         const location_t &exit);

    maze(const maze& rhs);
    maze& operator = (const maze& rhs);

    rooms_iterator rooms_begin();
    rooms_iterator rooms_end();

    const_rooms_iterator rooms_cbegin();
    const_rooms_iterator rooms_cend();

    room& room_at(const location_t &rl) throw (std::out_of_range);
    room& room_at(int x, int y) throw (std::out_of_range);

    std::size_t width() const;
    std::size_t height() const;

    void set_walls_everywhere();

    bool is_valid_room(const location_t &rl) const;

private:

    size_t room_index_(size_t x, size_t y) const;
    bool is_valid_entrance_(const location_t &rl) const;
    void set_valid_entrance_location_();
    void set_valid_entrance_walls_();

    std::vector<room> rooms_;

    size_t width_;
    size_t height_;

    location_t entrance_;
    location_t exit_;
};

#endif // MAZE_H
