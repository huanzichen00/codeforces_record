#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    fast = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
