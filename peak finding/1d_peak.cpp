#include <iostream>
using namespace std;

int peak(int a[], int x,int low, int high) {
  int mid = (low + high) / 2;
  if (mid < x - 1 && a[mid] < a[mid + 1]) {
    return peak(a,x, mid + 1, high);
  } else if (mid > 0 && a[mid] < a[mid - 1]) {
    return peak(a,x, low, mid - 1);
  } else {
    return mid;
  }
}

int main() {
  int n,a[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int y= a[peak(a, n, 0, n-1)];
cout<<"peak is "<<y;
  return 0;
}