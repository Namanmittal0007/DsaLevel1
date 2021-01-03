#include<iostream>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n>>k;
    long same=k;
    long diff=k*(k-1);
    for(int i=3;i<=n;i++){
        long nsame=diff;
        long ndiff=(same+diff)*(k-1);
        same=nsame;
        diff=ndiff;
    }
    cout<<(same+diff);
    return 0;
}