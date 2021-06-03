cmake_minimum_required(VERSION 3.0.0)
project(Matrix VERSION 0.1.0)

# Test 
include(CTest)
enable_testing()
add_subdirectory(tests)

include_directories(src)
file(GLOB source_files
"src/*.hpp"
"src/*.cpp"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Matrix ${source_files})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)