#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char>> &b, string &s, int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 'D') {
        print(b, s, i - 1, j - 1);
        cout << s[i - 1] << " ";
    } else if (b[i][j] == 'U') {
        print(b, s, i - 1, j);
    } else {
        print(b, s, i, j - 1);
    }
}

void lcs(string s1, string s2, int m, int n) {
    //s1-> m
    //s2-> n
    vector<vector<char>> b(m + 1, vector<char>(n + 1));
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';
            }
        }
    }

    cout << "Length of longest common subsequence is: " << c[m][n] << endl;
    cout << "LCS: ";
    print(b, s1, m, n);
    cout << endl;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    int m = s1.length();
    int n = s2.length();
    lcs(s1, s2, m, n);
    return 0;
}
