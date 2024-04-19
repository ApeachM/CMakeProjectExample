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

######### DOXYGEN ############
find_package(Doxygen REQUIRED)
# Configure the Doxygen input and output directories
set(
        DOXYGEN_INPUT_DIRS
        "${CMAKE_SOURCE_DIR}/src"
)
set(DOXYGEN_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/docs")

# Set Doxygen configuration options
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN NO)
set(DOXYGEN_OUTPUT_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

# Add a target for generating Doxygen documentation
doxygen_add_docs(
        doxygen_docs
        ${DOXYGEN_INPUT_DIR}
        COMMENT "Generate Doxygen documentation"
)
