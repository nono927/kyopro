#include "gtest/gtest.h"
#include "prime_factorization.hpp"
#include <unordered_map>

TEST(TestPrimeFactorization, Normal) {
    int n = 120;
    auto v = prime_factorization(n);

    std::unordered_map<int, int> gt = {
        {2, 3}, {3, 1}, {5, 1},
    };

    for (auto &&[p, e]: v) {
        ASSERT_NE(gt.find(p), gt.end());
        ASSERT_EQ(e, gt[p]);
    }
}

TEST(TestPrimeFactorization, Prime) {
    int n = 998244353;
    auto v = prime_factorization(n);

    std::unordered_map<int, int> gt = {
        {998244353, 1},
    };

    for (auto &&[p, e]: v) {
        ASSERT_NE(gt.find(p), gt.end());
        ASSERT_EQ(e, gt[p]);
    }
}

TEST(TestPrimeFactorization, Square) {
    int n = 121;
    auto v = prime_factorization(n);

    std::unordered_map<int, int> gt = {
        {11, 2},
    };

    for (auto &&[p, e]: v) {
        ASSERT_NE(gt.find(p), gt.end());
        ASSERT_EQ(e, gt[p]);
    }
}

TEST(TestPrimeFactorization, Large) {
    long long n = 48636156184;
    auto v = prime_factorization(n);

    std::unordered_map<int, int> gt = {
        {2, 3}, {7, 2}, {11, 3}, {31, 2}, {97, 1},
    };

    for (auto &&[p, e]: v) {
        ASSERT_NE(gt.find(p), gt.end());
        ASSERT_EQ(e, gt[p]);
    }
}