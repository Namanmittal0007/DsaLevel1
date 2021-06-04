#include<bits/stdc++.h>
using namespace std;
void combn(vector<char> &box, int ci,int ti, int idx){
    if(idx==box.size()){
        if(ci==(ti+1)){
            for(auto x:box){
                cout<<x;
            }
            cout<<endl;
        }
        return;
    }
    box[idx]='i';
    combn(box,ci+1,ti,idx+1);
    box[idx]='-';
    combn(box,ci,ti,idx+1);
}
int main(){
    int boxes,items;
    cin>>boxes>>items;
    vector<char> box(boxes,'-');
    combn(box,1,items,0);
    return 0;
}