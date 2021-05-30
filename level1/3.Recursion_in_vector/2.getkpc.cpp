#include<iostream>
#include<vector>
using namespace std;

vector<string> keypad{".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> getkpc(string s){
    if(s.length()==0){
        vector<string> fres{""};
        return fres;
    }
    char ch=s[0];
    vector<string> cres=getkpc(s.substr(1));
    vector<string> fres;
    string str=keypad[ch-'0'];
    for(int i=0;i<str.length();i++){
        for(int j=0;j<cres.size();j++){
            fres.push_back(str[i]+cres[j]);
        }
    }
    return fres;
}
int main(){
    string s;
    cin>>s;
    vector<string> result;
    result=getkpc(s);
    cout<<"["<<result[0];
    for(int i=1;i<result.size();i++){
        cout<<", "<<result[i];
    }
    cout<<"]";
    return 0;
} 