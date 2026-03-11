#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int longestWPI(vector<int>& hours) {
  unorderder_map<int, int> firstPos;
  int sum = 0;
  int ans = 0;

  for (int i = 0; i < hours.size(); i++) {
    sum += (hours[i] > 8 ? 1 : -1);
    
    if (sum > 0) {
      ans = i + 1;
    } else {
      if (firstPos.count(sum - 1)) {
        ans = max(ans, i - firstPos[sum - 1]);
      }
    }
  
    if (!firstPos.count(sum)) {
      firstPos[sum] = i;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
