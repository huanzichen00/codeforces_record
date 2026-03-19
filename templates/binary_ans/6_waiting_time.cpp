#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 计算等位时间
// 给定一个数组arr长度为n，表示n个服务员，每服务一个人的时间
// 给定一个正数m，表示有m个人等位，如果你是刚来的人，请问你需要等多久？
// 假设m远远大于n，比如n <= 10^3, m <= 10^9，该怎么做是最优解？
// 谷歌的面试，这个题连考了2个月
// 找不到测试链接，所以用对数器验证

int waitingTime1(vector<int>& arr, int w) {
  // 小根堆
  // pair.first  : 当前什么时候能再服务下一个人
  // pair.second : 服务一个人需要多久
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
  for (int x : arr) {
    heap.push({0, x});
  }

  // 前面有 w 个人，一次分配给当前最早空闲的服务员
  for (int i = 0; i < w; i++) {
    auto cur = heap.top();
    heap.pop();

    int wake = cur.first;
    int cost = cur.second;

    // 接待完这个人后，下一次可服务时间变成 wake + cost
    heap.push({wake + cost, cost});
  }

  // 模拟完前面 w 个人后，堆顶就是你最早开始被服务的时间
  return heap.top().first;
}

// 统计: 如果所有服务员工作到 time 时刻，最多能接待多少个人
int f(vector<int>& arr, int time) {
  int ans = 0;
  for (int num : arr) {
    // time / num : 到 time 为止完整服务结束了多少人
    ans += time / num + 1;
  }
  return ans;
}

// 二分答案
int waitingTime2(vector<int>& arr, int w) {
  int mn = INT_MAX;
  for (int x : arr) {
    mn = min(mn, x);
  }

  int ans = 0;
  for (int l = 0, r = mn * w, m; l <= r;) {
    // m 中点，表示一定要让服务员工作的时间
    m = l + ((r - l) >> 1);
    // 能够给几个客人提供服务
    if (f(arr, m) >= w + 1) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr = {3, 5};
  int w = 4;

  cout << waitingTime1(arr, w) << '\n';
  cout << waitingTime2(arr, w) << '\n';
  return 0;
}
