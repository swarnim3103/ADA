#include<iostream>
#include<vector>
using namespace std;

int find(int u,vector<int> &p){
    while(p[u]>0){
        u=p[u];
    }
    return u;
}
void union1(int u,int v,vector<int> &p){
    p[u]=v;
}

void heapify(vector<vector<int>>&cost, int i, int n){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<n && cost[l][0]<cost[largest][0]){
        largest=l;
    }
    if(r<n && cost[r][0]<cost[largest][0]){
        largest=r;
    }
    if(largest!=i){
        swap(cost[i],cost[largest]);
        heapify(cost,largest,n);
    }
}

void min_heap(vector<vector<int>>&cost, int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(cost,i,n);
    }
}
void kruskal(vector<vector<int>>&cost,int n){
    vector<int> p(n+1,-1);
    vector<vector<int>> ans;
    min_heap(cost,n);
    for(int i=0;i<n-1;i++){
        int u=find(cost[0][1],p);
        int v=find(cost[0][2],p);
        if(u!=v){
            ans.push_back(cost[0]);
            union1(u,v,p);
        }
        cost[0]=cost[n-1-i];
        heapify(cost,0,n-i-1);
    }
    cout<<"The edges in the minimum spanning tree are:\n";
    for(auto i:ans){
        cout<<i[1]<<" "<<i[2]<<" "<<i[0]<<"\n";
    }
}
int main(){
    int n,m;
    cout<<"Enter the number of edges and vertices:\n";
    cin>>m>>n;
    vector<vector<int>> cost(m,vector<int>(3));
    cout<<"Enter the edges with their weights:\n";
    for(int i=0;i<m;i++){
        cin>>cost[i][1]>>cost[i][2]>>cost[i][0];
    }
    kruskal(cost,n);
    return 0;
}