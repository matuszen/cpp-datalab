#include <iostream>

#include "../include/matrix.hpp"

#ifdef _WIN32
    #include <windows.h>
#endif

inline Matrix::Matrix(void): _rows(0), _columns(0), _data(nullptr) {}

inline Matrix::Matrix(const Matrix& object): _rows(object._rows), _columns(object._columns) {
    _data = new double*[_rows];

    for (unsigned long i = 0; i < _rows; ++i)
        _data[i] = new double[_columns];

    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; ++j)
            _data[i][j] = object._data[i][j];
    
    this->reset();
}

inline Matrix::Matrix(unsigned long rows, unsigned long columns): _rows(rows), _columns(columns) {
    _data = new double*[rows];

    for (unsigned long i = 0; i < rows; ++i)
        _data[i] = new double[columns];
    
    this->reset();
}

// Matrix::Matrix(const double*[] content) {}

inline Matrix::~Matrix(void) noexcept {
    for (unsigned long i = 0; i < _rows; ++i)
        delete[] _data[i];
    
    delete[] _data;
}

void Matrix::fill(const double value) noexcept {
    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; ++j)
            _data[i][j] = value;
}

void Matrix::reset(void) noexcept {
    this->fill(1);
}
