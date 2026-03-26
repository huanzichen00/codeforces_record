#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  // 洪水填充的做法
  // O(n * m) 最优解
  int numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          islands++;
          dfs(grid, i, j);
        }
      }
    }
    return islands;
  }

  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != '1') {
      return;
    }
    grid[i][j] = '2';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
