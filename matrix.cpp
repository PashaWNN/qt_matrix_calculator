#include "matrix.h"
#include "algorithm"

Matrix::Matrix(int N, int M)
{ // Constructor with matrix size
        n = N; m = M;
        for (int i = 0; i < n; i++) {
            QVector<double> temp;
            for (int j = 0; j < m; j++) {
                temp.push_back(0.0);
            }
            data.push_back(temp);
        }
}

Matrix::Matrix(const Matrix &mat)
{
    n = mat.getN(); m = mat.getM();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = mat.getElem(i, j);
        }
    }
}


void Matrix::setElem(int x, int y, double value) {
    data[x][y] = value;
}

double Matrix::getElem(int x, int y) const {
    return data[x][y];
}

const Matrix Matrix::transpose() {
    if (n != m) {
        throw "Транспонировать можно только квадратные матрицы!";
    }
    Matrix res(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; i < m; j++) {
            res.setElem(j, i, data[i][j]);
        }
    }
    return res;
}

const Matrix Matrix::operator +(Matrix &m2) {
    if (n != m2.n || m != m2.m) {
        throw "Складывать можно только матрицы с одинаковой размерностью!";
    }
    Matrix res(std::min(n, m2.n), std::min(m, m2.m));
    for (int i = 0; i < res.getN(); i++) {
        for (int j = 0; j < res.getM(); j++) {
            res.setElem(i, j, data[i][j] + m2.getElem(i, j));
        }
    }
    return res;
}

const Matrix Matrix::operator -(Matrix &m2) {
    if (n != m2.n || m != m2.m) {
        throw "Вычитать можно только матрицы с одинаковой размерностью!";
    }
    Matrix res(std::min(n, m2.n), std::min(m, m2.m));
    for (int i = 0; i < res.getN(); i++) {
        for (int j = 0; j < res.getM(); j++) {
            res.setElem(i, j, data[i][j] - m2.getElem(i, j));
        }
    }
    return res;
}

const Matrix Matrix::operator *(Matrix &m2) {
    Matrix res(n, m2.m);
    if (m != m2.n) {
        throw "Матрицы должны быть согласованы!";
    }
    for (int i = 0; i < res.n; i++) {
        for (int j = 0; j < res.m; j++) {
            int value = 0;
            for (int p = 0; p < m; p++) {
                value += data[i][p] * m2.getElem(p, j);
            }
            res.setElem(i, j, value);
        }
    }
    return res;
}

const Matrix Matrix::operator ^(int power) {
    Matrix res(n, m);
    for (int i = 0; i < power; i++) {
        res = res * *this;
    }
    return res;
}
