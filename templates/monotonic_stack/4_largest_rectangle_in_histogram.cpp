#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 100001;
  int st[MAXN];
  int r;
  
  int largestRectangleArea(vector<int>& height) {
    int n = height.size();
    r = 0;
    int ans = 0, cur, left;
    for (int i = 0; i < n; i++) {
      // i -> arr[i]
      while (r > 0 && height[st[r - 1]] >= height[i]) {
        cur = st[--r];
        left = r == 0 ? -1 : st[r - 1];
        // left 和 i 都在矩形之外(小于cur)
        ans = max(ans, height[cur] * (i - left - 1));
      }
      st[r++] = i;
    }
    while (r > 0) {
      cur = st[--r];
      left = r == 0 ? -1 : st[r - 1];
      ans = max(ans, height[cur] * (n - left - 1));
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
