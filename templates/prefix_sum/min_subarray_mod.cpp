#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int minSubarray(vector<int>& nums, int p) {
  ll total = 0;
  for (int x : nums) total += x;

  int mod = total % p;
  if (mod == 0) return 0;

  unordered_map<int, int> lastPos;
  lastPos[0] = -1;

  ll prefix = 0;
  int ans = nums.size();

  for (int i = 0; i < nums.size(); i++) {
    prefix += nums[i];
    int cur = prefix % p;

    int need = (cur - mod + p) % p;
    if (lastPos.count(need)) {
      ans = min(ans, i - lastPos[need]);
    }

    lastPos[cur] = i;
  }

  return ans == nums.size() ? -1 : ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
