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
    Matrix res(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; i < m; j++) {
            res.setElem(j, i, data[i][j]);
        }
    }
    return res;
}

const Matrix Matrix::operator +(Matrix &m2) {
    Matrix res(std::min(n, m2.n), std::min(m, m2.m));
    for (int i = 0; i < res.getN(); i++) {
        for (int j = 0; j < res.getM(); j++) {
            res.setElem(i, j, data[i][j] + m2.getElem(i, j));
        }
    }
    return res;
}

const Matrix Matrix::operator *(Matrix &m2) {
    Matrix res(std::min(n, m2.n), std::min(m, m2.m));
    for (int i = 0; i < res.n; i++) {
        for (int j = 0; j < res.m; j++) {
            res.setElem(i, j, data[i][j] * m2.getElem(i, j));
        }
    }
    return res;
}
