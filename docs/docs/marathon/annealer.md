# Annealer

焼きなまし法を行うためのクラス．

ある評価値 $E$ を最大化する問題を考える．
ある操作によって評価値が $\Delta E$ だけ変化するとき，以下の確率で遷移を行う．

$$
P = \min \left( \exp \left( \frac{\Delta E}{T} \right), 1 \right)
$$

ここで，$T$ は時間とともに減少するパラメータである．

## メンバ関数

### コンストラクタ

```cpp
Annealer::Annealer(double temp_start, double temp_end, double time_limit);
```

初期温度 $T_0$ を `temp_start`，探索終了時の温度 $T_1$ を `temp_end`，探索時間 $t_\mathrm{limit}$ を `time_limit` として初期化する．
温度は時刻に対して線形に変化し，探索終了時刻以降は一定値 $T_1$ をとる．

$$
T(t) = \cases{
    T_0 + (T_1 - T_0) \frac{t}{T_1} & $(0 \leq t \leq t_\mathrm{limit})$ \cr
    T_1 & $(t_\mathrm{limit} \leq t)$
}
$$

### クエリ
```cpp
bool Annealer::modify(double diff, double time);
```

評価値の差分を `diff` ，時刻を `time` を入力として，冒頭の確率にしたがって真偽値を返す．