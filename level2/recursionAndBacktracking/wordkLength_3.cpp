#include<bits/stdc++.h>
using namespace std;
void wordklength3(string s, unordered_map<char,int> &lastocc, int idx, vector<char> &ans, int asf, int k){
    if(idx == s.length()){
        if(asf==k){
            for(auto x:ans){
                cout<<x;
            }
            cout<<endl;
        }
        return;
    }
    char c = s[idx];
    int lo = lastocc[c];
    for(int i= lo+1; i<ans.size(); i++){
        if(ans[i]=='.'){
            lastocc[c] = i;
            ans[i] = c;
            wordklength3(s,lastocc,idx+1,ans,asf+1,k);
            ans[i] = '.';
            lastocc[c] = lo; 
        }
    }
    if(lo==(-1)){
        wordklength3(s,lastocc,idx+1,ans,asf,k);
    }
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    unordered_map<char,int> lastocc;
    for(int i=0;i<s.length();i++){
        if(lastocc.find(s[i])==lastocc.end()){
            lastocc[s[i]]=-1;
        }
    }
    vector<char> ans(k,'.');
    wordklength3(s,lastocc,0,ans,0,k);
}