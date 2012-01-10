#ifndef DFS_MAZE_GENERATOR_H
#define DFS_MAZE_GENERATOR_H

#include <map>

#include "maze_generator_interface.h"
#include "maze_generator_lib_global.h"
#include "wall_position_t.h"

class maze;

class dfs_maze_generator : public maze_generator_interface
{
public:

    dfs_maze_generator();

    std::auto_ptr<maze> generate(unsigned int width,
                                 unsigned int height,
                                 const wall_position_t &entrance,
                                 const wall_position_t &exit);

    std::string name()const;

private:
    class distance_comparator {
    public:
        //distance_comparator() {}
        distance_comparator(const location_t rl) : rl_(rl) {}

        bool operator () (const location_t &lhs, const location_t &rhs) const {
            return (lhs.distance(rl_) < rhs.distance(rl_));
        }
    private:
        location_t rl_;
    };

    typedef std::map<location_t, bool> visited_type;

    void random_dfs(const location_t &entrance);
    bool next_unvisited(location_t &rl) const;

    wall_position_t entrance_;
    wall_position_t exit_;
    maze* m_;

    visited_type visited_;
};


#endif // DFS_MAZE_GENERATOR_H
