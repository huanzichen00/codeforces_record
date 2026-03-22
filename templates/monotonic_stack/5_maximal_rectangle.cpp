#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 205;
  int height[MAXN]; 
  int st[MAXN];
  int top;

  int largestRectangleArea(int m) {
    top = 0;
    int ans = 0, cur, left;

    for (int i = 0; i < m; i++) {
      while (top > 0 && height[st[top - 1]] >= height[i]) {
        cur = st[--top];
        left = top == 0 ? -1 : st[top - 1];
        ans = max(ans, height[cur] * (i - left - 1));
      }
      st[top++] = i;
    }

    while (top > 0) {
      cur = st[--top];
      left = top == 0 ? -1 : st[top - 1]; 
      ans = max(ans, height[cur] * (m - left - 1));
    }

    return ans;
  }

  int maximalRectangle(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    fill (height, height + m, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        height[j] = (grid[i][j] == '0') ? 0 : height[j] + 1;
      }
      ans = max(ans, largestRectangleArea(m));
    }

    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
