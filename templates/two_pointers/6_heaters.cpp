#include <bits/stdc++.h>
using namespace std;

using ll = long long;



// 时间复杂度O(n)，因为有排序，额外空间复杂度O(1)
class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
  
    int ans = 0;
    for (int i = 0, j = 0; i < (int)houses.size(); i++) {
      // i 号房屋
      // j 号供暖器
      while (!best(houses, heaters, i, j)) {
        j++;
      }
      ans = max(ans, abs(houses[i] - heaters[j]));
    }
    return ans;
  }  

  // 函数的含义：
  // 当前的地点houses[i]由heaters[j]来供暖是最优的吗?
  //                                      ,产生的半径是a
  //                              j + 1   ,产生的半径是b
  // 如果 a < b 说明是最优，供暖不应该跳下一个位置
  // 如果 a >= b 说明不是最优，应该跳下一个位置
  bool best(vector<int>& houses, vector<int>& heaters, int i, int j) {
    return j == (int)heaters.size() - 1 ||
           abs(heaters[j] - houses[i]) < abs(heaters[j + 1] - houses[i]);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
