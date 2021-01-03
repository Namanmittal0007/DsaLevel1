#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int oinc=arr[0],oexc=0;
    for(int i=1;i<n;i++){
        int ninc=oexc+arr[i];
        int nexc=max(oinc,oexc);
        oinc=ninc;
        oexc=nexc;
    }
    cout<<(max(oinc,oexc));
    return 0;
}
