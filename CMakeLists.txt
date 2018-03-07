# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.6)
project (pazymiai)
set(CMAKE_CCX_STANDARD 11)
# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
 #add_executable (helloDemo main.cpp randutils.hpp  notworking.h)
set(SOURCE_FILES main.cpp randutils.hpp pazym.cpp pazym.h )
add_executable(pazymiai ${SOURCE_FILES})
#add_executable (masyvai masyvai.cpp randutils.hpp)
