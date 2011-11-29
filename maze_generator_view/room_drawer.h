#ifndef ROOM_DRAWER_H
#define ROOM_DRAWER_H

class QWidget;
class room;

class room_drawer
{
public:
    room_drawer(QWidget *w);

    void operator () (const room &r);

private:
    QWidget *window_;
};

#endif // ROOM_DRAWER_H
