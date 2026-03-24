#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class UnionFind {
public:
  static const int MAXN = 1000005;
  int father[MAXN];
  // 只有根节点处的 size 有意义
  // size[i] = 以 i 为根的集合大小
  int size[MAXN];

  // 初始化 1 ~ n
  void init(int n) {
    for (int i = 1; i <= n; i++) {
      father[i] = i;  // 一开始每个点的父亲都是自己
      size[i] = 1;    // 大小为 1
    }
  }

  // 找代表节点, 路径压缩
  // 在递归往上找根的同时, 把沿途节点都直接挂到根上
  int find(int x) {
    if (x != father[x]) {
      father[x] = find(father[x]);
    }
    return father[x];
  }

  // 合并两个集合, 按大小合并
  void unite(int x, int y) {
    int fx = find(x);  // x 所在集合的根 
    int fy = find(y);  // y 所在集合的根

    // 如果已经在一个集合里, 不需要合并
    if (fx == fy) {
      return;
    }

    // 按大小合并:
    // 保证 fx 对应的是较大的集合, fy 对应的是较小的集合
    // 这样后面统一写 father[fy] = fx;
    if (size[fx] < size[fy]) {
      swap(fx, fy);
    }

    // 小集合 fy 挂到大集合 fx 上
    father[fy] = fx;

    // 更新集合的大小
    size[fx] += size[fy];
  }

  void unite2(int x, int y) {
     father[find(x)] = find(y);
  }

  // 判断是否在同一个集合
  bool isSameSet(int x, int y) {
    return find(x) == find(y);
  }

  // 返回 x 所在的集合大小
  int getSize(int x) {
    return size[find(x)]; 
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  UnionFind uf;
  uf.init(5); // 初始化 1~5

  uf.unite(1, 2);
  uf.unite(3, 4);

  cout << uf.isSameSet(1, 2) << '\n'; // 1
  cout << uf.isSameSet(1, 3) << '\n'; // 0

  uf.unite(2, 3);

  cout << uf.isSameSet(1, 4) << '\n'; // 1
  cout << uf.getSize(1) << '\n';         // 4

  return 0;
}
