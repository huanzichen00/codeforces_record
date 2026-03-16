#include <bits/stdc++.h>
using namespace std;

using ll = long long;

char to_16(string sub) {
  int val = 0;
  for (char c : sub) {
    val = val * 2 + (c - '0');
  }
  if (val < 10) {
    return '0' + val;
  }
  return 'A' + (val - 10);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();
  int times = (n + 3) >> 2;
  int yu = n % 4;
  string ans;
  string sub;
  bool doit = true;
  while (times--) {
    if (times == 0 && yu != 0) {
      sub = s.substr(s.size() - yu, yu);
    } else {
      sub = s.substr(s.size() - 4, 4);
    }
    ans.push_back(to_16(sub));
    s.erase(s.size() - sub.size(), sub.size()); 
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}
