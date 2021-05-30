#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int profit=0,minprice=INT_MAX;
    for(int i=0;i<n;i++){
        if(minprice>price[i]){
            minprice=price[i];
        }
        int currprofit=price[i]-minprice;
        profit=currprofit>profit?currprofit:profit;
    }
    cout<<profit;
    return 0;
}