#include <vector>
#include <map>
#include <limits>
#include <algorithm>
#include <utility>
#include <iostream>

template<typename T>
class ConvexHullTrick {
    using Line = std::pair<T, T>;
    std::vector<Line> lines;

public:
    ConvexHullTrick() {}

    // add line y = a * x + b
    void add(T a, T b) {
        auto n = lines.size();
        if (n > 0 && lines[n-1].first == a) {
            auto tmp = lines[n-1].second;
            lines[n-1].second = std::min(tmp, b);
        } else {
            const auto f = [&](Line &l, Line &prev, Line &next) -> bool {   // true if l is necessary
                return (l.first - prev.first) * (next.second - l.second) < (next.first - l.first) * (l.second - prev.second);
            };
            Line l(a, b);
            while (lines.size() > 1 && !f(lines.back(), lines[lines.size()-2], l)) {
                lines.pop_back();
            }
            lines.emplace_back(a, b);
        }
    }

    // get min(a_i * x + b_i)
    T get(T x) {
        int n = lines.size();
        if (n == 1) {
            return this->get_i(x, 0);
        }

        int l = 0;
        int r = n - 2;
        if (this->get_i(x, l) <= this->get_i(x, l+1)) {
            return this->get_i(x, l);
        }
        if (this->get_i(x, r) >= this->get_i(x, r+1)) {
            return this->get_i(x, r+1);
        }

        while (r - l > 1) {
            int m = (l + r) / 2;
            if (this->get_i(x, m) > this->get_i(x, m+1)) {
                l = m;
            } else {
                r = m;
            }
        }
        return this->get_i(x, r);
    }

private:
    T get_i(T x, int i) {
        return lines[i].first * x + lines[i].second;
    }
};
