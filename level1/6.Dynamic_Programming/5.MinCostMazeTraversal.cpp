#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    int arr[n][m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int dp[n][m]={0};
    //dp[n-1][m-1]=arr[n-1][m-1];
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 and j==m-1){
                dp[i][j]=arr[i][j];
            }
            else if(i==n-1){
                dp[i][j]=dp[i][j+1]+arr[i][j];
            }
            else if(j==m-1){
                dp[i][j]=dp[i+1][j]+arr[i][j];
            }
            else{
                int mi;
                if(dp[i+1][j]<dp[i][j+1]){
                    mi=dp[i+1][j];
                    char x='0'+i+1;
                    char y='0'+j;
                    string str="(";
                    str=str+x;
                    str=str+",";
                    str=str+y;
                    str=str+")";
                    s=str+s;
                }
                else{
                    mi=dp[i][j+1];
                    char x='0'+i;
                    char y='0'+j+1;
                    string str="(";
                    str=str+x;
                    str=str+",";
                    str=str+y;
                    str=str+")";
                    s=str+s;
                }
                dp[i][j]=mi+arr[i][j];
            }
        }
    }
    cout<<dp[0][0];
    
}
