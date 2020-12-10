#include<iostream>
using namespace std;


void pzz(int n){
    if(n==0)
        return;
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
    
}



int main(){
    // n=1: 1 1 1
    // n=2: 2 1 1 1 2 1 1 1 2
    // n=3: 3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3
    int n; cin>>n;
    pzz(n);
}
