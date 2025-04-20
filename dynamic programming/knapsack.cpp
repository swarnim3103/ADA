#include<iostream>
#include<set>
#include<vector>
using namespace std;


set<pair<int,int>> mergePurge(set <pair<int,int>>&s1,set<pair<int,int>>&s2,int n,int W){
    set<pair<int,int>>s3;
    auto i=s1.begin();
    auto j=s2.begin();
    //mergeing the two sets
    // cout<<11;
    while(i!=s1.end() && j!=s2.end()){
        cout<<12;
        if(i->first<j->first){
            s3.insert(*i);
            i++;
        }else if(i->first>j->first){
            s3.insert(*j);
            j++;
        }else{
            s3.insert(*i);
            i++;
            j++;
        }
        cout<<13;
    }
    
    // cout<<14;
    auto k=s3.begin();
    auto l=k;
    //purging the set
    while (l != s3.end()) {
        cout<<14;
        l++;
        if (k->second > l->second) {
            s3.erase(k);
        } else {
            k++;
        }
    }
    // cout<<15;
    auto y=s3.begin();
    while (y != s3.end()) {
        cout<<15;
        if (y->second > W) {
           s3.erase(y);
        }
        y++;
    }
   return s3;
}

void knapsack(int n,vector<int>&wt,vector<int>&p,int W){
   vector< set<pair<int,int>>>s(n),s1(n);
   s[0].insert({0,0});
   //making the s1[n] set and s[n] set
   //    cout<<1;
   s[1].insert({0,0});
   for(int i=1;i<n;i++){
    if(s[i].rbegin()->second<W){
        cout<<7;
        s[i-1].insert({p[i-1], wt[i-1]});
        cout<<8;
        s1[i-1].insert({p[i-1] + p[i], wt[i-1] + wt[i]});
        cout<<9;
        s[i]=mergePurge(s[i-1],s1[i-1],s[i-1].size(),W);
        cout<<10;
    }
   
   }
   cout<<2;
   //the knapsack solution
   cout<<"The total profit is :"<< s[n-1].rbegin()->first;
   vector<bool>x(n,false);
   auto pro=s[n-1].rbegin()->first;
   auto w=s[n-1].rbegin()->second;
   //backtracking the solution
   cout<<3;
   for(int i=n-1;i>0;i--){
    pair<int,int> t={pro,w};
    auto it=s[i].find(t);
    if(it!=s[i].end()){
       x[i]=true;
       pro=pro-p[i-1];
         w=w-wt[i-1];
   }
}
cout<<4;
for(int i=0;i<n;i++){
    if(x[i]){
        cout<<"the profit is made by item profit :"<<p[i]<<" and weight :"<<wt[i]<<endl;
    }
}
}

int main(){
    int n,W;
    cout<<"Enter the number of items and the weight of the knapsack :";
    cin>>n>>W;
    vector<int> wt(n),p(n);
    cout<<"Enter the weights of the items :";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"Enter the profits of the items :";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    knapsack(n,wt,p,W);
    return 0;
}
