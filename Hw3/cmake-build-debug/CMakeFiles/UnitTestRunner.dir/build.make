# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bradybodily/Repositories/CS3460/Hw3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UnitTestRunner.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UnitTestRunner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UnitTestRunner.dir/flags.make

CMakeFiles/UnitTestRunner.dir/distributions.cpp.o: CMakeFiles/UnitTestRunner.dir/flags.make
CMakeFiles/UnitTestRunner.dir/distributions.cpp.o: ../distributions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UnitTestRunner.dir/distributions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTestRunner.dir/distributions.cpp.o -c /Users/bradybodily/Repositories/CS3460/Hw3/distributions.cpp

CMakeFiles/UnitTestRunner.dir/distributions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTestRunner.dir/distributions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS3460/Hw3/distributions.cpp > CMakeFiles/UnitTestRunner.dir/distributions.cpp.i

CMakeFiles/UnitTestRunner.dir/distributions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTestRunner.dir/distributions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS3460/Hw3/distributions.cpp -o CMakeFiles/UnitTestRunner.dir/distributions.cpp.s

CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.o: CMakeFiles/UnitTestRunner.dir/flags.make
CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.o: ../TestDistributions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.o -c /Users/bradybodily/Repositories/CS3460/Hw3/TestDistributions.cpp

CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS3460/Hw3/TestDistributions.cpp > CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.i

CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS3460/Hw3/TestDistributions.cpp -o CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.s

# Object files for target UnitTestRunner
UnitTestRunner_OBJECTS = \
"CMakeFiles/UnitTestRunner.dir/distributions.cpp.o" \
"CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.o"

# External object files for target UnitTestRunner
UnitTestRunner_EXTERNAL_OBJECTS =

UnitTestRunner: CMakeFiles/UnitTestRunner.dir/distributions.cpp.o
UnitTestRunner: CMakeFiles/UnitTestRunner.dir/TestDistributions.cpp.o
UnitTestRunner: CMakeFiles/UnitTestRunner.dir/build.make
UnitTestRunner: lib/libgtest_maind.a
UnitTestRunner: lib/libgtestd.a
UnitTestRunner: CMakeFiles/UnitTestRunner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable UnitTestRunner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnitTestRunner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UnitTestRunner.dir/build: UnitTestRunner

.PHONY : CMakeFiles/UnitTestRunner.dir/build

CMakeFiles/UnitTestRunner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UnitTestRunner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UnitTestRunner.dir/clean

CMakeFiles/UnitTestRunner.dir/depend:
	cd /Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bradybodily/Repositories/CS3460/Hw3 /Users/bradybodily/Repositories/CS3460/Hw3 /Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug /Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug /Users/bradybodily/Repositories/CS3460/Hw3/cmake-build-debug/CMakeFiles/UnitTestRunner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UnitTestRunner.dir/depend

