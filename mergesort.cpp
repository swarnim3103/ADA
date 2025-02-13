#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* x = new int[n1];
    int* y = new int[n2];

   
    for (int i = 0; i < n1; i++)
        x[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        y[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (x[i] <= y[j]) {
            arr[k] = x[i];
            i++;
        } else {
            arr[k] = y[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = x[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = y[j];
        j++;
        k++;
    }

    delete[] x;
    delete[] y;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

    
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}