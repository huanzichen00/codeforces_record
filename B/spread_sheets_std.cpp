#include <bits/stdc++.h>
using namespace std;

bool isRC(const string& s) {
    // RC format: R<digits>C<digits>
    if (s.size() < 4) return false;
    if (s[0] != 'R') return false;

    int i = 1;
    if (i >= (int)s.size() || !isdigit(s[i])) return false;
    while (i < (int)s.size() && isdigit(s[i])) i++;

    if (i >= (int)s.size() || s[i] != 'C') return false;
    i++;

    if (i >= (int)s.size() || !isdigit(s[i])) return false;
    return true;
}

string colToLetters(int col) {
    // 1 -> A, 26 -> Z, 27 -> AA
    string res;
    while (col > 0) {
        col--; // make it 0-indexed
        res.push_back(char('A' + (col % 26)));
        col /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int lettersToCol(const string& letters) {
    int col = 0;
    for (char ch : letters) {
        col = col * 26 + (ch - 'A' + 1);
    }
    return col;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        if (isRC(s)) {
            // R<row>C<col> -> <letters><row>
            int i = 1;
            int row = 0;
            while (i < (int)s.size() && isdigit(s[i])) {
                row = row * 10 + (s[i] - '0');
                i++;
            }
            // s[i] == 'C'
            i++;
            int col = 0;
            while (i < (int)s.size()) {
                col = col * 10 + (s[i] - '0');
                i++;
            }

            cout << colToLetters(col) << row << "\n";
        } else {
            // <letters><row> -> R<row>C<col>
            int i = 0;
            string letters;
            while (i < (int)s.size() && s[i] >= 'A' && s[i] <= 'Z') {
                letters.push_back(s[i]);
                i++;
            }

            int row = 0;
            while (i < (int)s.size()) {
                row = row * 10 + (s[i] - '0');
                i++;
            }

            int col = lettersToCol(letters);
            cout << "R" << row << "C" << col << "\n";
        }
    }
    return 0;
}
