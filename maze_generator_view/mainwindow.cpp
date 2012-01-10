#include <QMessageBox>

#include <current_maze.h>
#include <random_maze_generator.h>
#include <dfs_maze_generator.h>

#include "mainwindow.h"
#include "wall_position_t.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow     (parent),
    ui              (new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->randomMazeRadioBtn->setText(random_maze_generator().name().c_str());
    ui->type1MazeRadioBtn->setText(dfs_maze_generator().name().c_str());
}

MainWindow::~MainWindow()
{
    current_maze::release();
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    const size_t width  = ui->widthSpinBox->value();
    const size_t height = ui->heightSpinBox->value();
    const wall_position_t entrance = wall_position_t(location_t(-1,0), location_t(0,0));
    const wall_position_t exit     = wall_position_t(location_t(width-1,height), location_t(width,height));

    if (ui->randomMazeRadioBtn->isChecked()) {
        current_maze::set(random_maze_generator().generate(width,
                                                           height,
                                                           entrance,
                                                           exit));
    } else if (ui->type1MazeRadioBtn->isChecked()) {
        current_maze::set(dfs_maze_generator().generate(width,
                                                        height,
                                                        entrance,
                                                        exit));
    } else {
        QMessageBox::information(this,
                                 tr("Functionality not implemented"),
                                 tr("Selected maze generator is not implemented yet."),
                                 QMessageBox::Ok);
    }

    this->ui->mazeDrawingWidget->update();
}
