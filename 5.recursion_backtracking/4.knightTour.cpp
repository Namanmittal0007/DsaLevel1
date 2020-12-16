#include<bits/stdc++.h>
using namespace std;
void ktour(vector<vector<int>> &v,int row,int col,int place){
    if(row<0 || col<0 || row>=v.size() || col>=v.size() || v[row][col]>0){
        return;
    }
    if(place==(v.size()*v.size())){
        v[row][col]=place;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        v[row][col]=0;
        cout<<endl;
        return;
    }
    v[row][col]=place;
    ktour(v,row-2,col+1,place+1);
    ktour(v,row-1,col+2,place+1);
    ktour(v,row+1,col+2,place+1);
    ktour(v,row+2,col+1,place+1);
    ktour(v,row+2,col-1,place+1);
    ktour(v,row+1,col-2,place+1);
    ktour(v,row-1,col-2,place+1);
    ktour(v,row-2,col-1,place+1);
    v[row][col]=0;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (n,0));
    int r,c;
    cin>>r>>c;
    ktour(v,r,c,1);
}