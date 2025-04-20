#include<iostream>
using namespace std;
int algo(int a[6][6],int source,int j){
    for(int i=0;i<6;i++){
            if(a[source][i]!=0){
               j++;
               cout<<i<<"  ";
                j=algo(a,i,j);    
                break;
            } 
            if(i==5){
                return j;
            }
    }
}
int main(){
    int a[6][6]={{0,1,1,0,0,0},
                 {0,0,0,1,1,0},
                 {0,0,0,1,1,0},
                 {0,0,0,0,0,1},
                 {0,0,0,0,0,1},
                 {0,0,0,0,0,0}};
    int source=0;
    int j=1;
    int s=algo(a,source,j);
    cout<<"there are "<<s<<" stages";
    return 0;
    //output: 1  3  5  there are 4 stages
}