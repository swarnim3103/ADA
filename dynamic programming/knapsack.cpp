#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<pair<int, int>> mergePurge(set<pair<int, int>>& s1, set<pair<int, int>>& s2, int W) {
    set<pair<int, int>> s3;
    auto i = s1.begin();
    auto j = s2.begin();
    while (i != s1.end() && j != s2.end()) {
        if (i->first < j->first) {
            s3.insert(*i);
            ++i;
        } else if (i->first > j->first) {
            s3.insert(*j);
            ++j;
        } else {
            s3.insert(*i);
            ++i;
            ++j;
        }
    }
    while (i != s1.end()) {
        s3.insert(*i);
        ++i;
    }
    while (j != s2.end()) {
        s3.insert(*j);
        ++j;
    }
    auto k = s3.begin();
    auto l = next(k);
    while (l != s3.end()) {
        if (k->second > l->second) {
            k = s3.erase(k);
            l = next(k);
        } else {
            ++k;
            ++l;
        }
    }
    for (auto it = s3.begin(); it != s3.end(); ) {
        if (it->second > W) {
            it = s3.erase(it);
        } else {
            ++it;
        }
    }
    return s3;
}
void knapsack(int n, vector<int>& wt, vector<int>& p, int W) {
    vector<set<pair<int, int>>> s(n);
    vector<bool> x(n, false);
    s[0].insert({0, 0});
    if (wt[0] <= W) {
        s[0].insert({p[0], wt[0]});
    }
    for (int i = 1; i < n; i++) {
        set<pair<int, int>> temp;
        for (auto& it : s[i - 1]) {
            int newProfit = it.first + p[i];
            int newWeight = it.second + wt[i];
            if (newWeight <= W) {
                temp.insert({newProfit, newWeight});
            }
        }
        s[i] = mergePurge(s[i - 1], temp, W);
    }
    if (s[n - 1].empty()) {
        cout << "No valid subset found within weight capacity.\n";
        return;
    }
    int pro = s[n - 1].rbegin()->first;
    int w = s[n - 1].rbegin()->second;
    cout << "The total profit is: " << pro << endl;
    for (int i = n - 1; i > 0; i--) {
        if (s[i - 1].find({pro, w}) == s[i - 1].end()) {
            x[i] = true;
            pro -= p[i];
            w -= wt[i];
        }
    }
    if (pro != 0 && w != 0) {
        x[0] = true;
    }
    for (int i = 0; i < n; i++) {
        if (x[i]) {
            cout << "Item " << i + 1 << " included (Profit: " << p[i] << ", Weight: " << wt[i] << ")\n";
        }
    }
}
int main() {
    int n, W;
    cout << "Enter the number of items and the weight of the knapsack: ";
    cin >> n >> W;
    vector<int> wt(n), p(n);

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the profits of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    knapsack(n, wt, p, W);
    return 0;
}
