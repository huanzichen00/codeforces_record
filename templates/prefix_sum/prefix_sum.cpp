#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a = {0, 2, 4, 1, 3, 5};
  // 下标从1开始，a[0]只是占位

  int n = 5;
  vector<int> sum(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  // 查询区间 [l, r] 的和
  int l = 2, r = 4;
  cout << sum[r] - sum[l - 1] << endl;  // 4 + 1 + 3 = 8
  
  return 0;
}
