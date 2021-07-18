#include<bits/stdc++.h>
using namespace std;
void wordklength4(string ustr, unordered_map<char,int> fmap, string ans, int idx, int k){
    if(ans.length()==k){
        cout<<ans<<endl;
    }
    for(int i=0;i<ustr.length();i++){
        char c = ustr[i];
        if(fmap[c]>0){
            fmap[c]--;
            wordklength4(ustr,fmap,ans+string(1,c),idx+1,k);
            fmap[c]++;
        }
    }
}
int main(){
    string s,ustr="";
    int k;
    cin>>s>>k;
    unordered_map<char,int> fmap;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(fmap.find(c) == fmap.end()){
            fmap[c]=1;
            ustr+=string(1,c);
        }
        else{
            fmap[c]++;
        }
    }
    wordklength4(ustr,fmap,"",0,k);
}