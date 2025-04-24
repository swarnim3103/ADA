#include <iostream>
#include<vector>
using namespace std;

int cross_product(vector<int> p1, vector<int> p2, vector<int> p3) {
    return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]);
}

void convex_hull(vector<vector<int>> &points, int n) {
    if (n < 3) return; 

    vector<int> hull(n); 
    int hull_size = 0;

    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i][0] < points[leftmost][0]) {
            leftmost = i;
        }
    }

    int p = leftmost, q;
    do {
        hull[hull_size++] = p; 

        q = (p + 1) % n; 

        for (int i = 0; i < n; i++) {
        
            if (cross_product(points[p], points[i], points[q]) > 0) {
                q = i;
            }
        }

        p = q; 
    } while (p != leftmost); 

    cout << "Convex Hull points:\n";
    for (int i = 0; i < hull_size; i++) {
        cout << "(" << points[hull[i]][0] << ", " << points[hull[i]][1] << ")\n";
    }
}

int main() {
    int m;
    cout << "Enter the number of points: ";
    cin >> m;
    vector<vector<int>> points(m, vector<int>(2));
    cout << "Enter the points (x y):\n";
    for (int i = 0; i < m; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    
    // int n = sizeof(points) / sizeof(points[0]);

    int n = points.size();

    convex_hull(points, n);

    return 0;
}