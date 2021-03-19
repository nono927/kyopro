#include "gtest/gtest.h"
#include "factorial.hpp"

TEST(Factoral, Case1) {
    int n = 10;
    long long MOD = 7;
    auto [fact, ifact] = calc_factorial(n, MOD);

    ASSERT_EQ(fact.size(), n);
    ASSERT_EQ(ifact.size(), n);
    
    for (int i = 0; i < n; ++i) {
        ASSERT_EQ(fact[i] * ifact[i] % MOD, 1);
    }
}

TEST(Factoral, Case2) {
    int n = 20;
    long long MOD = 998244353;
    auto [fact, ifact] = calc_factorial(n, MOD);

    ASSERT_EQ(fact.size(), n);
    ASSERT_EQ(ifact.size(), n);
    
    for (int i = 0; i < n; ++i) {
        ASSERT_EQ(fact[i] * ifact[i] % MOD, 1);
    }
}

TEST(Factoral, Case3) {
    int n = 20;
    long long MOD = 1e9 + 7;
    auto [fact, ifact] = calc_factorial(n, MOD);

    ASSERT_EQ(fact.size(), n);
    ASSERT_EQ(ifact.size(), n);
    
    for (int i = 0; i < n; ++i) {
        ASSERT_EQ(fact[i] * ifact[i] % MOD, 1);
    }
}