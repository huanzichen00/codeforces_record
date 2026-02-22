#include <bits/stdc++.h>
using namespace std;

struct Item {
  int a, b;   // 你要排序/比较的关键字段（比如 w,h）
  int idx;    // 原始下标(1-based)
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Item> v;
  v.reserve(n);

  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y, i});   // 存数据 + 记原下标
  }

  // 自定义排序：先按 a 升序，再按 b 升序（你可按题改）
  sort(v.begin(), v.end(), [](const Item& p, const Item& q) {
    if (p.a != q.a) return p.a < q.a;
    return p.b < q.b;
  });

  // 输出排序后的原下标
  for (auto &it : v) cout << it.idx << " ";
  cout << "\n";
  return 0;
}
