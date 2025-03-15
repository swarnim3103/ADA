#include <iostream>
using namespace std;

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
