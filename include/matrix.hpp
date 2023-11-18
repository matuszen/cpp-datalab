#ifndef MATRIX_HPP
#define MATRIX_HPP


class matrix {
    private:
        unsigned long _rows;
        unsigned long _columns;

        double** _data;

    public:
        /* Default constructor for matrix object */
        inline matrix(void);

        /* Copy constructor for matrix object
        @param object a deep copy of this object will be used to initialize the new object */
        inline matrix(const matrix& object);

        /* Constructor for matrix object
        @param rows number of rows in Matrix
        @param columns number of columns in Matrix */
        inline matrix(const unsigned long rows, const unsigned long columns);

        /* Destructor for matrix object */
        inline ~matrix(void) noexcept;

        /* Fills the matrix with a given value
        @param value the value with which the matrix will be filled */
        inline void fill(const double value) noexcept;

        /* Fills the matrix with `0` value */
        inline void reset() noexcept;

        matrix& add(const double value);
        matrix& add(const matrix& object);

        matrix& sub(const double value);
        matrix& sub(const matrix& object);

        unsigned long rows() const noexcept;
        unsigned long columns() const noexcept;

        inline double* operator[](unsigned long);
        inline const double* operator[](unsigned long) const;

        inline double& operator()(unsigned long, unsigned long);
        inline const double operator()(unsigned long, unsigned long) const;

        friend matrix operator+(const matrix&, const double);
        friend matrix operator+(const double, const matrix&);
        friend matrix operator+(const matrix&, const matrix&);

        friend matrix& operator+=(matrix&, const double);
        friend matrix& operator+=(matrix&, const matrix&);

        friend std::ostream& operator<<(std::ostream&, const matrix&) noexcept;
};

#endif
