#include "gtest/gtest.h"
#include "cht.hpp"

TEST(ConvexHullTrick, Single) {
    ConvexHullTrick<int> cht;

    cht.add(2, 1);
    ASSERT_EQ(cht.get(3), 7);
    ASSERT_EQ(cht.get(-3), -5);
}

TEST(ConvexHullTrick, Small) {
    ConvexHullTrick<int> cht;

    cht.add(2, 1);
    ASSERT_EQ(cht.get(-1), -1);
    cht.add(1, -1);
    ASSERT_EQ(cht.get(-1), -2);
    cht.add(-1, 0);
    ASSERT_EQ(cht.get(-1), -2);
}
