#include <vector>
#include <utility>

std::vector<std::pair<long long, long long> > prime_factorization(long long x) {
    std::vector<std::pair<long long, long long> > ret;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        long long e = 0;
        while (x % i == 0) {
            ++e;
            x /= i;
        }
        ret.emplace_back(i, e);
    }
    if (x > 1) ret.emplace_back(x, 1);
    return ret;
}