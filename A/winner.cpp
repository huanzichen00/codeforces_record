#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<string, int>> logs; // 记录读入数据，便于第二遍按原顺序回放
  logs.reserve(n); // reserve 只分配空间，不增加元素数量。

  map<string, long long> total;

  // 第一遍，获取总分
  for (int i = 0; i < n; i++) {
    string name;
    int delta;
    cin >> name >> delta;
    logs.push_back({name, delta});
    total[name] += delta;
  }

  // 提取最高分
  long long maxScore = LLONG_MIN;
  for (auto& kv : total) {
    maxScore = max(maxScore, kv.second);
  }
  // 第二遍，顺序遍历记录，看谁最先达到>=最高分
  map<string, long long> cur;
  for (auto& e : logs) {
    const string& name = e.first;
    int delta = e.second;

    cur[name] += delta;

    if (total[name] == maxScore && cur[name] >= maxScore) {
      cout << name << "\n";
      return 0;
    }
  }  return 0;
}

