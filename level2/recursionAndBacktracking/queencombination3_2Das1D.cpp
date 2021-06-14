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
void combination2d(int cq,vector<vector<char>> &box, int tq, int last){
    if(cq==tq){
        displayy(box);
        return ;
    }
    for(int pos=last+1;pos<(box.size()*box.size());pos++){
        int row=pos/tq;
        int col=pos%tq;
        box[row][col]='q';
        combination2d(cq+1,box,tq,pos);
        box[row][col]='-';
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> box(n, vector<char> (n,'-'));
    combination2d(0,box,n,-1);
    return 0;
}