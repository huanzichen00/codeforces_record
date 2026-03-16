#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  string minWindow(string s, string t) {
    int cnts[256] = {0};

    // 先把 t 里的字符记成“欠债”
    for (char ch : t) {
      cnts[ch]--;
    }

    // 总债务
    int debt = t.size();
    // 从哪个位置开头，发现的最小覆盖子串
    int start = 0;
    // 最小覆盖子串的长度
    int len = INT_MAX;

    for (int l = 0, r = 0; r < (int)s.size(); r++) {
      // 窗口右边界向右，给出字符(相对于负债表)
      if (cnts[s[r]] < 0) {
        debt--;
      }
      cnts[s[r]]++;
      // 当前窗口已经覆盖t
      if (debt == 0) {
        // 窗口左边界向右，拿回字符(删去左边没用的字符)
        // 没用的字符包括不涵盖在tar里的字符和超过欠债的字符
        while (cnts[s[l]] > 0) {
          cnts[s[l]]--;
          l++;
        }

        // 更新答案
        if (r - l + 1 < len) {
          len = r - l + 1;
          start = l;
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
