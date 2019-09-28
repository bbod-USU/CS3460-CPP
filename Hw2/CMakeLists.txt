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

find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${SOURCE_FILES})
        get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
        set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
    endforeach()

    add_custom_target(
            ClangFormat COMMAND
            ${CLANG_FORMAT}
            -i
            -style=file
            ${SOURCE_FILES_PATHS})
    add_dependencies(RandDistributions ClangFormat)
endif()
