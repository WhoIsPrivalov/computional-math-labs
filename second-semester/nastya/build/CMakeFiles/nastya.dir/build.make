# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/main/git/computional-math-labs/second-semester/nastya

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/main/git/computional-math-labs/second-semester/nastya/build

# Include any dependencies generated for this target.
include CMakeFiles/nastya.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nastya.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nastya.dir/flags.make

CMakeFiles/nastya.dir/main.cpp.o: CMakeFiles/nastya.dir/flags.make
CMakeFiles/nastya.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/main/git/computional-math-labs/second-semester/nastya/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nastya.dir/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nastya.dir/main.cpp.o -c /home/main/git/computional-math-labs/second-semester/nastya/main.cpp

CMakeFiles/nastya.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nastya.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/main/git/computional-math-labs/second-semester/nastya/main.cpp > CMakeFiles/nastya.dir/main.cpp.i

CMakeFiles/nastya.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nastya.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/main/git/computional-math-labs/second-semester/nastya/main.cpp -o CMakeFiles/nastya.dir/main.cpp.s

CMakeFiles/nastya.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/nastya.dir/main.cpp.o.requires

CMakeFiles/nastya.dir/main.cpp.o.provides: CMakeFiles/nastya.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/nastya.dir/build.make CMakeFiles/nastya.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/nastya.dir/main.cpp.o.provides

CMakeFiles/nastya.dir/main.cpp.o.provides.build: CMakeFiles/nastya.dir/main.cpp.o


# Object files for target nastya
nastya_OBJECTS = \
"CMakeFiles/nastya.dir/main.cpp.o"

# External object files for target nastya
nastya_EXTERNAL_OBJECTS =

nastya: CMakeFiles/nastya.dir/main.cpp.o
nastya: CMakeFiles/nastya.dir/build.make
nastya: CMakeFiles/nastya.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/main/git/computional-math-labs/second-semester/nastya/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nastya"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nastya.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nastya.dir/build: nastya

.PHONY : CMakeFiles/nastya.dir/build

CMakeFiles/nastya.dir/requires: CMakeFiles/nastya.dir/main.cpp.o.requires

.PHONY : CMakeFiles/nastya.dir/requires

CMakeFiles/nastya.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nastya.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nastya.dir/clean

CMakeFiles/nastya.dir/depend:
	cd /home/main/git/computional-math-labs/second-semester/nastya/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/main/git/computional-math-labs/second-semester/nastya /home/main/git/computional-math-labs/second-semester/nastya /home/main/git/computional-math-labs/second-semester/nastya/build /home/main/git/computional-math-labs/second-semester/nastya/build /home/main/git/computional-math-labs/second-semester/nastya/build/CMakeFiles/nastya.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nastya.dir/depend

