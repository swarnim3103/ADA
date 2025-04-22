#include <iostream>
#include <vector>
using namespace std;

bool place(int k , int i){
    //k ->column 
    //i -> row
    //kth queen is placed in ith row and kth column
vector<int>queens(k);
for(int j=0 ; j<k-1 ; j++){
    if(queens[j] == i){
        return false;
    }
    return true;
} 
}

vector<int> nth(int k){
vector<int> queens(k);
for(int i=0 ; i<k ; i++){
    if(place(k,i)){

    }
}
    return queens;
}
int main(){
    return 0;
}