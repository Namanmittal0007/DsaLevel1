#include<bits/stdc++.h>
using namespace std;
void displayy(vector<vector<string>> box){
    for(auto x: box){
        for(auto y: x){
            cout<<y<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool canplace(vector<vector<string>> box, int row, int col){
    for(int i=row; i>=0; i--){
        if(box[i][col]!="-"){
            return false;
        }
    }
    for(int j=col; j>=0;j--){
        if(box[row][j]!="-"){
            return false;
        }
    }
    for(int i=row, j=col;i>=0 and j>=0; i--,j--){
        if(box[i][j]!="-"){
            return false;
        }
    }
    for(int i=row, j=col;i>=0 and j<box[0].size(); i--,j++){
        if(box[i][j]!="-"){
            return false;
        }
    }
    for(int i=row; i<box.size(); i++){
        if(box[i][col]!="-"){
            return false;
        }
    }
    for(int j=col; j<box[0].size();j++){
        if(box[row][j]!="-"){
            return false;
        }
    }
    for(int i=row, j=col;i<box.size() and j<box[0].size(); i++,j++){
        if(box[i][j]!="-"){
            return false;
        }
    }
    for(int i=row, j=col;i<box.size() and j>=0; i++,j--){
        if(box[i][j]!="-"){
            return false;
        }
    }
    return true;
}
void nqueenpermu(int cq,vector<vector<string>> &box, int tq, int last){
    if(cq==tq){
        displayy(box);
        return ;
    }
    for(int pos=0;pos<(box.size()*box.size());pos++){
        int row=pos/tq;
        int col=pos%tq;
        if(box[row][col]=="-"){
            if(canplace(box,row,col)){
                box[row][col]="q"+to_string(cq+1);
                nqueenpermu(cq+1,box,tq,pos);
                box[row][col]="-";
            }    
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> box(n, vector<string> (n,"-"));
    nqueenpermu(0,box,n,-1);
    return 0;
}