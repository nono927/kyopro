#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <cassert>

using namespace std;

vector<int> tsp_exact(vector<int> &xs, vector<int> &ys) {
    const int n = xs.size();
    const auto INF = numeric_limits<int>::max();

    // l1 distance between every two points
    vector<vector<int> > dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]);
        }
    }

    // dp
    vector<vector<int> > dp(1 << n, vector<int>(n, INF));
    vector<vector<int> > par(1 << n, vector<int>(n));
    dp[0][0] = 0;
    for (int bits = 0; bits < (1<<n); ++bits) {
        for (int i = 0; i < n; ++i) {
            // if (!(bits & (1 << i))) continue;
            if (dp[bits][i] == INF) continue;
            for (int j = 0; j < n; ++j) {   // i -> j
                if (bits & (1 << j)) continue;
                if (dp[bits][i] + dist[i][j] < dp[bits | (1<<j)][j]) {
                    dp[bits | (1<<j)][j] = dp[bits][i] + dist[i][j];
                    par[bits | (1<<j)][j] = i;
                }
            }
        }
    }

    // traceback
    vector<int> ret;
    for (int i = 0, bits = (1<<n) - 1; bits > 0;) {
        assert(bits & (1<<i));
        ret.emplace_back(i);
        auto p = par[bits][i];
        bits &= ~(1<<i);
        i = p;
    }
    return ret;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        cerr << "no input and output filename" << endl;
        return 1;
    }

    // open input file
    string fname_in(argv[1]);
    ifstream ifs(fname_in);
    if (!ifs) {
        cerr << "cannot open file" << endl;
        return 1;
    }

    // input
    int n;
    ifs >> n;
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        ifs >> xs[i] >> ys[i];
    }

    // solve tsp
    auto path = tsp_exact(xs, ys);

    // write result
    string fname_out(argv[2]);
    ofstream ofs(fname_out);
    if (!ofs) {
        cerr << "cannot open file" << endl;
        return 1;
    }

    for (auto &&p : path) {
        ofs << p << endl;
    }
}
