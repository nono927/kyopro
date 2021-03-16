#include <vector>
#include <cmath>
#include <limits>
#include <iostream>

#include <dice.hpp>
#include <timer.hpp>
#include <annealer.hpp>

using namespace std;
const auto INF = numeric_limits<int>::max();

int dist(int x0, int x1, int y0, int y1) {
    return abs(x0 - x1) + abs(y0 - y1);
}

int score(vector<int> &ps, vector<int> &xs, vector<int> &ys) {
    const int n = ps.size();
    int score = dist(xs[ps[0]], xs[ps[n-1]], ys[ps[0]], ys[ps[n-1]]);
    for (int i = 0; i < n - 1; ++i) {
        int u = ps[i];
        int v = ps[i+1];
        score += dist(xs[u], xs[v], ys[u], ys[v]);
    }
    return score;
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

    // 2-opt
    Dice dice(n);
    const double time_limit = 1000;
    const double tstart = 50;
    const double tend = 1;
    Timer timer;
    Annealer annealer(tstart, tend, time_limit);
    while (timer.time() < time_limit) {
        int i = dice();
        int j = dice();
        if (i == j) continue;
        if (i > j) swap(i, j);

        int p = (i == 0) ? ret[n-1] : ret[i-1];
        int q = ret[i];
        int r = ret[j];
        int s = (j == n) ? ret[0] : ret[j+1];
        int diff = dist(xs[p], xs[r], ys[p], ys[r])
                + dist(xs[q], xs[s], ys[q], ys[s])
                - dist(xs[p], xs[q], ys[p], ys[q])
                - dist(xs[r], xs[s], ys[r], ys[s]);
        
        if (annealer.modify(-diff, timer.time())) {
            while (i < j) {
                swap(ret[i], ret[j]);
                ++i; --j;
            }
        }
    }

    return ret;
}