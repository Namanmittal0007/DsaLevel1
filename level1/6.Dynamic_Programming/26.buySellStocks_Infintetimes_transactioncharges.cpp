#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n]={};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int fee;
    cin>>fee;
    int ob=-arr[0],os=0;
    //cout<<ob<<" | "<<os<<endl;
    for(int i=1;i<n;i++){
        int nb=ob,ns=os;
        if(os-arr[i]>ob){
            nb=os-arr[i];
        }
        if(arr[i]+ob-fee>os){
            ns=arr[i]+ob-fee;
        }
        ob=nb;
        os=ns;
       // cout<<ob<<" | "<<os<<endl;
    }
    cout<<os;
    return 0;
 }