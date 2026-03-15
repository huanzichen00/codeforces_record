#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int N = 205;  // 题目里 fields.length <= 100，所以 2 * n <= 200

  ll xs[N], ys[N];
  int diff[N][N];

  int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
    int n = forceField.size();
    // n : 矩形的个数，x 2*n个坐标
    for (int i = 0, k = 0, p = 0; i < n; i++) {
      ll x = forceField[i][0];
      ll y = forceField[i][1];
      ll side = forceField[i][2];

      xs[k++] = (x << 1) - side;
      xs[k++] = (x << 1) + side;
      ys[p++] = (y << 1) - side;
      ys[p++] = (y << 1) + side;
    }

    // xs数组中，排序了且相同值只留一份，返回有效长度
    int sizex = sort_unique(xs, n << 1);
    int sizey = sort_unique(ys, n << 1);

    for (int i = 0; i < sizex + 1; i++) {
      for (int j = 0; j < sizey + 1; j++) {
        diff[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++) {
      ll x = forceField[i][0];
      ll y = forceField[i][1];
      ll side = forceField[i][2];
      
      ll a = rank(xs, sizex, (x << 1) - side);
      ll b = rank(xs, sizey, (y << 1) - side);
      ll c = rank(xs, sizex, (x << 1) + side);      
      ll d = rank(ys, sizey, (y << 1) + side);

      add(a, b, c, d);
    }
    int ans = 0;
    for (int i = 1; i <= sizex; i++) {
      for (int j = 1; j <= sizey; j++) {
        diff[i][j] += diff[i - 1][j] + diff[i][j - 1]
                    - diff[i - 1][j - 1];
        ans = max(ans,diff[i][j]);
      }
    }
    return ans;
  }
  

  int sort_unique(ll arr[], int len) {
    sort(arr, arr + len);
    int size = 1;
    for (int i = 1; i < len; i++) {
      if (arr[i] != arr[size - 1]) {
        arr[size++] = arr[i];
      }
    }
    return size;
  }

  // arr 有序数组，有效长度是size，0~size-1范围上无重复值
  int rank(ll arr[], int size, ll v) {
    int l = 0, r = size - 1, ans = 0, mid = 0;
    while (l <= r) {
      mid = l + ((r - l) >> 1);
      if (arr[mid] >= v) {
        ans = mid;
        r = mid + 1;
      } else {
        l = mid + 1;
      }
    }
  }

  void add(int a, int b, int c, int d) {
    diff[a][b] += 1;
    diff[c + 1][d + 1] += 1;
    diff[c + 1][b] -= 1;
    diff[a][d + 1] -= 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
