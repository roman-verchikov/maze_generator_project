#include <QRadioButton>
#include <QMessageBox>

#include <algorithm>

#include "current_maze.h"
#include "maze.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wall_position_t.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow         (parent),
    ui                  (new Ui::MainWindow)
{
    ui->setupUi(this);

    addGeneratorTypeRadioButtons();
}

MainWindow::~MainWindow()
{
    current_maze::release();
    delete ui;
}

void MainWindow::generateMaze()
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
    const char *radioButtons[] = {
        "Random",
        "DFS"
    };
    const size_t radioButtonsLen = sizeof(radioButtons)/sizeof(*radioButtons);

    for(size_t i = 0; i < radioButtonsLen; ++i) {
        QRadioButton *rb = new QRadioButton(radioButtons[i]);

        connect(rb, SIGNAL(toggled(bool)), SLOT(on_rbToggle(bool)));

        radioButtonsGroup.addButton(rb, i);
        ui->verticalLayout->addWidget(rb);
    }
}

maze_generator_type MainWindow::getSelectedGeneratorType() const
{
    return (maze_generator_type)radioButtonsGroup.checkedId();
}

void MainWindow::on_stepByStepCheckBox_toggled(bool checked)
{
    if (checked) {
        current_maze::instance()->restore_previous_step();
    } else {
        current_maze::instance()->goto_last_step();
    }
}

void MainWindow::on_widthSpinBox_valueChanged(int)
{
    generateMaze();
}

void MainWindow::on_heightSpinBox_valueChanged(int)
{
    generateMaze();
}

void MainWindow::on_rbToggle(bool)
{
    generateMaze();
}
