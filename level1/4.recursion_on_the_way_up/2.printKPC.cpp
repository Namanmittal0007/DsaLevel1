#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printkpc(string ques, string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=ques[0];
    string s=codes[ch-'0'];
    string subs=ques.substr(1);
    for(int i=0;i<s.length();i++){
        printkpc(subs,ans+s[i]);
    }
}

int main(){
    string str;
    cin >> str;
    printkpc(str, "");
}