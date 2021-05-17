#include "gtest/gtest.h"
#include "lca.hpp"

TEST(TestLCA, Tree) {
    int n = 11;
    Graph g(n);
    std::vector<int> x = {0, 0, 1, 1, 3, 3, 3, 7, 8, 8};
    std::vector<int> y = {1, 7, 2, 3, 4, 5, 6, 8, 9, 10};
    for (int i = 0; i < n-1; ++i) {
        g[x[i]].emplace_back(y[i]);
        g[y[i]].emplace_back(x[i]);
    }

    LCA lca(g);
    ASSERT_EQ(lca.lca(1,  5), 1);
    ASSERT_EQ(lca.lca(1,  8), 0);
    ASSERT_EQ(lca.lca(2,  3), 1);
    ASSERT_EQ(lca.lca(4,  7), 0);
    ASSERT_EQ(lca.lca(6,  6), 0);
    ASSERT_EQ(lca.lca(9, 10), 8);
}
