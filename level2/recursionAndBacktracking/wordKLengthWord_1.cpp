#include<bits/stdc++.h>
using namespace std;
void k_len_word(int idx, int asfcount, string ustr, vector<char> &asf){
    if(idx==ustr.length()){
        if(asfcount==asf.size()){
            for(auto x: asf){
                cout<<x;
            }
            cout<<endl;
        }
        return ;
    }
    char c = ustr[idx];
    for(int i=0;i<asf.size();i++){
        if(asf[i]=='-'){
            asf[i]=c;
            k_len_word(idx+1,asfcount+1,ustr,asf);
            asf[i]='-';
        }
    }
    k_len_word(idx+1,asfcount,ustr,asf);
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
    k_len_word(0,0,ustr,asf);
    return 0;
}