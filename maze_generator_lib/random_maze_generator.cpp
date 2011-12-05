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
    maze* m = new maze(width, height, entrance, exit);

    for(size_t i = 0; i < m->width(); ++i) {
        for(size_t j = 0; j < m->height(); ++j) {
            direction_t rnd_direction = direction_t::random_direction();

            m->set_wall_at(location_t(i, j), rnd_direction);
        }
    }

    return m;
}


std::string random_maze_generator::name() const
{
    return "Random";
}
