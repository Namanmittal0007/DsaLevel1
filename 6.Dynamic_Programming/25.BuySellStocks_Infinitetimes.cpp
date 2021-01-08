#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int profit=0;
    int buy=arr[0],sell=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            sell=arr[i];
        }
        else{
            profit+=sell-buy;
            buy=sell=arr[i];
        }
    }
    profit+=sell-buy;
    cout<<profit;
    return 0;
    
}