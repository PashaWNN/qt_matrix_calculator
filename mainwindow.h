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

    void on_btn_trans_clicked();

    void on_btn_sum_clicked();

    void on_btn_multiply_clicked();

    void on_btn_sub_clicked();

    void on_btn_pow_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
