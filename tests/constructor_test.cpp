#include "catch.hpp"
#include "Matrix.hpp"

#include <iostream>

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
