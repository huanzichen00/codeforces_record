#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& a) {
  vector<int> d;
  for (int x : a) {
    auto it = lower_bound(d.begin(), d.end(), x);
    if (it == d.end()) d.push_back(x);
    else *it = x;
  }
  return d.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> tt;
  while (tt--) {
    cin >> n;
    vector<int> a;
    a.reserve(n);
    int num;
    for (int i = 0; i < n; i++) {
      a.push_back(num);
    }

    vector<int> help;
    help.reserve(n);
    
  }
}
