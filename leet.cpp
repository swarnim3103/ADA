// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
 int x;
 cin>>x;
 int k;
 for (int i=1 ;i<=x/2;i++){
     if( i*i==x ){
         k=i;
             break;
         }
 }
 cout<<k;
    return 0;
}