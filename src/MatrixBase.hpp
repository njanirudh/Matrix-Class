# ifndef NJ_MATRIX_BASE_HPP
# define NJ_MATRIX_BASE_HPP

namespace nj {

template <typename DataType, int Cols , int Rows>
class MatricBase
{
    public:
        const unsigned cols() const;
        const unsigned rows() const;
    private:
        unsigned int _cols = 0;
        unsigned int _rows = 0;
};


};

# endif