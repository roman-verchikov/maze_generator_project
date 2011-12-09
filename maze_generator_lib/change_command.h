#ifndef CHANGE_COMMAND_H
#define CHANGE_COMMAND_H

#include "location_t.h"
#include "direction_t.h"
#include "room.h"

class maze;

class change_command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;

protected:
    change_command(maze* m, const location_t&, const direction_t&);

    room get_room_();

    location_t   location_;
    direction_t  wall_at_;
    maze        *maze_;
};

class add_wall_command : public change_command
{
public:
    add_wall_command (maze* m, const location_t&, const direction_t &);

    void execute();
    void undo();
};

class remove_wall_command : public change_command
{
public:
    remove_wall_command (maze* m, const location_t&, const direction_t &);

    void execute();
    void undo();
};

#endif // CHANGE_COMMAND_H
