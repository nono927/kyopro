# Dice

ランダムな整数を使用するためのクラス．

## メンバ関数

### コンストラクタ
```cpp
Dice::Dice(int n);
Dice::Dice((int n, int seed);
```

0以上 $n$ 未満の整数をランダムに返す `Dice` クラスを作成する．
シード値 `seed` を指定しない場合，ランダムにシード値を設定する．

### クエリ

```cpp
int Dice::operator()();
```

0以上 $n$ 未満の整数をランダムに返す．