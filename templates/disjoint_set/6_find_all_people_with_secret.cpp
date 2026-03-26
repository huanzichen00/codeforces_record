#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 100000 + 5;
  int father[MAXN];
  bool secret[MAXN];

  void init(int n, int first) {
    for (int i = 0; i < n; i++) {
      father[i] = i;
      secret[i] = false;
    }
    father[first] = 0;
    secret[0] = true;
  }

  int find(int x) {
    if (father[x] != x) {
      father[x] = find(father[x]);
    }
    return father[x];
  }

  void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      father[fx] = fy;
      // 只要有一方知道秘密，就都知道秘密
      secret[fy] |= secret[fx];
    }
  }

  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    init(n, firstPerson);
    // {0 : 专家   1 : 专家编号   2 : 时刻}

    // 按时间排序
    sort(meetings.begin(), meetings.end(),
      [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
      });

    int m = meetings.size();

    // 按时间分组处理
    // 每场会议对应一个窗口
    for (int l = 0, r; l < m;) {
      r = l;
      while (r + 1 < m && meetings[r + 1][2] == meetings[l][2]) {
        r++;
      }

      // 1. 同一时刻的会议，先全部合并
      for (int i = l; i <= r; i++) {
        unite(meetings[i][0], meetings[i][1]);
      }

      // 2. 这一批结束后，把没连到秘密集合的人拆开
      for (int i = l; i <= r; i++) {
        int a = meetings[i][0];
        int b = meetings[i][1];

        if (!secret[find(a)]) {
          father[a] = a;
        }
        if (!secret[find(b)]) {
          father[b] = b;
        }
      }

      l = r + 1;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (secret[find(i)]) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
