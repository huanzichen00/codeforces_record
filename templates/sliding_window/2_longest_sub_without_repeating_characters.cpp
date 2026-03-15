#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size(), ans = 0;
    int cnt[256] = {0};

    for (int l = 0, r = 0; r < n; r++) {
      cnt[(unsigned char)s[r]]++;
      while (cnt[(unsigned char)s[r]] > 1) {
        cnt[(unsigned char)s[l]]--;
        l++;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }

  // 写个(unsigned char)更快且稳定
  int sol2(string s) {
    int last[256];
    memset(last, -1, sizeof(last));

    int ans = 0;
    int n = s.size();
    for (int l = 0, r = 0; r < n; r++) {
      l = max(l, last[s[r]] + 1);
      ans = max(ans, r - l + 1);
      last[s[r]] = r;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
