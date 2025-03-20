#include <iostream>
using namespace std;
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


int matrix(int a[100][100],int b[100][100]){
    int c[100][100];
    for(int i=1;i<2;i++)
    {
        for(int j=1;j<2;j++)
        {
            c[i][j]=0;
            for(int k=1;k<2;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
