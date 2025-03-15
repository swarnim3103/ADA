#include<iostream>
using namespace std;

int determinant(int x1,int y1,int x2,int y2,int x3,int y3){
    return (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
} 

int main(){
    // int x1,x2,x3,y1,y2,y3,x,y;
    // cin>>x1>>y1>>x2>>y2>>x3>>y3>>x>>y;
    
    // int A = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    // int A1 = (x*(y2-y3) + x2*(y3-y) + x3*(y-y2));
    // int A2 = (x1*(y-y3) + x*(y3-y1) + x3*(y1-y));
    // int A3 = (x1*(y2-y) + x2*(y-y1) + x*(y1-y2));

    // if(A==A1+A2+A3){
    //     cout<<"Point lies inside the triangle";
    // }
    // else{
    //     cout<<"Point lies outside the triangle";
    // }

    int x1,x2,x3,y1,y2,y3,x,y;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x>>y;
    int A1 = determinant(x,y,x2,y2,x3,y3);
    int A2 = determinant(x1,y1,x,y,x3,y3);
    int A3 = determinant(x1,y1,x2,y2,x,y);
    if(A1>0 && A2>0 && A3>0){
        cout<<"Point lies inside the triangle";
    }
    else{
        cout<<"Point lies outside the triangle";
    }
    return 0;
}