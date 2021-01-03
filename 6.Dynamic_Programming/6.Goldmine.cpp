#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int mine[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mine[i][j];
        }
    }
    int dp[n][m]={0};
    for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(j==m-1){
                dp[i][j]=mine[i][j];
            }
            else if(i==0){
                dp[i][j]=mine[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }
            else if(i==n-1){
                dp[i][j]=mine[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }
            else{
                dp[i][j]=mine[i][j]+max(dp[i+1][j+1],max(dp[i-1][j+1],dp[i][j+1]));
            }
        }
    }
    int result=INT_MIN;
    for(int i=0;i<n;i++){
        result=max(result,dp[i][0]);
    }
    cout<<result;
    return 0;
}
