#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    //cout<<n<<" "<<k<<endl;
    if(n==0 or k==0 or n<k){
        return 0;
    }
    long dp[k+1][n+1]={};
    
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i==1){
                dp[i][j]=1;
            }
            else if(j==i){
                dp[i][j]=1;
            }
            else if(j<i){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1]*(i);
            }
        }
    }
    cout<<dp[k][n];
    return 0;
}