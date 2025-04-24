//use Strassen's algorithm to multiply two matrices
//p=(a11+a22)(b11+b22)
//q=(a21+a22)b11
//r=a11(b12-b22)
//s=a22(b21-b11)
//t=(a11+a12)b22
//u=(a21-a11)(b11+b12)
//v=(a12-a22)(b21+b22)
//c11=p+s-t+v
//c12=r+t
//c21=q+s
//c22=p+-q+u

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

void strassen(int A[100][100], int B[100][100], int C[100][100], int size) {
    if (size == 2) {
        int a11 = A[0][0], a12 = A[0][1], a21 = A[1][0], a22 = A[1][1];
        int b11 = B[0][0], b12 = B[0][1], b21 = B[1][0], b22 = B[1][1];
        int p = (a11 + a22) * (b11 + b22);
        int q = (a21 + a22) * b11;
        int r = a11 * (b12 - b22);
        int s = a22 * (b21 - b11);
        int t = (a11 + a12) * b22;
        int u = (a21 - a11) * (b11 + b12);
        int v = (a12 - a22) * (b21 + b22);
        C[0][0] = p + s - t + v;
        C[0][1] = r + t;
        C[1][0] = q + s;
        C[1][1] = p - q + u;
        return;
    }

    int newSize = size / 2;
    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int C11[100][100], C12[100][100], C21[100][100], C22[100][100];
    int P1[100][100], P2[100][100], P3[100][100], P4[100][100];
    int P5[100][100], P6[100][100], P7[100][100];
    int temp1[100][100], temp2[100][100];

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

    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassen(temp1, temp2, P1, newSize);

    add(A21, A22, temp1, newSize);
    strassen(temp1, B11, P2, newSize);

    subtract(B12, B22, temp1, newSize);
    strassen(A11, temp1, P3, newSize);

    subtract(B21, B11, temp1, newSize);
    strassen(A22, temp1, P4, newSize);

    add(A11, A12, temp1, newSize);
    strassen(temp1, B22, P5, newSize);

    subtract(A21, A11, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassen(temp1, temp2, P6, newSize);

    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassen(temp1, temp2, P7, newSize);

    add(P1, P4, temp1, newSize);
    subtract(temp1, P5, temp2, newSize);
    add(temp2, P7, C11, newSize);

    add(P3, P5, C12, newSize);
    add(P2, P4, C21, newSize);

    subtract(P1, P2, temp1, newSize);
    add(temp1, P3, temp2, newSize);
    add(temp2, P6, C22, newSize);

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
    int A[100][100], B[100][100], C[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    strassen(A, B, C, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
