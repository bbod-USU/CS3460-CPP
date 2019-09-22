cmake_minimum_required(VERSION 3.14)
project(Assignment2)


set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        Assignment2.cpp)
add_executable(RandDistributions ${SOURCE_FILES})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(RandomDistributions PRIVATE /W4 /permissive-)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(RandomDistributions PRIVATE -Wall -Wextra -pedantic)
endif()
