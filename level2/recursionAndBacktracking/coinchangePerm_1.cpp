#include<bits/stdc++.h>
using namespace std;
void coinchangePerm1(vector<int> coins, string ans, unordered_map<int,bool> coinused, int currsum, int tar){
    if(currsum==tar){
        cout<<ans<<"."<<endl;
        return;
    }
    for(int i=0;i<coins.size();i++){
        if(!coinused[coins[i]]){
            coinused[coins[i]]=true;
            coinchangePerm1(coins,ans+to_string(coins[i])+"-", coinused,currsum+coins[i],tar);
            coinused[coins[i]]=false;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    unordered_map<int,bool> coinused;
    for(int i=0;i<n;i++){
        coinused[coins[i]]=0;
    }
    int tar;
    cin>>tar;
    coinchangePerm1(coins, "", coinused, 0, tar);
    return 0;
}