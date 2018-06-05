#include "QVector"
#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int n, m; // Matrix size
    QVector<QVector<double>> data;
public:
    Matrix() { // Default constructor
        throw "Not implemented";
    }
    Matrix(int N, int M);

    int getN() {
        return n;
    }
    int getM() {
        return m;
    }
    void setElem(int x, int y, double value);
    double getElem(int x, int y);

};

#endif // MATRIX_H
