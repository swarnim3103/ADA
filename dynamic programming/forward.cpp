#include<iostream>
#include<climits>
using namespace std;
int vertex(int cost[7][7],int fdist[],int j){
    int r=j+1;
    int min=INT_MAX;
    int index;

    while(r<7){
        cout<<"4"<<endl;
        if(cost[j][r]!=0 && cost[j][r]+fdist[r]<min){
            cout<<"3"<<endl;
            min=cost[j][r]+fdist[r];
            index=r;
            cout<<index<<"<=index";
        }
        r++;
    }
    return index;
}

void multigraph(int n,int k,int cost[7][7],int fdist[]){
    //k->number of stages
    //n->number of vertices
    //cost->distance between two vertices
    //fdist->forward distance
    fdist[n]=0;
    int* d=new int[k];
    for(int j=n-1;j>=1;j--){
        cout<<"1"<<endl;
        int r=vertex(cost,fdist,j);
        cout<<"2 "<<endl;
        fdist[j]=cost[j][r]+fdist[r];
        d[j]=r;
    }

}
void print(int d[],int k){
    int *p=new int[k];
    p[0]=1;
    p[k-1]=7;
    cout<<"The path is:";
    for(int i=1;i<k-1;i++){
        p[i]=d[p[i-1]];
    }
    for(int i=0;i<k;i++){
        cout<<p[i]<<" ";
    }
}

int main(){
    int n=7;
    int k=4;
    int cost[7][7]={{0,2,1,0,0,0,0},
                    {0,0,0,3,2,0,0},
                    {0,0,0,1,1,0,0},
                    {0,0,0,0,0,2,0},
                    {0,0,0,0,0,1,1},
                    {0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,0}};
    int fdist[7];
    multigraph(n,k,cost,fdist);
    print(fdist,k);
    return 0;
// Output: The path is:1 3 5 7
}