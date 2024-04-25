cmake_minimum_required(VERSION 3.20)
project(CppProjectTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# cmake --graphviz=[output.dot] .

# find package
find_package(TCL REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(src)
add_subdirectory(test)