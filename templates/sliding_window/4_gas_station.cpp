#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  // 贪心
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int sum = 0;     // 总盈亏
    int cur = 0;     // 从当前候选起点出发的油量余额
    int start = 0;   // 候选起点

    for (int i = 0; i < n; i++) {
      int diff = gas[i] - cost[i];
      sum += diff;
      cur += diff;

      // 当前起点撑不到 i+1
      if (cur < 0) {
        start = i + 1;
        cur = 0;
      }
    }

    return sum < 0 ? -1 : start;
  }

  // 窗口
  int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    // 本来下标是0..n-1，但是扩充到0..2*n-1，i位置的余量信息在(r%n)位置
    // 窗口范围是[l, r)，左闭右开，也就是说窗口是[l..r-1]，r是到不了的位置
    for (int l = 0, r = 0, sum; l < n; l = r + 1, r = l) {
      sum = 0;
      // 任何位置加上下一位累加和小于0，都直接进入下一起点
      while (sum + gas[r % n] - cost[r % n] >= 0) {
        // r位置即将右扩，窗口会变大
        if (r - l + 1 == n) {  // 检查是否已经转了一圈，是则返回起点
          return l;
        }
        // r位置进入窗口，累加和加上r位置的余量
        sum += gas[r % n] - cost[r % n];
        // r右扩，窗口变大了
        r++;
      }
    }
    return -1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
