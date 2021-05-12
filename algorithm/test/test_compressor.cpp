#include "gtest/gtest.h"
#include "compressor.hpp"

TEST(TestCompressor, Unique) {
    std::vector<int> v = {2, 3, 5, 7, 11};
    Compressor<int> compressor(v);

    std::vector<size_t> indexes = compressor.compress(v);
    std::vector<size_t> indexes_gt = {0, 1, 2, 3, 4};
    ASSERT_EQ(indexes.size(), 5);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(indexes[i], indexes_gt[i]);
        ASSERT_EQ(compressor[indexes[i]], v[i]);
    }
}

TEST(TestCompressor, Multiset) {
    std::vector<int> v = {47, 47, 21, 53, 21};
    Compressor<int> compressor(v);

    std::vector<size_t> indexes = compressor.compress(v);
    std::vector<size_t> indexes_gt = {1, 1, 0, 2, 0};
    ASSERT_EQ(indexes.size(), 5);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(indexes[i], indexes_gt[i]);
        ASSERT_EQ(compressor[indexes[i]], v[i]);
    }
}