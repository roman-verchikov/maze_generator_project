#include "room_drawer.h"

#include <QWidget>
#include <QPainter>

#include <room.h>
#include <maze.h>
#include <current_maze.h>

room_drawer::room_drawer(QWidget *w) : window_(w) {}

void room_drawer::operator () (const room &r)
{
    const size_t widget_width = window_->width();
    const size_t widget_height = window_->height();
    const size_t num_rooms_x = current_maze::instance()->width();
    const size_t num_rooms_y = current_maze::instance()->height();

    const int gap = 0;
    const int room_width = widget_width/num_rooms_x;
    const int room_height = widget_height/num_rooms_y;

    int i = r.location().x();
    int j = r.location().y();

    QPainter p(window_);

    if (r.is_wall(direction_t::NORTH)) {
        QLine l(i*room_width + gap,
                j*room_height + gap,
                (i+1)*room_width + gap,
                j*room_height + gap);

        p.drawLine(l);
    }

    if (r.is_wall(direction_t::SOUTH)) {
        QLine l(i*room_width + gap,
                (j+1)*room_height + gap,
                (i+1)*room_width + gap,
                (j+1)*room_height + gap);

        p.drawLine(l);
    }

    if (r.is_wall(direction_t::EAST)) {
        QLine l((i+1)*room_width + gap,
                j*room_height + gap,
                (i+1)*room_width + gap,
                (j+1)*room_height + gap);

        p.drawLine(l);
    }

    if (r.is_wall(direction_t::WEST)) {
        QLine l(i*room_width + gap,
                j*room_height + gap,
                i*room_width + gap,
                (j+1)*room_height + gap);

        p.drawLine(l);
    }
}
