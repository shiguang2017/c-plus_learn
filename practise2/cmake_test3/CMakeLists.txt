cmake_minimum_required (VERSION 2.6)
project (Tutorial)
add_executable(main main.cpp)

include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory (MathFunctions) 
 
# add the executable
add_executable (Tutorial tutorial.cxx)
target_link_libraries (Tutorial MathFunctions)
