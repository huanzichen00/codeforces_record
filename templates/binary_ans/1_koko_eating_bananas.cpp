#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());
    int ans = INT_MAX;
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      if (f(piles, h, m)) {
        ans = min(ans, m);
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }

  bool f(vector<int>& piles, int h, int k) {
    long long ret = 0;
    for (int i = 0; i < (int)piles.size(); i++) {
      ret += (piles[i] + k - 1) / k;
    }
    return ret <= h;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
