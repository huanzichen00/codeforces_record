#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n, a;
  cin >> t;
  while (t--) {
    cin >> n;
    bool ans = false;
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a == 67) {
        ans = true;
      }
    }
    cout << (ans ? "YES" : "NO") << "\n";
  }
  return 0;
}
