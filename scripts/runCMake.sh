##########################################################
# Set the working directory path
cd "$(dirname "$0")"

##########################################################
# -S means the location of CMake file
# -B means the location of build directory as `build`
cmake -S .. -B ../build

# This means executing building. It is similar with `make`
cmake --build ../build
##########################################################