#include <algorithm>

#include <QPainter>
#include <QWheelEvent>

#include "current_maze.h"
#include "maze.h"
#include "maze_drawing_widget.h"

#include "room_drawer.h"

maze_drawing_widget::maze_drawing_widget(QWidget *parent) :
    QWidget(parent)
{
}

void maze_drawing_widget::paintEvent(QPaintEvent *)
{
    std::for_each(current_maze::instance()->all_cells().begin(),
                  current_maze::instance()->all_cells().end(),
                  room_drawer(this));
}

void maze_drawing_widget::onNextGenerationStepEvent()
{
    current_maze::instance()->next_step();
}

void maze_drawing_widget::onPrevGenerationStepEvent()
{
    current_maze::instance()->prev_step();
}

void maze_drawing_widget::drawStepByStep(bool val)
{
    drawStepByStep_ = val;
}

void maze_drawing_widget::wheelEvent(QWheelEvent *e)
{
    if (e->delta() > 0) {
        onNextGenerationStepEvent();
    } else {
        onPrevGenerationStepEvent();
    }
    this->update();
}
