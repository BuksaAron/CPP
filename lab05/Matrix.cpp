//
// Created by buksa on 10/15/2025.
//

#include "Matrix.h"

#include <random>

#include "../lab03/Point.h"

using namespace std;

Matrix::Matrix(int rows, int cols) {
    this->mCols = cols;
    this->mRows = rows;
    this->mElements.resize(rows*cols, 0);
}

Matrix::Matrix(const Matrix &other) {
    this->mCols = other.getCols();
    this->mRows = other.getRows();
    this->mElements = other.mElements;
}

Matrix::Matrix(Matrix &&other) noexcept {
    this->mCols = other.getCols();
    this->mRows = other.getRows();
    other.mRows = 0;
    other.mCols = 0;
    this->mElements = move(other.mElements);
    other.mElements.clear();
}

void Matrix::fillMatrix(double value) {
    std::fill(this->mElements.begin(), this->mElements.end(), value);
}

void Matrix::randomMatrix(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(0, 2000);
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i*this->mCols+j] + distribution();
        }
    }

}

std::istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is>>mat.mElements[i*mat.mCols+j];
        }
    }
    return is;
}

void Matrix::printMatrix(std::ostream &os) const {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            os<<this->mElements[i * this->mCols + j] << " ";
        }
        os << endl;
    }
}

std::ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os<<mat.mElements[i * mat.mCols + j] << " ";
        }
        os << endl;
    }
    return os;
    //mat.printMatrix(os);
}

Matrix operator+(const Matrix& x, const Matrix& y){
    if (x.mCols != y.mCols || x.mRows != y.mRows) {
        throw out_of_range("A ket matrix nem egyezik");
    }
    Matrix m(x);
    for (int i = 0; i < m.mElements.size(); ++i) {
        m.mElements[i] += y.mElements[i];
    }
    return m;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    vector<double>mult;
    mult.resize(x.mCols * x.mRows, 0);
    for (int i = 0; i < x.mRows; ++i)
        for (int j = 0; j < y.mCols; ++j)
            for (int k = 0; k < x.mCols; ++k) {
                mult[i * x.mCols +j] += x(i,k) * y(k,j);
            }
            Matrix m(x.mRows, y.mCols);
            m.mElements = mult;
            return m;
}

Matrix &Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        this->mRows = other.mRows;
        this->mCols = other.mCols;
        this->mElements = other.mElements;
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        this->mCols = other.getCols();
        this->mRows = other.getRows();
        other.mRows = 0;
        other.mCols = 0;
        this->mElements = move(other.mElements);
        other.mElements.clear();
    }
    return *this;
}

double * Matrix::operator[](int row) {
    if (row >= this->mRows || row < 0) {
        throw out_of_range("Out of bounds!");
    }
    return &this->mElements[row * this->mCols];
}

const double * Matrix::operator[](int row) const {
    if (row >= this->mRows || row < 0) {
        throw out_of_range("Out of bounds!");
    }
    return &this->mElements[row * this->mCols];
}

double &Matrix::operator()(int row, int col) {
    if (row >= this->mRows || row < 0 || col >= this->mCols || col < 0) {
        throw out_of_range("Out of bounds!");
    }
    return this->mElements[row * this->mCols+col];
}

const double &Matrix::operator()(int row, int col) const {
    if (row >= this->mRows || row < 0 || col >= this->mCols || col < 0) {
        throw out_of_range("Out of bounds!");
    }
    return this->mElements[row * this->mCols+col];
}

