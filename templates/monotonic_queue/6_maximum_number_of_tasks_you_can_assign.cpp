#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MAXN = 50000 + 5;
  int q[MAXN];
  int h, t;

  static bool cmp(int a, int b) {
    return a < b;
  }

  bool check(vector<int> tasks, vector<int> workers, int pills, int strength, int m) {
    h = t = 0;
    int cnt = 0;
    int n = tasks.size();
    int wn = workers.size();

    int tl = 0, tr = m - 1;
    int wl = wn - m, wr = wn - 1;

    for (int i = wl, j = tl; i <= wr; i++) {
      while (j <= tr && tasks[j] <= workers[i]) {
        q[t++] = j++;
      }

      if (h < t) {
        h++;
      } else {
        while (j <= tr && tasks[j] <= workers[i] + strength) {
          q[t++] = j++;
        }
        if (h < t) {
          cnt++;
          t--;
        } else {
          return false;
        }
      }
    }

    return cnt <= pills;
  }

  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int l = 0;
    int r = min((int)tasks.size(), (int)workers.size());
    int ans = 0;

    while (l <= r) {
      int m = l + ((r - l) >> 1);
      if (check(tasks, workers, pills, strength, m)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
