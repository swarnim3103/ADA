#include<iostream>
using namespace std;

void matrix(int a[100][100],int m,int n){

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

int main(){
    int m,n,p;
    cin>>m>>n>>p;
int a[100][100],b[100][100],c[100][100];
cout<<"Enter the elements of first matrix"<<endl;
matrix(a,m,n);
cout<<"Enter the elements of second matrix"<<endl;
matrix(b,n,p);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    cout<<"The resultant matrix is"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
