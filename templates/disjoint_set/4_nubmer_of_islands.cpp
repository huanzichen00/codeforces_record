#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXSIZE = 1e5 + 5;
  int father[MAXSIZE];
  // index 的计算需要 cols
  int cols;
  int sets;

  int index(int a, int b) {
    return a * cols + b;
  }

  void init(int n, int m, vector<vector<char>>& grid) {
    cols = m;    
    sets = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0, idx; j < m; j++) {
        if (grid[i][j] == '1') {
          idx = index(i, j);
          father[idx] = idx;
          sets++;
        }
      }
    }
  }

  int find(int i) {
    if (i != father[i]) {
      father[i] = find(father[i]);
    }
    return father[i];
  }

  void unite(int a, int b, int c, int d) {
    int fx = find(index(a, b));
    int fy = find(index(c, d));
    if (fx != fy) {
      father[fx] = fy;
      sets--;
    }
  }
  
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    init(n, m, grid);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (grid[i][j] == '1') {
           if (j > 0 && grid[i][j - 1] == '1') {
             unite(i, j, i, j - 1);
           }
           if (i > 0 && grid[i - 1][j] == '1') {
             unite(i, j, i - 1, j);
           }
         }
       }
     }
     return sets;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
