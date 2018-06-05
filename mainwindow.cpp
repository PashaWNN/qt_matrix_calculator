#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMessageBox"

const int OP_SUM = 1;
const int OP_MULTIPLY = 2;
const int OP_DIVIDE = 3;
const int OP_SUB = 4;
const int OP_POW = 5;
const int OP_TRANS = 6;
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_act_quit_triggered()
{
    MainWindow::close();
}

void do_binary_operation(QTableWidget* m1, QTableWidget* m2, int operation, QTableWidget* result) {
    Matrix matrix1(m1->rowCount(), m2->columnCount());
    for (int i = 0; i < matrix1.getN(); i++) {
        for (int j = 0; j < matrix1.getM(); j++) {
            QTableWidgetItem* elem = m1->item(i, j);
            if (elem && !elem->text().isEmpty()) {
                matrix1.setElem(i, j, elem->text().toDouble());
            } else throw "Не полностью заполнена матрица 1!";
        }
    }
    Matrix matrix2(m2->rowCount(), m2->columnCount());
    for (int i = 0; i < matrix2.getN(); i++) {
        for (int j = 0; j < matrix2.getM(); j++) {
            QTableWidgetItem* elem = m2->item(i, j);
            if (elem && !elem->text().isEmpty()) {
                matrix2.setElem(i, j, elem->text().toDouble());
            } else throw "Не полностью заполнена матрица 2!";
        }
    }
}

void refresh_table(QTableWidget* tbl, int row, int col) {
    QString txt = tbl->selectedItems().back()->text(); // Getting text from updated item
    qDebug() << QString("Updated item(%1, %2): '%3'").arg(QString::number(row),
                                                          QString::number(col),
                                                          txt);
    bool ok;
    txt.toDouble(&ok);
    if (!ok && !txt.isEmpty()) {
        QMessageBox mbox;
        mbox.critical(0, "Неправильный ввод!", "Нужно вводить только числа.");
        mbox.show();
        tbl->setItem(row, col, new QTableWidgetItem("0"));
    }

    if (row == tbl->rowCount() - 1) {
        if (txt != "") { // If text added to last item
            tbl->setRowCount(tbl->rowCount() + 1); // Increase row count
            }
        } else if (row == tbl->rowCount() - 2) { // Else check if we have to decrease it
        bool flag = false;
        for (int i = 0; i < tbl->columnCount() - 1; i++) {
            QTableWidgetItem* item = tbl->item(tbl->rowCount() - 2, i);
            if (item && !item->text().isEmpty()) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            tbl->setRowCount(tbl->rowCount() - 1);
        }
    }
    if (col == tbl->columnCount() - 1) {
        if (txt != "") { // If text added to last item
            tbl->setColumnCount(tbl->columnCount() + 1); // Increase col count
            }
        } else if (col == tbl->columnCount() - 2) { // Else check if we have to decrease it
        bool flag = false;
        for (int i = 0; i < tbl->rowCount() - 1; i++) {
            QTableWidgetItem* item = tbl->item(i, tbl->columnCount() - 2);
            if (item && !item->text().isEmpty()) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            tbl->setColumnCount(tbl->columnCount() - 1);
        }
    }
}

void MainWindow::on_tbl_mat_1_cellChanged(int row, int column)
{
    refresh_table(ui->tbl_mat_1, row, column);
}



void MainWindow::on_tbl_mat_2_cellChanged(int row, int column)
{
    refresh_table(ui->tbl_mat_2, row, column);
}


