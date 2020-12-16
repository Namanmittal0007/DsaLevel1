#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<vector<int>> v,int row,int col){
    for(int i=row-1;i>=0;i--){
        if(v[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
        if(v[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 and j<v[0].size();i--,j++){
        if(v[i][j]==1){
            return false;
        }
    }
    return  true;
}
void nqueen(vector<vector<int>> v,int row,string ans){
    //cout<<row<<endl;
    if(row==v.size()){
        cout<<ans<<"."<<endl;
        return;
    }
    for(int col=0;col<v[0].size();col++){
        if(ispossible(v,row,col)){
            v[row][col]=1;
            nqueen(v,row+1,ans+to_string(row)+"-"+to_string(col)+", ");
            v[row][col]=0;
        }
        //else{cout<<"faild for: "<<row<<","<<col<<endl;}
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> cboard(n,vector<int> (n,0));
    
    nqueen(cboard,0,"");
}