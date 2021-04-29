#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int> um;
    um["delhi"]=100;
    um["mumbai"]=120;
    um["gujrat"]=60;
    um["bihar"]=50;
    for(auto x:um){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<um["delhi"]<<endl;
    if(um.find("delhi")!=um.end()){
        cout<<"Found"<<" ";
    }
    else{
        cout<<"Not found";
    }
    return 0;
}