//use divide and conquer to multiply two matrices
#include <iostream>
using namespace std;

void add(int A[100][100], int B[100][100], int C[100][100], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[100][100], int B[100][100], int C[100][100], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiply(int A[100][100], int B[100][100], int C[100][100], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int C11[100][100], C12[100][100], C21[100][100], C22[100][100];
    int M1[100][100], M2[100][100];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    multiply(A11, B11, M1, newSize);
    multiply(A12, B21, M2, newSize);
    add(M1, M2, C11, newSize);

    multiply(A11, B12, M1, newSize);
    multiply(A12, B22, M2, newSize);
    add(M1, M2, C12, newSize);

    multiply(A21, B11, M1, newSize);
    multiply(A22, B21, M2, newSize);
    add(M1, M2, C21, newSize);

    multiply(A21, B12, M1, newSize);
    multiply(A22, B22, M2, newSize);
    add(M1, M2, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    int A[100][100], B[100][100], C[100][100] = {0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    multiply(A, B, C, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
