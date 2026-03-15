#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;

    for (int l = 0, r = 0, sum = 0; r < n; r++) {
      sum += nums[r];
      while (sum >= target) {
        ans = min(ans, r - l + 1);
        sum -= nums[l++];
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
