# Prime factorization

与えられた素数の素因数分解を計算する．

## 関数

```cpp
std::vector<std::pair<long long, long long> > prime_factorization(long long x);
```

整数 `n` の素因数分解を計算する．
戻り値の型は `std::vector<std::pair<long long, long long> >`．
入力した整数が $n = \Pi_{0 \le i < m} \ {p_i}^{e_i}$ （$p_i$ は素数，$p_0 < \dots < p_{m-1}$，$e_i > 0$）と素因数分解されるとき，戻り値の $i$ 番目の要素は組 $(p_i, e_i)$ となる．
`n` が1以下の場合は空列を返す．
計算量は $O(\sqrt{n})$．