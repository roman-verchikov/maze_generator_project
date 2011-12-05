#include <stack>
#include <map>
#include <memory>

#include "dfs_maze_generator.h"
#include "room.h"
#include "maze.h"

dfs_maze_generator::dfs_maze_generator()
{
    srand(time(0));
}

maze* dfs_maze_generator::generate(unsigned int width,
                                   unsigned int height,
                                   const location_t &entrance,
                                   const location_t &exit)
{
    entrance_ = entrance;
    exit_     = exit;

    m_ = new maze(width, height, entrance, exit);
    m_->set_walls_everywhere();

    location_t cur_entrance = entrance_;
    bool got_next_entrance = false;

    do {
        random_dfs(cur_entrance);
        got_next_entrance = next_unvisited(cur_entrance);
    } while (got_next_entrance);

    return m_;
}

void dfs_maze_generator::random_dfs(const location_t &entrance)
{
    typedef std::pair<location_t, direction_t> move_t;

    std::stack<location_t> s;
    std::vector<move_t> all_neighbours;

    all_neighbours.reserve(direction_t::NUM_DIRECTIONS);
    s.push(entrance);

    while (!s.empty()) {
        location_t current_room = s.top();
        s.pop();

        visited_[current_room] = true;

        if (current_room == exit_) {
            break;
        }

        // peek random neighbour
        for(direction_t i; i < direction_t::NUM_DIRECTIONS; ++i) {
            const location_t cur_neighbour(current_room + i);

        }

        if (!all_neighbours.empty()) {
            move_t rnd_neighbour = all_neighbours[rand() % all_neighbours.size()];
            s.push(rnd_neighbour.first);

            // clear walls between current and random cells
            m_->remove_wall_at(current_room, rnd_neighbour.second);
            m_->remove_wall_at(rnd_neighbour.first, rnd_neighbour.second.opposite());

            all_neighbours.clear();
        }
    }
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
