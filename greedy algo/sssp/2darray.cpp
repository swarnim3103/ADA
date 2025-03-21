#include<iostream>
using namespace std;

void funcout(int **a,int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    int **a=new int*[2];
    for(int i=0;i<2;i++){
        cout<<"enter row "<<i<<"\n";
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    funcout(a,n);
    return 0;
}