#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 嗯用滑窗，看数据量只有小写字母就遍历26次
class Solution {
public:
  int longestSubstring(string s, int k) {
    int n = s.size();
    int cnts[256];
    int ans = 0;

    // 每次要求子串必须含有 require 种字符，每种字符都必须 >= k次 
    // 这样的最长子串是多长
    for (int require = 1; require <= 26; require++) {
      memset(cnts, 0, sizeof(cnts));

      // collect : 窗口中一共收集到的种类数
      // satisfy : 窗口中达标的种类数(次数 >= k)
      for (int l = 0, r = 0, collect = 0, satisfy = 0; r < n;  r++) {
        cnts[s[r]]++;
        if (cnts[s[r]] == 1) {
          collect++;
        }
        if (cnts[s[r]] ==  k) {
          satisfy++;
        }
        while (collect > require) {
          if (cnts[l] == 1) {
            collect--;
          }
          if (cnts[l] == k) {
            satisfy--;
          }
          cnts[l++]--;
        }
        if (satisfy == require) {
          ans = max(ans, r - l + 1);
        }
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
