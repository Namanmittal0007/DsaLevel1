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
void combination2d(int cq,vector<vector<char>> &box, int tq, int li, int lj){
    if(cq==tq){
        displayy(box);
        return ;
    }
    for(int col=lj+1;col<box[0].size();col++){
        box[li][col]='q';
        combination2d(cq+1,box,tq,li,col);
        box[li][col]='-';
    }
    for(int row=li+1;row<box.size();row++){
        for(int col=0;col<box[0].size();col++){
            box[row][col]='q';
            combination2d(cq+1,box,tq,row,col);
            box[row][col]='-';
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> box(n, vector<char> (n,'-'));
    combination2d(0,box,n,0,-1);
    return 0;
}