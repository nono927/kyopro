#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int> >;

void bfs(Graph &g, int root) {
    const int n = g.size();
    vector<bool> visited(n, false);
    vector<int> parent(n);
    parent[root] = -1;

    queue<int> que;
    que.emplace(root);
    while (!que.empty()) {
        auto tmp = que.front();
        que.pop();
        if (visited[tmp]) continue;
        visited[tmp] = true;

        // something

        for (auto &to : g[tmp]) {
            if (to != parent[tmp] && !visited[to]) {
                parent[to] = tmp;
                que.emplace(to);
            }
        }
    }
}
