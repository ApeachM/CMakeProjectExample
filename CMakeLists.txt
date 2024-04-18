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


# Set link option
#add_link_options("-static")  # global setting
target_link_options(my_project PRIVATE "-static")

# Set compile option
#add_compile_options(-Wall -O2) # global setting
target_compile_options(my_project PRIVATE "-Wall" "-O2")

# Set compile definitions
#add_compile_definitions("-DLOG_LEVEL=2") # global setting
target_compile_definitions(my_project PRIVATE "-DLOG_LEVEL=2")
target_compile_definitions(my_project PRIVATE
        "-DMAX_BUFFER_SIZE=1024"
        "-DUSE_FEATURE_X"
)


