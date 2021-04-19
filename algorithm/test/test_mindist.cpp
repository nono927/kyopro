#include <vector>
#include "gtest/gtest.h"
#include "mindist.hpp"

TEST(Mindist, Simple) {
    mindist_graph<int> graph(4);
    ASSERT_EQ(0, graph.add_edge(0, 1, 3));
    ASSERT_EQ(1, graph.add_edge(0, 2, 4));
    ASSERT_EQ(2, graph.add_edge(0, 3, 6));

    auto dist = graph.dist(0);
    ASSERT_EQ(dist[0], 0);
    ASSERT_EQ(dist[1], 3);
    ASSERT_EQ(dist[2], 4);
    ASSERT_EQ(dist[3], 6);
}

TEST(Mindist, NonNegative) {
    mindist_graph<int> graph(5);
    ASSERT_EQ(0, graph.add_edge(0, 1, 3));
    ASSERT_EQ(1, graph.add_edge(0, 2, 6));
    ASSERT_EQ(2, graph.add_edge(1, 2, 2));
    ASSERT_EQ(3, graph.add_edge(1, 3, 7));
    ASSERT_EQ(4, graph.add_edge(1, 4, 1));
    ASSERT_EQ(5, graph.add_edge(2, 4, 5));
    ASSERT_EQ(6, graph.add_edge(3, 4, 4));

    auto dist = graph.dist(0);
    ASSERT_EQ(dist[0], 0);
    ASSERT_EQ(dist[1], 3);
    ASSERT_EQ(dist[2], 5);
    ASSERT_EQ(dist[3], 8);
    ASSERT_EQ(dist[4], 4);
}

TEST(Mindist, Negative) {
    mindist_graph<int> graph(5);
    ASSERT_EQ(0, graph.add_edge(0, 1, 1, false));
    ASSERT_EQ(1, graph.add_edge(0, 2, 4, false));
    ASSERT_EQ(2, graph.add_edge(1, 2, -2, false));
    ASSERT_EQ(3, graph.add_edge(1, 3, 3, false));
    ASSERT_EQ(4, graph.add_edge(1, 4, 1, false));
    ASSERT_EQ(5, graph.add_edge(2, 4, 2, false));
    ASSERT_EQ(6, graph.add_edge(3, 4, 2, false));

    auto dist = graph.dist(0);
    ASSERT_EQ(dist[0], 0);
    ASSERT_EQ(dist[1], 1);
    ASSERT_EQ(dist[2], -1);
    ASSERT_EQ(dist[3], 4);
    ASSERT_EQ(dist[4], 1);
}

TEST(Mindist, NegativeLoop) {
    mindist_graph<int> graph(5);
    ASSERT_EQ(0, graph.add_edge(0, 1, 1, false));
    ASSERT_EQ(1, graph.add_edge(0, 2, 4, false));
    ASSERT_EQ(2, graph.add_edge(1, 2, -2, false));
    ASSERT_EQ(3, graph.add_edge(1, 3, 3, false));
    ASSERT_EQ(4, graph.add_edge(4, 1, -1, false));
    ASSERT_EQ(5, graph.add_edge(2, 4, 2, false));
    ASSERT_EQ(6, graph.add_edge(3, 4, 2, false));

    auto dist = graph.dist(0);
    ASSERT_TRUE(dist.empty());
}
