#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    unordered_set<int> allnum;
    int totalxor=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
        allnum.insert(num[i]);
        totalxor = totalxor ^ num[i];
        totalxor = totalxor ^ (i+1);
    }
    int a=0,b=0;
    int rsb = totalxor &  ( -totalxor);
    for(int i=0;i<n;i++){
        if((num[i] & rsb) > 0){
            a = a^num[i];
        }
        if(((i+1) & rsb) > 0){
            a = a ^ (i+1);
        }
    }
    b = totalxor^a;
    a = totalxor^b;
    if(allnum.find(a) == allnum.end()){
        cout<<"Missing Number -> "<<a<<endl<<"Repeating Number -> "<<b;
    }
    else{
        cout<<"Missing Number -> "<<b<<endl<<"Repeating Number -> "<<a;
    }
    return 0;
}