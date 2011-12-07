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
    std::for_each(current_maze::get()->all_cells().begin(),
                  current_maze::get()->all_cells().end(),
                  room_drawer(this));
}

void maze_drawing_widget::onNextGenerationStepEvent()
{
    current_maze::get()->next_step();
}

void maze_drawing_widget::onPrevGenerationStepEvent()
{
    current_maze::get()->prev_step();
}

void maze_drawing_widget::drawStepByStep(bool val)
{
    drawStepByStep_ = val;
}
