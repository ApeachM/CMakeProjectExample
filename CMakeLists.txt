cmake_minimum_required(VERSION 3.20)
project(CppProjectTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Make library (target)
add_library(my_library
        STATIC
        src/myFunction.cpp
)
target_include_directories(my_library
        PUBLIC
        include
)

# Make executable file (target)
add_executable(my_project
        src/main.cpp
)

# Link binary and library
target_link_libraries(my_project
        PUBLIC
        my_library
)