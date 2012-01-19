#include "unknown_maze_generator_exception.h"

const char* unknown_maze_generator_exception::what() const throw()
{
    return "Selected maze generator algorithm is not implemented yet.";
}
