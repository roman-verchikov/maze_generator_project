#ifndef RANDOM_MAZE_GENERATOR_H
#define RANDOM_MAZE_GENERATOR_H

#include "maze_generator_interface.h"


class random_maze_generator : public maze_generator_interface
{
public:
    std::auto_ptr<maze> generate(unsigned int width,
                                 unsigned int height,
                                 const wall_position_t &entrance,
                                 const wall_position_t &exit);

    std::string name() const;
};

#endif // RANDOM_MAZE_GENERATOR_H
