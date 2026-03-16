#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    int sum = 0;
    int w = 1;
    for (int i = 0; i < 12; i++) {
      if (s[i] == '-') {
        continue;
      }
      sum += (s[i] - '0') * w;
      w++;
    }

    int mod = sum % 11;
    char check = (mod == 10 ? 'X' : char('0' + mod));
    
    if (s[12] == check) {
      cout << "Right\n";
    } else {
      s[12] = check;
      cout << s << '\n';
    }
  }

  return 0;
}
