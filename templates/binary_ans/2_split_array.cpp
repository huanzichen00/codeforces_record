#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    long long ans = 0;
    for (long long l = 0, r = sum, m, need; l <= r;) {
      m = l + ((r - l) >> 1);
      need = f(nums, m);
      if (need <= k) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return (int)ans;
  }

  // 必须让数组nums每一部分的累加和<=limit,划分成几个部分才够
  // 返回需要的部分数量
  int f(vector<int>& nums, long long limit) {
    int parts = 1;
    long long sum = 0;

    for (int& x : nums) {
      if (x > limit) {
        return INT_MAX;
      }
      if (sum + x > limit) {
        parts++;
        sum = x;
      } else {
        sum += x;
      }
    }
    return parts;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
