# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bradybodily/Repositories/CS3460/Hw6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bradybodily/Repositories/CS3460/Hw6/build

# Utility rule file for ClangFormat.

# Include the progress variables for this target.
include CMakeFiles/ClangFormat.dir/progress.make

CMakeFiles/ClangFormat:
	/usr/local/bin/clang-format -i -style=file /Users/bradybodily/Repositories/CS3460/Hw6/Pattern.hpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternAcorn.hpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternBlinker.hpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternBlock.hpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternGlider.hpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternGosperGliderGun.hpp /Users/bradybodily/Repositories/CS3460/Hw6/LifeSimulator.hpp /Users/bradybodily/Repositories/CS3460/Hw6/Renderer.hpp /Users/bradybodily/Repositories/CS3460/Hw6/RendererConsole.hpp /Users/bradybodily/Repositories/CS3460/Hw6/rlutil.h /Users/bradybodily/Repositories/CS3460/Hw6/PatternAcorn.cpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternBlinker.cpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternBlock.cpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternGlider.cpp /Users/bradybodily/Repositories/CS3460/Hw6/PatternGosperGliderGun.cpp /Users/bradybodily/Repositories/CS3460/Hw6/LifeSimulator.cpp /Users/bradybodily/Repositories/CS3460/Hw6/RendererConsole.cpp /Users/bradybodily/Repositories/CS3460/Hw6/main.cpp

ClangFormat: CMakeFiles/ClangFormat
ClangFormat: CMakeFiles/ClangFormat.dir/build.make

.PHONY : ClangFormat

# Rule to build all files generated by this target.
CMakeFiles/ClangFormat.dir/build: ClangFormat

.PHONY : CMakeFiles/ClangFormat.dir/build

CMakeFiles/ClangFormat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClangFormat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClangFormat.dir/clean

CMakeFiles/ClangFormat.dir/depend:
	cd /Users/bradybodily/Repositories/CS3460/Hw6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bradybodily/Repositories/CS3460/Hw6 /Users/bradybodily/Repositories/CS3460/Hw6 /Users/bradybodily/Repositories/CS3460/Hw6/build /Users/bradybodily/Repositories/CS3460/Hw6/build /Users/bradybodily/Repositories/CS3460/Hw6/build/CMakeFiles/ClangFormat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClangFormat.dir/depend
