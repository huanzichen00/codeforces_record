#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    vector<int> ones, zeros;
    ones.reserve(n);
    zeros.reserve(n);

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') ones.push_back(i + 1);
      else zeros.push_back(i + 1);
    }

    if ((int)ones.size() % 2 == 0) {
      cout << ones.size() << "\n";
      for (int i = 0; i < (int)ones.size(); ++i) {
        if (i) cout << ' ';
        cout << ones[i];
      }
      cout << "\n";
    } else if ((int)zeros.size() % 2 == 1) {
      cout << zeros.size() << "\n";
      for (int i = 0; i < (int)zeros.size(); ++i) {
        if (i) cout << ' ';
        cout << zeros[i];
      }
      cout << zeros[i];
    }
    cout << "\n";
  }
  return 0;
}
