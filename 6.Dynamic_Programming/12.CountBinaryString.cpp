#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int e0=1;
    int e1=1;
    for(int i=2;i<=n;i++){
        int ne0=e1;
        int ne1=e0+e1;
        e0=ne0;
        e1=ne1;
    }
    cout<<(e0+e1);
    return 0;
}