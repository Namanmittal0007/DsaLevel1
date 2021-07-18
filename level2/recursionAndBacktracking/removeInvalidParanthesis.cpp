#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='('){
            st.push(c);
        }
        else{
            if(st.empty()){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    else{
        return true;
    }
}
void correctExp(int idx, string s, string ans){
    if(idx==s.length()){
        if(isvalid(ans)){
            cout<<ans<<endl;
        }
        return;
    }
    correctExp(idx+1,s,ans+string(1,s[idx]));
    correctExp(idx+1,s,ans);
}
int minremove(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='('){
            st.push(c);
        }
        else{
            if(!st.empty() and st.top()=='('){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
    }
    return st.size();
}
int main(){
    string s;
    cin>>s;
    cout<<minremove(s);
    // correctExp(0,s,"");
    return 0;
}