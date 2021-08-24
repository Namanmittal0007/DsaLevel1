#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    int axorb=0;
    for(int i=0; i<n; i++){
        cin>>num[i];
        axorb=axorb^num[i];
    }
    int rsb = axorb & (-axorb);
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if((rsb & num[i] )> 0){
            a=a^num[i];
        }
    }
    b = axorb^a;
    if(a<b){
        cout<<a<<endl<<b;
    }
    else{
        cout<<b<<endl<<a;
    }
    return 0;
}