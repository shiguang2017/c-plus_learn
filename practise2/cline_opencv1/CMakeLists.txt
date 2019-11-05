cmake_minimum_required(VERSION 3.8)
project(cline_opencv1)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES opencv1.cpp)
add_executable(cline_opencv1 ${SOURCE_FILES}) #下面是我加的 untitled为自己的工程名
find_package(OpenCV) #或者find_package(OpenCV3)
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES opencv1.cpp)
target_link_libraries( cline_opencv1 ${OpenCV_LIBS} ) #到这都是我加的
