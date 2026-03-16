#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int gcd_3(int a, int b, int c) {
  return gcd(gcd(a, b), c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b, c;
  cin >> n;

  int ans = 0;
  while (n--) {
    cin >> a >> b >> c;
    ans = gcd_3(a, b, c);
    cout << ans << '\n';
  }
  return 0;
}
