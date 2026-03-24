#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

struct Node {
  int x, y;
} arr[MAXN];

int maxq[MAXN], minq[MAXN];
int maxh, maxt, minh, mint;

bool cmp(const Node& a, const Node& b) {
  return a.x < b.x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }

  sort(arr, arr + n, cmp);

  maxh = maxt = 0;
  minh = mint = 0;
  int ans = INT_MAX;

  for (int l = 0, r = 0; r < n; r++) {
    while (maxh < maxt && arr[maxq[maxt - 1]].y <= arr[r].y) maxt--;
    maxq[maxt++] = r;

    while (minh < mint && arr[minq[mint - 1]].y >= arr[r].y) mint--;
    minq[mint++] = r;

    while (maxh < maxt && minh < mint &&
           arr[maxq[maxh]].y - arr[minq[minh]].y >= d) {
      ans = min(ans, arr[r].x - arr[l].x);
      if (maxq[maxh] == l) maxh++;
      if (minq[minh] == l) minh++;
      l++;
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << '\n';
  return 0;
}
