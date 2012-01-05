#ifndef ROOM_DRAWER_H
#define ROOM_DRAWER_H

class QWidget;
class wall_position_t;

class room_drawer
{
public:
    room_drawer(QWidget *w);

    void operator () (const wall_position_t &);

private:
    QWidget *const window_;
};

#endif // ROOM_DRAWER_H
