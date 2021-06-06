#include<bits/stdc++.h>
using namespace std;
void displayy(vector<vector<char>> board){
    for(auto x : board){
        for(auto y : x){
            cout<<y;
        }
        cout<<endl;
    }
    cout<<endl;
}
void combination2d(vector<vector<char>> board, int i, int j, int qsf){
    if(i==board.size()){
        // if n*n board place n queens
        if(qsf==board.size()){
            displayy(board);
        }
        return ;
    }
    int ni=i,nj=j+1;
    if(j==(board[0].size()-1)){
        ni=i+1;
        nj=0;
    }
    board[i][j]='q';
    combination2d(board,ni,nj,qsf+1);
    board[i][j]='-';
    combination2d(board,ni,nj,qsf);
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> board(n,vector<char> (n,'-'));
    combination2d(board,0,0,0);
    return 0;
}