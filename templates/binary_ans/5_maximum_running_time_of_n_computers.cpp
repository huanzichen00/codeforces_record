#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  // 纯二分答案
  long long maxRunTime1(int n, vector<int>& arr) {
    long long l = 0;
    long long r = accumulate(arr.begin(), arr.end(), 0);
    long long m;
    int ans = 0;

    while (l <= r) {
      m = l + ((r - l) >> 1);
      if (f1(arr, n, m)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }

  bool f1(const vector<int>& arr, int n, long long time) {
    // 碎片电量总和
    long long sum = 0;
    for (int x : arr) {
      if (x > time) {
        n--;
      } else {
        // x <= time, 是碎片电池
        sum += x;
      }
    }
    if (sum >= (long) n * time) {
      // 碎片电量 >= 台数 * 要求
      return true;
    }
    return false;
  }

  // 二分答案法 + 增加分析（贪心）
  // 时间复杂度 O(n * log(max)) ，额外空间复杂度 O(1)
  // 
  long long maxRunTime2(int n, vector<int>& arr) {
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    long long mx = *max_element(arr.begin(), arr.end());

    // 就是增加了这里的逻辑
    // 意思是可以判定全部是碎片
    if (sum > 1LL * mx * n) {
      // 所有电池的最大电量是mx
      // 如果此时 sum > 1LL mx * n
      // 说明 : 最终的供电时间一定在 >= max,而如果最终的供电时间 >= max
      // 说明 : 对于最终答案 X 来说, 所有电池都是 "碎片拼接" 的概念
      // 那么寻找 ? * n <= sum 的情况中, 尽量大的 ? 即可
      // 即sum / n
      return sum / n;
    }

    // 最终的供电时间一定在 < max 范围上
    long long ans = 0;

    for (long long l = 0, r = mx, m; l <= r;) {
      m = l + ((r - l) >> 1);
      if (f2(arr, n, m)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }

  bool f2(const vector<int>& arr, int n, long long time) {
    long long sum = 0;
    for (int x : arr) {
      if (x > time) {
        n--;
      } else {
        sum += x;
      }
    }
    return sum >= 1LL * n * time;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
