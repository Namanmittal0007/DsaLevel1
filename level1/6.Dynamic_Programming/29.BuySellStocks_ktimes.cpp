#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int dp[k+1][n]={};
    for(int i=1;i<=k;i++){
        int maxx=INT_MIN;
        for(int j=1;j<n;j++){
            if(dp[i-1][j-1]-arr[j-1]>maxx){
                maxx=dp[i-1][j-1]-arr[j-1];
            }
            if(maxx+arr[j]>dp[i][j-1]){
                dp[i][j]=maxx+arr[j];
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
          //  cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[k][n-1];
    return 0;
}