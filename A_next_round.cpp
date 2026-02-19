#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int std = a[k - 1];
 
  for(int x : a) {
    if (x >= std && x != 0) {
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
