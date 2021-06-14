#include<bits/stdc++.h>
using namespace std;
void displayy(vector<vector<char>> box){
    for(auto x: box){
        for(auto y: x){
            cout<<y<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool canplaceknight(vector<vector<char>> box, int row, int col){
    int i,j;
    i=row-2;
    j=col-1;
    if(i>=0 and j>=0 and box[i][j]=='k'){
        return false;
    }
    i=row-2;
    j=col+1;
    if(i>=0 and j<box[0].size() and box[i][j]=='k'){
        return false;
    }
    i=row-1;
    j=col+2;
    if(i>=0 and j<box[0].size() and box[i][j]=='k'){
        return false;
    }
    i=row+1;
    j=col+2;
    if(i<box.size() and j<box[0].size() and box[i][j]=='k'){
        return false;
    }
    i=row+2;
    j=col+1;
    if(i<box.size() and j<box[0].size() and box[i][j]=='k'){
        return false;
    }
    i=row+2;
    j=col-1;
    if(i<box.size() and j>=0 and box[i][j]=='k'){
        return false;
    }
    i=row+1;
    j=col-2;
    if(i<box.size() and j>=0 and box[i][j]=='k'){
        return false;
    }
    i=row-1;
    j=col-2;
    if(i>=0 and j>=0 and box[i][j]=='k'){
        return false;
    }
    return true;
}
void nknightcombination(int ck,vector<vector<char>> &box, int tk, int last){
    if(ck==tk){
        displayy(box);
        return ;
    }
    for(int pos=last+1;pos<(box.size()*box.size());pos++){
        int row=pos/tk;
        int col=pos%tk;
        if(canplaceknight(box,row,col)){
            box[row][col]='k';
            nknightcombination(ck+1,box,tk,pos);
            box[row][col]='-';
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> box(n, vector<char> (n,'-'));
    nknightcombination(0,box,n,-1);
    return 0;
}