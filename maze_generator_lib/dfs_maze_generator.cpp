#include <stack>
#include <map>
#include <memory>

#include "dfs_maze_generator.h"
#include "maze.h"
#include "wall_position_t.h"

using std::auto_ptr;
using boost::optional;

dfs_maze_generator::dfs_maze_generator() {}

auto_ptr<maze>
dfs_maze_generator::generate(unsigned int width,
                             unsigned int height,
                             const wall_position_t &entrance,
                             const wall_position_t &exit)
{
    auto_ptr<maze> m(new maze(width, height, entrance, exit));

    m->set_walls_everywhere();

    optional<location_t> random_unvisited_cell;

    while (random_unvisited_cell = next_unvisited(m.get())) {
        random_dfs(m.get(), random_unvisited_cell.get());
    }

    return m;
}

void
dfs_maze_generator::random_dfs(maze *m, location_t &starting_point)
{
    std::stack<location_t> s;
    s.push(starting_point);
    visited_cells_.insert(starting_point);

    while (!s.empty()) {
        location_t current_location = s.top();
        s.pop();

        location_t rnd_location = m->random_neighbour(current_location);

        if (visited_cells_.find(rnd_location) == visited_cells_.end()) {
            s.push(rnd_location);
            visited_cells_.insert(rnd_location);
            m->record_remove_wall_at(wall_position_t(current_location, rnd_location));
        }
    }
}

optional<location_t>
dfs_maze_generator::next_unvisited(const maze* m) const
{
    optional<location_t> unvisited;

    for (int i = 0; i < m->width() && !unvisited; ++i) {
        for (int j = 0; j < m->height() && !unvisited; ++j) {
            location_t l(i,j);
            if (visited_cells_.find(l) == visited_cells_.end()) {
                unvisited = l;
            }
        }
    }

    return unvisited;
}

std::string dfs_maze_generator::name()const
{
    return "DFS generator";
}
