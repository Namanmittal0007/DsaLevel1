#include<bits/stdc++.h>
using namespace std;
vector<int> graycode(int n){
    if(n==1){
        return vector<int> {0,1};
    }
    vector<int> code = graycode(n-1);
    vector<int> res;
    for(int i=0;i<code.size();i++){
        res.push_back(code[i]);
    }
    for(int i=code.size()-1;i>=0;i--){
        res.push_back(code[i]|1<<(n-1));
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> res= graycode(n);
    cout<<"[";
    for(int x=0; x<res.size(); x++){
        if(x!=(res.size()-1)){
            cout<<res[x]<<", ";
        }
        else{
            cout<<res[x]<<"]";
        }
    }
    return 0;
}