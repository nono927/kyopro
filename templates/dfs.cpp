#include <vector>
#include <stack>

using namespace std;
using Graph = vector<vector<int> >;

void dfs(Graph &g, int root) {
    const int n = g.size();
    vector<bool> pushed(n, false);
    vector<bool> visited(n, false);
    vector<int> parent(n);
    parent[root] = -1;

    stack<int> st;
    st.emplace(root);
    pushed[root] = true;
    while (!st.empty()) {
        auto tmp = st.top();
        if (!visited[tmp]) {    // forward
            visited[tmp] = true;

            // something

            for (auto &to : g[tmp]) {
                if (to != parent[tmp] && !pushed[to]) {
                    pushed[to] = true;
                    parent[to] = tmp;
                    st.emplace(to);
                }
            }
        } else {                // backward
            st.pop();

            // something

        }
    }
}
