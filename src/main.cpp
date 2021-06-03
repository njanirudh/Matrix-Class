#include <iostream>

#include "Matrix.hpp"

int main(int, char**) {


    nj::Matrix mat1({{1,2,3},
                    {4,5,6},
                    {7,8,9}});

    nj::Matrix mat2({{1,2,3},
                    {4,5,6}});
            
    nj::Matrix mat3({{5,2,7},
                    {2,8,6}});

    auto equal = (mat2 != mat3);
    std::cout<< equal <<std::endl;

    // Matrix multiply
    auto mat_mul = mat1 * mat1; 
    std::cout<< mat_mul <<std::endl;

    // Matrix Scalar arithematic
    std::cout<< mat2 <<std::endl;
    mat2 *= 10;
    std::cout<< mat2 <<std::endl;
    mat2 /= 10;
    std::cout<< mat2 <<std::endl;

    nj::Matrix mat6({{1,2,3},
                   {4,5,6},
                   {7,8,9}});
    nj::Matrix mat7{{{1},{1},{1}}};

    auto result5 = mat6*mat7;    
    std::cout<< result5 <<std::endl;
 

}
