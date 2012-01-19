#ifndef RANDOM_GT_RB_H
#define RANDOM_GT_RB_H

#include <QRadioButton>
#include "gt_rb_interface.h"

// TODO: readable names for classes
class random_generator_type_radio_button : public generator_type_radio_button_interface
{
    Q_OBJECT
public:
    explicit random_generator_type_radio_button(QWidget *parent = 0);


    maze_generator_type get_type() const {
        return RANDOM_GENERATOR_TYPE;
    }

signals:

public slots:

};

#endif // RANDOM_GT_RB_H
