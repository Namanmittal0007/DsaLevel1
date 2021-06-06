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
void permutation2d(vector<vector<string>> box, int tq, int qsf){
    if(qsf>tq){
        displayy(box);
        return ;
    }
    for(int i=0;i<box.size();i++){
        for(int j=0;j<box[0].size();j++){
            if(box[i][j]=="-"){
                box[i][j]="q"+to_string(qsf);
                permutation2d(box,tq,qsf+1);
                box[i][j]="-";
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> box(n,vector<string> (n,"-"));
    permutation2d(box,n,1);
    return 0;
}