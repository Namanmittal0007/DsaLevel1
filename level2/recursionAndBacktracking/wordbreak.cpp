#include<bits/stdc++.h>
using namespace std;
void wordbreak(string ans, string s, unordered_set<string> dict){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<s.length();i++){
        string newS=s.substr(0,i+1);
        if(dict.find(newS)!=dict.end()){ 
            string ros=s.substr(i+1);
            wordbreak(ans+newS+" ",ros,dict);
        }
    }
}
int main(){
    int n;
    cin>>n;
    unordered_set<string> dict;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        dict.insert(s);
    }
    string s;
    cin>>s;
    wordbreak("",s,dict);
    return 0;
}