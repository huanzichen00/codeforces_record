#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class TrieTree {
public:
  static const int MAXN = 150001;

  int tree[MAXN][26];
  int End[MAXN];
  int pass[MAXN];
  int cnt;

  TrieTree() {
    build();
  }

  // 初始化：1号节点做根
  void build() {
    cnt = 1;
    memset(tree[1], 0, sizeof(tree[1]));
    End[1] = 0;
    pass[1] = 0;
  }

  // 插入字符串
  void insert(const string& word) {
    int cur = 1;
    pass[cur]++;
    for (char ch : word) {
      int path = ch - 'a';
      if (tree[cur][path] == 0) {
        tree[cur][path] = ++cnt;
      }
      cur = tree[cur][path];
      pass[cur]++;
    }
    End[cur]++;
  }

  // 查询完整字符串出现次数
  int search(const string& word) {
    int cur = 1;
    for (char ch : word) {
      int path = ch - 'a';
      if (tree[cur][path] == 0) {
        return 0;
      }
      cur = tree[cur][path];
    }
    return End[cur];
  }

  // 删除一个字符串
  void erase(const string& word) {
    if (search(word) > 0) {
      int cur = 1;
      pass[cur]--;
      for (char ch : word) {
        int path = ch - 'a';
        int next = tree[cur][path];
        if (--pass[next] == 0) {
          tree[cur][path] = 0;
          return;
        }
        cur = next;
      }
      End[cur]--;
    }
  }

  // 清空当前用过的节点，适合多组数据
  void clear() {
    for (int i = 1; i <= cnt; i++) {
      memset(tree[i], 0, sizeof(tree[i]));
      End[i] = 0;
      pass[i] = 0;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
