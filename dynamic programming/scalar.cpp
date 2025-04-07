#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void print(vector<vector<int>> &s,int i,int j){
    if(i==j){
        cout<<"A"<<i+1;
    }else{
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}

void mcm(vector<int> &p,int n){ //matrix chain mulitplication
    vector<vector<int>> m(n,vector<int>(n,0));
    vector<vector<int>> s(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        m[i][i]=0;
    }
    // cout<<1;
    for(int l=2;l<=n;l++){
        // cout<<2;
        for(int y=0;y<n-l+1;y++){
            int x=y+l-1;
            m[y][x]=INT_MAX;
            // cout<<3;
            for(int k=y;k<x;k++){
                // cout<<4;
                int q=m[y][k]+m[k+1][x]+p[y-1]*p[k]*p[x];
                if(q<m[y][x]){
                    m[y][x]=q;
                    s[y][x]=k;
                    // cout<<5;

                }
            }
        }
    }
    print(s,0,n-1);

}
int main(){
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    cout<<"Enter the dimensions of matrices: ";
    vector<int> p(n+1);
    for(int i=0;i<n+1;i++){
        cin>>p[i];
    }
    cout<<"Minimum number of multiplications is: "<<endl;
    mcm(p,n);
    return 0;
}

//const vector<int> &p
//const vector<int> &s
//vector<vector<int>> m(n,vector<int>(n,0));
//vector<vector<int>> s(n,vector<int>(n,0)); -->vector takes 0 based indexing