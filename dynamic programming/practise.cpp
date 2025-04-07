#include<iostream>
#include<set>
using namespace std;

int main(){
    set<pair<int,int>> s={{1,2},{2,3},{3,4}};
    cout<<"The set is:";
    for(auto const &i:s){
        cout<<i.first<<" "<<i.second<<endl;
    }
}