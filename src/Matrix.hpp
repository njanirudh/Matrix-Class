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
        friend Matrix operator +(Matrix& lhs, const Matrix& rhs);
        friend Matrix operator -(Matrix& lhs, const Matrix& rhs);
        friend Matrix operator *(Matrix& lhs, const Matrix& rhs);
    
    public:

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

        const Matrix& operator +=(const Matrix& rhs);
        const Matrix& operator -=(const Matrix& rhs);

        const Matrix& operator *=(const int& rhs);
        const Matrix& operator /=(const int& rhs);


};

// ----------- Constructors
Matrix::Matrix(unsigned rows, unsigned cols):nrows(rows), ncols(cols)
{
    this->ncols = cols;
    this->nrows = rows;

    // Default values set to 0 
    this->data = Vector2D{rows ,std::vector<int>(cols, 0)};
}

Matrix::Matrix(unsigned rows, unsigned cols, int value):Matrix(rows,cols)
{
    this->ncols = cols;
    this->nrows = rows;

    // Default values set to 0 
    this->data = Vector2D{rows ,std::vector<int>(cols, value)};
}

Matrix::Matrix(Vector2D vec2d):data(vec2d)
{
    this->nrows = vec2d.size();
    this->ncols = vec2d[0].size();
}

// ----------- 
const unsigned Matrix::get_cols() const
{
    return this->ncols;
}

const unsigned Matrix::get_rows() const
{
    return this->nrows;
}

auto Matrix::operator[](const int& i)
{
    return this->data[i];
}

std::ostream & operator<<(std::ostream &os, const Matrix& p)
{
    for (auto const row : p.data)
    {
        for (auto const value : row)
        {
            os << value << " ";
        }
        os << std::endl;
    }
    return os;
}

// ----------- Matrix Algebra
const Matrix& Matrix::operator +=(const Matrix& rhs)
{
    for(int row = 0; row < this->get_rows(); row++)
    {
        for(int col = 0; col < this->get_cols(); col++)
        {
            this->data[row][col] = this->data[row][col] + rhs.data[row][col];
        }
    }
    return *this;
}

const Matrix& Matrix::operator -=(const Matrix& rhs)
{
    for(int row = 0; row < this->get_rows(); row++)
    {
        for(int col = 0; col < this->get_cols(); col++)
        {
            this->data[row][col] = this->data[row][col] - rhs.data[row][col];
        }
    }
    return *this;
}

Matrix operator +(Matrix& lhs, const Matrix& rhs)
{
    lhs += rhs;
    return lhs;
}

Matrix operator -(Matrix& lhs, const Matrix& rhs)
{
    lhs -= rhs;
    return lhs;
}

Matrix operator *(Matrix& lhs, const Matrix& rhs)
{
    Matrix result(lhs.get_rows(), rhs.get_cols());
    for(int row = 0; row < lhs.get_rows(); row++)
    {
        for(int col = 0; col < rhs.get_cols(); col++)
        {
            result.data[row][col] = lhs.data[row][col] * rhs.data[col][row];
        }
    }
    return result;
}

// --------- Scalar Algebra
const Matrix& Matrix::operator *=(const int& rhs)
{
    for(int row = 0; row < this->get_rows(); row++)
    {
        for(int col = 0; col < this->get_cols(); col++)
        {
            this->data[row][col] = this->data[row][col] * rhs;
        }
    }
    return *this;
}

const Matrix& Matrix::operator /=(const int& rhs)
{
    for(int row = 0; row < this->get_rows(); row++)
    {
        for(int col = 0; col < this->get_cols(); col++)
        {
            this->data[row][col] = this->data[row][col] / rhs;
        }
    }
    return *this;
}

}

#endif 