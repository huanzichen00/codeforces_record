#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 3 * 100000 + 5;
  int father[MAXN];
  int maxcnt[MAXN];
  
  void init(int n) {
    for (int i = 0; i < n; i++) {
      father[i] = i;
      maxcnt[i] = 1;
    }
  }

  int find(int x) {
    if (x != father[x]) {
      father[x] = find(father[x]);
    }    
    return father[x];
  }

  // 合并两个点所在的集合
  // 返回这次合并新产生了多少条好路径
  int unite(int x, int y, vector<int>& vals) {
    int fx = find(x);
    int fy = find(y);

    int path = 0;

    // 谁的值大，谁做新节点的根
    // 这样可以保证: 集合根节点对应的值，始终是集合最大值
    if (vals[fx] > vals[fy]) {
      father[fy] = fx;
    } else if (vals[fx] < vals[fy]) {
      father[fx] = fy;
    } else {
      // 两个集合最大值相等
      // 左边有 maxcnt[fx] 个最大值点
      // 右边有 maxcnt[fy] 个最大值点
      // 它们两两配对，都会新增一条好路径
      path = maxcnt[fx] * maxcnt[fy];

      father[fy] = fx;
      maxcnt[fx] += maxcnt[fy];
    }

    return path;
  }

  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();
    init(n);

    // 每个点单独也算一条好路径
    int ans = n;
    sort(edges.begin(), edges.end(),
         [&](const vector<int>& a, const vector<int>& b) {
           return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);;
         });

    for (auto& e : edges) {
      ans += unite(e[0], e[1], vals);
    }

    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
