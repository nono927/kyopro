cmake_minimum_required(VERSION 3.0)
project(test_mylibs CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -O2)

find_package(GTest REQUIRED)
include(GoogleTest)
enable_testing()

add_executable(test_mindist test_mindist.cpp)
target_link_libraries(test_mindist PRIVATE GTest::GTest GTest::Main)
gtest_discover_tests(test_mindist)

add_executable(test_matrix test_matrix.cpp)
target_link_libraries(test_matrix PRIVATE GTest::GTest GTest::Main)
gtest_discover_tests(test_matrix)

add_executable(test_trie_tree test_trie_tree.cpp)
target_link_libraries(test_trie_tree PRIVATE GTest::GTest GTest::Main)
gtest_discover_tests(test_trie_tree)
