#include<bits/stdc++.h>
using namespace std;
void displayy(vector<vector<char>> box){
    for(auto x: box){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool canplace(vector<vector<char>> box, int row, int col){
    for(int i=row; i>=0; i--){
        if(box[i][col]=='q'){
            return false;
        }
    }
    for(int j=col; j>=0;j--){
        if(box[row][j]=='q'){
            return false;
        }
    }
    for(int i=row, j=col;i>=0 and j>=0; i--,j--){
        if(box[i][j]=='q'){
            return false;
        }
    }
    for(int i=row, j=col;i>=0 and j<box[0].size(); i--,j++){
        if(box[i][j]=='q'){
            return false;
        }
    }
    return true;
}
void nqueencomb(int cq,vector<vector<char>> &box, int tq, int last){
    if(cq==tq){
        displayy(box);
        return ;
    }
    for(int pos=last+1;pos<(box.size()*box.size());pos++){
        int row=pos/tq;
        int col=pos%tq;
        if(canplace(box,row,col)){
            box[row][col]='q';
            nqueencomb(cq+1,box,tq,pos);
            box[row][col]='-';
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> box(n, vector<char> (n,'-'));
    nqueencomb(0,box,n,-1);
    return 0;
}