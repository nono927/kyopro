#include "gtest/gtest.h"
#include "trie_tree.hpp"
#include <string>

TEST(TrieTree, Add) {
    TrieTree t;
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::string s3 = "application";
    std::string s4 = "app";
    std::string s5 = "bananana";

    t.add(s1);
    t.add(s2);
    t.add(s3);

    ASSERT_TRUE(t.find(s1));
    ASSERT_TRUE(t.find(s2));
    ASSERT_TRUE(t.find(s3));
    ASSERT_FALSE(t.find(s4));
    ASSERT_FALSE(t.find(s5));
}
