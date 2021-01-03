#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    int dp[tar+1]={0};
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=tar;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    cout<<dp[tar];
    return 0;
}