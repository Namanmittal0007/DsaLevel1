#include<bits/stdc++.h>
using namespace std;
void floodfill(int n,int m,vector<vector<int>> arr,int row,int col,string ans){
    if(row<0 || col<0 || row>=n || col>=m || arr[row][col]==1){
        return;
    }
    if(row==n-1 and col==m-1){
        cout<<ans<<endl;
        return ;
    }
    arr[row][col]=1;
    floodfill(n,m,arr,row-1,col,ans+'t');
    floodfill(n,m,arr,row,col-1,ans+'l');
    floodfill(n,m,arr,row+1,col,ans+'d');
    floodfill(n,m,arr,row,col+1,ans+'r');
    arr[row][col]=0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    floodfill(n,m,arr,0,0,"");
    return 0;
}