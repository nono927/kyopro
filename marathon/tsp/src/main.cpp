#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "tsp.hpp"

using namespace std;

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
