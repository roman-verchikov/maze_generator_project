#ifndef MAZE_GENERATOR_FACTORY_H
#define MAZE_GENERATOR_FACTORY_H

#include "maze_generator_interface.h"
#include "maze_generator_type.h"
#include "unknown_maze_generator_exception.h"

std::auto_ptr<maze_generator_interface>
maze_generator_factory(maze_generator_type t) throw (unknown_maze_generator_exception);

#endif // MAZE_GENERATOR_FACTORY_H
