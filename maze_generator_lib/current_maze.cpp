#include <boost/thread/locks.hpp>

#include "current_maze.h"
#include "maze.h"

using boost::mutex;
using boost::lock_guard;

std::auto_ptr<maze>
current_maze::current_maze_(new maze (0, 0, location_t(), location_t()));
mutex current_maze::locker_;

void current_maze::release()
{
    current_maze_.reset();
}

// Leaves ownership for the current_maze class
maze* current_maze::instance()
{
    return current_maze_.get();
}

void current_maze::set(std::auto_ptr<maze> m)
{
    current_maze_.reset();
    current_maze_ = m;
}

boost::mutex& current_maze::mutex()
{
    return locker_;
}
