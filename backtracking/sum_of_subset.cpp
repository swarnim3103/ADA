#include <iostream>
#include <vector>
using namespace std;

void sos(int s, int k, int r, const vector<int>& w, vector<int>& x, int m) {
    x[k] = 1;
    if (s + w[k] == m) {
        for (int i = 0; i <= k; ++i) {
            if (x[i]) cout << w[i] << " ";
        }
        cout << endl;
    } else if (k + 1 < w.size() && s + w[k] + w[k + 1] <= m) {
        sos(s + w[k], k + 1, r - w[k], w, x, m);
    }

    if (k + 1 < w.size() && s + r - w[k] >= m && s + w[k + 1] <= m) {
        x[k] = 0;
        sos(s, k + 1, r - w[k], w, x, m);
    }
}
int main() {
    int n, m;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> w(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    cout << "Enter the target sum: ";
    cin >> m;

    int r = 0;
    for (int val : w) r += val;

    vector<int> x(n, 0);
    cout << "Subsets that sum to " << m << ":\n";
    sos(0, 0, r, w, x, m);
    return 0;
}
