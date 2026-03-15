#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXM = 1000005;
const int SHIFT = 3000005;                  // OFFSET
const int MAXN = SHIFT + MAXM + 3000005;

ll arr[MAXN];

void set1(int l, int r, int s, int e, int d) {
  // 为了防止x - 3 * v + 1出现负数下标，进而有很多很烦的边界讨论
  // 所以任何位置，都加上一个较大的数字(SHIFT)
  // 这样一来，所有下标就都在0以上了，省去了大量边界讨论
  // 这就是为什么arr在初始化的适合要准备SHIFT + MAXM + OFFSET这么多的空间
  arr[l + SHIFT] += s;
  arr[l + 1 + SHIFT] += d - s;
  arr[r + 1 + SHIFT] -= d + e;
  arr[r + 2 + SHIFT] += e;
}

void fall(int v, int x) {
  set1(x - 3 * v + 1, x - 2 * v, 1, v, 1);
  set1(x - 2 * v + 1, x, v - 1, -v, -1);
  set1(x = 1, x + 2 * v, -v + 1, v, 1);
  set1(x + 2 * v, x + 3 * v - 1, v - 1, 1, -1);  
}

void build(int m) {
  for (int i = 1; i <= m + SHIFT; i++) {
    arr[i] += arr[i - 1];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // n 个等差数列操作
  int n, m;
  cin >> n >> m;

  while (n--) {
    int v, x;
    cin >> v >> x;
    // v体积的朋友，在x处落水，修改差分数组
    fall(v, x);
  }
  // 生成最终的水位数组
  build(m);
  int start = SHIFT + 1;
  cout << arr[start++];
  for (int i = 2; i <= m; i++) {
    cout << " " << arr[start++];
  }
  cout << '\n';

  return 0;
}
