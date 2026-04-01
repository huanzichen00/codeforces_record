#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1000001;
const int MAXM = 1000001;

int n, m;

// 链式前向星
int head[MAXM];
int nxt[MAXM];
int to[MAXM];
int cnt;

// 入度
int indegree[MAXN];

// 小根堆
int heap[MAXN];
int heapSize;

// 答案
int ans[MAXN];

void build() {
  cnt = 1;
  heapSize = 0;
  for (int i = 0; i < n; i++) {
    head[i] = 0;
    indegree[i] = 0; 
  }
}

void addEdge(int from, int dest) {
  nxt[cnt] = head[from];
  to[cnt] = dest;
  head[from] = cnt++;
}

void swapHeap(int i, int j) {
  int tmp = heap[i];
  heap[i] = heap[j];
  heap[j] = tmp;
}

void push(int x) {
  int i = heapSize++;
  heap[i] = x;
  while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
    swapHeap(i, (i - 1) / 2); 
    i = (i - 1) / 2;
  }
}

int pop() {
  int ret = heap[0];
  heap[0] = heap[--heapSize];

  int i = 0;
  int l = i * 2 + 1;
  while (l < heapSize) {
    int best = l;
    if (l + 1 < heapSize && heap[l + 1] < heap[l]) {
      best = l + 1;
    }
    if (heap[i] <= heap[best]) {
      break;
    }
    swapHeap(i, best);
    i = best;
    l = i * 2 + 1;
  }
  return ret;
}

bool isEmpty() {
  return heapSize == 0;
}

void topoSort() {
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      push(i);
    }
  }

  int fill = 0;
  while (!isEmpty())  {
    int cur = pop();
    ans[fill++] = cur;

    for (int ei = head[cur]; ei != 0; ei = nxt[ei]) {
      if (--indegree[to[ei]] == 0) {
        push(to[ei]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  build();

  for (int i = 0, from, dest; i < m; i++) {
    cin >> from >> dest;
    addEdge(from, dest);
    indegree[dest]++;
  }

  topoSort();

  for (int i = 0; i < n - 1; i++) {
    cout << ans[i] << ' ';
  }
  cout << ans[n - 1] << '\n';

  return 0;
}
