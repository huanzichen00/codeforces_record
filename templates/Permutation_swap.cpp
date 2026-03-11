#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(vector<int>& nums, int start) {
  if (start == (int)nums.size()) {
    for (int x : nums) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
