# Convex Hull Trick

以下の2つの操作を高速に行うデータ構造．

* 直線 $y = a_i x + b_i$ を追加する．
* $\min_i \{ a_i x + b_i \}$ を計算する．

!!! Warning
    追加する直線群の傾きが単調増加である必要があります．

## メンバ関数

### コンストラクタ

```cpp
template<typename T>
ConvexHullTrick::ConvexHullTrick<T>();
```

### 直線の追加
```cpp
template<typename T>
void ConvexHullTrick::add(T a, T b);
```

直線 $y = ax + b$ を追加する．計算量はならし $O(1)$．

### クエリ

```cpp
template<typename T>
T ConvexHullTrick::get(T x);
```
$\min_i \{ a_i x + b_i \}$ を計算する．計算量は $O(\log N)$．