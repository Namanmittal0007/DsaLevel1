#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int min_jump(int jumps[],int n){
    int dp[n+1];
    fill_n(dp,n+1,-1);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        if(jumps[i]>0){
            int minjump=INT_MAX;
            for(int j=1;j<=jumps[i] and i+j<=n;j++){
                if(dp[i+j]!=(-1)){
                    if(dp[i+j]<minjump){
                        minjump=dp[i+j];
                    }
                }
            }
            if(minjump!=INT_MAX){
                dp[i]=minjump+1;
            }
        }
    }
    return dp[0];
}
int main(){
    int n;
    cin>>n;
    int jumps[n];
    for(int i=0;i<n;i++){
        cin>>jumps[i];
    }
    cout<<min_jump(jumps,n);
    return 0;
}