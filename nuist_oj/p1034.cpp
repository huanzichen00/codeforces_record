#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  string s;
  cin >> k;
  cin >> s;

  int n = s.size();
  k %= n;
  string ans = s.substr(k) + s.substr(0, k);
  cout << ans << '\n';
  return 0;
}
