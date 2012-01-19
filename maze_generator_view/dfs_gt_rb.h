#ifndef DFS_GT_RB_H
#define DFS_GT_RB_H

#include <QRadioButton>
#include "gt_rb_interface.h"

// TODO: readable names for classes
class dfs_generator_type_radio_button : public generator_type_radio_button_interface
{
    Q_OBJECT
public:
    explicit dfs_generator_type_radio_button(QWidget *parent = 0);

    maze_generator_type get_type() const {
        return DFS_GENERATOR_TYPE;
    }

signals:

public slots:

};

#endif // DFS_GT_RB_H
