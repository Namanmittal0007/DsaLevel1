#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> getss(string s){
    if(s.size()==0){
        vector<string> finres={""};
        return finres;
    }
    char firstchar=s[0];
    vector<string> curres=getss(s.substr(1));
    vector<string> finres;
    for(int i=0;i<curres.size();i++){
        finres.push_back(curres[i]);
        finres.push_back(firstchar+curres[i]);
    }
    return finres;
}
int main(){
    string s;
    cin>>s;
    vector<string> res;
    res=getss(s);
    cout<<"["<<res[0];
    for(int i=1;i<res.size();i++){
        cout<<", "<<res[i];
    }
    cout<<"]";
    return 0;
}
