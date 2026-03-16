#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int trap(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }

    int l = 1, r = n - 2;
    int lmax = nums[0], rmax = nums[n - 1];
    int ans = 0;

    
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
