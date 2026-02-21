#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n, s, x;
    cin >> n >> s >> x;
    int sum = 0;

    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      sum += num;
    }

    bool yes = false;
    while (sum >= 1 && sum <= 100) {
      if (sum == s) {
        cout << "yes" << "\n";
        yes = true;
        break;
      }
      sum += x;
    }

    if (!yes) {
      cout << "no" << "\n";
    }
  }
  return 0;
}
