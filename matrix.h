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
        //throw "Not implemented";
    }
    Matrix(int N, int M);
    Matrix(const Matrix &mat);
    int getN() const{
        return n;
    }
    int getM() const{
        return m;
    }
    void setElem(int x, int y, double value);
    double getElem(int x, int y) const;
    const Matrix transpose();
    const Matrix operator + (Matrix &m2);
    const Matrix operator * (Matrix &m2);
    const Matrix operator - (Matrix &m2);
    const Matrix operator ^ (int power);

};

#endif // MATRIX_H
