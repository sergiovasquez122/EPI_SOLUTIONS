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
include CMakeFiles/regular_expression.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/regular_expression.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/regular_expression.dir/flags.make

CMakeFiles/regular_expression.dir/regular_expression.cc.o: CMakeFiles/regular_expression.dir/flags.make
CMakeFiles/regular_expression.dir/regular_expression.cc.o: ../regular_expression.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/regular_expression.dir/regular_expression.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/regular_expression.dir/regular_expression.cc.o -c /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/regular_expression.cc

CMakeFiles/regular_expression.dir/regular_expression.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/regular_expression.dir/regular_expression.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/regular_expression.cc > CMakeFiles/regular_expression.dir/regular_expression.cc.i

CMakeFiles/regular_expression.dir/regular_expression.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/regular_expression.dir/regular_expression.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/regular_expression.cc -o CMakeFiles/regular_expression.dir/regular_expression.cc.s

# Object files for target regular_expression
regular_expression_OBJECTS = \
"CMakeFiles/regular_expression.dir/regular_expression.cc.o"

# External object files for target regular_expression
regular_expression_EXTERNAL_OBJECTS =

regular_expression: CMakeFiles/regular_expression.dir/regular_expression.cc.o
regular_expression: CMakeFiles/regular_expression.dir/build.make
regular_expression: CMakeFiles/regular_expression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable regular_expression"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/regular_expression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/regular_expression.dir/build: regular_expression

.PHONY : CMakeFiles/regular_expression.dir/build

CMakeFiles/regular_expression.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/regular_expression.dir/cmake_clean.cmake
.PHONY : CMakeFiles/regular_expression.dir/clean

CMakeFiles/regular_expression.dir/depend:
	cd /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles/regular_expression.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/regular_expression.dir/depend

