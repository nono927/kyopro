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

add_executable(test_factorial test_factorial.cpp)
target_link_libraries(test_factorial gtest_main)
add_test(NAME test_factorial COMMAND test_factorial)

add_executable(test_prime_factorization test_prime_factorization.cpp)
target_link_libraries(test_prime_factorization gtest_main)
add_test(NAME test_prime_factorization COMMAND test_prime_factorization)

add_executable(test_compressor test_compressor.cpp)
target_link_libraries(test_compressor gtest_main)
add_test(NAME test_compressor COMMAND test_compressor)

add_executable(test_lca test_lca.cpp)
target_link_libraries(test_lca gtest_main)
add_test(NAME test_lca COMMAND test_lca)