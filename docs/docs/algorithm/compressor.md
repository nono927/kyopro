# Compressor

座標圧縮を行うクラス．

## メンバ関数

### コンストラクタ
```cpp
Compressor::Compressor(std::vector<T> &v);
```

コンストラクタ．

### 圧縮
```cpp
std::vector<size_t> Compressor::compress(std::vector<T> &v);
```

入力 `v` を圧縮した数列を返す．

### 解凍
```cpp
T Compressor::operator[](size_t i);
```

圧縮後の数字 `i` に対応する，圧縮前の数値を返す．