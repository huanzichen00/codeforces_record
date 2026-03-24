#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 100000 + 5;
  int arr[MAXN];

  int maxq[MAXN], minq[MAXN];
  int maxh, maxt, minh, mint;

  int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    maxh = maxt = 0;
    minh = mint = 0;

    int ans = 0;

    for (int l = 0, r = 0; r < n; r++) {
      // maxq 维护窗口最大值
      while (maxh < maxt && nums[maxq[maxt - 1]] <= nums[r]) {
        maxt--;
      }
      maxq[maxt++] = r;

      // minq 维护窗口最小值
      while (minh < mint && nums[minq[mint - 1]] >= nums[r]) {
        mint--;
      }
      minq[mint] = r;

      while (nums[maxq[maxh]] - nums[minq[minh]] > limit) {
        if (maxq[maxh] == l) {
          maxh++;
        }
        if (minq[minh] == r) {
          minh++;
        }
        l++;
      }

      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
