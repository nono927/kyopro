cmake_minimum_required(VERSION 3.0)
project(test_mylibs CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -O2)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Add tests
enable_testing()

add_executable(test_mindist test_mindist.cpp)
target_link_libraries(test_mindist gtest_main)
add_test(NAME test_mindist COMMAND test_mindist)

add_executable(test_matrix test_matrix.cpp)
target_link_libraries(test_matrix gtest_main)
add_test(NAME test_matrix COMMAND test_matrix)

add_executable(test_trie_tree test_trie_tree.cpp)
target_link_libraries(test_trie_tree gtest_main)
add_test(NAME test_trie_tree COMMAND test_trie_tree)
