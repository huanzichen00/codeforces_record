#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200 + 5;

int a[MAXN], b[MAXN], c[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  int n = s1.size();
  int m = s2.size();

  for (int i = 0; i < n; i++) {
    a[i + 1] = s1[n - 1 - i] - '0';
  }

  for (int j = 0; j < m; j++) {
    b[j + 1] = s2[m - 1 - j] - '0';
  }

  int len = max(m, n);

  for (int i = 1; i <= len; i++) {
    c[i] += a[i] + b[i];
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }

  if (c[len + 1] > 0) {
    len++;
  }
  
  for (int i = len; i >= 1; i--) {
    cout << c[i];
  }

  cout << '\n';
  return 0;
}
