#ifndef ROOM_LOCATION_T_H
#define ROOM_LOCATION_T_H

class direction_t;

class location_t
{
public:
    location_t(int x = 0, int y = 0);

    int x()const;
    int y()const;

    void x(const int &val);
    void y(const int &val);

    void set(int x, int y);

    bool operator == (const location_t &rhs) const;
    bool operator != (const location_t &rhs) const;

    bool operator < (const location_t &rhs) const;

    location_t operator + (direction_t d) const;

    unsigned long distance(const location_t &rhs) const   ;

private:

    int x_;
    int y_;
};

#endif // ROOM_LOCATION_T_H
