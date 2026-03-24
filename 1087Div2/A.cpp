#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 105;
int arr[MAXN];
bool used[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  int n;
  ll c, k;
  while (tt--) {
    cin >> n >> c >> k;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      used[i] = false;
    }

    sort(arr, arr + n);

    while (true) {
      int id = -1;
      for (int i = 0; i < n; i++) {
        if (!used[i] && arr[i] <= c) {
          id = i;
          break;
        }
      }

      if (id == -1) {
        break;
      }

      ll use = min(k, c - arr[id]);
      c += arr[id] + use;
      k -= use;
      used[id] = true;
    }
    cout << c << '\n';
  }
  return 0;
}
