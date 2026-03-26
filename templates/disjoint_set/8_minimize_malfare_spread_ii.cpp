#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 301;
  bool virus[MAXN];  // 点 i 是否是初始感染来源
  int cnts[MAXN];    // cnts[x] : 如果删掉感染源 x; 最多能救下多少个普通点
  int infect[MAXN];  // infect[root] : 这个普通联通块被哪些感染源碰到
                     // -1 : 还没被任何感染源碰到, 还没被感染源碰到                     // >= 0 目前只被一个感染源碰到, 值就是那个感染源编号
                     // -2 : 被多个不同感染源碰到, 删一个也救不了这个块
  int father[MAXN];
  int sz[MAXN];

  void init(int n, vector<int>& initial) {
    for(int i = 0; i < n; i++) {
      father[i] = i;
      sz[i] = 1;
      virus[i] = false;
      infect[i] = -1; // -1 : 还没被任何感染源碰到
      cnts[i] = 0;
    }
    // 标记哪些点是初始感染源
    for (int x : initial) {
      virus[x] = true;
    }
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

      sz[fy] += sz[fx];
    }
  }

  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int n = graph.size();
    init(n, initial);

    // 找到两端节点都是普通点的边，将两个点并同一个普通连通块
    for (int i = 0; i < n; i++) {
      if (!virus[i]) {
        for (int j = i + 1; j < n; j++) {
          if (!virus[j] && graph[i][j] == 1) {
            unite(i, j);
          }
        }
      }
    }

    // 遍历每个感染源 sick:
    // 再依次遍历 neighbor, 更新 infect 数组信息
    for (int sick : initial) {
      for (int neighbor = 0; neighbor < n; neighbor++) {
        if (sick != neighbor && !virus[neighbor] && graph[sick][neighbor] == 1) {
          int fn = find(neighbor);
          if (infect[fn] == -1) {
            infect[fn] = sick;
          } else if (infect[fn] != -2 && infect[fn] != sick) {
            infect[fn] = -2;
          }
        }
      }
    }

    // 统计每个感染源"独占能拯救"的普通点数量
    // 只有 infect[root] >= 0 符合条件
    // 只统计集合根, 每个块只统计一次
    for (int i = 0; i < n; i++) {
      if (!virus[i] && i == find(i) && infect[i] >= 0) {
        cnts[infect[i]] += sz[i];
      }
    }

    // 选出答案 
    sort(initial.begin(), initial.end());

    int ans = initial[0];
    int best =  cnts[ans];

    for (int x : initial) {
      if (cnts[x] > best) {
        best = cnts[x];
        ans = x;
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
