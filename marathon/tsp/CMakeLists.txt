cmake_minimum_required(VERSION 3.0)
project(tsp CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -O2)

include_directories(include)
add_subdirectory(src)