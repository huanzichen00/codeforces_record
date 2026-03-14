#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
  public:
    int largest1BorderedSquare(vector<vector<int>& grid) {
      int n = grid.size();
      int m = grid[0].size();

      build(grid, n, m);  

      // 矩阵里全是0，直接返回
      if (sum(grid, 0, 0, n - 1, m - 1) == 0) {
        return 0;
      }

      // 找到的最大合法正方形边长
      int ans = 1;

      for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
          // (a, b)所有左上角点
          //       (c, d)更大边长的右下角点，k时当前尝试的边长
          for (int c = a + ans, d = b + ans, k = ans + 1; c < n && d < m; c++, d++, k++) {
            if (sum(grid, a, b, c, d) - sum(grid, a + 1, b + 1, c - 1, d - 1) == ((k - 1) << 2)) {
              ans = k;
            }
          }
        }
      }
      return ans * ans;
    }

    void build(vector<vector<int>>& g, int n, int m) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          g[i][j] += get(g, i, j - 1) + get(g, i - 1, j) - get(g, i - 1, j - 1);
        }
      }
    }

    int sum(vector<vector<int>>& g, int a, int b, int c, int d) {
      if (a > c || b > d) {
        return 0;
      }
      return g[c][d] - get(g, c, b - 1) - get(g, a - 1, d) + get(g, a - 1, b - 1);
    }

    int get(vector<vector<int>>& g, int i, int j) {
      return (i < 0 || j < 0) ? 0 : g[i][j];
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  
  return 0;
}
