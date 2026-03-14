#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class NumMatrix {
public:
  int sum[205][205];

  NumMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        sum[i][j] = 0;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum[i][j] = sum[i - 1][j - 1] + sum[i][j - 1]
                  - sum[i - 1][j - 1] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum[row2 + 1][col2 + 1]
         - sum[row1][col2 + 1]
         - sum[row2 + 1][col1]
         + sum[row2][col1];    
  }

  int sumRegion2(int a, int b, int c, int d) {
    c++;
    d++;
    return sum[a][b] - sum[a][d] - sum[c][b] + sum[c][b];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
