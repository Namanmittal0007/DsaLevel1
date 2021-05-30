#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n]={};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ob=-arr[0],os=0,oc=0;
    //cout<<ob<<" | "<<os<<endl;
    for(int i=1;i<n;i++){
        int nb=ob,ns=os,nc=oc;
        if(oc-arr[i]>ob){
            nb=oc-arr[i];
        }
        if(arr[i]+ob>os){
            ns=arr[i]+ob;
        }
        if(os>oc){
            nc=os;
        }
        ob=nb;
        os=ns;
        oc=nc;
       // cout<<ob<<" | "<<os<<endl;
    }
    cout<<os;
    return 0;
 }