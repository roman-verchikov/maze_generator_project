#include "random_maze_generator.h"

#include <vector>
#include <memory>

#include "room.h"
#include "maze.h"
#include "direction_t.h"

maze* random_maze_generator::generate(unsigned int width,
                                   unsigned int height,
                                   const location_t &entrance,
                                   const location_t &exit)
{
    if (width == 0) {
        width = maze::DEFAULT_WIDTH;
    }

    if (height == 0) {
        height = maze::DEFAULT_HEIGHT;
    }

    maze* m = new maze(width, height, entrance, exit);

    for(size_t i = 0; i < m->width(); ++i) {
        for(size_t j = 0; j < m->height(); ++j) {
            m->room_at(i, j).set_wall(direction_t::random_direction());
        }
    }

    return m;
}


std::string random_maze_generator::name() const
{
    return "Random";
}
