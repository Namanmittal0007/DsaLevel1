#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void allpalindromicpartition( string ans, string s){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=1;i<=s.length();i++){
        string newS=s.substr(0,i);
        // cout<<newS<<" ";
        string ros=s.substr(i);
        // cout<<ros<<endl;
        if(ispalindrome(newS)){
            allpalindromicpartition(ans+"("+newS+") ",ros);
        }
        else{
            // cout<<newS<<" not palindromic"<<endl;
        }
    }
}
int main(){
    string s;
    cin>>s;
    allpalindromicpartition("",s);
    return 0;
}