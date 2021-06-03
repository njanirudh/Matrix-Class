#include "catch.hpp"

#include "Matrix.hpp"
#include <iostream>

using namespace nj;

TEST_CASE("Matrix comparator", "[comparator]")
{

  nj::Matrix mat1({{1,2,3},
                   {4,5,6}});
            
  nj::Matrix mat2({{5,2,7},
                   {2,8,6}});

  SECTION("Equality"){
    REQUIRE(1 == (mat1 == mat1));
    REQUIRE(0 == (mat1 == mat2));
  }

  SECTION("Inequality"){
    REQUIRE(1 == (mat1 != mat2));
    REQUIRE(0 == (mat1 != mat1));
  }

}

TEST_CASE("Vector-matrix arithematic", "[arithmetic]") 
{
  SECTION("Multiplication"){
    nj::Matrix mat6({{1,2,3},
                   {4,5,6},
                   {7,8,9}});
    nj::Matrix mat7{{{1},{1},{1}}};
    nj::Matrix result4{{{6},{15},{24}}};
    REQUIRE(result4 == (mat6*mat7));
  }
}

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

  SECTION("Multiplication"){
    nj::Matrix mat5({{1,2,3},
                   {4,5,6},
                   {7,8,9}});
    nj::Matrix result3({{30,36,42},
                   {66,81,96},
                   {102,126,150}});
    REQUIRE(result3 == (mat5*mat5));
  }

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