enable_language(CXX)

include_directories(
   ${PROJECT_SOURCE_DIR}/src
)

file(GLOB source_files
"${PROJECT_SOURCE_DIR}/tests/constructor_test.cpp"
"${PROJECT_SOURCE_DIR}/tests/operations_test.cpp"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(Catch2_main STATIC ${PROJECT_SOURCE_DIR}/tests/test_main.cpp)
add_library(MatrixLib STATIC ${PROJECT_SOURCE_DIR}/src/Matrix.cpp ${PROJECT_SOURCE_DIR}/src/Matrix.hpp)

add_executable(ConstructorTest "${PROJECT_SOURCE_DIR}/tests/constructor_test.cpp")
add_test(NAME constructorlibtest COMMAND ConstructorTest) 
target_link_libraries(ConstructorTest PRIVATE MatrixLib Catch2_main)

add_executable(OperatorTest "${PROJECT_SOURCE_DIR}/tests/operations_test.cpp")
add_test(NAME operatorlibtest COMMAND OperatorTest) 
target_link_libraries(OperatorTest PRIVATE MatrixLib Catch2_main)
