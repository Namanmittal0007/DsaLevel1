#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, count=0;
    cin>>n;
    while(n>0){
        int rmsb = n&(-n);
        n-=rmsb;
        count++;
    }
    cout<<count;
    return 0;
}

