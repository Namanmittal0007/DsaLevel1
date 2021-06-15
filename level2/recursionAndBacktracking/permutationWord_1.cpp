#include<bits/stdc++.h>
using namespace std;
void wordpermute(unordered_map<char,int> charcount, vector<char> charseq,string s, string asf){
    if(asf.length()==s.length()){
        cout<<asf<<endl;
        return;
    }
    for(int i=0;i<charseq.size();i++){
        char c=charseq[i];
        if(charcount.find(c)!=charcount.end() and charcount[c]>0){
            charcount[c]--;
            wordpermute(charcount,charseq,s,asf+string(1,c));
            charcount[c]++;
        }
    }
}
int main(){
    string s;
    cin>>s;
    vector<char> charseq;
    unordered_map<char,int> charcount;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(charcount.find(c)==charcount.end()){
            charcount[c]=1;
            charseq.push_back(c);
        }
        else{
            charcount[c]++;
        }
    }
    wordpermute(charcount,charseq,s,"");
    return 0;
}