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
    bool dp[n+1][tar+1]={0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=tar;j++){
            if(i==0 and j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(j==0){
                dp[i][j]=true;
            }
            else{
                if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }
                else{
                    int val=arr[i-1];
                    if(j>=val){
                        if(dp[i-1][j-val]==true){
                            dp[i][j]=true;
                        }
                    }
                }
            }
        }
    }
    cout<<(dp[n][tar]?"true":"false");
    return 0;
}
