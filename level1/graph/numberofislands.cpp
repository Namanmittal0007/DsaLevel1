#include<bits/stdc++.h>
using namespace std;
void markisland(vector<vector<int>> land,int x,int y, vector<vector<bool>> &visited){
    if(x==land.size() || x<0 || y<0 || y==land[x].size() || land[x][y] || visited[x][y]){
        return;
    }
    visited[x][y]=true;
    markisland(land,x-1,y,visited);
    markisland(land,x,y+1,visited);
    markisland(land,x,y-1,visited);
    markisland(land,x+1,y,visited);
}
int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<int>> land(row, vector<int> (col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){

            cin>>land[i][j];
        }
    }
    int count=0;
    vector<vector<bool>> visited(row, vector<bool> (col,0));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!land[i][j] and !visited[i][j]){
                markisland(land,i,j,visited);
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}