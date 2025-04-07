#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int vertex(int cost[7][7],int fdist[],int j){
    int r=j+1;
    int min=INT_MAX;
    int index;

    while(r<7){
        // cout<<"4"<<endl;
        if(cost[j][r]!=0 && cost[j][r]+fdist[r]<min){
            // cout<<"3"<<endl;
            min=cost[j][r]+fdist[r];
            index=r;
        }
        r++;
    }
    return index;
}

vector<int> multigraph(int n,int k,int cost[7][7],int fdist[]){
    //k->number of stages
    //n->number of vertices
    //cost->distance between two vertices
    //fdist->forward distance
    fdist[n]=0;
    vector<int> d(n,0);
    for(int j=n-2;j>=0;j--){
        // cout<<"1"<<endl;
        int r=vertex(cost,fdist,j);
        // cout<<"2 "<<endl;
        fdist[j]=cost[j][r]+fdist[r];
        d[j]=r;
    }
return d;
}
void print(vector <int> &d,int k){
    vector<int> p(k,0);
    p[0]=0;
    cout<<"The path is:";
    for(int i=1;i<k;i++){
        p[i]=d[p[i-1]];
    }
    for(int i=0;i<k;i++){
        cout<<p[i]+1<<" ";
    }
}

int main(){
    int n=7;
    int k=4;
    vector<int> d(n,0);
    int cost[7][7]={{0,2,1,0,0,0,0},
                    {0,0,0,3,2,0,0},
                    {0,0,0,1,1,0,0},
                    {0,0,0,0,0,2,0},
                    {0,0,0,0,0,1,1},
                    {0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,0}};
    int fdist[7];
    d=multigraph(n,k,cost,fdist);
    print(d,k);
    return 0;
// Output: The path is:1 3 5 7
}