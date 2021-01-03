#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n>>k;
    int arr[n][k];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }
    int least=INT_MAX,sleast=INT_MAX;
    int dp[n][k]={};
    for(int j=0;j<k;j++){
        dp[0][j]=arr[0][j];
        if(dp[0][j]<least){
            sleast=least;
            least=dp[0][j];
        }
        else if(dp[0][j]<sleast){
            sleast=dp[0][j];
        }
    }
    for(int i=1;i<n;i++){
        int nleast=INT_MAX;
        int nsleast=INT_MAX;
        for(int j=0;j<k;j++){
            if(dp[i-1][j]==least){
                dp[i][j]=sleast+arr[i][j];
            }
            else{
                dp[i][j]=least+arr[i][j];
            }
            if(dp[i][j]<=nleast){
                nsleast=nleast;
                nleast=dp[i][j];
            }
            else if(dp[i][j]<nsleast){
                nsleast=dp[i][j];
            }
        }
        least=nleast;
        sleast=nsleast;
    }
    cout<<least;
    return 0;
}