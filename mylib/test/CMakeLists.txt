cmake_minimum_required(VERSION 3.0)

add_executable(test_mindist test_mindist.cpp)
target_link_libraries(test_mindist gtest_main)
add_test(NAME test_mindist COMMAND test_mindist)

add_executable(test_matrix test_matrix.cpp)
target_link_libraries(test_matrix gtest_main)
add_test(NAME test_matrix COMMAND test_matrix)

add_executable(test_trie_tree test_trie_tree.cpp)
target_link_libraries(test_trie_tree gtest_main)
add_test(NAME test_trie_tree COMMAND test_trie_tree)

add_executable(test_cht test_cht.cpp)
target_link_libraries(test_cht gtest_main)
add_test(NAME test_cht COMMAND test_cht)
