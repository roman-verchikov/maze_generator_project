#ifndef RANDOM_GT_RB_H
#define RANDOM_GT_RB_H

#include <QRadioButton>
#include "gt_rb_interface.h"

class random_gt_rb : public gt_rb_interface
{
    Q_OBJECT
public:
    explicit random_gt_rb(QWidget *parent = 0);


    maze_generator_type get_type() const {
        return RANDOM_GENERATOR_TYPE;
    }

signals:

public slots:

};

#endif // RANDOM_GT_RB_H
