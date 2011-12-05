#include "current_maze.h"
#include "maze.h"

#include <boost/thread/locks.hpp>

current_maze::maze_ptr
current_maze::current_maze_ = new maze(0, 0, location_t(), location_t());

boost::mutex current_maze::locker_;

void current_maze::release()
{
    //boost::lock_guard<boost::mutex> l(locker_);
    delete current_maze_;
    current_maze_ = 0;
}

maze* current_maze::get()
{
    // Prevent reading while being set();
    //boost::lock_guard<boost::mutex> l(locker_);
    return current_maze_;
}

void current_maze::set(maze_ptr m)
{
    //boost::lock_guard<boost::mutex> l(locker_);
    release();
    current_maze_ = m;
}

