#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 100000 + 5;
  int q[MAXN];
  int head, tail;

  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    head = tail = 0;

    // i 是窗口右边界
    for (int i = 0; i < n; i++) {
      // [head, tail) 左闭右开
      // head < tail 表示窗口里有元素
      // tail - 1 即最后一个元素的下标，与右扩入队的元素比较大小，直到结束
      while (head < tail && nums[q[tail - 1]] <= nums[i]) {
        tail--;
      }
      q[tail++] = i;

      if (q[head] <= i - k) {
        head++;
      }

      // 从 k - 1 开始弹出答案
      if (i >= k - 1) {
        // 不要忘了 ans 里存的是值不是下标 
        ans.push_back(nums[q[head]]);
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
