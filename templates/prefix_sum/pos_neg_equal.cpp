#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int longestEqualPosNeg(vector<int>& nums) {
  unordered_map<int, int> firstPos;
  firstPos[0] = -1;

  int sum = 0;
  int ans = 0;
  
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) sum += 1;
    else if (nums[i] < 0) sum -= 1;
    // nums[i] == 0 时 sum 不变
  
    if (firstPos.count(sum)) {
      ans = max(ans, i - firstPos[sum]);
    } else {
      firstPos[sum] = i;
    }
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
