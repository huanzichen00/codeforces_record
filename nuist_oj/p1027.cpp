#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(int m, int k) {
  int n = 2 * m;
  int pos = 0;

  for (int i = 1; i <= m; i++) {
    pos = (pos + k - 1) % n;
    if (pos < m) {
      return false;
    }
    n--;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;
  
  for (int k = m; ; k++) {
    if (check(m, k)) {
      cout << k << '\n';
      break;
    }
  }
  cout << '\n';
  return 0;
}
