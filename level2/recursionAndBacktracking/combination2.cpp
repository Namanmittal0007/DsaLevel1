#include<bits/stdc++.h>
using namespace std;
void combination2(vector<char> &box, int ci, int num, int li){
    if(ci>num){
        for(auto x:box){
            cout<<x;
        }
        cout<<endl;
        return ;
    }
    for(int i=li+1;i<box.size();i++){
        box[i]='i';
        combination2(box,ci+1,num,i);
        box[i]='-';
    }
}
int main(){
    int boxes, num;
    cin>>boxes>>num;
    vector<char> box(boxes, '-');
    combination2(box,1,num,-1);
    return 0;
}