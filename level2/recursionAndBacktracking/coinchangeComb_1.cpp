#include<bits/stdc++.h>
using namespace std;
void coincomb1(int idx,vector<int> coins, string ans, int cursum, int tarsum){
    if(idx==coins.size() || cursum>tarsum){
        if(cursum==tarsum){
            cout<<ans<<"."<<endl;
        }
        return;
    }
    coincomb1(idx+1, coins, ans+to_string(coins[idx])+"-", cursum+coins[idx], tarsum);
    coincomb1(idx+1, coins, ans, cursum, tarsum);
}
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }        
    int tarsum;
    cin>>tarsum;
    coincomb1(0,coins,"",0,tarsum);
}