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
include CMakeFiles/making_change.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/making_change.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/making_change.dir/flags.make

CMakeFiles/making_change.dir/making_change.cc.o: CMakeFiles/making_change.dir/flags.make
CMakeFiles/making_change.dir/making_change.cc.o: ../making_change.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/making_change.dir/making_change.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/making_change.dir/making_change.cc.o -c /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/making_change.cc

CMakeFiles/making_change.dir/making_change.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/making_change.dir/making_change.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/making_change.cc > CMakeFiles/making_change.dir/making_change.cc.i

CMakeFiles/making_change.dir/making_change.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/making_change.dir/making_change.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/making_change.cc -o CMakeFiles/making_change.dir/making_change.cc.s

# Object files for target making_change
making_change_OBJECTS = \
"CMakeFiles/making_change.dir/making_change.cc.o"

# External object files for target making_change
making_change_EXTERNAL_OBJECTS =

making_change: CMakeFiles/making_change.dir/making_change.cc.o
making_change: CMakeFiles/making_change.dir/build.make
making_change: CMakeFiles/making_change.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable making_change"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/making_change.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/making_change.dir/build: making_change

.PHONY : CMakeFiles/making_change.dir/build

CMakeFiles/making_change.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/making_change.dir/cmake_clean.cmake
.PHONY : CMakeFiles/making_change.dir/clean

CMakeFiles/making_change.dir/depend:
	cd /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles/making_change.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/making_change.dir/depend

