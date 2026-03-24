#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 35;

  int father[MAXN];
  int sets;

  void init(int m) {
    for (int i = 0; i < m; i++) {
      father[i] = i;
    }
    sets = m;
    return;
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
  
  int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    int m = n / 2;  // 情侣对数
    init(m);

    for (int i = 0; i < n; i += 2) {
      unite(row[i] / 2, row[i + 1] / 2);
    }

    return m - sets;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
