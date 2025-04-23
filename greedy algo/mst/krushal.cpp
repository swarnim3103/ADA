#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void swap(int &a,int &b){
	int temp = b;
	b= a;
	a= temp;
}

int find(int u,vector<int> &p){
    while (p[u]>0){
        u = p[u];
    }
    return u;

}
void unions(int u,int v,vector<int> &p){
    p[u]=v;
}



vector<int> MinEdge(vector<vector<int>> &cost, int &u, int &v, int n) {
    int minEdge = INT_MAX;
    u = -1;
    v = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < minEdge) {
                minEdge = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    if (u != -1 && v != -1) {
        cost[u][v] = cost[v][u] = INT_MAX; 
    }
    vector<int> edge(2);
    edge[0] = u;
    edge[1] = v;

    return edge;
}

int kruskal(vector<vector<int>> &cost,vector<vector<int>> &dig,int n,vector<vector<int>> &t){
    // cout<<1;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        p[i]=-1;
    }
    // cout<<2;
    int minCost = 0;
    int j=0;
    vector<int> edge(2);
    // cout<<3;
    while(j<n-1){
        int u,v;
        // cout<<4;
        edge = MinEdge(cost, u, v, n);
        // cout<<5;
        u=edge[0];
        v=edge[1];
        // cout<<6;
        int k=find(u,p);
        int l=find(v,p);
        // cout<<7;
        if(k!=l){
            t[j][0]=u;
            t[j][1]=v;
            j++;
            unions(k,l,p);
            minCost+=dig[u][v];
        }
        // cout<<8;
    }
    // cout<<9;
    if(j!=n-1){
        cout<<"No MST possible"<<endl;
        return -1;
    }else{
        // cout<<10;
        return minCost;
    }
    
}

int main(){
    int n;
    cout<<"Enter the number of vertices:\n";
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n,0));
    vector<vector<int>> dig(n,vector<int>(n,0));
    cout<<"Enter the cost matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            dig[i][j]=cost[i][j];
        }
        cout<<endl;
    }
    vector<vector<int>> t(n,vector<int>(2,0));
    int minCost = kruskal(cost,dig,n,t);
    cout<<"The minimum cost is:"<<minCost<<endl;
    cout<<"The edges in the MST are:\n";
    for(int i=0;i<n-1;i++){
        cout<<t[i][0]<<" "<<t[i][1]<<endl;
    }
    return 0;
}
