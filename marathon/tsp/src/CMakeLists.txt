add_library(tsp_exact SHARED tsp_exact.cpp)
add_library(tsp_heuristic SHARED tsp_heuristic.cpp)
add_executable(main main.cpp)
target_link_libraries(main tsp_exact tsp_heuristic)