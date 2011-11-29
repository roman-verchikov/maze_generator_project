#ifndef MAZE_DRAWING_WIDGET_H
#define MAZE_DRAWING_WIDGET_H

#include <QWidget>
#include <QAbstractButton>

class maze_drawing_widget : public QWidget
{
    Q_OBJECT
public:
    explicit maze_drawing_widget(QWidget *parent = 0);

    void drawStepByStep(bool val);

signals:

public slots:

    void paintEvent(QPaintEvent *);

private:

    void drawMaze();

    bool drawStepByStep_;

};

#endif // MAZE_DRAWING_WIDGET_H
