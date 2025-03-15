#include<iostream>
#include<random>
using namespace std;

int determinant(int x1,int y1,int x2,int y2,int x3,int y3){
    return (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
} 

int main(){
int a[100][100],b[100][100];
int q=1,w=1;
int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
            // a[i][j] = rand()%100;
        }

    }
    for(int k=1;k<=5;k++){
        for(int l=1;l<=5;l++){
           for(int m=1;m<=5;m++){
                for(int n=1;n<=5;n++){
                    if(k!=l && l!=m && m!=n && n!=k && k!=m && l!=n){
                        x1=a[1][k];
                        y1=a[2][k];
                        x2=a[1][l];
                        y2=a[2][l];
                        x3=a[1][m];
                        y3=a[2][m];
                        x4=a[1][n];
                        y4=a[2][n];
                        int A1 = determinant(x1,y1,x3,y3,x4,y4);
                        int A2 = determinant(x1,y1,x2,y2,x3,y3);
                        int A3 = determinant(x1,y1,x2,y2,x4,y4);
                        if(A1<0 || A2<0 || A3<0){
                            b[q][w]=x1;
                            q++;
                            b[q][w]=y1;
                            w++;
                            q=1;
                        }
                }
                else{
                    continue;
                }
           }
        }
        
    }   
}
for(int i=1;i<=2;i++){
    for(int j=1;j<=w-1;j++){
        cout<<b[i][j]<<" ";
    }
    cout<<"\n";
}
    return 0;
}