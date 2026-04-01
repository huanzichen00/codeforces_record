#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    vector<vector<int>> graph(numCourses);

    // 入度表  
    vector<int> indegree(numCourses, 0);

    // edge = [a, b], 表示要学 a 之前必须先学 b
    // 所以建边 : b -> a
    for (auto& edge : prerequisites) {
      graph[edge[1]].push_back(edge[0]);
      indegree[edge[0]]++;
    }

    // 数组模拟队列
    vector<int> queue(numCourses);
    int l = 0, r = 0;

    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        queue[r++] = i;
      }
    }

    int cnt = 0;

    while (l < r) {
      int cur = queue[l++];
      cnt++;

      for (int next : graph[cur]) {
        if (--indegree[next] == 0) {
          queue[r++] = next;
        }
      }
    }

    if (cnt == numCourses) {
      return queue;
    }
    // 图是有环图，不符合要求，返回空数组
    return {};
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
