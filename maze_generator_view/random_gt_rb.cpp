#include "random_gt_rb.h"

random_generator_type_radio_button::random_generator_type_radio_button(QWidget *parent) :
    generator_type_radio_button_interface(parent)
{
    this->setText(tr("Random"));
}
