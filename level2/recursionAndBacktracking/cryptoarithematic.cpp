//this soln was TLE, because of the hashmap used it is never O(1).


#include<bits/stdc++.h>
using namespace std;
int calscore(string word, unordered_map<char,int> score){
    int res=0;
    for(int i=0;i<word.length();i++){
        res=res*10+score[word[i]];
    }
    return res;
}
void printseq(unordered_map<char,int> score){
    for(int i=0;i<26;i++){
        char x=char('a'+i);
        if(score.find(x)!=score.end()){
            cout<<x<<"-"<<score[x]<<" ";
        }
    }
    cout<<endl;
}
void crypto( vector<string> words, vector<bool> &num, unordered_map<char,int> score, string s,int idx){
    if(idx==s.length()){
        int s1=calscore(words[0],score);
        int s2=calscore(words[1],score);
        int s3=calscore(words[2],score);
        if(s1+s2==s3){
            printseq(score);
        }
        return;
    }
    for(int i=0;i<10;i++){
        if(!num[i]){
            score[s[idx]]=i;
            num[i]=true;
            crypto(words,num,score,s,idx+1);
            num[i]=false;
            score[s[idx]]=-1;
        }
    }
}
int main(){
    vector<string> words(3);
    cin>>words[0]>>words[1]>>words[2];
    string s="";
    vector<bool> num(10);
    unordered_map<char,int> score;
    for(int i=0;i<3;i++){
        for(char x:words[i]){
            if(score.find(x)==score.end()){
                score[x]=-1;
                string temp(1,x);
                s=s+temp;
            }
        }
    }
    crypto(words,num,score,s,0);
    //cout<<s;
    return 0;
}