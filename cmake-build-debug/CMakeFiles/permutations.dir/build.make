# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/sergio/Downloads/clion-2018.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sergio/Downloads/clion-2018.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/permutations.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/permutations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/permutations.dir/flags.make

CMakeFiles/permutations.dir/permutations.cc.o: CMakeFiles/permutations.dir/flags.make
CMakeFiles/permutations.dir/permutations.cc.o: ../permutations.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/permutations.dir/permutations.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/permutations.dir/permutations.cc.o -c /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/permutations.cc

CMakeFiles/permutations.dir/permutations.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/permutations.dir/permutations.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/permutations.cc > CMakeFiles/permutations.dir/permutations.cc.i

CMakeFiles/permutations.dir/permutations.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/permutations.dir/permutations.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/permutations.cc -o CMakeFiles/permutations.dir/permutations.cc.s

# Object files for target permutations
permutations_OBJECTS = \
"CMakeFiles/permutations.dir/permutations.cc.o"

# External object files for target permutations
permutations_EXTERNAL_OBJECTS =

permutations: CMakeFiles/permutations.dir/permutations.cc.o
permutations: CMakeFiles/permutations.dir/build.make
permutations: CMakeFiles/permutations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable permutations"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/permutations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/permutations.dir/build: permutations

.PHONY : CMakeFiles/permutations.dir/build

CMakeFiles/permutations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/permutations.dir/cmake_clean.cmake
.PHONY : CMakeFiles/permutations.dir/clean

CMakeFiles/permutations.dir/depend:
	cd /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles/permutations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/permutations.dir/depend

