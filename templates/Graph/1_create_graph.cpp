#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class CreateGraph {
public:
  // 点的最大数量
  static const int MAXN = 11;

  // 边的最大数量
  // 只有链式前向星需要这个数量
  // 如果无向图最多 m 条边，要准备 2 * m 的空间
  static const int MAXM = 21;

  // 邻接矩阵
  int graph1[MAXN][MAXM];

  // 邻接表
  vector<pair<int, int>> graph2[MAXN];

  // 链式前向星
  int head[MAXM];
  int next[MAXM];
  int to[MAXM];
  int weight[MAXM];
  int cnt;

  void build(int n) {
    // 邻接矩阵清空
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        graph1[i][j] = 0;
      }
    }

    // 邻接表清空
    for (int i = 0; i <= n; i++) {
      graph2[i].clear();
    }

    // 链式前向星清空
    cnt = 1;
    for (int i = 1; i <= n; i++) {
      head[i] = 0;
    }
  }

  void addEdge(int u, int v, int w) {
    next[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
    cnt++;
  }

  // 三种方式建立有向带权图
  void directGraph(const vector<array<int, 3>>& edges) {
    // 邻接矩阵
    for (auto edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph1[u][v] = w;
    }

    // 邻接表
    for (auto edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph2[u].push_back({v, w});
    }

    // 链式前向星
    for (auto edge : edges) {
      int u = edge[0], v = edge[1], w =edge[2];
      addEdge(u, v, w);
    }
  }

  // 三种方式建立无向带权图
  void undirectGraph(const vector<array<int, 3>>& edges) {
    // 邻接矩阵
    for (auto edge : edges) {
      int u = edge[0], v = edge[2], w = edge[2];
      graph1[u][v] = w;
      graph1[v][u] = w;
    }

    // 邻接表
    for (auto edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph2[u].push_back({v, w});
      graph2[v].push_back({u, w});
    }

    // 链式前向星
    for (auto edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      addEdge(u, v, w);
      addEdge(v, u, w);
    }
  }

  void traversal(int n) {
    cout << "邻接矩阵遍历 :\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << graph1[i][j] << ' ';
      }
      cout << '\n';
    }

    cout << "邻接表遍历 :\n";
    for (int i = 1 ; i <= n; i++) {
      cout << i << "(邻居、边权) : ";
      for (auto [v, w] : graph2[i]) {
        cout << "(" << v << "," << w << ") ";
      }
      cout << '\n';
    }

    cout << "链式前向星: \n";
    for (int i = 1; i <= n; i++) {
      cout << i << "(邻居、边权) : ";
      for (int ei = head[i]; ei > 0; ei = next[ei]) {
        cout << "(" << to[ei] << "," << weight[ei] << ") ";
      }
      cout << '\n';
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  
  return 0;
}
