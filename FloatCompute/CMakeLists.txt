# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


cmake_minimum_required(VERSION 3.3)
project( FloatCompute )
add_executable(FloatCompute surprising.cpp)
target_link_libraries(FloatCompute ${CGAL_LIBRARIES})