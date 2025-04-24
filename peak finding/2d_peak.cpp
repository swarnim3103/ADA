#include <iostream>
using namespace std;

int findMaxRow(int mat[][100], int rows, int col) {
    int maxRow = 0;
    for (int i = 1; i < rows; i++) {
        if (mat[i][col] > mat[maxRow][col])
            maxRow = i;
    }
    return maxRow;
}

int peak2D(int mat[][100], int rows, int cols, int startCol, int endCol) {
    int midCol = (startCol + endCol) / 2;
    int maxRow = findMaxRow(mat, rows, midCol);
    if (midCol > 0 && mat[maxRow][midCol] < mat[maxRow][midCol - 1])
        return peak2D(mat, rows, cols, startCol, midCol - 1);
    else if (midCol < cols - 1 && mat[maxRow][midCol] < mat[maxRow][midCol + 1])
        return peak2D(mat, rows, cols, midCol + 1, endCol);
    else
        return mat[maxRow][midCol];
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    int mat[100][100];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];
    int result = peak2D(mat, rows, cols, 0, cols - 1);
    cout << "peak is " << result;
    return 0;
}
