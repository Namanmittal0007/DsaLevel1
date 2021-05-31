#include<bits/stdc++.h>
using namespace std;
void printbox(vector<vector<char>> box){
    for(int i=0;i<box.size();i++){
        for(int j=0;j<box[0].size();j++){
            cout<<box[i][j]<<"\t";
        }
        cout<<endl;
    }
}
bool canplaceposL(vector<vector<char>> &box, int i,int j, vector<int> poscol,vector<int> posrow, vector<int> negrow,vector<int> negcol){
    if((j==0 or box[i][j-1]!='+') and (i==0 or box[i-1][j]!='+') and (i==0 or box[i-1][j+1]!='-') and ((j+1)==box[0].size()-1 or box[i][j+2]!='-') ){
        return true;
    }
    return false;
}
bool canplacenegL(vector<vector<char>> &box, int i,int j, vector<int> poscol,vector<int> posrow, vector<int> negrow,vector<int> negcol){
    if((j==0 or box[i][j-1]!='-') and (i==0 or box[i-1][j]!='-') and (i==0 or box[i-1][j+1]!='+') and ((j+2)==box[0].size() or box[i][j+2]!='+')){
        return true;
    }
    return false;
}
bool canplaceposT(vector<vector<char>> &box, int i,int j, vector<int> poscol,vector<int> posrow, vector<int> negrow,vector<int> negcol){
    if((j==0 or box[i][j-1]!='+') and (i==0 or box[i-1][j]!='+') and (j==box[0].size()-1 or box[i][j+1]!='+') ){
        return true;
    }
    return false;
}
bool canplacenegT(vector<vector<char>> &box, int i,int j, vector<int> poscol,vector<int> posrow, vector<int> negrow,vector<int> negcol){
    if((j==0 or box[i][j-1]!='-') and (i==0 or box[i-1][j]!='-') and (j==box[0].size()-1 or box[i][j+1]!='-') ){
        return true;
    }
    return false;
}
bool satisfycond(vector<vector<char>> &box, vector<int> poscol,vector<int> posrow, vector<int> negrow,vector<int> negcol){
    vector<int> prow(box.size(),0), nrow(box.size(),0), pcol(box[0].size(),0), ncol(box[0].size(),0);
    for(int i=0;i<box.size();i++){
        for(int j=0;j<box[0].size();j++){
            char c=box[i][j];
            if(c=='+'){
                prow[i]++;
                pcol[j]++;
            }
            else if(c=='-'){
                nrow[i]++;
                ncol[j]++;
            }
        }
    } 
    // for(auto x : pcol){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x : prow){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x : nrow){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x : ncol){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // cout<<endl;

    for(int i=0;i<box.size();i++){
        if(posrow[i]!=-1){
            if(prow[i]!=posrow[i]){
                return false;
            }
        }
        if(negrow[i]!=-1){
            if(nrow[i]!=negrow[i]){
                return false;
            }
        }
    }
    for(int i=0;i<box[0].size();i++){
        if(poscol[i]!=-1){
            if(pcol[i]!=poscol[i]){
                return false;
            }
        }
        if(negcol[i]!=-1){
            if(ncol[i]!=negcol[i]){
                return false;
            }
        }
    }
    return true;
}
bool placemagnet(vector<vector<char>> &box, int i,int j, vector<int> poscol,vector<int> posrow, vector<int> negrow,vector<int> negcol){
    if(i==box.size()){
        if(satisfycond(box,poscol,posrow,negrow,negcol)){
            printbox(box);
            return true;
        }
        return false;
    }
    int ni=i, nj=j+1;
    if(j==box[0].size()-1){
        ni=i+1;
        nj=0;
    }
    if(box[i][j]=='L' or box[i][j]=='T'){
        bool cont=false;
        if(box[i][j]=='L'){
            if(canplaceposL(box,i,j,poscol,posrow,negrow,negcol) and !cont ){
                box[i][j]='+';
                box[i][j+1]='-';
                cont=placemagnet(box,ni,nj,poscol,posrow,negrow,negcol);
                box[i][j]='L';
                box[i][j+1]='R';
            }
            if(canplacenegL(box,i,j,poscol,posrow,negrow,negcol) and !cont ){
                box[i][j]='-';
                box[i][j+1]='+';
                cont=placemagnet(box,ni,nj,poscol,posrow,negrow,negcol);
                box[i][j]='L';
                box[i][j+1]='R';
            }
            if(true and !cont ){
                box[i][j]='X';
                box[i][j+1]='X';
                cont=placemagnet(box,ni,nj,poscol,posrow,negrow,negcol);
                box[i][j]='L';
                box[i][j+1]='R';
            }
        }
        else{
            if(canplaceposT(box,i,j,poscol,posrow,negrow,negcol) and !cont ){
                box[i][j]='+';
                box[i+1][j]='-';
                cont=placemagnet(box,ni,nj,poscol,posrow,negrow,negcol);
                box[i][j]='T';
                box[i+1][j]='B';
            }
            if(canplacenegT(box,i,j,poscol,posrow,negrow,negcol) and !cont ){
                box[i][j]='-';
                box[i+1][j]='+';
                cont=placemagnet(box,ni,nj,poscol,posrow,negrow,negcol);
                box[i][j]='T';
                box[i+1][j]='B';
            }
            if(true and !cont ){
                box[i][j]='X';
                box[i+1][j]='X';
                cont=placemagnet(box,ni,nj,poscol,posrow,negrow,negcol);
                box[i][j]='T';
                box[i+1][j]='B';
            }
        }
            return cont;
    }
    else{
               return placemagnet(box,ni,nj,poscol,posrow,negrow,negcol);
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>> box(m,(vector<char> (n)));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>box[i][j];
        }
    }
    vector<int> poscol(n,0), posrow(m,0), negrow(m,0), negcol(n,0);
    for(int i=0;i<n;i++){
        cin>>poscol[i];
    }
    for(int i=0;i<m;i++){
        cin>>posrow[i];
    }
    for(int i=0;i<m;i++){
        cin>>negrow[i];
    }
    for(int i=0;i<n;i++){ 

        cin>>negcol[i];
    }

    placemagnet(box,0,0,poscol,posrow,negrow,negcol);
}