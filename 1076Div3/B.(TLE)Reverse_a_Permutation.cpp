#include <bits/stdc++.h>
using namespace std;

void f(int&, vector<int>&, int&, const int&);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;

    vector<int> p;
    p.reserve(n);
    int num;
    int max_index = 0;

    for (int i = 0; i < n; i++) {
      cin >> num;
      p.push_back(num);
      if (num == n) {
        max_index = i;
      }
    }

    int where = 0;
    f(max_index, p, where, n);

    for (auto& v : p) cout << v << " ";
    cout << "\n";
  }
}

void f(int& max_index, vector<int>& p, int& where, const int& n) {
  if (where >= n) return;

  if (max_index != where) {
    reverse(p.begin() + where, (max_index == n - 1 ? p.end() : p.begin() + max_index + 1));
    return;
  } else {
    for (int i = where; i < n; i++) {
      if (p[i] == n - where - 1) {
        max_index = i;
      }
    }
    where++;
    f(max_index, p, where, n);
  }
}
