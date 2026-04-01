#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    int m = stamp.size();
    int n = target.size();

    // 一共有 n - m + 1 个窗口
    // 初始化入度为 m
    vector<int> indegree(n - m + 1, m);

    vector<vector<int>> graph(n);

    // 队列里放已经可用的窗口节点 
    vector<int> queue(n - m + 1);
    int l = 0, r = 0;

    // 枚举每个窗口 i
    for (int i = 0; i < n - m + 1; i++) {
      // 枚举 stamp 的每一位 j
      for (int j = 0; j < m; j++) {
        if (target[i + j] == stamp[j]) {
          if (--indegree[i] == 0) {
            // 这个位置本来就匹配
            // 窗口 i 还差的位置数减 1
            queue[r++] = i;
          } 
        } else {
          // 这个位置不匹配
          // 记一条依赖关系
          // 位置 i+j 如果将来被别的窗口"消掉"
          // 就能帮助窗口 i 少一个错误位置
          graph[i + j].push_back(i);
        }
      }
    }

    // vis[pos] : 位置 pos 是否已经被当作"解决"处理过
    // 同一个位置只能贡献一次, 不能重复减
    vector<bool> vis(n, false);

    // 倒退得到的盖章位置顺序
    vector<int> path;
    path.reserve(n - m + 1);

    while (l < r) {
      int cur = queue[l++];
      path.push_back(cur);

      // 当前窗口 cur 被覆盖
      // 那么它覆盖的所有位置 cur ... cur + m - 1
      // 都可以视为"已经解决"
      for (int i = 0; i < m; i++) {
        int pos = cur + i;
        if (!vis[pos]) {
          vis[pos] = true;

          // 这个位置一旦解决
          // 所有依赖它的窗口都能少一个错误数
          for (int next : graph[pos]) {
            if (--indegree[next] == 0) {
              queue[r++] = next;
            }
          }
        }
      }
    }

    // 如果不是所有窗口都能被倒退出, 说明无解
    if ((int)path.size() != n - m + 1) {
      return {};
    }

    // 现在得到的是"倒着擦章"的顺序
    // 题目要的是正着盖章的顺序, 所以反转
    reverse(path.begin(), path.end());
    return path;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
