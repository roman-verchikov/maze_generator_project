#ifndef CURRENT_MAZE_H
#define CURRENT_MAZE_H

#include <boost/thread/mutex.hpp>
#include <memory>

#include "maze_generator_lib_global.h"

class maze;

class MAZE_GENERATOR_LIBSHARED_EXPORT current_maze
{
public:
    static maze* instance();

    static void set(std::auto_ptr<maze>);
    static void release();

    static boost::mutex& mutex();

private:

    current_maze();
    current_maze(const current_maze&);
    current_maze& operator = (const current_maze&);

    static std::auto_ptr<maze> current_maze_;

    static boost::mutex locker_;
};

#endif // CURRENT_MAZE_H
