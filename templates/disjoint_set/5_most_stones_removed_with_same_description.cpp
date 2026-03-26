#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  // key : 某行/列
  // value : 第一次遇到的石头编号
  static const int MAXN = 1005;
  int father[MAXN];
  int sets;

  void init(int n) {
    for (int i = 0; i < n; i++) {
      father[i] = i;
    }
    sets = n;
  }

  int find(int i) {
    if (i != father[i]) {
      father[i] = find(father[i]);
    }
    return father[i];
  }

  void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      father[fx] = fy;
      sets--;
    }
  }
  
  int removeStones(vector<vector<int>>& stones) {
    unordered_map<int, int> rowFirst;
    unordered_map<int, int> colFirst;    int n = stones.size();
    init(n);
    for (int i = 0; i < n; i++) {
      int row = stones[i][0];
      int col = stones[i][1];
      // 处理行
      if (rowFirst.find(row) == rowFirst.end()) {
        rowFirst[row] = i;
      } else {
        unite(i, rowFirst[row]);
      }
      if (colFirst.find(col) == colFirst.end()) {
        colFirst[col] = i;
      } else {
        unite(i, colFirst[col]);
      }
    }

    return n - sets;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
