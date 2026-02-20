#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin  >> n;
  ll arr[18];
  for (int i = 0; n != 0; i++, n = n / 10) {
    arr[i] = n % 10;
  }
  int cnt = 0;
  for (int x : arr) {
    if (x == 4 || x == 7) {
      cnt++;
    }
  }
  if (cnt == 4 || cnt == 7) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}

