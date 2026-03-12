#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n = 1000001;

int arr[1000001];

void set(int l, int r, int s, int e, int d) {
  arr[l] += s;
  arr[l + 1] += d - s;
  arr[r + 1] -= d + e;
  arr[r + 2] += e;
}

void build() {
  for (int i = 0; i <= n; i++) {
    arr[i] += arr[i - 1];
  }
  for (int i = 0; i <= n; i++) {
    arr[i] += arr[i - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  return 0;
}
