#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n,i,j,k,l;
    cin>>n>>i>>j>>k>>l;
    int onmask=1<<i;
    int offmask=~(1<<j);
    int togglemask=1<<k;
    int checkmask=1<<l;
    cout<<(n | onmask)<<endl;
    cout<<(n & offmask)<<endl;
    cout<<(n ^ togglemask)<<endl;
    cout<<(((n & checkmask) > 0) ?"true":"false")<<endl;
    return 0;
}
