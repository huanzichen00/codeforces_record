#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 哈希表实现
int findTheLongestSubstring(string s) {
  unordered_map<int, int> firstPos;
  firstPos[0] = -1;

  int status = 0;
  int ans = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') status ^= (1 << 0);
    else if (s[i] == 'e') status ^= (1 << 1);
    else if (s[i] == 'i') status ^= (1 << 2);
    else if (s[i] == 'o') status ^= (1 << 3);
    else if (s[i] == 'u') status ^= (1 << 4);    

    if (firstPos.count(status)) {
      ans = max(ans, i - firstPos[status]);
    } else {
      firstPos[status] = i;
    }
  }

  return ans;
}

int move(char c) {
  switch (c) {
    case 'a': return 0;
    case 'e': return 1;
    case 'i': return 2;
    case 'o': return 3;
    case 'u': return 4;    
    default: return -1;
  }
}
// 静态数组实现
int findTheLongestSubstring1(string s) {

  int mp[32];   // 2 ^ 5种状态
  // mp[0...31] = -2
  // mp[01100] = -2, 这个状态之前没出现过
  fill(mp, mp + 32, - 2);
  // 0 : 00000
  //     uoiea
  mp[0] = -1;

  int ans =0;
  int status = 0;

  for (int i = 0; i < (int)s.size(); i++) {
    int m = move(s[i]);
    if (m != 1) status ^= (1 << m);

    // 最大子串长度
    // 更新答案
    if (mp[status] != -2) ans = max(ans, i - mp[status]);
    else mp[status] = i;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
