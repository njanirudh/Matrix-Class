enable_language(CXX)

include_directories(
   ${PROJECT_SOURCE_DIR}/src
)

file(GLOB source_files
"${PROJECT_SOURCE_DIR}/tests/constructor_test.cpp"
"${PROJECT_SOURCE_DIR}/tests/operations_test.cpp"
)

add_library(Catch2_main STATIC ${PROJECT_SOURCE_DIR}/tests/test_main.cpp)
add_library(MatrixLib STATIC ${PROJECT_SOURCE_DIR}/src/Matrix.cpp ${PROJECT_SOURCE_DIR}/src/Matrix.hpp)

add_executable(Test ${source_files})

add_test(NAME testlibtest COMMAND Test) # Command can be a target
target_link_libraries(Test PRIVATE MatrixLib Catch2_main)
