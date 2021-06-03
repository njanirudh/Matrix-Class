#include "Matrix.hpp"

using namespace nj;

namespace nj {
    
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

bool operator ==(const Matrix &lhs, const Matrix &rhs)
{
    bool equality = false;
    for(int row = 0; row < lhs.get_rows(); row++)
    {
        for(int col = 0; col < lhs.get_cols(); col++)
        {
            if(lhs.data[row][col] == rhs.data[row][col])
            {
                equality = true;
            }
            else
            {
                equality = false;
                return equality;
            }
                
        }
    }
    return equality;
}

bool operator !=(const Matrix &lhs, const Matrix &rhs)
{
    return !(lhs == rhs);
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

Matrix operator +(const Matrix& lhs, const Matrix& rhs)
{
    Matrix result(lhs.get_rows(), rhs.get_cols());
    for(int row = 0; row < lhs.get_rows(); row++)
    {
        for(int col = 0; col < lhs.get_cols(); col++)
        {
            result.data[row][col] = lhs.data[row][col] + rhs.data[row][col];
        }
    }
    return result;
}

Matrix operator -(const Matrix& lhs, const Matrix& rhs)
{
    Matrix result(lhs.get_rows(), rhs.get_cols());
    for(int row = 0; row < lhs.get_rows(); row++)
    {
        for(int col = 0; col < lhs.get_cols(); col++)
        {
            result.data[row][col] = lhs.data[row][col] - rhs.data[row][col];
        }
    }
    return result;
}

Matrix operator *(const Matrix& lhs, const Matrix& rhs)
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