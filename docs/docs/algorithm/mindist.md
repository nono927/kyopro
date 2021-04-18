# Mindist

単一始点最短経路を計算する．

!!! Warning
    動作検証が不十分であるため，バクを含んでいる可能性が高いです．

## メンバ関数

### コンストラクタ

```cpp
mindist_graph::mindist_graph<Cost>(int n);
```

頂点数 `n` ，辺集合が空のグラフを生成する．

### 追加

```cpp
int mindist_graph::add_edge(int from, int to, Cost cost, bool bidirected = true);
```

頂点 `from` から頂点 `to` へコスト `cost` の辺を追加する．
有向辺を追加するときは `bidirected = false` とする．

### 最短経路の計算

```cpp
std::vector<Cost> mindist_graph::dist(int s);
```

始点を `s` としたときの，各頂点までの最短距離を計算する．
戻り値の型は `std::vector<Cost>` であり，`i` 番目の要素は頂点 `s` から頂点 `i` への最短経路である（ただし，頂点 `s` から頂点 `i` へのパスが存在しない場合，`std::numeric_limits<Cost>::max()` が格納されている）．
辺の本数を $m$ とすると，すべての辺のコストが非負のとき，計算量は $O((n + m)\log m)$ となる．
そうではなく，ある辺が負のコストを持つとき，計算量は $O(nm)$ となる．
