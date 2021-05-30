#include<bits/stdc++.h>
using namespace std;
void displayboard(vector<vector<int>> board,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void knighttour(vector<vector<int>> &board, int size, int row, int col,int step){
    if(row<0 || row>=size || col<0 || col>=size || board[row][col]>0){
        return;
    }
    else if(step==size*size){
        board[row][col]=step;
        displayboard(board,size);
        cout<<endl;
        board[row][col]=0;
        return;
    }
    board[row][col]=step;
    knighttour(board,size,row-2,col+1,step+1);
    knighttour(board,size,row-1,col+2,step+1);
    knighttour(board,size,row+1,col+2,step+1);
    knighttour(board,size,row+2,col+1,step+1);
    knighttour(board,size,row+2,col-1,step+1);
    knighttour(board,size,row+1,col-2,step+1);
    knighttour(board,size,row-1,col-2,step+1);
    knighttour(board,size,row-2,col-1,step+1);
    board[row][col]=0;
}
int main(){
    int size,row,col;
    cin>>size>>row>>col;
    vector<vector<int>> board(size,vector<int>(size,0));
    knighttour(board,size,row,col,1);
    return 0;
}