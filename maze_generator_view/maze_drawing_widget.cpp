#include <algorithm>

#include <QPainter>

#include <current_maze.h>
#include <maze.h>
#include <maze_drawing_widget.h>

#include "room_drawer.h"

maze_drawing_widget::maze_drawing_widget(QWidget *parent) :
    QWidget(parent)
{
}

void maze_drawing_widget::paintEvent(QPaintEvent *)
{
    if (current_maze::get()) {
        std::for_each(current_maze::get()->rooms_cbegin(),
                      current_maze::get()->rooms_cend(),
                      room_drawer(this));
    }
}

void maze_drawing_widget::drawStepByStep(bool val)
{
    drawStepByStep_ = val;
}
