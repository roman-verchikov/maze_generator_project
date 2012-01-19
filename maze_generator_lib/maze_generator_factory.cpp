#include "dfs_maze_generator.h"
#include "maze_generator_factory.h"
#include "random_maze_generator.h"
#include "unknown_maze_generator_exception.h"

std::auto_ptr<maze_generator_interface>
maze_generator_factory(maze_generator_type t) throw (unknown_maze_generator_exception)
{
    std::auto_ptr<maze_generator_interface> mg;

    switch (t) {
        case RANDOM_GENERATOR_TYPE:
            mg.reset(new random_maze_generator);
            break;
        case DFS_GENERATOR_TYPE:
            mg.reset(new dfs_maze_generator);
            break;

        default:
            throw unknown_maze_generator_exception();
    }

    return mg;
}
