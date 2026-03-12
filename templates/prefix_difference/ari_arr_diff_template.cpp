#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 10000005;

ll arr[MAXN];

void set1(int l, int r, int s, ll e, ll d) {
  arr[l] += s;
  arr[l + 1] += d - s;
  arr[r + 1] -= d + e;
  arr[r + 2] += e;
}

void build(int n) {
  for (int i = 0; i < n; i++) {
    arr[i] += arr[i - 1];
  }
  for (int i = 0; i < n; i++) {
    arr[i] += arr[i - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int l, r;
    ll s , e;
    cin >> l >> r;

    ll d = (r == l ? 0 : (e - s) / (r - l));

    build(n);
    set1(l, r, s, e, d);
  }

  ll cur = 0;
  ll mx = 0;
  ll xr = 0;

  for (int i = 0; i <= n; i++) {
    cur += arr[i];
    mx = max(mx, cur);
    xr ^= cur;
  }

  cout << xr << ' ' << mx << '\n';
  return 0;
}
