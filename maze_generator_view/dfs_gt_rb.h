#ifndef DFS_GT_RB_H
#define DFS_GT_RB_H

#include <QRadioButton>
#include "gt_rb_interface.h"

class dfs_gt_rb : public gt_rb_interface
{
    Q_OBJECT
public:
    explicit dfs_gt_rb(QWidget *parent = 0);

    maze_generator_type get_type() const {
        return DFS_GENERATOR_TYPE;
    }

signals:

public slots:

};

#endif // DFS_GT_RB_H
