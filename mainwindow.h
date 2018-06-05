#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_act_quit_triggered();

    void on_tbl_mat_1_cellChanged(int row, int column);

    void on_tbl_mat_2_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
