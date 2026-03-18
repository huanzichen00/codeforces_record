#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int trap1(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }

    vector<int> lmax(n), rmax(n);

    lmax[0] = nums[0];
    for (int i = 1; i < n; i++) {
      lmax[i] = max(lmax[i - 1], nums[i]);
    }

    rmax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      rmax[i] = max(rmax[i + 1], nums[i]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      ans += min(lmax[i], rmax[i]) - nums[i];    
    }

    return ans;
  }

  int trap21(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }

    int l = 1, r = n - 2;
    int lmax = nums[0], rmax = nums[n - 1];
    int ans = 0;

    while (l <= r) {
      if (lmax <= rmax) {
        ans += max(0, lmax - nums[l]);
        lmax = max(lmax, nums[l]);
        l++;
      } else {
        ans += max(0, rmax - nums[r]);
        rmax = max(lmax, nums[r]);
        r++;
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
