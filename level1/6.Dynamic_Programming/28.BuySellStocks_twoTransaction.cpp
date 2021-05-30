#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int minbuy=arr[0];
    int dpl[n]={0};
    for(int i=1;i<n;i++){
        if(minbuy>arr[i]){
            minbuy=arr[i];
        }
        int currprofit=arr[i]-minbuy;
        dpl[i]=currprofit>dpl[i-1]?currprofit:dpl[i-1];
    }
    int maxsell=arr[n-1];
    int dpr[n]={0};
    for(int i=n-2;i>=0;i--){
        if(maxsell<arr[i]){
            maxsell=arr[i];
        }
        int currprofit=maxsell-arr[i];
        dpr[i]=currprofit>dpr[i+1]?currprofit:dpr[i-+1];
    }
    int result=INT_MIN;
    for(int i=0;i<n;i++){
        result=dpl[i]+dpr[i]>result?dpl[i]+dpr[i]:result;
    }
    cout<<result;
    return 0;
    
}