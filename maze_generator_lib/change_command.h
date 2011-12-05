#ifndef CHANGE_COMMAND_H
#define CHANGE_COMMAND_H

#include "location_t.h"
#include "direction_t.h"
#include "room.h"

class change_command
{
public:
    change_command(const location_t&, const direction_t&);

    room get_room() const;

private:
    location_t  location_;
    direction_t wall_at_;
};

#endif // CHANGE_COMMAND_H
