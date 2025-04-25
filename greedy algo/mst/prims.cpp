#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int primMST(vector<vector<int>> cost, int n, vector<pair<int, int>>& t) {
    vector<int> near(n, 0);
    int mincost = 0;

    int k = 0, l = 0, min = INF;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    t.push_back({k, l});
    mincost += cost[k][l];
    near[k] = near[l] = 0;

    for (int i = 0; i < n; i++) {
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }

    for (int i = 1; i < n - 1; i++) {
        int min = INF, j = -1;
        for (int k = 0; k < n; k++) {
            if (near[k] != 0 && cost[k][near[k]] < min) {
                min = cost[k][near[k]];
                j = k;
            }
        }

        t.push_back({j, near[j]});
        mincost += cost[j][near[j]];
        near[j] = 0;

        for (int k = 0; k < n; k++) {
            if (near[k] != 0 && cost[k][near[k]] > cost[k][j]) {
                near[k] = j;
            }
        }
    }

    return mincost;
}

int main() {
    int n = 5;
    vector<vector<int>> cost = {
        {INF, 2, INF, 6, INF},
        {2, INF, 3, 8, 5},
        {INF, 3, INF, INF, 7},
        {6, 8, INF, INF, 9},
        {INF, 5, 7, 9, INF}
    };

    vector<pair<int, int>> t;
    int mincost = primMST(cost, n, t);

    cout << "Edges in MST:\n";
    for (auto edge : t)
        cout << edge.first << " - " << edge.second << endl;

    cout << "Minimum Cost: " << mincost << endl;

    return 0;
}
