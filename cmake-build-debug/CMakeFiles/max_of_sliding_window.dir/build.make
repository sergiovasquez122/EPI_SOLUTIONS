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
include CMakeFiles/max_of_sliding_window.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/max_of_sliding_window.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/max_of_sliding_window.dir/flags.make

CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.o: CMakeFiles/max_of_sliding_window.dir/flags.make
CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.o: ../max_of_sliding_window.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.o -c /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/max_of_sliding_window.cc

CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/max_of_sliding_window.cc > CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.i

CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/max_of_sliding_window.cc -o CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.s

# Object files for target max_of_sliding_window
max_of_sliding_window_OBJECTS = \
"CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.o"

# External object files for target max_of_sliding_window
max_of_sliding_window_EXTERNAL_OBJECTS =

max_of_sliding_window: CMakeFiles/max_of_sliding_window.dir/max_of_sliding_window.cc.o
max_of_sliding_window: CMakeFiles/max_of_sliding_window.dir/build.make
max_of_sliding_window: CMakeFiles/max_of_sliding_window.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable max_of_sliding_window"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/max_of_sliding_window.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/max_of_sliding_window.dir/build: max_of_sliding_window

.PHONY : CMakeFiles/max_of_sliding_window.dir/build

CMakeFiles/max_of_sliding_window.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/max_of_sliding_window.dir/cmake_clean.cmake
.PHONY : CMakeFiles/max_of_sliding_window.dir/clean

CMakeFiles/max_of_sliding_window.dir/depend:
	cd /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug /home/sergio/Desktop/EPIJudge-master/epi_judge_cpp/cmake-build-debug/CMakeFiles/max_of_sliding_window.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/max_of_sliding_window.dir/depend

