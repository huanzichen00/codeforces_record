#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solve(int n) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }
  return solve(n - 1) + solve(n - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << solve(n) << '\n';
  return 0;
}
