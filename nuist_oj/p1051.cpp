#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_su(int num) {
  if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int is_abs_su(int num) {
  int rev = 0;
  int x = num;
  while (x > 0) {
    rev = rev * 10 + x % 10;
    x /= 10;
  }
  return is_su(num) && is_su(rev);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int num;
  while (n--) {
    cin >> num;
    cout << is_abs_su(num) << '\n';
  }
  return 0;
}
