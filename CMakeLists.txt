CMAKE_MINIMUM_REQUIRED(VERSION 3.3 FATAL_ERROR)
PROJECT(CGALExamples)
find_package(CGAL QUIET)
include(${CGAL_USE_FILE})
#set(CMAKE_SUPPRESS_REGENERATION FALSE)
add_subdirectory(HelloWorld)
add_subdirectory(FloatCompute)
add_subdirectory(exact)

