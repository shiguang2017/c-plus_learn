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
CMAKE_SOURCE_DIR = /home/xionglin/NewDisk/345G/Clion_Project/__init__1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xionglin/NewDisk/345G/Clion_Project/__init__1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/__init__1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/__init__1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/__init__1.dir/flags.make

CMakeFiles/__init__1.dir/main.cpp.o: CMakeFiles/__init__1.dir/flags.make
CMakeFiles/__init__1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xionglin/NewDisk/345G/Clion_Project/__init__1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/__init__1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/__init__1.dir/main.cpp.o -c /home/xionglin/NewDisk/345G/Clion_Project/__init__1/main.cpp

CMakeFiles/__init__1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/__init__1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xionglin/NewDisk/345G/Clion_Project/__init__1/main.cpp > CMakeFiles/__init__1.dir/main.cpp.i

CMakeFiles/__init__1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/__init__1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xionglin/NewDisk/345G/Clion_Project/__init__1/main.cpp -o CMakeFiles/__init__1.dir/main.cpp.s

# Object files for target __init__1
__init__1_OBJECTS = \
"CMakeFiles/__init__1.dir/main.cpp.o"

# External object files for target __init__1
__init__1_EXTERNAL_OBJECTS =

__init__1: CMakeFiles/__init__1.dir/main.cpp.o
__init__1: CMakeFiles/__init__1.dir/build.make
__init__1: CMakeFiles/__init__1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xionglin/NewDisk/345G/Clion_Project/__init__1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable __init__1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__init__1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/__init__1.dir/build: __init__1

.PHONY : CMakeFiles/__init__1.dir/build

CMakeFiles/__init__1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/__init__1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/__init__1.dir/clean

CMakeFiles/__init__1.dir/depend:
	cd /home/xionglin/NewDisk/345G/Clion_Project/__init__1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xionglin/NewDisk/345G/Clion_Project/__init__1 /home/xionglin/NewDisk/345G/Clion_Project/__init__1 /home/xionglin/NewDisk/345G/Clion_Project/__init__1/cmake-build-debug /home/xionglin/NewDisk/345G/Clion_Project/__init__1/cmake-build-debug /home/xionglin/NewDisk/345G/Clion_Project/__init__1/cmake-build-debug/CMakeFiles/__init__1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/__init__1.dir/depend

