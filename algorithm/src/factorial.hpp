#include <vector>
#include <tuple>

template<typename T>
T modinv(T a, T MOD) {
    T x0[3] = {a, 1, 0};
    T x1[3] = {MOD, 0, 1};
    while (x1[0] > 0) {
        T q = x0[0] / x1[0];
        for (int i = 0; i < 3; ++i) {
            std::tie(x0[i], x1[i]) = std::tuple(x1[i], x0[i] - q * x1[i]);
            x1[i] = (x1[i] >= 0) ? x1[i] % MOD : MOD - (MOD - x1[i]) % MOD; 
        }
    }
    return x0[1];
}

std::tuple<std::vector<long long>, std::vector<long long> > calc_factorial(
    const int n, const long long MOD)
{
    std::vector<long long> fact(n), ifact(n);

    // n!
    fact[0] = 1;
    for (int i = 1; i < n; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }

    // 1 / n!
    ifact[n-1] = modinv(fact[n-1], MOD);
    for (int i = n-1; i > 0; --i) {
        ifact[i-1] = ifact[i] * i % MOD;
    }

    return {fact, ifact};
}