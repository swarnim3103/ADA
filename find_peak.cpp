#include <iostream>
using namespace std;

int first_peak(int a[], int low, int high, int n) {
  int mid = (low + high) / 2;
if (mid > 0 && a[mid] < a[mid - 1]) {
    return first_peak(a, low, mid - 1, n);
  } else if (mid < n - 1 && a[mid] < a[mid + 1]) {
    return first_peak(a, mid + 1, high, n);
  }if (mid > 0 && a[mid] < a[mid - 1]) {
    return first_peak(a, low, mid - 1, n);
  } else {
    return mid;
  }
}

int main() {
  int n,a[100];
  cout << "Enter size of array: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << "The First Peak Found Is " << a[first_peak(a, 0, n - 1, n)];

  return 0;
}