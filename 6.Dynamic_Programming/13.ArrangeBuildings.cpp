#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long b=1;
    long NOb=1;
    for(int i=2;i<=n;i++){
        long newb=NOb;
        long newNOb=b+NOb;
        b=newb;
        NOb=newNOb;
    }
    cout<<((b+NOb)*(b+NOb));
    return 0;
}