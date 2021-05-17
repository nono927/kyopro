#include <vector>
#include <utility>

using Graph = std::vector<std::vector<int> >;

class LCA {
    int n;
    const int KMAX = 30;
    Graph g;
    std::vector<std::vector<int> > parents;
    std::vector<int> depth;

    void dfs(int tmp, int from = -1) {
        parents[tmp][0] = from;
        for (int k = 0; k < KMAX - 1; ++k) {
            int p = parents[tmp][k];
            parents[tmp][k+1] = (p < 0) ? -1 : parents[p][k];
        }

        depth[tmp] = (from < 0) ? 0 : depth[from] + 1;

        for (auto &&to: g[tmp]) {
            if (to != from) dfs(to, tmp);
        }
    }

public:
    LCA(Graph &g, int root = 0): g(g) {
        n = g.size();
        parents.resize(n);
        for (int i = 0; i < n; ++i) parents[i].resize(KMAX);
        depth.resize(n);
        dfs(root);
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        for (int i = KMAX - 1, d = depth[v] - depth[u]; i >= 0; --i) {
            if ((d >> i) & 1) v = parents[v][i];
        }

        if (u == v) return u;
        for (int i = KMAX - 1; i >= 0; --i) {
            if (parents[u][i] != parents[v][i]) {
                u = parents[u][i];
                v = parents[v][i];
            }
        }

        return parents[u][0];
    }
};