#include <bits/stdc++.h>
using namespace std;

vector<int> path;
vector<boolean> used;
vector<int> nums;  // 原数组

void dfs(int n) {
  if (path.size == n) {
    for (int x : path)
      cout << "x" << " ";
    cout << "\n";
    return;
  } 
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    used[i] = true;
    path.push_back(nums[i]);
    dfs(n);
    path.pop_back();
    used[i] = false;
  }
}

int main() {
  int n;  
  cin >> n;

  nums.resize(n);
  used.resize(n, false);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  dfs(n);
} 
