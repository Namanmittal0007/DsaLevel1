//This is only possible if all the character are present even times and only one char can be available in odd numbers
#include<bits/stdc++.h>
using namespace std;
void palindromicpermutation(string s, int len, unordered_map<char, int> &charcnt, char oddchar, int count){
    if(s.length()==len){
        cout<<s;
        if(oddchar!='!'){
            cout<<oddchar;
        }
        for(int i=s.length()-1;i>-1;i--){
            cout<<s[i];
        }
        cout<<endl;
        return ;
    }
    for(auto x:charcnt){
        // cout<<count<<" "<<x.first<<":"<<x.second<<endl;
        if(x.second>0){
            charcnt[x.first]=x.second-1;
            s+=string(1,x.first);
            palindromicpermutation(s,len,charcnt,oddchar,count+1);
            charcnt[x.first]=x.second;
            s=s.substr(0,s.length()-1);
        }
    }
}
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> charcnt;
    for(int i=0;i<s.length();i++){
        if(charcnt.find(s[i])!=charcnt.end()){
            charcnt[s[i]]++;
        }
        else{
            charcnt[s[i]]=1;
        }
    }    
    int oddcount=0;
    char oddchar='!';
    for(auto x:charcnt){
        if(x.second%2!=0){
            oddcount++;
            oddchar=x.first;
        }
        charcnt[x.first]=x.second/2;
    }
    palindromicpermutation("",s.length()/2,charcnt,oddchar,1);
    return 0;
}