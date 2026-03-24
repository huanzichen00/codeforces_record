#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(const vector<string>& str, const string& sub) {
  string rev = sub;
  reverse(rev.begin(), rev.end());

  for (const string& ss : str) {
    if (ss.find(sub) == string::npos && ss.find(rev) == string::npos) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<string> str(n);
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }

  int mn = 0;
  for (int i = 1; i < n; i++) {
    if (str[i].size() <= str[mn].size()) {
      mn = i;
    }
  }

  string smallest = str[mn];
  int mx_len = smallest.size();

  for (int len = mx_len; len >= 1; len--) {
    for (int l = 0; l + len <= mx_len; l++) {
      string sub = smallest.substr(l, len);
      if (check(str, sub)) {
        cout << len << '\n';
        return 0;
      }
    }
  }
  
  return 0;
}
