cmake_minimum_required(VERSION 3.14)
project(Hw6)

set(CMAKE_CXX_STANDARD 17)

#
# Manually specifying all the source files.
#
set(HEADER_FILES
        Pattern.hpp
        PatternAcorn.hpp
        PatternBlinker.hpp
        PatternBlock.hpp
        PatternGlider.hpp
        PatternGosperGliderGun.hpp
        LifeSimulator.hpp
        Renderer.hpp
        RendererConsole.hpp
        rlutil.h)

set(SOURCE_FILES
        PatternAcorn.cpp
        PatternBlinker.cpp
        PatternBlock.cpp
        PatternGlider.cpp
        PatternGosperGliderGun.cpp
        LifeSimulator.cpp
        RendererConsole.cpp
        main.cpp)


add_executable(ConwaysLife ${HEADER_FILES} ${SOURCE_FILES})

#
# We want the C++ 17 standard for our project
#
set_property(TARGET ConwaysLife PROPERTY CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(ConwaysLife PRIVATE /W4 /permissive-)

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(ConwaysLife PRIVATE -Wall -Wextra -pedantic -Wl,--stack,10000000 -O3)
endif()
#
# Prepare a pre-build step to run clang-format over all the [ch]pp source files.
# Start by finding the location of the clang-format executable.
#
find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    #
    # Need to take the simple source file locations used for the project and get their full
    # file system locations for use in putting together the clang-format command line
    #
    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${HEADER_FILES} ${SOURCE_FILES})
        get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
        set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
    endforeach()


    #
    # This creates the clang-format target/command
    #
    add_custom_target(
            ClangFormat
            COMMAND ${CLANG_FORMAT}
            -i
            -style=file
            ${SOURCE_FILES_PATHS}
    )
    #
    # This makes the clang-format target a dependency of the main GoogleTestIntro project
    #
    add_dependencies(ConwaysLife ClangFormat)
else()
    message("Unable to find clang-format")
endif()

