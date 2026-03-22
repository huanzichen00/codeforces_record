#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MOD = 1e9 + 7;
  static const int MAXN = 30001;
  int st[MAXN];
  int top;

  int sumSubarrayMins(vector<int>& arr) {
    long long ans = 0;
    int n = arr.size();
    top = 0;

    for (int i = 0; i < n; i++) {
      while (top > 0 && arr[st[top - 1]] >= arr[i]) {
        int cur = st[--top];
        // -1 和开头有一种等效
        int left = (top == 0 ? -1 : st[top - 1]);
        // (cur - left) : 开头的可能性, (i - cur) : 结尾的可能性
        ans = (ans + 1LL * (cur - left) * (i - cur) * arr[cur]) % MOD;
      }
      st[top++] = i;
    }

    while (top > 0) {
      int cur = st[--top];
      int left = (top == 0 ? -1 : st[top - 1]);
      ans = (ans + 1LL * (cur - left) * (n - cur) * arr[cur]) % MOD;
    }

    return (int) ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
