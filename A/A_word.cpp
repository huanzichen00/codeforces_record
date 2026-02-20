#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int cnt = 0;  // count the number of lower case characters
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' and s[i] <= 'z') {
      cnt++;
    }
  }
  if (cnt >= s.length() - cnt) {
    for (char &c : s) c = tolower(c);
  } else {
    for (char &c : s) c = toupper(c);
  }
  cout << s << "\n";
  return 0;
}
