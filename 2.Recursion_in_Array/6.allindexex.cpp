#include<iostream>
using namespace std;
int* allindices(int* arr,int idx,int x,int n,int count){
    if(idx==n){
        int* res=new int[count+1];
        res[0]=count;
        return res;
    }
    int* res;
    if(arr[idx]==x){
        res=allindices(arr,idx+1,x,n,count+1);
    }
    else{
        res=allindices(arr,idx+1,x,n,count);
    }
    if(arr[idx]==x){
        res[count+1]=idx;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int* res=allindices(arr,0,x,n,0);
    for(int i=1;i<=res[0];i++){
        cout<<res[i]<<"\n";
    }
}