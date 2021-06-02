#include<bits/stdc++.h>
using namespace std;
void kequalsumsubset(int idx,vector<int> num, vector<int> &arrsum, vector<vector<int>> &arrnum, int tsum, bool &flag){
    if(idx==num.size()){
        bool allequal=true;
        for(int i=0;i<arrsum.size()-1;i++){
            if(arrsum[i]!=arrsum[i+1]){
                allequal=false;
            }
        }
        if(allequal){
            for(int i=0;i<arrnum.size();i++){
                cout<<"[";
                for(int j=0;j<arrnum[i].size();j++){
                    if(j!=(arrnum[i].size()-1)){
                        cout<<arrnum[i][j]<<", ";
                    }
                    else{
                        cout<<arrnum[i][j];
                    }
                }
                cout<<"] ";
            }
            cout<<endl;
        flag=true;
        }
    }
    for(int i=0;i<arrsum.size();i++){
        if(arrnum[i].size()>0){
            if(num[idx]+arrsum[i]<=tsum/arrsum.size()){
                arrsum[i]+=num[idx];
                arrnum[i].push_back(num[idx]);
                kequalsumsubset(idx+1,num,arrsum,arrnum,tsum,flag);
                arrsum[i]-=num[idx];
                arrnum[i].pop_back();
            }
        }
        else{
            if(num[idx]+arrsum[i]<=tsum/arrsum.size()){
                arrsum[i]+=num[idx];
                arrnum[i].push_back(num[idx]);
                kequalsumsubset(idx+1,num,arrsum,arrnum,tsum,flag);
                arrsum[i]-=num[idx];
                arrnum[i].pop_back();
            }
            break;
        }
    }
}
int main(){
    int n,tsum=0;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
        tsum+=num[i];
    }
    int k;
    cin>>k;
    if(tsum%k!=0){
        cout<<tsum;
        cout<<"-1";
        return 0;
    }
    else{
        vector<int> arrsum(k);
        vector<vector<int>> arrnum(k);
        bool flag=false;
        kequalsumsubset(0,num,arrsum,arrnum,tsum,flag);
        if(!flag){
            cout<<"-1";
        }
    }
    return 0;
}