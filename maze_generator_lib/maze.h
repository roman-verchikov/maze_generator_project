#ifndef MAZE_H
#define MAZE_H

#include <set>
#include <vector>
#include <utility>

#include <boost/shared_ptr.hpp>

#include "change_command.h"
#include "location_t.h"
#include "maze_generator_lib_global.h"
#include "vector2d.h"
#include "wall_position_t.h"

using std::size_t;
using std::pair;
using std::set;
using std::vector;
using boost::shared_ptr;

class maze
{
public:
    typedef set<wall_position_t>::iterator       wall_iterator;
    typedef set<wall_position_t>::const_iterator const_wall_iterator;

    maze(size_t w,
         size_t h,
         const location_t &entrance,
         const location_t &exit);

    maze(const maze& rhs);
    maze& operator = (const maze& rhs);

    void set_wall_at          (const wall_position_t &);
    void remove_wall_at       (const wall_position_t &);
    void record_set_wall_at   (const wall_position_t &);
    void record_remove_wall_at(const wall_position_t &);

    wall_iterator walls_begin();
    wall_iterator walls_end();
    const_wall_iterator walls_begin() const;
    const_wall_iterator walls_end() const;

    void next_step();
    void prev_step();


    bool is_valid(const location_t &) const;

    vector<location_t> valid_neighbours(const location_t &) const;
    location_t random_location() const;
    location_t random_neighbour(const location_t &) const;

    size_t width() const;
    size_t height() const;

    void set_walls_everywhere();
    void remove_all_walls();

private:

    void set_borders_();
    void set_valid_entrance_location_();
    void set_valid_entrance_walls_();

    void initial_state_();

    vector<shared_ptr<change_command> > commands_;
    set<wall_position_t> walls_;

    unsigned int current_step_;

    size_t width_;
    size_t height_;
    location_t entrance_;
    location_t exit_;
};

#endif // MAZE_H
