#ifndef CURRENT_MAZE_H
#define CURRENT_MAZE_H

#include <memory>

class maze;

class current_maze
{
public:
    static maze* instance();

    static void set(std::auto_ptr<maze>);
    static void release();

private:

    current_maze();
    current_maze(const current_maze&);
    current_maze& operator = (const current_maze&);

    static std::auto_ptr<maze> current_maze_;
};

#endif // CURRENT_MAZE_H
