#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <boost/shared_ptr.hpp>

#include "change_command.h"
#include "location_t.h"
#include "maze_generator_lib_global.h"
#include "room.h"
#include "vector2d.h"

using std::size_t;

class MAZE_GENERATOR_LIBSHARED_EXPORT  maze
{
public:
    enum {
        DEFAULT_WIDTH = 10,
        DEFAULT_HEIGHT = 10
    };

    maze(size_t w,
         size_t h,
         const location_t &entrance,
         const location_t &exit);

    maze(const maze& rhs);
    maze& operator = (const maze& rhs);

    void set_wall_at   (const location_t &, const direction_t &);
    void remove_wall_at(const location_t &, const direction_t &);

    room& room_at(const location_t&);
    const room& room_at(const location_t&)const;

    const vector2d<room>& all_cells()const;
    void next_step();
    void prev_step();

    std::size_t width() const;
    std::size_t height() const;

    void set_walls_everywhere();
    void remove_all_walls();

private:

    void set_borders_();
    void set_valid_entrance_location_();
    void set_valid_entrance_walls_();

    void initial_state_();

    vector2d<room> rooms_at_current_step_;
    std::vector<boost::shared_ptr<change_command> > commands_;
    unsigned int current_step_;

    location_t entrance_;
    location_t exit_;
};

#endif // MAZE_H
