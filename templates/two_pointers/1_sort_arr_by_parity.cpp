#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 1;
        
        while (even < n && odd < n) {
            int last = nums[n - 1];
            if (last % 2 == 0) {
                swap(nums[even], nums[n - 1]);
                even += 2;
            } else {
                swap(nums[odd], nums[n - 1]);
                odd += 2;
            }
        }
        return nums;
    }
};

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
