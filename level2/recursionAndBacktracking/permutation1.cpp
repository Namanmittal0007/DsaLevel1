#include<bits/stdc++.h>
using namespace std;
void permu(vector<int> &box, int citem, int items){
    if(citem>items){
        for(auto x:box){
            cout<<x<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<box.size();i++){
        if(box[i]==0){
            box[i]=citem;
            permu(box,citem+1,items);
            box[i]=0;
        }
    }
}
int main(){
    int boxes,items;
    cin>>boxes>>items;
    vector<int> box(boxes,0);
    permu(box,1,items);
    return 0;
}