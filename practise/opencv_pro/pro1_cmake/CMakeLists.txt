CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 
project( DisplayImage ) 
find_package( OpenCV REQUIRED ) 
add_executable( main main.cpp ) 
target_link_libraries( main ${OpenCV_LIBS} ) 

