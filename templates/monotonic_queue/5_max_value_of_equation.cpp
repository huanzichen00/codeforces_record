#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 100000 + 5;
  int q[MAXN][2];
  int head, tail;

  // 拆分成 (y2 + x2) + (x1 - y1), 因为从左往右, 右减左可以去掉绝对值 
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int n = points.size();
    head = tail = 0;

    // 比较最大值如果没强调非负一定要用 INT_MAX
    int ans = INT_MIN;
    for (int i = 0, x, y; i < n; i++) {
      x = points[i][0];
      y = points[i][1];

      // 如果头部不符合条件，弹出
      while (head < tail && q[head][0] + k < x) {
        // 单调队列头部的可能性过期了，头部点的 x 与当前点的 x 的距离超过了k
        head++;
      }

      // 可以确保合法性，直接输出答案
      if (head < tail) {
        ans = max(ans, x + y + q[head][1] - q[head][0]);
      }

      // i 号点的 x 和 y，改从尾部进入单调队列
      while (head < tail && q[tail - 1][1] - q[tail - 1][0] <= y - x) {
        tail--;
      }
      q[tail][0] = x;
      q[tail++][1] = y;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
