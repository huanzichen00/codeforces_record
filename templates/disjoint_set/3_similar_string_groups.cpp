#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 305;
  int father[MAXN];
  int sets;

  void init(int n) {
    for (int i = 0; i < n; i++) {
      father[i] = i;
    }
    sets = n;
  }
  
  int find(int x) {
    if (x != father[x]) {
      father[x] = find(father[x]);
    }
    return father[x];
  }

  void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      father[fx] = fy;
      sets--;
    }
  }
  
  int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();

    init(n);

    // 两两比较字符串
    // 一旦 diff >= 3，就不用再数了
    // 因为这题只有 diff == 0 或 diff == 3 次啊能算相似
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (find(i) == find(j)) {
          continue;
        }
        int diff = 0;

        // 统计不同位置个数
        // 一旦 diff >= 3，就不用再数了
        // 因为这题只有 diff == 0 或 diff == 2 才能算相似
        for (int k = 0; k < m && diff < 3; k++) {
          if (strs[i][k] != strs[j][k]) {
            diff++;
          }
        }

        // 为什么是 0 或 2:
        // 1. diff == 0，两个字符串本来就一样，当然相似
        // 2. diff == 2，交换其中两个不同位置，就能变成一样
        if (diff == 0 || diff == 2) {
          unite(i, j);
        }
      }
    }
    // 剩下多少个集合，就是多少组
    return sets;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
