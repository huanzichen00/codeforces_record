#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 这个版本leetcode过不了，不能用静态数组
// 因为题目限制格子的数量，而N,M可以很大，导致memory爆掉
class Solution {
public:
  static const int N = 1005;
  int sum[N][N];
  int diff[N][N];
   bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
     int n = grid.size();
     int m = grid[0].size();

     // 清空
     for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
         sum[i][j] = 0;
         diff[i][j] = 0;
       }
     }

     // 原矩阵拷进前缀和数组，位置整体右下偏移1
     for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
         sum[i + 1][j + 1] = grid[i][j];
       }
     }

     build(sum, n + 1, m + 1);

     // 枚举每一张邮票左上角
     for (int a = 1, c = a + stampHeight - 1; c <= n; a++, c++) {
       for (int b = 1, d = b + stampWidth - 1; d <= m; b++, d++) {
         // 这个区域全是0，说明可以贴
         if (sumRegion(a, b, c, d) == 0) {
           add(a, b, c, d);
         }
       }
     }

     // 还原二维差分，得到每个位置被覆盖了多少次
     build(diff, n + 1, m + 1);

     // 检查所有空位是否都被覆盖
     for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
         if (grid[i][j] == 0 && diff[i + 1][j + 1] == 0) {
           return false;
         }
       }
     }

     return true;
   }

   void build(int arr[][N], int n, int m) {
     for (int i = 1; i < n; i++) {
       for (int j = 1; j < m; j++) {
         arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
       }
     }
   }

   int sumRegion(int a, int b, int c, int d) {
     return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
   }

   void add(int a, int b, int c, int d) {
     diff[a][b] += 1;
     diff[c + 1][d + 1] += 1;
     diff[c + 1][b] -= 1;
     diff[a][d + 1] -= 1;
   }
};

class Solutioni1 {
public:
    static const int MAXS = 600010;

    int sums[MAXS];
    int diff[MAXS];
    int cols;

    int idx(int i, int j) {
        return i * cols + j;
    }

    void build(int arr[], int n, int m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[idx(i, j)] += arr[idx(i - 1, j)] + arr[idx(i, j - 1)] - arr[idx(i - 1, j - 1)];
            }
        }
    }

    int query(int arr[], int a, int b, int c, int d) {
        return arr[idx(c, d)] - arr[idx(a - 1, d)] - arr[idx(c, b - 1)] + arr[idx(a - 1, b - 1)];
    }

    void add(int a, int b, int c, int d) {
        diff[idx(a, b)] += 1;
        diff[idx(c + 1, b)] -= 1;
        diff[idx(a, d + 1)] -= 1;
        diff[idx(c + 1, d + 1)] += 1;
    }

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size();
        int m = grid[0].size();

        cols = m + 2;
        int rows = n + 2;
        int size = rows * cols;

        for (int i = 0; i < size; i++) {
            sums[i] = 0;
            diff[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sums[idx(i + 1, j + 1)] = grid[i][j];
            }
        }

        build(sums, n, m);

        for (int a = 1, c = a + stampHeight - 1; c <= n; a++, c++) {
            for (int b = 1, d = b + stampWidth - 1; d <= m; b++, d++) {
                if (query(sums, a, b, c, d) == 0) {
                    add(a, b, c, d);
                }
            }
        }

        build(diff, n, m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && diff[idx(i + 1, j + 1)] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solutioni2 {
public:
    vector<vector<int>> sum;
    vector<vector<int>> diff;

    void build(vector<vector<int>>& arr, int n, int m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
    }

    int query(vector<vector<int>>& arr, int a, int b, int c, int d) {
        return arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1];
    }

    void add(int a, int b, int c, int d) {
        diff[a][b] += 1;
        diff[c + 1][b] -= 1;
        diff[a][d + 1] -= 1;
        diff[c + 1][d + 1] += 1;
    }

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size();
        int m = grid[0].size();

        sum.assign(n + 2, vector<int>(m + 2, 0));
        diff.assign(n + 2, vector<int>(m + 2, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i + 1][j + 1] = grid[i][j];
            }
        }

        build(sum, n, m);

        for (int a = 1, c = a + stampHeight - 1; c <= n; a++, c++) {
            for (int b = 1, d = b + stampWidth - 1; d <= m; b++, d++) {
                if (query(sum, a, b, c, d) == 0) {
                    add(a, b, c, d);
                }
            }
        }

        build(diff, n, m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && diff[i + 1][j + 1] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
