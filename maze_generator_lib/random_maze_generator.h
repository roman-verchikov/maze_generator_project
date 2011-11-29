#ifndef RANDOM_MAZE_GENERATOR_H
#define RANDOM_MAZE_GENERATOR_H

#include "maze_generator_interface.h"
#include "maze_generator_lib_global.h"

class maze;

class MAZE_GENERATOR_LIBSHARED_EXPORT random_maze_generator : public maze_generator_interface
{
public:
    maze* generate(unsigned int width,
                   unsigned int height,
                   const location_t &entrance,
                   const location_t &exit);

    std::string name() const;
};

#endif // RANDOM_MAZE_GENERATOR_H
