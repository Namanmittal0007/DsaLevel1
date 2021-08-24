#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, res=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        res = res ^ num;
    }
    cout<<res;
    return 0;
}