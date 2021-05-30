#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    if(n==0){
        return 1;
    }
    int Xnby2=powerLogarithmic(x,n/2);
    int xn=Xnby2*Xnby2;
    if(n%2>0){
        xn=xn*x;
    }
    return xn;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}