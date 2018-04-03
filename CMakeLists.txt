cmake_minimum_required (VERSION 3.6)

project (pazymiai)

set(CMAKE_CCX_STANDARD 11)

SET(GCC_COVERAGE_COMPILE_FLAGS "-O2 -fopenmp")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set(SOURCE_FILES main.cpp randutils.hpp pazym.cpp pazym.h splibygrades.h)

add_executable(pazymiai ${SOURCE_FILES})
add_executable (masyvai masyvai.cpp randutils.hpp)
