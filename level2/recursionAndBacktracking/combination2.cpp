#include<bits/stdc++.h>
using namespace std;
void combination2(vector<int> &box, int ci, int num, int li){
    if(ci>num){
        for(auto x:box){
            cout<<x;
        }
        cout<<endl;
        return ;
    }
    for(int i=li+1;i<box.size();i++){
        box[i]=ci;
        combination2(box,ci+1,num,i);
        box[i]=0;
    }
}
int main(){
    int boxes, num;
    cin>>boxes>>num;
    vector<int> box(boxes, 0);
    combination2(box,1,num,-1);
    return 0;
}