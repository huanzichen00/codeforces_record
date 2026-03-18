#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  // 时间复杂度O(n)，额外空间复杂度O(1)
  int firstMissingPositive(vector<int>& nums) {
    // l的左边，都是做到i位置上放着i + 1的区域
    // 永远盯着 l 位置的数字看，看能不能扩充(l++)
    int n = nums.size();
    int l = 0;
    // [r.....]垃圾区
    // 最好的状况下，认为 1~r 是可以收集全的，每个数字收集1个，不能有垃圾
    // 有垃圾呢？预期就会变差
    int r = nums.size();
    while (l < r) {
      if (nums[l] == l + 1) {
        l++;
      } else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) {
        swap(nums[l], nums[--r]);
      } else {
        swap(nums[l], nums[nums[l] - 1]);
      }
    }
    return l + 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
