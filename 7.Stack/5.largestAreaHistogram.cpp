#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int> st;
    int sR[n],sL[n];      ///sR=small on right, sL=small on left
    for(int i=0;i<n;i++){
        while(st.size()>0 and arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.size()==0){
            sL[i]=-1;
        }
        else{
            sL[i]=st.top();
        }
        st.push(i);
    }
    while(st.size()>0){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(st.size()>0 and arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.size()==0){
            sR[i]=n;
        }
        else{
            sR[i]=st.top();
        }
        st.push(i);
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        int curr=(sR[i]-sL[i]-1)*arr[i];
        //cout<<sR[i]<<" - "<<sL[i]<<" : "<<curr<<endl;
        max=max>curr?max:curr;
    }
    cout<<max;
    return 0;
 }