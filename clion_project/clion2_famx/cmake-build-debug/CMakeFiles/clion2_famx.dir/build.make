# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/xionglin/NewDisk/274G1/programfiles/clion-2018.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/xionglin/NewDisk/274G1/programfiles/clion-2018.3.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/clion2_famx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/clion2_famx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clion2_famx.dir/flags.make

CMakeFiles/clion2_famx.dir/main.cpp.o: CMakeFiles/clion2_famx.dir/flags.make
CMakeFiles/clion2_famx.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clion2_famx.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clion2_famx.dir/main.cpp.o -c /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/main.cpp

CMakeFiles/clion2_famx.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clion2_famx.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/main.cpp > CMakeFiles/clion2_famx.dir/main.cpp.i

CMakeFiles/clion2_famx.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clion2_famx.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/main.cpp -o CMakeFiles/clion2_famx.dir/main.cpp.s

# Object files for target clion2_famx
clion2_famx_OBJECTS = \
"CMakeFiles/clion2_famx.dir/main.cpp.o"

# External object files for target clion2_famx
clion2_famx_EXTERNAL_OBJECTS =

clion2_famx: CMakeFiles/clion2_famx.dir/main.cpp.o
clion2_famx: CMakeFiles/clion2_famx.dir/build.make
clion2_famx: CMakeFiles/clion2_famx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clion2_famx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clion2_famx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clion2_famx.dir/build: clion2_famx

.PHONY : CMakeFiles/clion2_famx.dir/build

CMakeFiles/clion2_famx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clion2_famx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clion2_famx.dir/clean

CMakeFiles/clion2_famx.dir/depend:
	cd /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/cmake-build-debug /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/cmake-build-debug /home/xionglin/NewDisk/345G/Clion_Project/clion2_famx/cmake-build-debug/CMakeFiles/clion2_famx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clion2_famx.dir/depend
