#include<bits/stdc++.h>
using namespace std;
void wordkselection3(string ustr, unordered_map<char,int> umap, int idx, string ans, int anslen){
    if(idx==ustr.length()){
        if(ans.length()==anslen){
            cout<<ans<<endl;
        }
        return;
    }
    char c = ustr[idx]; 
    if(umap[c]>0){
        umap[c]--;
        wordkselection3(ustr,umap,idx,ans+string(1,c),anslen);
        umap[c]++;
    }
    wordkselection3(ustr,umap,idx+1,ans,anslen);
}
int main(){
    string str,ustr="";
    cin>>str;
    int k;
    cin>>k;
    unordered_map<char, int> umap;
    for(int i=0; i<str.length();i++){
        char c = str[i];
        if(umap.find(c)!=umap.end()){
            umap[c]++;
        }
        else{
            umap[c]=1;
            ustr+=string(1,c);
        }
    }
    wordkselection3(ustr, umap,  0, "",k);
    return 0;
}