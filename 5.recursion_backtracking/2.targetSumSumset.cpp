#include<iostream>
using namespace std;
void targetsum(int arr[],int n,int idx,int cursum,int tar,string ans){
    if(idx==n){
        if(cursum==tar){
            cout<<ans<<"."<<endl;
        }
            return;
    }
    targetsum(arr,n,idx+1,cursum+arr[idx],tar,ans+to_string(arr[idx])+", ");
    targetsum(arr,n,idx+1,cursum,tar,ans);
}
int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    targetsum(arr,n,0,0,tar,"");
    return 0;
}