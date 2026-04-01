#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100001;
const int MAXM = 100001; 

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
  for (int i = 1; i <= n; i++) {
    heap[i] = 0;
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
  // 先把新元素放到堆的最后一个位置 
  int i = heapSize++;
  heap[i] = x;

  // 然后不断向上调整
  // 如果当前节点比父节点更小，就交换
  // 直到: 来到堆顶 或者 父节点已经不比它大
  // (i - 1) / 2 是父节点计算公式
  while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
    swapHeap(i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

// 弹出并返回小根堆种的最小值
int pop() {
  // 堆顶就是最小值
  int ret = heap[0];

  // 用最后一个元素覆盖堆顶
  heap[0] = heap[--heapSize];

  // 然后从堆顶开始向下调整
  int i = 0;
  int l = i * 2 + 1; // 左孩子下标
  while (l < heapSize) {
    int best = l;
    if (l + 1 < heapSize && heap[l + 1] < heap[l]) {
      best = l + 1;
    }

    // 如果当前节点已经 <= 更小的那个孩子
    // 说明当前位置已经满足小根堆性质，停止调整
    if (heap[i] <= heap[best]) {
      break;
    }

    // 否则就和更小的孩子交换
    swapHeap(i, best);

    // 继续向下调整
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
  while (!isEmpty()) {
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
  for (int i = 0, from, dest; i< m; i++) {
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
