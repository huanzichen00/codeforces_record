#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 100001;
  int st[MAXN];
  int top;

  vector<int> dailyTemperatures(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    top = 0;

    for (int i = 0, cur; i < n; i++) {
      while (top > 0 && nums[st[top - 1]] < nums[i]) {
        cur = st[--top];
        ans[cur] = i - cur;
      }
      st[top++] = i;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
