#include <QWidget>
#include <QPainter>

#include <algorithm>

#include "current_maze.h"
#include "maze.h"
#include "room_drawer.h"
#include "wall_position_t.h"

room_drawer::room_drawer(QWidget *w) : window_(w) {}

void room_drawer::operator () (const wall_position_t &wall_pos)
{
    const size_t widget_width = window_->width();
    const size_t widget_height = window_->height();
    const size_t num_rooms_x = current_maze::instance()->width();
    const size_t num_rooms_y = current_maze::instance()->height();

    const int gap = 0;
    const int room_width  = widget_width/num_rooms_x;
    const int room_height = widget_height/num_rooms_y;

    int x1 = wall_pos.first.x();
    int y1 = wall_pos.first.y();
    int x2 = wall_pos.second.x();
    int y2 = wall_pos.second.y();

    QPainter p(window_);

#if 1
    // Vertical line
    if (x1 == x2) {
        QLine l( x2 * room_width + gap,
                 y2 * room_height + gap,
                (x2 + 1) * room_width + gap,
                 y2 * room_height + gap);

        p.drawLine(l);
    }

    // Horizontal line
    if (y1 == y2) {
        QLine l( x2 * room_width + gap,
                 y2 * room_height + gap,
                 x2 * room_width + gap,
                (y2 + 1) * room_height + gap);

        p.drawLine(l);
    }
#else
    QLine l( x2 * room_width + gap,
             y2 * room_height + gap,
            (2*x2 - x1) * room_width + gap,
            (2*y2 - y1) * room_height + gap);

    p.drawLine(l);
#endif
}
