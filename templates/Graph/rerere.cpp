#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    int n = target.size();
    int m = stamp.size();

    vector<int> indegree(n - m + 1, m);
    vector<vector<int>> graph(n);
    vector<int> queue(n - m + 1);
    int l = 0, r = 0;
    for (int i = 0; i <=n; i++) {
      for (int j = 0; j <= m; j++) {
        if (target[i + j] == stamp[j]) {
          if (--indegree[i] == 0) {
            queue[r++] = i;
          }
        } else {
          graph[i + j].push_back(i);
        }
      }
    }

    vector<char> vis(n, 0);
    vector<int> path;
    path.reserve(n - m + 1);

    while (l < r) {
      int cur = queue[l++];
      path.push_back(cur);

      for (int i = 0; i < m; i++) {
        int pos = cur + i;
        if (!vis[pos]) {
          vis[pos] = 1;
          for (int next : graph[pos]) {
            if (--indegree[next] == 0) {
              queue[r++] = next;
            }
          }
        }
      }
    }
    if ((int)path.size() != n - m + 1) {
      return {};
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
