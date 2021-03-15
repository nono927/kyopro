cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -O2)

add_library(tsp_exact STATIC tsp_exact.cpp)
add_executable(main main.cpp)
target_link_libraries(main tsp_exact)
