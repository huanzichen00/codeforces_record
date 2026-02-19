#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int sum, num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    sum += num;
  }
  double ans;
  ans = (double)sum / (double)n;
  cout << ans << "\n";
  return 0;
}
