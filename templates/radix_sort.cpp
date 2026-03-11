#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void radix_sort(vector<int>& a) {
  int n = a.size();
  int max_val = *max_element(a.begin(), a.end());

  for (int exp = 0; max_val/exp > 0; exp *= 10) {
    vector<int> output(n);
    vector<int> cnt(10, 0);

    for (int i = 0; i < n; i++) {
      cnt[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      cnt[i + 1] += cnt[i];
    }
    for (int i = n - 1; i > 0; i++) {
      int digit = (a[i] / exp) % 10;
      output[--cnt[digit]] = a[i]; 
    }
    a = output;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
