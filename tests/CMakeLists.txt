include_directories(
   ${PROJECT_SOURCE_DIR}/src
)

add_library(Catch2_main STATIC ${PROJECT_SOURCE_DIR}/tests/test_main.cpp)

add_executable(Test 
            "${PROJECT_SOURCE_DIR}/tests/constructor_test.cpp"
            "${PROJECT_SOURCE_DIR}/tests/operations_test.cpp"
            )

add_test(NAME testlibtest COMMAND Test) # Command can be a target
target_link_libraries(Test PRIVATE Catch2_main)
