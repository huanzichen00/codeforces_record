#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // sufMax[i] = max(p[i..n-1]), pos[i] = 这个最大值的位置（取最左那个）
    vector<int> sufMax(n), pos(n);
    int curMax = -1, curPos = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (p[i] > curMax) {
        curMax = p[i];
        curPos = i;
      }
      sufMax[i] = curMax;
      pos[i] = curPos;
    }

    int l = -1;
    for (int i = 0; i < n; i++) {
      if (p[i] != sufMax[i]) { // 当前位置不是后缀最大，能通过一次 reverse 变大
        l = i;
        break;
      }
    }

    if (l != -1) {
      int r = pos[l];
      reverse(p.begin() + l, p.begin() + r + 1);
    }

    for (int i = 0; i < n; i++) {
      cout << p[i] << (i + 1 == n ? '\n' : ' ');
    }
  }
  return 0;
}
