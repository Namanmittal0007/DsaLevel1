#include<bits/stdc++.h>
using namespace std;
void rtol(int arr[],int r2l[],int n){
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.size()>0 and st.top()<=arr[i]){
            st.pop();
        }
        if(st.size()==0){
            r2l[i]=-1;
        }
        else{
            r2l[i]=st.top();
        }
        st.push(arr[i]);
    }
}
void ltor(int arr[],int l2r[],int n){
    stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 and arr[st.top()]<arr[i]){
            int idx=st.top();
            l2r[idx]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(st.size()>0){
        int idx=st.top();
        l2r[idx]=-1;
        st.pop();
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l2r[n]={0},r2l[n]={0};
    ltor(arr,l2r,n);
    rtol(arr,r2l,n);
    for(int i=0;i<n;i++){
        cout<<l2r[i]<<"\n";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<r2l[i]<<"\n";
    }
    return 0;
}