#include<bits/stdc++.h>
using namespace std;
void displayy(vector<vector<string>> box){
    for(auto x : box){
        for(auto y : x){
            cout<<y<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
void permutation2d(int i, int j, vector<vector<string>> &box, vector<bool> &item, int qsf){
    if(i==box.size()){
        if(qsf==item.size()){
            displayy(box);
        }
        return ;
    }
    
    int ni=i,nj=j+1;
    if(nj==box[0].size()){
        ni=i+1;
        nj=0;
    }
    for(int idx=1;idx<item.size();idx++){
        if(!item[idx]){
            item[idx]=true;
            box[i][j]="q"+to_string(idx);
            permutation2d(ni,nj,box,item,qsf+1);
            box[i][j]="-";
            item[idx]=false;
        }
    }
    permutation2d(ni,nj,box,item,qsf);
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> box(n,vector<string> (n,"-"));
    vector<bool> item(n+1,false);
    permutation2d(0,0,box,item,1);
    return 0;
}