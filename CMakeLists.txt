cmake_minimum_required(VERSION 3.5)
project(App VERSION 1.0.0)

# creates static libraries by default, add SHARED after library name to create dynamic library
# there is a third lib type called MODULE

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(Grasshopper)
add_subdirectory(Sandbox)