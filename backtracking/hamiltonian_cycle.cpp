#include <iostream>
#include <vector>
using namespace std;

void NextValue(int k, int n, vector<int>& x, const vector<vector<int>>& G) {
    while (true) {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0) return;
        if (G[x[k - 1]][x[k]] != 0) {
            int j;
            for (j = 1; j < k; j++) {
                if (x[j] == x[k]) break;
            }
            if (j == k) {
                if (k < n || (k == n && G[x[n]][x[1]] != 0)) return;
            }
        }
    }
}

void Hamiltonian(int k, int n, vector<int>& x, const vector<vector<int>>& G) {
    while (true) {
        NextValue(k, n, x, G);
        if (x[k] == 0) return;
        if (k == n) {
            for (int i = 1; i <= n; i++) cout << x[i] << " ";
            cout << x[1] << endl;
        } else {
            Hamiltonian(k + 1, n, x, G);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> G(n + 1, vector<int>(n + 1));
    vector<int> x(n + 1, 0);

    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> G[i][j];

    x[1] = 1;

    cout << "Hamiltonian cycles:\n";
    Hamiltonian(2, n, x, G);

    return 0;
}
