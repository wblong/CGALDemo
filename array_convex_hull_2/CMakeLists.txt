# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


cmake_minimum_required(VERSION 3.3)
project( array_convex_hull_2 )
add_executable(array_convex_hull_2 array_convex_hull_2.cpp)
target_link_libraries(array_convex_hull_2 ${CGAL_LIBRARIES})