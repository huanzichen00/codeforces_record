#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100005;
int arr[MAXN];
int n;

bool f(int energy, int mx) {
  for (int i = 1; i <= n; i++) {
    energy = energy * 2 - arr[i];
    if (energy >= mx) {
      return true;
    }
    if (energy < 0) {
      return false;
    }
  }
  return true;
}

int compute(int l, int r, int mx) {
  int ans = -1;
  while (l <= r) {
    int m = l + ((r - l) >> 1);
    if (f(m, mx)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> n) {
    int mx = 0;
    for (int i = 1; i <=n; i++) {
      cin >> arr[i];
      mx = max(mx, arr[i]);
    }
    cout << compute(0, mx, mx) << '\n';
  }
  return 0;
}
