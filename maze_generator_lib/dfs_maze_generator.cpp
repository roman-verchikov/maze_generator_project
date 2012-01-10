#include <stack>
#include <map>
#include <memory>

#include "dfs_maze_generator.h"
#include "maze.h"
#include "wall_position_t.h"

using std::auto_ptr;

dfs_maze_generator::dfs_maze_generator() {}

auto_ptr<maze> dfs_maze_generator::generate(unsigned int width,
                                   unsigned int height,
                                   const wall_position_t &entrance,
                                   const wall_position_t &exit)
{
    auto_ptr<maze> m(new maze(width, height, entrance, exit));

    m->set_walls_everywhere();

    return m;
}

void dfs_maze_generator::random_dfs(const location_t &)
{
    // TODO
}

bool dfs_maze_generator::next_unvisited(location_t &rl) const
{
    bool found = false;

    for (visited_type::const_iterator i = visited_.begin(); i != visited_.end(); ++i) {
        if (!(i->second)) {
            found = true;
            rl = i->first;
            break;
        }
    }

    return found;
}

std::string dfs_maze_generator::name()const
{
    return "DFS generator";
}
