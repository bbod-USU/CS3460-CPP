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
CMAKE_SOURCE_DIR = /Users/bradybodily/Repositories/CS3460/HW8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bradybodily/Repositories/CS3460/HW8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW8.dir/flags.make

CMakeFiles/HW8.dir/main.cpp.o: CMakeFiles/HW8.dir/flags.make
CMakeFiles/HW8.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS3460/HW8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW8.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW8.dir/main.cpp.o -c /Users/bradybodily/Repositories/CS3460/HW8/main.cpp

CMakeFiles/HW8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW8.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS3460/HW8/main.cpp > CMakeFiles/HW8.dir/main.cpp.i

CMakeFiles/HW8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW8.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS3460/HW8/main.cpp -o CMakeFiles/HW8.dir/main.cpp.s

# Object files for target HW8
HW8_OBJECTS = \
"CMakeFiles/HW8.dir/main.cpp.o"

# External object files for target HW8
HW8_EXTERNAL_OBJECTS =

HW8: CMakeFiles/HW8.dir/main.cpp.o
HW8: CMakeFiles/HW8.dir/build.make
HW8: CMakeFiles/HW8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bradybodily/Repositories/CS3460/HW8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW8.dir/build: HW8

.PHONY : CMakeFiles/HW8.dir/build

CMakeFiles/HW8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW8.dir/clean

CMakeFiles/HW8.dir/depend:
	cd /Users/bradybodily/Repositories/CS3460/HW8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bradybodily/Repositories/CS3460/HW8 /Users/bradybodily/Repositories/CS3460/HW8 /Users/bradybodily/Repositories/CS3460/HW8/cmake-build-debug /Users/bradybodily/Repositories/CS3460/HW8/cmake-build-debug /Users/bradybodily/Repositories/CS3460/HW8/cmake-build-debug/CMakeFiles/HW8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW8.dir/depend

