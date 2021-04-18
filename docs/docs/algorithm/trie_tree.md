# Trie tree

文字列集合を扱うデータ構造．
共通の接頭辞を持つ文字列をまとめて管理することで，文字列の検索を高速に行う．

## メンバ関数

### コンストラクタ

```cpp
TrieTree::TrieTree();
```

空のTrie木を生成する．

### 追加

```cpp
void TrieTree::add(std::string &s);
```

Trie木に文字列 `s` を追加する．計算量は $O(|s|)$．

### 検索

```cpp
bool TrieTree::find(std::string &s);
```

Trie木に文字列 `s` が含まれていれば `true` を返す．計算量は $O(|s|)$．