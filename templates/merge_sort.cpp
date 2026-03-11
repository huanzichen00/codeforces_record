#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<int> help(n);
vector<int> arr(n);

void merge(int l, int r) {
  if (l == r) {
    return;
  }
  int m = l + ((r - 1) >> 1);
  merge(l, m);
  merge(m + 1, r);
  int i = l, j = m + 1;
  while (i <= m && j <= r) {
    help.push_back(arr[i] < arr[j] ? arr[i++] : arr[j]);
  }
  while (i <= m) {
    help.push_back(arr[i++]);
  }
  while (j <= r) {
    help.push_back(arr[j++]);
  }
  arr = help;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    arr.push_back(num);
  }
  merge(0, n);
  for (int x : arr) {
    if (i) cout << " ";
    cout << x;
  }
  return 0;
}
