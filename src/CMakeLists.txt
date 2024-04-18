# Make executable file (target)
add_executable(my_project
        main.cpp
)

# Make library (target)
add_library(my_library
        STATIC
        myFunction.cpp
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
        ${TCL_LIBRARY}
        # /usr/lib/x86_64-linux-gnu/libtcl8.6.a z m dl # for static linking
)


# Set link option
#add_link_options("-static")  # global setting
#target_link_options(my_project PRIVATE "-static")

# Set compile option
#add_compile_options(-Wall -O2) # global setting
target_compile_options(my_project PRIVATE "-Wall" "-O2")

# Set compile definitions
#add_compile_definitions("-DLOG_LEVEL=2") # global setting
target_compile_definitions(my_project PRIVATE "-DLOG_LEVEL=2")


# Set the location of library file
# ARCHIVE_OUTPUT_DIRECTORY means the location of static library
# LIBRARY_OUTPUT_DIRECTORY means the location of dynamic library
set_target_properties(my_library PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib"
)
# Set the location of binary file
set_target_properties(my_project PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/bin"
)

