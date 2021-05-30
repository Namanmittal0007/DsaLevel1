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
    int dp[cap+1]={};
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=wt[i];j<=cap;j++){
            int cur_val=dp[j-wt[i]]+val[i];
            if(dp[j]<cur_val){
                dp[j]=cur_val;
            }
        }
    }
    cout<<dp[cap];
    return 0;
}