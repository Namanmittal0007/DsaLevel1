#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    else if(str.length()==1){
        char ch=str[0];
        if(ch=='0'){
            return;
        }
        else{
            int digit=ch-'0';
            char code='a'+(digit-1);
            ans=ans+code;
            cout<<ans<<endl;
            return;
        }
    }
    else{
        char ch=str[0];
        if(ch=='0'){
            return;
        }
        else{
            int digit=ch-'0';
            char code='a'+(digit-1);
            string subs=str.substr(1);
            printEncoding(subs,ans+code);
        }
        string s=str.substr(0,2);
        string subs=str.substr(2);
        int digit=stoi(s);
        if(digit<=26){
            char code='a'+(digit-1);
            printEncoding(subs,ans+code);
        }
    }
    
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}