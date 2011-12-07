#ifndef CURRENT_MAZE_H
#define CURRENT_MAZE_H

#include <boost/thread/mutex.hpp>
#include <memory>

#include "maze_generator_lib_global.h"

class maze;

class MAZE_GENERATOR_LIBSHARED_EXPORT current_maze
{
public:
    typedef maze* maze_ptr;

    static maze* instance();

    static void set(maze_ptr);
    static void release();

private:

    current_maze();
    current_maze(const current_maze&);
    current_maze& operator = (const current_maze&);

    static maze_ptr current_maze_;

    static boost::mutex locker_;
};

#endif // CURRENT_MAZE_H
