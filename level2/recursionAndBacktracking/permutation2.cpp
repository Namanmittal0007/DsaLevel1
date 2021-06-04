#include<bits/stdc++.h>
using namespace std;
void permutation2(int idx, int num, vector<int> &box, vector<bool> &item, int ssf){
    if(idx==box.size()){
        if(ssf==(item.size()-1)){
            for(auto x:box){
                cout<<x;
            }
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=num;i++){
        if(!item[i]){
            box[idx]=i;
            item[i]=1;
            permutation2(idx+1,num,box,item,ssf+1);
            item[i]=0;
            box[idx]=0;
        }
    }
    permutation2(idx+1,num,box,item,ssf);
}
int main(){
    int boxes,num;
    cin>>boxes>>num;
    vector<int> box(boxes,0);
    vector<bool> item(num+1,false);
    permutation2(0,num,box,item,0);
    return 0;
}