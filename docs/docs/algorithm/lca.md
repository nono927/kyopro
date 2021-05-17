# LCA

最小共通祖先を計算するクラス．

## メンバ関数

### コンストラクタ
```cpp
LCA::LCA(Graph &g, int root = 0);
```

根を `root` とする木 `g` に対して前処理を行う．

### クエリ
```cpp
int LCA::lca(int u, int v);
```

２頂点 `u` と `v` のLCAを計算する．