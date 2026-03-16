#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 200001;
  // 桶
  int cnts[MAXN];
  
  int subarraysWithKDistinct(vector<int>& arr, int k) {
    return numsOfMostKinds(arr, k) - numsOfMostKinds(arr, k - 1);
  }

  // arr中有多少子数组，数字种类不超过k
  // arr的长度是n，arr里的数值1~n之间
  int numsOfMostKinds(vector<int>& arr, int k) {
    fill(cnts + 1, cnts + arr.size() + 1, 0);

    int ans = 0;
    for (int l = 0, r = 0, collect = 0; r < (int)arr.size(); r++) {
      // r(刚进)
      if (++cnts[arr[r]] == 1) {
        collect++;
      }
      // l.....r   要求不超过3种，已经4种，l往右(吐数字)
      while (collect > k) {
        if (--cnts[arr[l++]] == 0) {
          collect--;
        }
      }
      // l....r不超过了
      ans += r - l + 1;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
