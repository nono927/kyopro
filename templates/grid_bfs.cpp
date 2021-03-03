#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using Grid = vector<vector<char> >;

void grid_bfs(Grid &g, int si, int sj) {
    using Pii = pair<int, int>;
    const int h = g.size();
    const int w = g[0].size();
    vector<vector<bool> > visited(h, vector<bool>(w, false));

    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    const auto is_prohibited = [&](int i, int j) -> bool {
        return i < 0 || h <= i || j < 0 || w <= j || g[i][j] == '#';
    };

    queue<Pii> que;
    que.emplace(si, sj);
    while (!que.empty()) {
        int i, j;
        tie(i, j) = que.front();
        que.pop();
        if (visited[i][j]) continue;
        visited[i][j] = true;

        // something

        for (int k = 0; k < di.size(); ++k) {
            int i_next = i + di[k];
            int j_next = j + dj[k];
            if (is_prohibited(i_next, j_next)) continue;
            if (!visited[i_next][j_next]) {
                que.emplace(i_next, j_next);
            }
        }
    }
}
