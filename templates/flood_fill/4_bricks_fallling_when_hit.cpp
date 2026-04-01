#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:  
  int n, m;
  
  int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) {
      return 0;
    }

    grid[i][j] = 2;

    return 1
      + dfs(grid, i + 1, j)
      + dfs(grid, i - 1, j)      
      + dfs(grid, i, j + 1)
      + dfs(grid, i, j - 1);
  }

  bool worth(vector<vector<int>>& grid, int i, int j) {
    if (grid[i][j] != 1) {
      return false;
    }
    if (i == 0) {
      return true;
    }
    if (i > 0 && grid[i - 1][j] == 2) {
      return true;
    }
    if (i + 1 < n && grid[i + 1][j] == 2) {
      return true;
    }
    if (j > 0 && grid[i][j - 1] == 2) {
      return true;
    }
    if (j + 1 < m && grid[i][j + 1] == 2) {
      return true;
    }
    return false;
  }
  
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    n = grid.size();
    m = grid[0].size();

    for (auto& h : hits) {
      grid[h[0]][h[1]]--;
    }  

    for (int j = 0; j < m; j++) {
      dfs(grid, 0 , j);
    }
    int k = hits.size();
    vector<int> ans(k);

    // 倒序恢复
    for (int i = k - 1; i >= 0; i--) {
      int x = hits[i][0];
      int y = hits[i][1];

      grid[x][y]++;

      if (worth(grid, x, y)) {
        ans[i] = dfs(grid, x, y) - 1;
      } else {
        ans[i] = 0;
      }
    }

    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
