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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sailor_mbp/CLionProjects/ff_list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sailor_mbp/CLionProjects/ff_list/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ff_list.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ff_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ff_list.dir/flags.make

CMakeFiles/ff_list.dir/main.cpp.o: CMakeFiles/ff_list.dir/flags.make
CMakeFiles/ff_list.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sailor_mbp/CLionProjects/ff_list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ff_list.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ff_list.dir/main.cpp.o -c /Users/sailor_mbp/CLionProjects/ff_list/main.cpp

CMakeFiles/ff_list.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ff_list.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sailor_mbp/CLionProjects/ff_list/main.cpp > CMakeFiles/ff_list.dir/main.cpp.i

CMakeFiles/ff_list.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ff_list.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sailor_mbp/CLionProjects/ff_list/main.cpp -o CMakeFiles/ff_list.dir/main.cpp.s

# Object files for target ff_list
ff_list_OBJECTS = \
"CMakeFiles/ff_list.dir/main.cpp.o"

# External object files for target ff_list
ff_list_EXTERNAL_OBJECTS =

ff_list: CMakeFiles/ff_list.dir/main.cpp.o
ff_list: CMakeFiles/ff_list.dir/build.make
ff_list: CMakeFiles/ff_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sailor_mbp/CLionProjects/ff_list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ff_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ff_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ff_list.dir/build: ff_list

.PHONY : CMakeFiles/ff_list.dir/build

CMakeFiles/ff_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ff_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ff_list.dir/clean

CMakeFiles/ff_list.dir/depend:
	cd /Users/sailor_mbp/CLionProjects/ff_list/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sailor_mbp/CLionProjects/ff_list /Users/sailor_mbp/CLionProjects/ff_list /Users/sailor_mbp/CLionProjects/ff_list/cmake-build-debug /Users/sailor_mbp/CLionProjects/ff_list/cmake-build-debug /Users/sailor_mbp/CLionProjects/ff_list/cmake-build-debug/CMakeFiles/ff_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ff_list.dir/depend

