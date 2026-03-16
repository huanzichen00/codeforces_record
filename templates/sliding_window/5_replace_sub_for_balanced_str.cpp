#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int balancedString(string str) {
    int n = str.size();
    // 映射数组
    vector<int> s(n);
    // 统计词频
    int cnts[4] = {0};

    for (int i = 0; i < n; i++) {
      char c = str[i];
      // 这么写有点骚
      s[i] = c == 'W' ? 1 : (c == 'E' ? 2 : (c == 'R' ? 3 : 0));
      cnts[s[i]]++;
    }

    int debt = 0;
    for (int i = 0; i < 4; i++) {
      if (cnts[i] < n / 4) {
        cnts[i] = 0;
      } else {
        cnts[i] = n / 4 - cnts[i];
        debt -= cnts[i];
      }
    }

    if (debt == 0) {
      return 0;
    }

    int ans = INT_MAX;
    for (int l = 0, r = 0; r < n; r++) {
      if (cnts[s[r]]++ < 0) {
        debt--;
      }
      if (debt == 0) {
        while (cnts[s[l]] > 0) {
          cnts[s[l]]--;
          l++;
        }
        ans = min(ans, r - l + 1);
      }
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
