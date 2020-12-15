#include <vector>
#include <utility>
#include <limits>
#include <queue>
#include <tuple>

template<typename Cost>
class mindist_graph {
    using P = std::pair<Cost, int>;
    int n, m;
    std::vector<std::vector<P> > g;
    bool is_non_negative = true;

public:
    mindist_graph<Cost>(int n) {
        this->n = n;
        this->m = 0;
        this->g.resize(n);
    }

    int add_edge(int from, int to, Cost cost, bool bidirected = true) {
        this->g[from].emplace_back(cost, to);
        if (bidirected) {
            this->g[to].emplace_back(cost, from);
        }
        this->is_non_negative &= (cost >= 0);
        return this->m++;
    }

private:
    std::vector<Cost> dijkstra(int s) {
        constexpr Cost INF = std::numeric_limits<Cost>::max();
        std::vector<Cost> ds(this->n, INF);
        std::priority_queue<P, std::vector<P>, std::greater<P> > que;
        que.emplace(0, s);
        while (!que.empty()) {
            int tmp;
            Cost d;
            std::tie(d, tmp) = que.top();
            que.pop();
            if (ds[tmp] < d) continue;
            ds[tmp] = d;
            for (auto &e: this->g[tmp]) {
                int to;
                Cost cost;
                std::tie(cost, to) = e;
                if (ds[tmp] + cost < ds[to]) {
                    que.emplace(ds[tmp] + cost, to);
                }
            }
        }
        return ds;
    }

    std::vector<Cost> bellman_ford(int s) {
        constexpr Cost INF = std::numeric_limits<Cost>::max();
        std::vector<Cost> ds(this->n, INF);
        ds[s] = 0;
        for (int i = 0; i < this->n - 1; ++i) {
            for (int j = 0; j < this->n; ++j) {
                if (ds[j] == INF) continue;
                for (auto &e: this->g[j]) {
                    int to;
                    Cost cost;
                    std::tie(cost, to) = e;
                    ds[to] = std::min(ds[to], ds[j] + cost);
                }
            }
        }

        for (int j = 0; j < this->n; ++j) {
            if (ds[j] == INF) continue;
            for (auto &e: this->g[j]) {
                int to;
                Cost cost;
                std::tie(cost, to) = e;
                if (ds[j] + cost < ds[to]) {
                    return std::vector<Cost>();
                }
            }
        }
        return ds;
    }

public:
    std::vector<Cost> dist(int s) {
        if (this->is_non_negative) {
            return this->dijkstra(s);
        }
        return this->bellman_ford(s);
    }
};
