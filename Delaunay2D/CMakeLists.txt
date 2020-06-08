# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


cmake_minimum_required(VERSION 3.3)
project( Delaunay2D )
add_executable(Delaunay2D Delaunay2D.cpp)
target_link_libraries(Delaunay2D ${CGAL_LIBRARIES})