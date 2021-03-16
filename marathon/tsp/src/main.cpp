#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <getopt.h>
#include "tsp.hpp"

using namespace std;

int main(int argc, char **argv) {
    bool is_exact = false;
    string fname_in, fname_out;

    auto optstring = "";
    const struct option longopts[] = {
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"exact", no_argument, 0, 'e'},
    };
    opterr = 0;
    int c, longindex = 0;
    while ((c = getopt_long(argc, argv, optstring, longopts, &longindex)) != -1) {
        if (c == 'i') {
            fname_in = string(optarg);
        } else if (c == 'o') {
            fname_out = string(optarg);
        } else if (c == 'e') {
            is_exact = true;
        }
    }

    // open input file
    ifstream ifs(fname_in);
    if (!ifs) {
        cerr << "cannot open input file" << endl;
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
    auto &tsp = is_exact ? tsp_exact : tsp_heuristic;
    auto path = tsp(xs, ys);

    // write result
    ofstream ofs(fname_out);
    if (!ofs) {
        cerr << "cannot open output file" << endl;
        return 1;
    }

    for (auto &&p : path) {
        ofs << p << endl;
    }
}
