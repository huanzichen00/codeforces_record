#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int id = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          dfs(grid, n, m, i, j, id++);
        }
      }
    }
    vector<int> sizes(id, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] > 1) {
          ans = max(ans, ++sizes[grid[i][j]]);
        }
      }
    }
    vector<bool> vis(id, false);
    int up, down, left, right, merge;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          up = i > 0 ? grid[i - 1][j] : 0;
          down = i + 1 < n ? grid[i + 1][j] : 0;
          left = j > 0 ? grid[i][j - 1] : 0;
          right = j + 1 < m ? grid[i][j + 1] : 0;
          int merge = 1;
          if (up > 1 && !vis[up]) {
            merge += sizes[up];
            vis[up] = true;
          }
          if (!vis[left]) {
            merge += sizes[left];
            vis[left] = true;
          }
          if (!vis[right]) {
            merge += sizes[right];
            vis[right] = true;
          }
          if (!vis[down]) {
            merge += sizes[down];
            vis[down] = true;
          }
          ans = max(ans, merge);
          if (up > 1) vis[up] = false;
          if (down > 1) vis[down] = false;
          if (left > 1) vis[left] = false;
          if (right > 1) vis[right] = false;
        }
      }
    }
    return ans;
  }

  void dfs(vector<vector<int>>& grid, int n, int m, int i, int j, int id) {
    if (i < 0 || i == n || j == m || j < 0 || grid[i][j] != 1) {
      return;
    }
    grid[i][j] = id;
    dfs(grid, n, m, i - 1, j, id);
    dfs(grid, n, m, i + 1, j, id);
    dfs(grid, n, m, i, j - 1, id);
    dfs(grid, n, m, i, j + 1, id);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
