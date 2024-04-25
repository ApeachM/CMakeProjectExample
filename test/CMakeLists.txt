# Add the executable target for the test
add_executable(my_tests test_main.cpp)

# Link the executable target for the test with gtest, gtest_main, and the library which will be tested.
target_link_libraries(
        my_tests
        PRIVATE
        my_library
        GTest::gtest
        GTest::gtest_main
)


# Set the location of binary file
set_target_properties(my_tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/bin"
)
