#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1e9 + 7;

void solve() {
  ll n; cin >> n;
  string s; cin >> s;
  ll ct = 1 + (int)(s.front() != s.back());
  for (ll i = 1; i < n; i++) {
    if (s[i] != s[i - 1])x ct++;
  }
  ct = min(n, ct);
  cout << ct << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  if (!(cin >> tt)) return 0;

  while (tt--) {
    solve();
  }
  return 0;
}
