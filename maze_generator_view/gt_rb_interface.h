#ifndef GT_RB_INTERFACE_H
#define GT_RB_INTERFACE_H

#include <QRadioButton>

#include "maze_generator_type.h"

class gt_rb_interface : public QRadioButton {
    public:
        gt_rb_interface(QWidget *parent = 0) : QRadioButton(parent) {}
        virtual maze_generator_type get_type() const = 0;
};

#endif // GT_RB_INTERFACE_H
