#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int numsRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int n = people.size();
    int l = 0, r = n - 1;
    int ans = 0;
    int sum = 0;
    while (l <= r) {
      sum = l  == r ? people[l] : people[l] + people[r];
      if (sum > limit) {
        r--;
      } else {
        l++;
        r--;
      }
      ans++;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  
  return 0;
}
