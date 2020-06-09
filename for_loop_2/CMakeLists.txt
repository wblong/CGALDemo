# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


cmake_minimum_required(VERSION 3.3)
project( for_loop_2 )
# add_executable(for_loop_2 for_loop_2.cpp)
# target_link_libraries(for_loop_2 ${CGAL_LIBRARIES})
find_package(CGAL COMPONENTS Qt5)
add_definitions(-DCGAL_USE_BASIC_VIEWER)
create_single_source_cgal_program("for_loop_2.cpp")
target_link_libraries(for_loop_2 PUBLIC CGAL::CGAL_Qt5)