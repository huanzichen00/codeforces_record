#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    // [0 ... nums[n - 1] - nums[0]] 开始二分
    for (int l = 0, r = nums[n - 1] - nums[0], m, cnt; l <= r; ) {
      m = l + ((r - l) >> 1);
      // 返回距离不大于 m 的数对数量
      cnt = f(nums, m);
      // 如果数量已经大于k，说明m可行，继续往左找更小
      if (cnt >= k) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }

  // 数组中任意两数的差值 <= limit
  // 这样的数字配对，有几对
  int f(vector<int>& nums, int limit) {
    int ans = 0;
    // 滑动窗口找距离小于 limit 的数对
    for (int l = 0, r = 0; l < nums.size(); l++) {
      while (r + 1 < (int)nums.size() && nums[r + 1] - nums[l] <= limit) {
        r++;
      }
      ans += r - l;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
