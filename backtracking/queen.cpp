#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool Place(int k, int i, const vector<int>& x) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

void NQueens(int k, int n, vector<int>& x) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i, x)) {
            x[k] = i;
            if (k == n - 1) {
                for (int j = 0; j < n; j++)
                    cout << x[j] << " ";
                cout << endl;
            } else {
                NQueens(k + 1, n, x);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<int> x(n);
    NQueens(0, n, x);
    return 0;
}
