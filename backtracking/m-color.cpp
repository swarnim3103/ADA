#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& G, vector<int>& color, int c) {
    for (int i = 0; i < G.size(); i++) {
        if (G[v][i] && color[i] == c)
            return false;
    }
    return true;
}

void mColoring(int k, vector<vector<int>>& G, int m, vector<int>& color) {
    while (true) {
        color[k]++;
        while (color[k] <= m && !isSafe(k, G, color, color[k]))
            color[k]++;
        if (color[k] > m)
            return;
        if (k == G.size() - 1) {
            for (int i = 0; i < color.size(); i++)
                cout << color[i] << " ";
            cout << endl;
        } else {
            mColoring(k + 1, G, m, color);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];
    cout << "Enter number of colors: ";
    cin >> m;
    vector<int> color(n, 0);
    mColoring(0, G, m, color);
    return 0;
}
