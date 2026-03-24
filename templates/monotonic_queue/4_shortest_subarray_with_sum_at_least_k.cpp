#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 100000 + 5;
  int q[MAXN];
  int head, tail;

  // sum[0] : 前 0 个数的前缀和
  // sum[i] : 前 i 个数的前缀和
  long long sum[MAXN];

  int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      // 跳过了 0
      sum[i + 1] = sum[i] + nums[i];
    }

    head = tail = 0;
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
      while (head != tail && sum[q[tail - 1]] >= sum[i]) {
        tail--;
      }

      while (head != tail && sum[i] - sum[q[head]] >= k) {
        // 如果当前前缀和 - 头前缀和达标
        // r 是开区间界限，所以长度是 r - q[head];
        ans = min(ans, i - q[head]);
        head++;
      }

      q[tail++] = i;
    }
    return ans != INT_MAX ? ans : -1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
