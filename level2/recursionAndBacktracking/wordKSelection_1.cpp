#include<bits/stdc++.h>
using namespace std;
void wordKSelect(int idx, string ustr, string asf, int k){
    if(idx==ustr.length()){
        if(asf.length()==k){
            cout<<asf<<endl;
        }
        return;
    }
    char c=ustr[idx];
    wordKSelect(idx+1,ustr,asf+string(1,c),k);
    wordKSelect(idx+1,ustr,asf,k);
}
int main(){
    string s;
    cin>>s;
    unordered_set<char> unique;
    string ustr="";
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(unique.find(c)==unique.end()){
            unique.insert(c);
            ustr+=string(1,c);
        }
    }
    int k;
    cin>>k;
    // cout<<ustr<<k;
    wordKSelect(0,ustr,"",k);
    return 0;
}