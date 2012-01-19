#include <QRadioButton>
#include <QMessageBox>

#include <algorithm>

#include "current_maze.h"
#include "random_gt_rb.h"
#include "dfs_gt_rb.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wall_position_t.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow         (parent),
    ui                  (new Ui::MainWindow)
{
    ui->setupUi(this);

    radioButtons.push_back(new random_generator_type_radio_button(ui->mazeGeneratorTypeGroupBox));
    radioButtons.push_back(new dfs_generator_type_radio_button(ui->mazeGeneratorTypeGroupBox));

    addGeneratorTypeRadioButtons();
}

MainWindow::~MainWindow()
{
    current_maze::release();
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    const size_t w = ui->widthSpinBox->value();
    const size_t h = ui->heightSpinBox->value();
    const wall_position_t in  = wall_position_t(location_t(-1,0), location_t(0,0));
    const wall_position_t out = wall_position_t(location_t(w-1,h), location_t(w,h));

    try {
        current_maze::set(maze_generator_factory(getSelectedGeneratorType())->generate(w, h, in, out));
    } catch (const unknown_maze_generator_exception &ex) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr(ex.what()),
                                 QMessageBox::Ok);
    }
    this->ui->mazeDrawingWidget->update();
}

void MainWindow::addGeneratorTypeRadioButtons()
{
    std::for_each(radioButtons.begin(),
                  radioButtons.end(),
                  [=] (generator_type_radio_button_interface *i) {
                    ui->verticalLayout->addWidget(i);
                  });

    radioButtons.front()->setChecked(true);
}

maze_generator_type MainWindow::getSelectedGeneratorType() const
{
    typedef generator_type_radio_button_interface *radio_buttons_element;

    radio_buttons_const_iterator selected = std::find_if(radioButtons.begin(),
                                                         radioButtons.end(),
                                                         [] (radio_buttons_element i) -> bool
                                                         { return i->isChecked(); });

    return (selected != radioButtons.end()) ? (*selected)->get_type() :
                                              UNKNOWN_GENERATOR_TYPE;
}

void MainWindow::on_stepByStepCheckBox_toggled(bool checked)
{

}
