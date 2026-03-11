#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int single_number(vector<int> nums) {
  int eor = 0;
  for (int num : nums) {
    eor ^= num;
  }
  return eor;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
