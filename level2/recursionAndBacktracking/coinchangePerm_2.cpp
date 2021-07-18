#include<bits/stdc++.h>
using namespace std;
void coinchangePerm1(vector<int> coins, string ans, int currsum, int tar){
    if(currsum>=tar){
        if(currsum==tar){
            cout<<ans<<"."<<endl;
        }
        return;
    }
    for(int i=0;i<coins.size();i++){
            coinchangePerm1(coins,ans+to_string(coins[i])+"-", currsum+coins[i],tar);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int tar;
    cin>>tar;
    coinchangePerm1(coins, "", 0, tar);
    return 0;
}