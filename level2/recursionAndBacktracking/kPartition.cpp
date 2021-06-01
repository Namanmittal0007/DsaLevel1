#include<bits/stdc++.h>
using namespace std;
int countt=1;
void printpartition(int idx, int n, int k, vector<vector<int>> &kpart){
    if(idx>n){
        bool flag=true;
        for(int i=0;i<kpart.size();i++){
            if(kpart[i].size()<=0){
                flag=false;
            }
        }
        if(flag){
            cout<<countt++<<".";
            string s="";
            for(int i=0;i<kpart.size();i++){
               s=s+" [";
               for(int j=0;j<kpart[i].size();j++){
                   s+=to_string(kpart[i][j])+", ";
               }
               s=s.substr(0,s.length()-2);
               s+="]";
            }
            cout<<s<<endl;
        }
        return;
    }
    for(int i=0;i<kpart.size();i++){
        if(kpart[i].size()>0){
            kpart[i].push_back(idx);
            printpartition(idx+1,n,k,kpart);
            kpart[i].pop_back();
        }
        else{
            kpart[i].push_back(idx);
            printpartition(idx+1,n,k,kpart);
            kpart[i].pop_back();
            break;
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> kpart(k);
    printpartition(1,n,k,kpart);
    return 0;
}