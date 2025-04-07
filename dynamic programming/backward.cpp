#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int vertexBackward(int cost[7][7], int bdist[], int j) {
    int r = 0;
    int minCost = INT_MAX;
    int index = -1;

    while (r < j) {
        if (cost[r][j] != 0 && bdist[r] + cost[r][j] < minCost) {
            minCost = bdist[r] + cost[r][j];
            index = r;
        }
        r++;
    }
    return index;
}

vector<int> bgraph(int n, int k, int cost[7][7], int bdist[]) {
    // bdist -> backward distance array
    bdist[0] = 0;
    vector<int> d(n, 0);
    for (int j = 1; j < n; j++) {
        int r = vertexBackward(cost, bdist, j);
        bdist[j] = bdist[r] + cost[r][j];
        d[j] = r;
    }
    return d;
}

void printPathBackward(vector<int> &d, int k) {
    vector<int> p(k, 0);
    p[k - 1] = d.size() - 1;
    cout << "The path is: ";
    for (int i = k - 2; i >= 0; i--) {
        p[i] = d[p[i + 1]];
    }
    for (int i = 0; i < k; i++) {
        cout << p[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    int n = 7;
    int k = 4;
    vector<int> d(n, 0);
    int cost[7][7] = {
        {0,2,1,0,0,0,0},
        {0,0,0,3,2,0,0},
        {0,0,0,1,1,0,0},
        {0,0,0,0,0,2,0},
        {0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0}
    };
    int bdist[7];
    d = bgraph(n, k, cost, bdist);
    printPathBackward(d, k);
    return 0;
}
