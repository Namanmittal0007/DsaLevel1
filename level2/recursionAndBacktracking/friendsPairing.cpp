#include<bits/stdc++.h>
using namespace std;
int countt=1;
void friendpair(int i, int n, string s, vector<bool> &usedn){
    if(i>n){
        cout<<countt<<"."<<s<<endl;
        countt++;
        return ;
    }
    if(!usedn[i]){
        usedn[i]=true;
        friendpair(i+1,n,s+"("+to_string(i)+") ",usedn);
        for(int x=i+1;x<=n;x++){
            if(!usedn[x]){
                usedn[x]=true;
                friendpair(i+1,n,s+"("+to_string(i)+","+to_string(x)+") ",usedn);
                usedn[x]=false;
            }
        }
        usedn[i]=false;
    }
    else{
        friendpair(i+1,n,s,usedn);
    }
}
int main(){
    int n;
    cin>>n;
    vector<bool> usedn(n+1,false);
    friendpair(1,n,"",usedn);
    return 0;
}