#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    bool is_RC = false;
    int end1;

    for (int i = 0; i < s.length() - 1; ++i)
      if ((s[i] >= '0' && s[i] <= '9') && (s[i + 1] == 'C')) {
        is_RC = true;
        end1 = i;
      }

    if (is_RC) {
      int row = 0, col = 0;
      string column;
      for (int i = 1; i <= end1; ++i) {
        row = row * 10 + s[i] - '0';
      }
      for (int i = end1 + 2; i < s.length(); ++i) {
        col = col * 10 + s[i] - '0';
      }
      while (col > 0) {
        col--;
        column.push_back((char)'A' + col % 26);
        col /= 26;
      }
      reverse(column.begin(), column.end());
      cout << column << row << "\n";
    } else {
      int R = 0, C = 0, where;
      for (int i = 0; s[i] >= 'A' && s[i] <= 'Z'; ++i) {
        C = C * 26 + (s[i] - 'A' + 1);
        where = i;
      }
      for (int i = where + 1; i < s.length(); ++i) {
        R = R * 10 + (s[i] - '0');
      }
      cout << "R" << R << "C" << C << "\n";
    }
  }
}
