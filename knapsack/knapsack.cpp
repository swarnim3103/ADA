#include <iostream>
using namespace std;

void swap(float *a,float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

void sort(float arr[],float arr2[],int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap( &arr[j], &arr[j + 1]);
                swap( &arr2[j], &arr2[j + 1]);
            }
        }
    }
}

void ratio(float profit[],float weight[],int size2){
    for(int i=0;i<size2;i++){
        profit[i]=(float)(profit[i]/weight[i]);

    }
    sort(profit,weight,size2);
}
float knapsack(float profit[],float weight[],int capacity,int size3){
    ratio(profit,weight,size3);
    float max_profit=0;
    for(int i=0;i<size3;i++){
        if(weight[i]<=capacity){
            max_profit+=profit[i]*weight[i];
            capacity-=weight[i];
        }
        else{
            max_profit+=profit[i]*capacity;
            break;
        }
    }
    return max_profit;
}
int main(){
    float profit[]={60,100,120};
    float weight[]={10,20,30};
    int capacity=50;
    cout<<knapsack(profit,weight,capacity,3);
    // for(int i=0;i<3;i++){
    //     cout<<profit[i]<<" ";
    // }
    
    return 0;
}