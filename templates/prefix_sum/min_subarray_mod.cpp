#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int minSubarray(vector<int>& nums, int p) {
  ll total = 0;
  for (int x : nums) total += x;

  int mod = total % p;
  if (mod == 0) return 0;

  unordered

  unordered_map<int, int> lastPos;
  lastPos[0] = -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
