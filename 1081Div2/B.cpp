#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; string s;
  cin >> n >> s;

  int zeros = 0, ones = 0;
  int idx1[n];
  int limit = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 1) {
      ones++;
      idx1[i] = limit++;
    }
  }
  zeros = n - ones;
  if (n % 2 == 1 && ones % 2 == 1) {
    cout << "-1" << "\n";
    return 0;
  }
  if (ones % 2 == 0) {
    cout << ones << "\n";
    int limit1 = 0;
    for (int i = 0; i < n; i++) {
      if (i == idx1[limit1]) {
        cout << i + 1 << " ";
        limit1++;
      }
    }
    cout << "\n";
    return 0;
  }
  cout << zeros << "\n";
  int limit2 = 0;
  for (int i = 0; i < n; i++) {
    if (i != idx1[limit2]) {
      cout << i + 1 << " ";
    } else {
      limit2++;
    }
  }
  cout << "\n";
  return 0;
}
