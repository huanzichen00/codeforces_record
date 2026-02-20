#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int j = 0; j < 18;j++)
      for (int k = 0; k * 2 + 1 < n; k++)
        if (a[k] > a[k * 2 + 1])
          swap(a[k], a[k * 2 + 1]);
    cout << (is_sorted(a, a + n) ? "YES" : "NO") << "\n";
  }
  return 0;
}
