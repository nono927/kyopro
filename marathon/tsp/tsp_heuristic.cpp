#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <cassert>

using namespace std;

vector<int> tsp_heuristic(vector<int> &xs, vector<int> &ys) {
    const int n = xs.size();
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) ret[i] = i;
    return ret;
}