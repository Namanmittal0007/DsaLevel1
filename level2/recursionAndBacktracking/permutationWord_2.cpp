#include<bits/stdc++.h>
using namespace std;
void wordpermu2(string s, int idx, unordered_map<char,int> lastocc, vector<char> &asf){
    if(idx==s.length()){
        for(auto x : asf ){
            cout<<x;
        }
        cout<<endl;
        return ;
    }
    char c=s[idx];
    for(int loc=lastocc[c]+1;loc<asf.size();loc++){
        if(asf[loc]=='-'){
            int temp=lastocc[c];
            lastocc[c]=loc;
            asf[loc]=c;
            wordpermu2(s,idx+1,lastocc,asf);
            asf[loc]='-';
            lastocc[c]=temp;
        }
    }
}
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> lastocc;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(lastocc.find(c)==lastocc.end()){
            lastocc[c]=-1;
        }
    }
    vector<char> asf(s.length(),'-');
    wordpermu2(s,0,lastocc,asf);
}