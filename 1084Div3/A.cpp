#include <bits/stdc++.h>
using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a;
    a.reserve(n);
    int num;
    for (int i = 0; i < n; i++) {
      cin >> num;
      a.push_back(num);
    }
    int m = INT_MIN;
    for (int i = 0; i < n; i++) {
      m = max(m, a[i])
    }
    cout << ans << "\n";
  }
  return 0;
}

