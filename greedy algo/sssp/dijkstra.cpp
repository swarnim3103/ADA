// Dijkstra's Algorithm -> find shoteest path from source vertex to all other vertices
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int min(vector<int> &dist,vector<bool> &flag,int n){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<n;i++){
        if(flag[i]==false && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void sssp(int v,vector<vector<int>> &cost,int n,vector<int> &dist){
    //v ->visited vertex
    //cost ->distance between two vertices ->u and v
    //n ->total number of vertices
    //dist->distance of array from the source vertex ->u
    //input should be v{1,2,...} and e[i][j]=cost and source vertex index
    //output -> visited vertex sequence and dist 
    vector<bool> flag(n);
    for(int i=0;i<n;i++){
        dist[i]=cost[v][i];
        flag[i]=false;
    }
    flag[v]=true;
    for(int j=1;j<=n-1;j++){
        int u=min(dist,flag,n);
        flag[u]=true;
       for(int i=0;i<n;i++){
              if(!flag[i] && dist[u]+cost[u][i]<dist[i]){
                dist[i]=dist[u]+cost[u][i];
              }
         }
    }

}
int main(){
    int n,v;
    cout<<"Enter the number of vertices:";
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n,0));
    vector<int> dist(n);
   cout<<"Enter the cost of vertices"<<endl;
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>cost[i][j];
       }
       cout<<endl;
   }
   cout<<"Enetr the index of source vertex:";
   cin>>v;
   sssp(v,cost,n,dist);
    cout<<"The shortest path from source vertex to all other vertices is:";
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}