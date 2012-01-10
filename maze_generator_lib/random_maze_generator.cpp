#include "direction_t.h"
#include "maze.h"
#include "random_maze_generator.h"
#include "wall_position_t.h"

std::auto_ptr<maze> random_maze_generator::generate(unsigned int width,
                                   unsigned int height,
                                   const wall_position_t &entrance,
                                   const wall_position_t &exit)
{
    std::auto_ptr<maze> m(new maze(width, height, entrance, exit));

    for(size_t i = 0; i < width*height/2; ++i) {
        location_t r1 = m->random_location();
        location_t r2 = m->random_neighbour(r1);

        m->record_set_wall_at(wall_position_t::wall_position_with(r1, r2));
    }

    return m;
}

std::string random_maze_generator::name() const
{
    return "Random";
}
