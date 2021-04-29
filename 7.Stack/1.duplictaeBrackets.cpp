#include<bits/stdc++.h>
using namespace std;
bool check(stack<char> &st,char c){
    if(st.top()==c){
        return true;
    }
    while(st.top()!=c){
        st.pop();
    }
    
    st.pop();
    return false;
}
int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    bool res=false;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c==')'){
            res=check(st,'(');
            if(res){
                cout<<"true";
                return 0;
            }
        }
        else if(c==']'){
            res=check(st,'[');
            if(res){
                cout<<"true";
                return 0;
            }
        }
        else if(c=='}'){
            res=check(st,'{');
            if(res){
                cout<<"true";
                return 0;
            }
        }
        else{
            st.push(c);
        }
    }
    cout<<"false";
    return 0;
}