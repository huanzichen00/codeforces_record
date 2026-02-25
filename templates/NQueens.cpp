#include <bits/stdc++.h>
using namespace std;

int f1(int i, vector<int>& path, int n);
bool check(vector<int>& path, int i, int j);
int f2(int limit, int col, int left, int right);

int totalNQueens1(int n) {
    if (n < 1) {
        return 0;
    }
    vector<int> path(n);
    return f1(0, path, n);
}

// i : current row
// path : columns of queens in rows 0...i-1
// n : N-Queens size
// return : number of valid methods from row i to n-1
int f1(int i, vector<int>& path, int n) {
    if (i == n) {
        return 1;
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (check(path, i, j)) {
            path[i] = j;
            ans += f1(i + 1, path, n);
        }
    }
    return ans;
}

// place a queen at (i, j)
// path[0..i-1] is the status of previous rows
// true means no conflict
bool check(vector<int>& path, int i, int j) {
    for (int k = 0; k < i; k++) {
        if (j == path[k] || abs(i - k) == abs(j - path[k])) {
            return false;
        }
    }
    return true;
}

// N-Queens with bitmask path representation
int totalNQueens2(int n) {
    if (n < 1) {
        return 0;
    }
    int limit = (1 << n) - 1;
    return f2(limit, 0, 0, 0);
}

// limit : problem size mask
// col : occupied columns
// left : right-up to left-down diagonal impact
// right : left-up to right-down diagonal impact
int f2(int limit, int col, int left, int right) {
    if (col == limit) {
        return 1;
    }
    int ban = col | left | right;
    int candidate = limit & (~ban);
    int place = 0;
    int ans = 0;
    while (candidate != 0) {
        place = candidate & (-candidate);
        candidate ^= place;
        ans += f2(limit, col | place, (left | place) >> 1, (right | place) << 1);
    }
    return ans;
}

int main() {
    int n = 14;
    long long start, end;
    cout << "test start" << '\n';
    cout << "solve " << n << " queens" << '\n';

    start = chrono::duration_cast<chrono::milliseconds>(
                chrono::system_clock::now().time_since_epoch())
                .count();
    cout << "method1 answer : " << totalNQueens1(n) << '\n';
    end = chrono::duration_cast<chrono::milliseconds>(
              chrono::system_clock::now().time_since_epoch())
              .count();
    cout << "method1 time : " << (end - start) << " ms" << '\n';

    start = chrono::duration_cast<chrono::milliseconds>(
                chrono::system_clock::now().time_since_epoch())
                .count();
    cout << "method2 answer : " << totalNQueens2(n) << '\n';
    end = chrono::duration_cast<chrono::milliseconds>(
              chrono::system_clock::now().time_since_epoch())
              .count();
    cout << "method2 time : " << (end - start) << " ms" << '\n';
    cout << "test end" << '\n';

    return 0;
}
