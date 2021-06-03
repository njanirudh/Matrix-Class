#include "catch.hpp"

#include "Matrix.hpp"
#include <iostream>

using namespace nj;

TEST_CASE("Matrix constructor", "[constructor]")
{
  SECTION("Identity"){
    nj::Matrix mat1(2,2);
    nj::Matrix result1({{0,0},{0,0}});
    REQUIRE(mat1 == result1);
  }

  SECTION("Same Values"){
    nj::Matrix mat2(2,2,5);
    nj::Matrix result2({{5,5},{5,5}});
    REQUIRE(mat2 == result2);
  }

  SECTION("Initializer List"){
    nj::Matrix mat3({{1,2},{3,4}});
    nj::Matrix result3({{1,2},{3,4}});
    REQUIRE(mat3 == result3);
  }
}


TEST_CASE("Vector constructor", "[constructor]")
{
  SECTION("Identity Row Vec"){
    nj::Matrix mat1(1,2);
    nj::Matrix result1({{0,0}});
    REQUIRE(mat1 == result1);
  }

  SECTION("Identity Col Vec"){
    nj::Matrix mat2(3,1);
    nj::Matrix result2{{{0},{0},{0}}};
    REQUIRE(mat2 == result2);
  }

  SECTION("Copy constructor"){
    nj::Matrix mat3(3,3,5);
    nj::Matrix result3(mat3);
    REQUIRE(mat3 == result3);
  }

}
