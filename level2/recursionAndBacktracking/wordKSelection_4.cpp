#include<bits/stdc++.h>
using namespace std;
void wordkselection4(string ustr, unordered_map<char,int> fmap, int idx,string ans, int k){
    if(ans.length()==k){
        cout<<ans<<endl;
    }
    for(int i=idx; i<ustr.length(); i++){
        char c = ustr[i];
        if(fmap[c]>0){
            fmap[c]--;
            wordkselection4(ustr,fmap,i,ans+string(1,c),k);
            fmap[c]++;
        }
    }
}
int main(){
    string s,ustr;
    cin>>s;
    int k;
    cin>>k;
    unordered_map<char, int> fmap;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(fmap.find(c)==fmap.end()){
            fmap[c]=1;
            ustr+=string(1,c);
        }
        else{
            fmap[c]++;
        }
    }
    // for( auto x : fmap){
    //     cout<<x.first<<" : "<<x.second<<endl;
    // }
    wordkselection4(ustr,fmap,0,"",k);
    return 0;
}