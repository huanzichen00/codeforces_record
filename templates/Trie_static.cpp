#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 100000;  // 最大节点数

int trie[N][26];  // Trie树
int End[N];    // 在该节点结尾的字符串数量
int pass[N];   // 经过该节点的字符串数量
int idx = 1;      // 节点编号

// 插入字符串
void insert(string s) {
  int p = 0;  // root
  pass[p]++;

  for (char c : s) {
    int u = c - 'a';

    if (!trie[p][u]) {   // 计数为0
      trie[p][u] = idx++;
    }

    p = trie[p][u];
    pass[p]++;
  }

  End[p]++;
}

// 查询某个字符串出现次数
int search(string s) {
  int p = 0;

  for (char c : s) {
    int u = c - 'a';

    if (!trie[p][u]) {
      return 0;
    }

    p = trie[p][u];
  }

  return End[p];
}

// 查询某个前缀出现次数
int prefixNumber(string s) {
  int p = 0;

  for (char c : s) {
    int u = c - 'a';
  }

  if (!trie[p][u]) {
    return 0;
  }

  p = trie[p][u];
}

void clear() {
  for (int i = 0; i <= idx)
}











int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
