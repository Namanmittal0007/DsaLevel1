#include <bits/stdc++.h>
using namespace std;

int fib(int n,int dp[]){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]>0){
        return dp[n];
    }
    int fibnm1=fib(n-1,dp);
    int fibnm2=fib(n-2,dp);
    dp[n]=fibnm1+fibnm2;
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int dp[n+1]={0};
    cout<<fib(n,dp)<<endl;
    return 0;
}