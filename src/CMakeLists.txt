# Make executable file (target)
add_executable(my_project
        main.cpp
)

# Make library (target)
add_library(my_library
        STATIC
        myFunction.cpp
        myClass.cpp
)
# Let the library and executable file (by PUBLIC OPTION) know the header file's location
target_include_directories(my_library
        PUBLIC
        ${CMAKE_SOURCE_DIR}/src
)

# Link binary and library
target_link_libraries(my_project
        PUBLIC
        my_library
)



