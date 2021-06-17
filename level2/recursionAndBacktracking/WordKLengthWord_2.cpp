#include<bits/stdc++.h>
using namespace std;
void k_len_word(int idx, unordered_map<char, bool> uniquechar, string ustr, vector<char> &asf){
    if(idx==asf.size()){
        for(auto x: asf){
            cout<<x;
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<ustr.length();i++){
        char c=ustr[i];
        if(!uniquechar[c]){
            uniquechar[c]=true;
            asf[idx]=c;
            k_len_word(idx+1,uniquechar,ustr,asf);
            uniquechar[c]=false;
            asf[idx]='-';
        }
    }
}
int main(){
    string s;
    cin>>s;
    unordered_map<char, bool> uniquechar;
    string ustr="";
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(uniquechar.find(c)==uniquechar.end()){
            uniquechar[c]=false;
            ustr+=string(1,c);
        }
    }
    int k;
    cin>>k;
    vector<char> asf(k,'-');
    k_len_word(0,uniquechar,ustr,asf);
    return 0;
}