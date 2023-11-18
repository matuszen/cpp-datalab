#include <iostream>

#include "../include/matrix.hpp"

inline matrix::matrix(void): _rows(0), _columns(0), _data(nullptr) {}

inline matrix::matrix(const matrix& object): _rows(object._rows), _columns(object._columns), _data(new double*[_rows]) {
    for (unsigned long i = 0; i < _rows; ++i)
        _data[i] = new double[_columns];

    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; ++j)
            _data[i][j] = object._data[i][j];
    
    this->reset();
}

inline matrix::matrix(unsigned long rows, unsigned long columns): _rows(rows), _columns(columns), _data(new double*[rows]) {
    for (unsigned long i = 0; i < rows; ++i)
        _data[i] = new double[columns];
    
    this->reset();
}

// matrix::matrix(const double*[] content) {}

inline matrix::~matrix(void) noexcept {
    for (unsigned long i = 0; i < _rows; ++i)
        delete[] _data[i];
    
    delete[] _data;
}

void matrix::fill(const double value) noexcept {
    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; ++j)
            _data[i][j] = value;
}

void matrix::reset(void) noexcept {
    this->fill(0);
}

const double* matrix::operator[](unsigned long index) const {
    if (index < _rows)
        return _data[index];
    
    else
        throw std::out_of_range("Matrix index out of range");
}

double* matrix::operator[](unsigned long index) {
    if (index < _rows)
        return _data[index];
    
    else
        throw std::out_of_range("Matrix index out of range");
}

double& matrix::operator()(unsigned long row, unsigned long column) {
    if (row >= _rows)
        throw std::out_of_range(
            "Matrix has " + std::to_string(_rows - 1) + " rows but you tried to call an " + std::to_string(row) + " row"
        );
    
    if (column >= _columns)
        throw std::out_of_range(
            "Matrix has " + std::to_string(_columns - 1) + " columns but you tried to call an " + std::to_string(column) + " column"
        );
    
    return _data[row][column];
}

const double matrix::operator()(unsigned long row, unsigned long column) const {
    return this->operator()(row, column);
}

std::ostream& operator<<(std::ostream& stream_out, const matrix& object) noexcept {
    for (unsigned long i = 0; i < object._rows; ++i) {
        for (unsigned long j = 0; j < object._columns; ++j) {
            stream_out << object._data[i][j] << " ";
        }
        stream_out << std::endl;
    }

    return stream_out;
}