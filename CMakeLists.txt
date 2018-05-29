cmake_minimum_required (VERSION 3.6)

project (pazymiai)

set(CMAKE_CCX_STANDARD 11)


SET(GCC_COVERAGE_COMPILE_FLAGS "-O3 -fopenmp -std=c++11")


add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set(SOURCE_FILES main.cpp randutils.hpp splibygrades.h splitbygradesclass.cpp splitbygradesclass.h calculation.cpp calculation.h filecheck.cpp filecheck.h catch.hpp)

add_executable(pazymiai ${SOURCE_FILES})

set(stuff catch.hpp testing.cpp calculation.cpp)


add_executable(testing ${stuff})

