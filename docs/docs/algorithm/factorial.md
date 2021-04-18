# Factorial

階乗 $n!$ とその逆元 $\frac{1}{n!}$ をmodで計算する．

## 関数

```cpp
std::tuple<std::vector<long long>, std::vector<long long> > calc_factorial(const int n, const long long MOD);
```

整数 `n` と素数 `MOD` に対して， タプル `(fact, ifact)` を返す．
`fact`，`ifact` は長さ `n` の `std::vector<long long>` であり，各要素の値は以下のようになる．

\[
\begin{eqnarray*}
    &\mathrm{fact[i]} = i! \mod \mathrm{MOD} \\
    &\mathrm{ifact[i]} = \frac{1}{i!} \mod \mathrm{MOD}
\end{eqnarray*}
\]
