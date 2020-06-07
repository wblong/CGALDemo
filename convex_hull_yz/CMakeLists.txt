# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


cmake_minimum_required(VERSION 3.3)
project( convex_hull_yz )
add_executable(convex_hull_yz convex_hull_yz.cpp)
target_link_libraries(convex_hull_yz ${CGAL_LIBRARIES})