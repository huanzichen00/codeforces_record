#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int to_norm(int num, int B) {
  int ans = 0;
  int base = 1;
  while (num > 0) {
    if (num % 10 > B - 1) {
      return -1;
    }
    ans += num % 10 * base;
    base *= B;
    num /= 10;
  }
  return ans;
}

bool is_valid(int p, int q, int r, int B) {
  int pp = to_norm(p, B);
  int qq = to_norm(q, B);
  int rr = to_norm(r, B);
  if (1LL * pp * qq == rr && pp > 0 && qq > 0 && rr > 0) {
    return true;
  }
  return false;
}

int solve(int p, int q, int r) {
  for (int B = 2; B <= 16; B++) {
    if (is_valid(p, q, r, B)) {
      return B;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int q, p, r;
    cin >> p >> q >> r;
    cout << solve(p, q, r) << '\n';
  }
  return 0;
}
