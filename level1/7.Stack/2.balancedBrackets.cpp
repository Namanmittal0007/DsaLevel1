#include<bits/stdc++.h>
using namespace std;
bool check(stack<char> &st,char c){
     if(st.size()==0){
         //cout<<"extra closing: "<<c<<endl;
         return false;
     }
     else if(st.top()!=c){
         //cout<<"diff closing and ending"<<endl;
         return false;
     }
     else{
         //cout<<"Pop: "<<c<<endl;
         st.pop();
     }
     return true;
}
int main(){
    string s;
    getline(cin,s);
    bool res=true;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='(' or c=='[' or c=='{'){
            st.push(c);
            //cout<<"Push: "<<c<<endl;
        }
        else if(c==')'){
            res=check(st,'(');
        }
        else if(c==']'){
            res=check(st,'[');
        }
        else if(c=='}'){
            res=check(st,'{');
        }
        else{

        }
        if(!res){
            break;
        }
    }
    if(st.size()>0 or !res){
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    return 0;
}