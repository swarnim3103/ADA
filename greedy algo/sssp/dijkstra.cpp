// Dijkstra's Algorithm -> find shoteest path from source vertex to all other vertices
#include<iostream>
using namespace std;

int min(int *dist,bool *flag,int n){
    int min=INT_MAX;
    int min_index;
    for(int i=1;i<=n;i++){
        if(flag[i]==false && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void sssp(int v,int **cost,int n,int *dist){
    //v ->visited vertex
    //cost ->distance between two vertices ->u and v
    //n ->total number of vertices
    //dist->distance of array from the source vertex ->u
    //input should be v{1,2,...} and e[i][j]=cost and source vertex index
    //output -> visited vertex sequence and dist 
    bool *flag;
    for(int i=1;i<=n;i++){
        dist[i]=cost[v][i];
        flag[i]=false;
    }
    flag[v]=true;
    for(int j=2;j<n-1;j++){
        int u=min(dist,flag,n);
        flag[u]=true;
       for(int i=1;i<=n;i++){
              if(!flag[i] && dist[u]+cost[u][i]<dist[i]){
                dist[i]=dist[u]+cost[u][i];
              }
         }
    }

}