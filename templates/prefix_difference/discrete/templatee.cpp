#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N], b[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    int m = unique(b + 1, b + n + 1) - (b + 1);

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }

    return 0;
}
