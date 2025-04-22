//return 2d array of shortest path from source vertex to all other vertices
#include<iostream>
#include<vector>
using namespace std;

 vector<vector<int>> apsp(int n, vector<vector<int>> &cost){
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=cost[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
    return a;
 }

 int main(){
    int n;
    cout<<"Enter the number of vertices:\n";
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n,0));
    cout<<"Enter the cost matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
        cout<<endl;
    }
    vector<vector<int>> a=apsp(n,cost);
    cout<<"The shortest path matrix is:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
 }