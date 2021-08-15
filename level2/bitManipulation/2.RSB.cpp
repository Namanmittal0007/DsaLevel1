#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rmsb = n&(-n);
    string ans="";
    while(rmsb>1){
        ans="0"+ans;
        rmsb=rmsb>>1;
    }
    ans="1"+ans;
    cout<<ans;
    return 0;
}