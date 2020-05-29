# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


cmake_minimum_required(VERSION 3.3)
project( HelloWorld )
add_executable(HelloWorld points_and_segment.cpp)
target_link_libraries(HelloWorld ${CGAL_LIBRARIES})