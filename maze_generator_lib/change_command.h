#ifndef CHANGE_COMMAND_H
#define CHANGE_COMMAND_H

#include "wall_position_t.h"

class maze;

class change_command_t
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;

protected:
    change_command_t(maze* m, const wall_position_t &);

    wall_position_t wall_pos_;
    maze           *maze_;
};

class add_wall_command : public change_command_t
{
public:
    add_wall_command (maze* m, const wall_position_t &);

    void execute();
    void undo();
};

class remove_wall_command : public change_command_t
{
public:
    remove_wall_command (maze* m, const wall_position_t &);

    void execute();
    void undo();
};

#endif // CHANGE_COMMAND_H
