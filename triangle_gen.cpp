#include <iostream>
using namespace std;
 int main(){
    int n;
    cin>>n;
    cout<<"number of triangles generated is "<<(n*(n-1)*(n-2))/6;
    return 0;
 }