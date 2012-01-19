#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <vector>

#include "maze_generator_factory.h"
#include "gt_rb_interface.h"

class maze;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_generateButton_clicked();

    void on_stepByStepCheckBox_toggled(bool checked);

private:
    maze_generator_type getSelectedGeneratorType() const;
    void addGeneratorTypeRadioButtons();

    Ui::MainWindow *ui;

    std::vector<generator_type_radio_button_interface*> radioButtons;
};

#endif // MAINWINDOW_H
