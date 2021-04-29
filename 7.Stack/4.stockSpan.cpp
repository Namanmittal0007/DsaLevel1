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
    int ss[n];    //stockspan[n]
    for(int i=0;i<n;i++){
        while(st.size()>0 and arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.size()==0){
            ss[i]=i+1;
        }
        else{
            ss[i]=i-st.top();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ss[i]<<endl;
    }
    return 0;
}