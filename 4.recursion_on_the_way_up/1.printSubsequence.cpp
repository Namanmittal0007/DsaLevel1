#include <bits/stdc++.h>
using namespace std;

void printSS(string ques, string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=ques[0];
    string subs=ques.substr(1);
    printSS(subs,ans+ch);
    printSS(subs,ans);
    
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}