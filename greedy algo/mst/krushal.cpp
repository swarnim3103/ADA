#include<iostream>
using namespace std;

int find(int u,int *p){
    while(p[u]>0){
        u=p[u];
    }
    return u;
}
void union1(int u,int v,int *p){
    p[u]=v;
}

void min_heap(int **cost,)