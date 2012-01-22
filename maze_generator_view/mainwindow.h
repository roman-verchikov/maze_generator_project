#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

#include <memory>
#include <vector>

#include "maze_generator_factory.h"

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

    void on_stepByStepCheckBox_toggled(bool checked);

    void on_widthSpinBox_valueChanged(int arg1);

    void on_heightSpinBox_valueChanged(int arg1);
    void on_rbToggle(bool checked);

private:
    void generateMaze();
    maze_generator_type getSelectedGeneratorType() const;
    void addGeneratorTypeRadioButtons();

    Ui::MainWindow *ui;

    QButtonGroup radioButtonsGroup;
};

#endif // MAINWINDOW_H
