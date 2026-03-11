#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool forward = 0, backward = 0;
  string a, b, c;
  getline(cin, a);
  getline(cin, b);
  getline(cin, c);
  int a1 = a.size();
  if (a.find(b) <= a1 && a.find(c, a.find(b) + b.size()) <= a1)
    forward = 1;
  reverse(a.begin(), a.end());
  if (a.find(b) <= a1 && a.find(c, a.find(b) + b.size()) <= a1)
    backward = 1;
  if (forward && backward) {
    cout << "both";
  } else if (forward) {
    cout << "forward";
  } else if (backward) {
    cout << "backward";
  } else {
    cout << "fantasy";
  }
  return 0;
}
