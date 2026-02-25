#include <bits/stdc++.h>
using namespace std;

struct Item { int w, h, idx; };

int main() {
  int tt, w, h; cin >> tt >> w >> h;

  vector<Item> v;
  v.reserve(tt);

  for (int i = 1; i <= tt; i++) {
    int wi, hi;
    cin >> wi >> hi;
    if (wi < w && hi < h) {
      v.push_back({wi, hi, i});
    }
  }

  sort(v.begin(), v.end(), [](const Item& a, const Item& b) {
    if (a.w != b.w) return a.w < b.w;
    return a.h < b.h;
  });

  cout << v.size() << "\n";
  for (auto& it : v) cout << it.idx << " ";
  cout << "\n";
  return 0;
}

