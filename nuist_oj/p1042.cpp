#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string nums;
  cin >> nums;
  cout << "6" + nums.substr(nums.size() - 5, 5) << '\n';
  return 0;
}
