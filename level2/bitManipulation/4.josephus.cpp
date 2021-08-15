#include<bits/stdc++.h>
using namespace std;
int removelmsb(int n){
    int num=1, temp=n;
    while(temp>1){
        num=num*2;
        temp=temp/2;
    }
    return n-num;
}
int main(){
    int n;
    cin>>n;
    n=removelmsb(n);     //remove left most significant bit
    cout<<((2*n)+1);
    return 0;
}