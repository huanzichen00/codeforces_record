#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int arr[MAXN];
int st[MAXN];
int ans[MAXN][2];
int n, top;

void compute() {
  top = 0;
  int cur;

  // 遍历阶段
  for (int i = 0; i < n; i++) {
    // top代表栈内元素数量
    while (top > 0 && arr[st[top - 1]] <= arr[i]) {
      cur = st[--top];
      ans[cur][0] = top > 0 ? st[top - 1] : -1;
      ans[cur][1] = i;
    }
    st[top++] = i;
  }

  // 清算阶段
  while (top > 0) {
    cur = st[--top];
    // cur当前弹出的位置，左边最近且小
    ans[cur][0] = top > 0 ? st[top - 1] : -1; 
    ans[cur][1] = -1;
  }

  // 修正阶段
  // 左侧的答案不需要修正一定是正确的，只有右侧答案需要修正
  // 从右往左修正，n-1位置的右侧答案一定是-1，不需要修正
  for (int i = n - 2; i >= 0; i--) {
    if (ans[i][1] != -1 && arr[ans[i][1]] == arr[i]) {
      ans[i][1] = ans[ans[i][1]][1];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    compute();
    for (int i = 0; i < n; i++) {
      cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
  }
  return 0;
}
