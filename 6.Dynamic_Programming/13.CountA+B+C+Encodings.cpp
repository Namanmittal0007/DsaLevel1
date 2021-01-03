#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a=0,ab=0,abc=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            a=a+a+1;
        }
        else if(s[i]=='b'){
            ab=ab+ab+a;
        }
        else  if(s[i]=='c'){
            abc=abc+abc+ab;
        }
    }
    cout<<abc;
    return 0;
}
