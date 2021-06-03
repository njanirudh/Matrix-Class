#include "catch.hpp"

#include "Matrix.hpp"
#include <iostream>

using namespace nj;


TEST_CASE("Matrix arithematic", "[arithmetic]") 
{

  nj::Matrix mat1({{1,2,3},
                   {4,5,6}});
            
  nj::Matrix mat2({{5,2,7},
                   {2,8,6}});


  SECTION("Addition"){
    nj::Matrix result1({{6,4,10},
                        {6,13,12}});
    auto mat3 = mat1 + mat2; 
    REQUIRE(mat3 == result1);
  }

  SECTION("Subtraction"){
    nj::Matrix result2({{-4,0,-4},
                        {2,-3,0}});
    auto mat4 = mat1 - mat2; 
    REQUIRE(mat4 == result2);
  }

  // SECTION("Multiplication"){
  //   std::vector<int> v( 5 );
  //   REQUIRE( v.size() == 5 );
  // }

}

TEST_CASE("Scalar arithematic", "[arithmetic]") 
{
  nj::Matrix mat1({{1,2,3},
                   {4,5,6}});

  SECTION("Multiplication"){
    nj::Matrix result1({{10,20,30},
                        {40,50,60}});
    mat1 *= 10;
    REQUIRE( mat1 == result1 );
  }

  SECTION("Division"){
    nj::Matrix result1({{10,20,30},
                        {40,50,60}});
    mat1 *= 10;
    REQUIRE( mat1 == result1 );
  }
  
}