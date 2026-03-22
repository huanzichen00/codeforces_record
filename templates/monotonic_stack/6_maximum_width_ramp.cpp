#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 500005;
  int st[MAXN];
  int top;
  
  int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    st[0] = 0;
    top = 1;

    // 建立严格单调递减栈
    for (int i = 0; i < n; i++) {
      if (nums[st[top - 1]] > nums[i]) {
        st[top++] = i;
      }
    }

    int ans = 0;

    // 从右往左枚举右端点
    for (int j = n - 1; j >= 0; j--) {
      while (top > 0 && nums[st[top - 1]] <= nums[j]) {
        ans = max(ans, j - st[--top]);
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
