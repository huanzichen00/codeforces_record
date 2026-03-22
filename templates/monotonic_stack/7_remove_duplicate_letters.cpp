#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 26;
  // 各种字符词频
  int cnts[MAXN];
  // 各种字符目前有没有进栈
  bool enter[MAXN];
  // 单调栈
  char st[MAXN];
  int top;

  string removeDuplicateLetters(string s) {
    fill(cnts, cnts + MAXN, 0);    
    fill(enter, enter + MAXN, false);
    top = 0;

    for (char c : s) {
      cnts[c - 'a']++;
    }

    for (char cur : s) {
      // 从左往右依次遍历字符，a -> 0 b -> 1 ... z -> 25
      // cur -> cur - 'a'
      if (!enter[cur - 'a']) {
        // 栈不为空 后面还有此字符(词频 > 0)
        while (top > 0 && st[top - 1] > cur && cnts[st[top - 1] - 'a'] > 0) {
          enter[st[top - 1] - 'a'] = false;
          top--;
        }
        st[top++] = cur;
        enter[cur - 'a'] = true;
      }
      // 如果已经进过栈，跳过并减词频
      // 没进过，先经历进栈逻辑，再减词频
      cnts[cur - 'a']--;
    }
    return string(st, st + top);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
