# Matrix

行列クラス `Matrix` を使えるようになる．
加法，乗法が定義されている．

## メンバ関数

### コンストラクタ

```cpp
Matrix::Matrix<T>(int size);
Matrix::Matrix<T>(int rows, int cols);
Matrix::Matrix<T>(std::initializer_list<std::initializer_list<T> > init);
```

### サイズ

```cpp
int Matrix::rows();
```
縦のサイズを返す．

```cpp
int Matrix::cols();
```
横のサイズを返す．

### 演算

```cpp
Matrix<T> Matrix::operator-() const;
Matrix<T> &Matrix::operator+=(const Matrix<T> &m);
Matrix<T> &Matrix::operator-=(const Matrix<T> &m);
```

## 非メンバ関数

### 演算

```cpp
Matrix<T> operator+(const Matrix<T> &m1, const Matrix<T> &m2);
Matrix<T> operator-(const Matrix<T> &m1, const Matrix<T> &m2);
Matrix<T> operator*(const Matrix<T> &m1, const Matrix<T> &m2);
```

```cpp
Matrix<T> Matrix::pow(int n);
```
$n$ 乗を計算する．正方行列でない場合は未定義．計算量は $O(H^3\log{n})$.

```cpp
Matrix<T> Matrix::transpose() const;
```
転置行列を計算する．計算量は $O(HW)$.

## 静的メンバ関数

```cpp
static Matrix<T> Matrix::ones(const int size);
```
サイズ `size * size` の単位行列を返す．