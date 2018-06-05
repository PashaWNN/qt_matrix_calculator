#include "matrix.h"

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


void Matrix::setElem(int x, int y, double value) {
    data[x][y] = value;
}

double Matrix::getElem(int x, int y) {
    return data[x][y];
}
