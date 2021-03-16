#include <vector>
#include <cmath>
#include <limits>

#include <dice.hpp>
#include <timer.hpp>

using namespace std;
const auto INF = numeric_limits<int>::max();

int dist(int x0, int x1, int y0, int y1) {
    return abs(x0 - x1) + abs(y0 - y1);
}

int nearest_neighbor(int tmp, vector<bool> &used, vector<int> &xs, vector<int> &ys) {
    const int n = used.size();
    int mind = INF;
    int ret = -1;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        auto d = dist(xs[tmp], xs[i], ys[tmp], ys[i]);
        if (d < mind) {
            mind = d;
            ret = i;
        }
    }
    return ret;
}

vector<int> tsp_heuristic(vector<int> &xs, vector<int> &ys) {
    const int n = xs.size();
    vector<int> ret(n);
    vector<bool> used(n);

    // greedy
    for (int i = 1, tmp = 0; i < n; ++i) {
        used[tmp] = true;
        tmp = nearest_neighbor(tmp, used, xs, ys);
        ret[i] = tmp;
    }

    return ret;
}