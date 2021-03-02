#include "gtest/gtest.h"
#include "cht.hpp"
#include <vector>
#include <map>

template<typename T>
class ConvexHullTrickNaive {
    std::map<T, T> lines;

public:
    ConvexHullTrickNaive() {}

    void add(T a, T b) {
        auto itr = lines.find(a);
        if (itr == lines.end() || b < itr->second) {
            lines[a] = b;
        }
    }

    T get(T x) {
        T ret = std::numeric_limits<T>::max();
        for (auto &&p : lines) {
            ret = std::min(ret, p.first * x + p.second);
        }
        return ret;
    }
};

class ConvexHullTrickTest : public ::testing::Test {
protected:
    ConvexHullTrick<int> cht;
    ConvexHullTrickNaive<int> cht_naive;

    void add(int a, int b) {
        cht.add(a, b);
        cht_naive.add(a, b);
    }

    bool ok(int x) {
        return cht.get(x) == cht_naive.get(x);
    }
};

template<typename T>
struct Query {
    enum class Type {
        ADD,
        GET,
    };
    Type type;
    T a, b, x;

    Query(T a, T b) : type(Type::ADD), a(a), b(b) {}
    Query(T x) : type(Type::GET), x(x) {}
};

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

TEST_F(ConvexHullTrickTest, Monotonic) {
    std::vector<Query<int> > queries = {
        Query(5, 3),
        Query(3, 2),
        Query(-1),
        Query(2, 0),
        Query(0, 6),
        Query(-1, 4),
        Query(1),
        Query(-2, 7),
        Query(-4, 1),
        Query(2),
    };

    for (auto &&q : queries) {
        if (q.type == Query<int>::Type::ADD) {
            add(q.a, q.b);
        } else {
            ASSERT_TRUE(ok(q.x));
        }
    }
}
