#include<bits/stdc++.h>
using namespace std;
void coinchange2(int idx, vector<int> coins, string ans, int currsum, int tar){
    if(idx==coins.size()){
        if(currsum==tar){
            cout<<ans<<"."<<endl;
        }
        return ;
    }
    for(int i = tar/coins[idx] ; i>0; i--){
        string currans="";
        for(int j = 0 ; j<i; j++){
            currans=currans+to_string(coins[idx])+"-";
        }
        coinchange2(idx+1, coins, ans+currans, currsum+(i*coins[idx]), tar);
    }
    coinchange2(idx+1, coins, ans, currsum, tar);
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
    coinchange2(0,coins,"",0,tar);
    return 0;
}