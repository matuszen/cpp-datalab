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

inline matrix::~matrix(void) noexcept {
    for (unsigned long i = 0; i < _rows; ++i)
        delete[] _data[i];
    
    delete[] _data;
}

inline void matrix::fill(const double value) noexcept {
    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; ++j)
            _data[i][j] = value;
}

inline void matrix::reset(void) noexcept {
    this->fill(0);
}

matrix& matrix::add(const double value) {
    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; j++)
            this->_data[i][j] += value;

    return *this;
}

matrix& matrix::add(const matrix& object) {
    if (_rows != object._rows || _columns != object._columns)
        throw std::invalid_argument(
            "To add a matrix to a matrix, both must have the same dimensions"
        );
    
    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; j++)
            this->_data[i][j] += object._data[i][j];
    
    return *this;
}

matrix& matrix::sub(const double value) {
    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; j++)
            this->_data[i][j] -= value;

    return *this;
}

matrix& matrix::sub(const matrix& object) {
    if (_rows != object._rows || _columns != object._columns)
        throw std::invalid_argument(
            "To subtract a matrix to a matrix, both must have the same dimensions"
        );
    
    for (unsigned long i = 0; i < _rows; ++i)
        for (unsigned long j = 0; j < _columns; j++)
            this->_data[i][j] -= object._data[i][j];
    
    return *this;
}

unsigned long matrix::rows() const noexcept {
    return _rows;
}

unsigned long matrix::columns() const noexcept {
    return _columns;
}

inline const double* matrix::operator[](unsigned long index) const {
    if (index < _rows)
        return _data[index];
    
    else
        throw std::out_of_range("Matrix index out of range");
}

inline double* matrix::operator[](unsigned long index) {
    if (index < _rows)
        return _data[index];
    
    else
        throw std::out_of_range("Matrix index out of range");
}

inline double& matrix::operator()(unsigned long row, unsigned long column) {
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

inline const double matrix::operator()(unsigned long row, unsigned long column) const {
    return this->operator()(row, column);
}

matrix operator+(const matrix& object, const double scalar) {
    matrix buffer(object);
    buffer.add(scalar);

    return buffer;
}

matrix operator+(const double scalar, const matrix& object) {
    matrix buffer(object);
    buffer.add(scalar);
    
    return buffer;
}

matrix operator+(const matrix& first_object, const matrix& second_object) {
    matrix buffer(first_object);
    buffer.add(second_object);
    
    return buffer;
}

matrix& operator+=(matrix& object, const double scalar) {
    return object.add(scalar);
}

matrix& operator+=(matrix& first_object, const matrix& second_object) {
    return first_object.add(second_object);
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