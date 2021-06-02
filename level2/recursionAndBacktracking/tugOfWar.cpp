#include<bits/stdc++.h>
using namespace std;
int mindiff=INT_MAX;
string res="";
void kequalsumsubset(int idx,vector<int> num, vector<int> &arrsum, vector<vector<int>> &arrnum){
    if(idx==num.size()){
        int currdiff=abs(arrsum[0]-arrsum[1]);
        if(currdiff<mindiff){
            mindiff=currdiff;
            string cres="[";
            for(int i=0;i<arrnum[0].size();i++){
                if(i!=(arrnum[0].size()-1)){
                    cres+=to_string(arrnum[0][i])+", ";
                }
                else{
                    cres+=to_string(arrnum[0][i]);
                }
            }
            cres+="] [";
            for(int i=0;i<arrnum[1].size();i++){
                if(i!=(arrnum[1].size()-1)){
                    cres+=to_string(arrnum[1][i])+", ";
                }
                else{
                    cres+=to_string(arrnum[1][i]);
                }
            }
            res=cres+"]";
        }
    }
    if(arrnum[0].size()<(num.size()+1)/2){
        arrsum[0]+=num[idx];
        arrnum[0].push_back(num[idx]);
        kequalsumsubset(idx+1,num,arrsum,arrnum);
        arrsum[0]-=num[idx];
        arrnum[0].pop_back();
    }
    if(arrnum[1].size()<(num.size()+1)/2){
        arrsum[1]+=num[idx];
        arrnum[1].push_back(num[idx]);
        kequalsumsubset(idx+1,num,arrsum,arrnum);
        arrsum[1]-=num[idx];
        arrnum[1].pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int> arrsum(2);
    vector<vector<int>> arrnum(2);
    kequalsumsubset(0,num,arrsum,arrnum);
    cout<<res;
    return 0;
}