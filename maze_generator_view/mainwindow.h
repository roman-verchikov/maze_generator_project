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

    typedef std::vector<generator_type_radio_button_interface*> radio_buttons_vector;
    typedef radio_buttons_vector::iterator radio_buttons_iterator;
    typedef radio_buttons_vector::const_iterator radio_buttons_const_iterator;

    radio_buttons_vector radioButtons;
};

#endif // MAINWINDOW_H
