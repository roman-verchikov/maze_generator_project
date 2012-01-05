#include <stack>
#include <map>
#include <memory>

#include "dfs_maze_generator.h"
#include "maze.h"

dfs_maze_generator::dfs_maze_generator()
{
    srand(time(0));
}

std::auto_ptr<maze> dfs_maze_generator::generate(unsigned int width,
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

    return std::auto_ptr<maze>(m_);
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
