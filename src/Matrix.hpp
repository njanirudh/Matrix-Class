/**
 * Matrix Class
 *
 * @author Anirudh Narasimamurthy Jayasimha
 * Contact: anijaya9@gmail.com
 */


#ifndef INCLUDE_MATRIX_HPP
#define INCLUDE_MATRIX_HPP

#include <vector> // vector
#include <iostream> // cout, endl

namespace nj
{


/*!
Objects are stored as a vector of vector.
For large matrix and general impl use C style arrays or 'std::valarray' for slicing.
Only integer types can be stored for now. Template classes can be used to store different types.
(https://scicomp.stackexchange.com/questions/3159/is-it-a-good-idea-to-use-vectorvectordouble-to-form-a-matrix-class-for-high/3162)
(https://stackoverflow.com/questions/59530086/difference-between-array-vector-and-matrix-in-c)

We assume that the size of matrices during addition, subtraction, multiplication are correct.
ie. No size check is performed.
*/

using Vector2D = std::vector<std::vector<int>>;

/*!
@brief a class to store Matrix an perform general arithematic on it.

@requirement The class satisfies the following concept requirements:
- Basic
 - [DefaultConstructible](https://en.cppreference.com/w/cpp/named_req/DefaultConstructible):
   JSON values can be default constructed. The result will be a JSON null
   value.
 - [MoveConstructible](https://en.cppreference.com/w/cpp/named_req/MoveConstructible):
   A JSON value can be constructed from an rvalue argument.
 - [CopyConstructible](https://en.cppreference.com/w/cpp/named_req/CopyConstructible):
   A JSON value can be copy-constructed from an lvalue expression.
 - [Destructible](https://en.cppreference.com/w/cpp/named_req/Destructible):
   JSON values can be destructed.
*/

class Matrix
{
    private:
        unsigned nrows = 0;
        unsigned ncols = 0;
        int val = 0;
        Vector2D data;

        friend std::ostream & operator<<(std::ostream &os, const Matrix& p);

        // Matrix arithematic (Outputs new matrix)
        friend Matrix operator +(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator -(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator *(const Matrix& lhs, const Matrix& rhs);

        // Matrix comparison
        friend bool operator ==(const Matrix &lhs, const Matrix &rhs);
        friend bool operator !=(const Matrix &lhs, const Matrix &rhs);
    
    public:

        // Default constructors
        Matrix() = default; // DefaultConstructible
        Matrix(const Matrix&) = default; // MoveConstructible
        Matrix(Matrix&&) = default;	// CopyConstructible
        ~Matrix() = default; // Destructible

        Matrix(unsigned rows, unsigned cols);
        Matrix(unsigned rows, unsigned cols, int value);
        Matrix(Vector2D vec);

        const unsigned get_rows() const;
        const unsigned get_cols() const;

        auto operator [](const int& i);

        // Inplace matrix arithematic
        const Matrix& operator +=(const Matrix& rhs);
        const Matrix& operator -=(const Matrix& rhs);

        // Inplace scalar arithematic
        const Matrix& operator *=(const int& rhs);
        const Matrix& operator /=(const int& rhs);

};

}

#endif 