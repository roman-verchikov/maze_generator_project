#ifndef UNKNOWN_MAZE_GENERATOR_EXCEPTION_H
#define UNKNOWN_MAZE_GENERATOR_EXCEPTION_H

#include <exception>

class unknown_maze_generator_exception : public std::exception
{
public:
    virtual const char* what() const throw();
};

#endif // UNKNOWN_MAZE_GENERATOR_EXCEPTION_H
