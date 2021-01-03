#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int wt[n]={0},val[n]={0};
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int cap;
    cin>>cap;
    int dp[n+1][cap+1]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            int cur_wt=wt[i-1];
            int cur_val=val[i-1];
            dp[i][j]=dp[i-1][j];
            if(j>=cur_wt){
                if(dp[i-1][j-cur_wt]+cur_val>dp[i][j]){
                    dp[i][j]=dp[i-1][j-cur_wt]+cur_val;
                }
            }
        }
    }
    cout<<dp[n][cap];
    return 0;
}