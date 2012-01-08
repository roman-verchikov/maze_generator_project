#ifndef MAZE_GENERATOR_INTERFACE_H
#define MAZE_GENERATOR_INTERFACE_H

#include <string>
#include <memory>

class location_t;
class maze;

class maze_generator_interface
{
public:
    virtual std::auto_ptr<maze> generate(unsigned int width,
                                         unsigned int height,
                                         const location_t &entrance,
                                         const location_t &exit) = 0;

    // TODO: should support l10n
    virtual std::string name() const = 0;
};

#endif // MAZE_GENERATOR_INTERFACE_H
