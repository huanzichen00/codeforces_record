#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool f(vector<int>& cuts, vector<int>& poisons, ll hp, int limit) {
  int n = min((int)cuts.size(), limit);
  for (int i = 0, j = 1; i < n; i++, j++) {
    hp -= max((ll)cuts[i], 1LL * (limit - j) * poisons[i]);
  }
  if (hp > 0) {
      return true;
    }
    return false;
  }

int fast2(vector<int>& cuts, vector<int>& poisons, ll hp) {
  int ans = INT_MAX;
  for (int l = 1, r = hp + 1, m; l <= r;) {
    m = l + ((r - l) >> 1);
    if (f(cuts, poisons, hp, m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

// 对数器辅助函数
vector<int> randomArray(int n, int v) {
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = rand() % v + 1;
  }  
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  srand((unsigned)time(nullptr));

  cout << "测试开始" << '\n';

  // 数据不能太大，否则fast1会很慢
  int N = 30;
  int V = 20;
  int H = 300;
  int testTimes = 10000;
  
  for (int t = 0; t < testTimes; t++) {
    int n = rand() % N + 1;
    vector<int> cuts = randomArray(n, V);
    vector<int> poisons = randomArray(n, V);
    int hp = rand() % H + 1;

    int ans1 = fast1(cuts, poisons, hp);
    int ans2 = fast2(cuts, poisons, hp);    

    if (ans1 != ans2) {
      cout << "出错了!" << '\n';
      cout << "n = " << n << '\n';
      cout << "hp = " << hp << '\n';

      cout << "cuts: ";
      for (int x : cuts) {
        cout << x << ' ';
      }
      cout << '\n';

      cout << "poisons: ";
      for (int x : poisons) {
        cout << x << ' ';
      }
      cout << '\n';

      cout << "fast1 = " << ans1 << '\n';
      cout << "fast2 = " << ans2 << '\n';
    }
  }
  cout << "测试结束" << '\n';
  return 0;
}
