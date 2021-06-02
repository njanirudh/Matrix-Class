#include <iostream>

#include "src/Matrix.hpp"

int main(int, char**) {


    nj::Matrix mat1({{1,2,3},
                    {4,5,6}});
    nj::Matrix mat2({{5,2,7},
                    {2,8,6}});

    auto mat3 = mat1 + mat2;

    std::cout<< mat2 <<std::endl;
    mat2 *= 10;
    std::cout<< mat2 <<std::endl;
    mat2 /= 10;
    std::cout<< mat2 <<std::endl;
    
    std::cout<< mat3 <<std::endl;
}
