#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int maxLength(vector<int>& arr, int k) {
  unordered_map<ll, int> firstPos;
  firstPos[0] = -1;  // 前缀和为0，认为在下标-1位置出现

  ll sum = 0;
  int ans = 0;

  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];

    if (firstPos.count(sum - k)) {
      ans = max(ans, i - firstPos[sum - k]);
    }

    // 只记录最早出现的位置
    if (!firstPos.count(sum)) {
      firstPos[sum] = i;
    }
  }

  return ans;
}

int subArraySum(vector<int>& nums, int k) {
  unordered_map<ll, int> cnt;
  cnt[0] = 1; // 前缀和为0出现一次

  ll sum = 0;
  int ans = 0;

  for (int x : nums) {
    sum += x;

    if (cnt.count(sum - k)) {
      ans += cnt[sum - k];
    }

    cnt[sum]++;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
