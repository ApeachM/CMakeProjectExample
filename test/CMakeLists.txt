# Add the executable target for the test
add_executable(my_function_tests test_function_main.cpp)
# Link the executable target for the test with gtest, gtest_main, and the library which will be tested.
target_link_libraries(
        my_function_tests
        PRIVATE
        my_library
        GTest::gtest
        GTest::gtest_main
)

# Also for the class code
add_executable(my_class_tests test_class_main.cpp)
target_link_libraries(
        my_class_tests
        PRIVATE
        my_library
        GTest::gtest
        GTest::gtest_main
)

include(CTest)
# To use gtest_discover_test function
include(GoogleTest)
# find the test cases automatically and execute them
gtest_discover_tests(my_function_tests)
gtest_discover_tests(my_class_tests)
