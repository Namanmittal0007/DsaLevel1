#include<bits/stdc++.h>
using namespace std;
void wordKSelect(int idx, unordered_map<char, int> uniquechar, string ustr, int ustridx, vector<char> &asf){
    if(idx==asf.size()){
        for(auto x : asf){
            cout<<x;
        }
        cout<<endl;
        return;
    }
    for(int i=ustridx+1;i<ustr.length();i++){
        char c=ustr[i];
        if(!uniquechar[c]){
            uniquechar[c]=1;
            asf[idx]=c;
            wordKSelect(idx+1,uniquechar,ustr,i,asf);
            uniquechar[c]=0;
        }
    }
}
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> uniquechar;
    string ustr="";
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(uniquechar.find(c)==uniquechar.end()){
            uniquechar[c]=0;
            ustr+=string(1,c);
        }
    }
    int k;
    cin>>k;
    vector<char> asf(k);
    wordKSelect(0,uniquechar,ustr,-1,asf);
    return 0;
}