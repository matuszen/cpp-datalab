#ifndef MATRIX_HPP
#define MATRIX_HPP


class Matrix {
    private:
        unsigned long _rows;
        unsigned long _columns;

        double** _data;
    
    public:
        // Default constructor for Matrix class
        inline Matrix(void);

        // Copy constructor for Matrix class
        // @param object a deep copy of this object will be used to initialize the new object
        inline Matrix(const Matrix& object);

        // Constructor for Matrix class
        // @param rows number of rows in Matrix
        // @param columns number of columns in Matrix
        inline Matrix(const unsigned long rows, const unsigned long columns);

        // Matrix(const double*[]);

        // Destructor for Matrix class
        inline ~Matrix(void) noexcept;

        void fill(const double) noexcept;
        // Set
        void reset() noexcept;
};

#endif
