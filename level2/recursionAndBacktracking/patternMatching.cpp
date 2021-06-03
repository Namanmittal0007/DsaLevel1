#include<bits/stdc++.h>
using namespace std;
void matchpattern(string s,string pat, unordered_map<char,string> &patmatch,string op){
    if(pat.length()==0 ){
        if(s.length()==0){
            unordered_set<char> allreadyprinted;
            for(int i=0;i<op.length();i++){
                if(allreadyprinted.find(op[i])==allreadyprinted.end()){
                    allreadyprinted.insert(op[i]);
                    cout<<op[i]<<"-> "<<patmatch[op[i]]<<", ";
                }
                else{
                    continue;
                }
            }
            cout<<"."<<endl;
        }
        return;
    }
    char c=pat[0];
    string rop=pat.substr(1);
    if(patmatch.find(c)!=patmatch.end()){
        string newS=patmatch[c];
        if(s.length()>=newS.length()){
            string ros=s.substr(newS.length());
            string comp=s.substr(0,newS.length());
            if(newS==comp){    
                matchpattern(ros,rop,patmatch,op);
            }
        }
    }
    else{
        for(int i=0;i<s.length();i++){
            string newS=s.substr(0,i+1);
            string ros=s.substr(i+1);
            patmatch[c]=newS;
            matchpattern(ros,rop,patmatch,op);
            patmatch.erase(c);
        }    
    }
}
int main(){
    string s,pat,op;
    cin>>s>>pat;
    op=pat;
    unordered_map<char,string> patmatch;
    matchpattern(s,pat,patmatch,op);
    return 0;
}