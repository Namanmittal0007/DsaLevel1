#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> getpath(int n){
    if(n==0){
        vector<string> fpath;
        fpath.push_back("");
        return fpath;
    }
    else{
        vector<string> path1,path2,path3;
        if(n>0){
            path1=getpath(n-1);
        }
        if(n>1){
            path2=getpath(n-2);
        }
        if(n>2){
            path3=getpath(n-3);
        }
        vector<string> fpath;
        for(int i=0;i<path1.size();i++){
            fpath.push_back('1'+path1[i]);
        }
        for(int i=0;i<path2.size();i++){
            fpath.push_back('2'+path2[i]);
        }
        for(int i=0;i<path3.size();i++){
            fpath.push_back('3'+path3[i]);
        }
        return fpath;
    }
}
int main(){
    int n;
    cin>>n;
    vector<string> result;
    result=getpath(n);
    cout<<"["<<result[0];
    for(int i=1;i<result.size();i++){
        cout<<", "<<result[i];
    }
    cout<<"]";
    return 0;
}